#include "GUIMyFrame.h"
#include "stdafx.h"
#include <wx/image.h>
#include <wx/msgdlg.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/filedlg.h>
#include <vector>

////////////////////////////////////////////////////////////////////////
struct Point {
	float x, y, z, val;
	Point(float _x, float _y, float _z, float _val) : x(_x), y(_y), z(_z), val(_val) {}
};


////////////////////////////////////////////////////////////////////////
GUIMyFrame::GUIMyFrame(wxWindow* parent)
	:
	GraphicsFrame(parent)
{
	std::string val = TextCtrl1->GetValue().ToStdString();
	m_min = std::stof(val);
	val = TextCtrl2->GetValue().ToStdString();
	m_max = std::stof(val);
	this->SetBackgroundColour(wxColor(192, 192, 192));
	MemoryBitmap.Create(50,50, 24);
	image.Create(500, 500);
	m_current_val = 0;
	m_slice_c = 3;
	my_wxmemorydc = new wxMemoryDC();
	DrawMap();
}

////////////////////////////////////////////////////////////////////////
void GUIMyFrame::Panel_Repaint(wxUpdateUIEvent& event)
{
	Repaint();
}

////////////////////////////////////////////////////////////////////////
void GUIMyFrame::m_button_load_function_click(wxCommandEvent& event)
{
	wxFileDialog WxOpenFileDialog(this, wxT("Choose a file"), wxT(""), wxT(""), wxT("DAT file (*.dat)|*.dat"), wxFD_OPEN | wxFD_FILE_MUST_EXIST);

	if (WxOpenFileDialog.ShowModal() == wxID_OK)
	{
		float x, y, z, val;
		m_max_val = -100;
		m_min_val = 100;
		std::ifstream in(WxOpenFileDialog.GetPath().ToAscii());
		if (in.is_open())
		{
			data.clear();
			while (!in.eof())
			{
				in >> x >> y >> z >> val;
				if (val < m_min_val) m_min_val = val;
				if (val > m_max_val) m_max_val = val;
				data.push_back(Point(x, y, z, val));
			}
			in.close();
		}
	}
	DrawMap();
}

////////////////////////////////////////////////////////////////////////
void GUIMyFrame::m_get_min(wxKeyEvent& event) 
{
	std::string val = TextCtrl1->GetValue().ToStdString();
	m_min = std::stof(val);
	DrawMap();
}

////////////////////////////////////////////////////////////////////////
void GUIMyFrame::m_get_max(wxKeyEvent& event) {
	std::string val = TextCtrl2->GetValue().ToStdString();
	m_max = std::stof(val);
	DrawMap();
}

////////////////////////////////////////////////////////////////////////
void GUIMyFrame::m_slice_count(wxCommandEvent& event) {
	int i = event.GetSelection();
	if (i == 0) m_slice_c = 2;
	else if (i == 1) m_slice_c = 3;
	else if (i == 2) m_slice_c = 4;
	else if (i == 3) m_slice_c = 5;
	else if (i == 4) m_slice_c = 10;
	else if (i == 5) m_slice_c = 20;
	DrawMap();
}

////////////////////////////////////////////////////////////////////////
void GUIMyFrame::Scroll_Updated(wxScrollEvent& event) {
	int unit = 100 / m_slice_c;
	int val = Slider1->GetValue();
	int c = val / unit;
	float prev = m_current_val;
	m_current_val = m_min + (c * (m_max - m_min))/(m_slice_c - 1);
	if (Slider1->GetValue() == 100) m_current_val = m_max;
	StaticText6->SetLabel(wxString::Format(wxT("%.1f"), m_current_val));
	if (fabs(prev - m_current_val) > 1e-2) DrawMap();
}

////////////////////////////////////////////////////////////////////////
void GUIMyFrame::Scroll_Updated_mouse(wxMouseEvent& event) {
	int unit = 100 / m_slice_c;
	int val = Slider1->GetValue();
	double step = (m_max - m_min) / (m_slice_c - 1);
	int c = val / unit;
	if (event.RightDown()) {
		if (c < m_slice_c) {
			m_current_val = m_min + step*(c+1);
			Slider1->SetValue(100*((m_current_val - m_min)/(m_max-m_min)));
			StaticText6->SetLabel(wxString::Format(wxT("%.1f"), m_current_val));
		}
	}
	if (event.LeftDown()) {
		if (c > 0) {
			if (c == m_slice_c)
				m_current_val = m_min + step * (c - 2);
			else 
				m_current_val = m_min + step * (c - 1);
			Slider1->SetValue(100 * ((m_current_val - m_min) / (m_max - m_min)));
			StaticText6->SetLabel(wxString::Format(wxT("%.1f"), m_current_val));
		}
	}
	DrawMap();
}

////////////////////////////////////////////////////////////////////////
void  GUIMyFrame::keyboard_events(wxKeyEvent& event)
{
	int unit = 100 / m_slice_c;
	int val = Slider1->GetValue();
	double step = (m_max - m_min) / (m_slice_c - 1);
	int c = val / unit;
	static bool flag = true;
	if (event.GetKeyCode() == WXK_UP && flag)
	{
		if (c < m_slice_c) {
			m_current_val = m_min + step * (c + 1);
			Slider1->SetValue(100 * ((m_current_val - m_min) / (m_max - m_min)));
			StaticText6->SetLabel(wxString::Format(wxT("%.1f"), m_current_val));
		}
		flag = false;
	}
	else if (event.GetKeyCode() == WXK_DOWN && flag) {
		if (c > 0) {
			if (c == m_slice_c)
				m_current_val = m_min + step * (c - 2);
			else
				m_current_val = m_min + step * (c - 1);
			Slider1->SetValue(100 * ((m_current_val - m_min) / (m_max - m_min)));
			StaticText6->SetLabel(wxString::Format(wxT("%.1f"), m_current_val));
		}
		flag = false;
	}
	else flag = true;
	DrawMap();
}
////////////////////////////////////////////////////////////////////////
void GUIMyFrame::Repaint()
{

	wxImage temp_image = MemoryBitmap.ConvertToImage();
	temp_image.Rescale(500, 500);
	temp_image = temp_image.Blur(5);
	image = temp_image.Copy();
	wxBitmap tmp(image);
	wxMemoryDC memDC;
	memDC.SelectObject(tmp);
	wxClientDC dc(Panel1);
	dc.Blit(0, 0, 500, 500, &memDC, 0, 0);
	memDC.SelectObject(wxNullBitmap);
	
}



////////////////////////////////////////////////////////////////////////
float GUIMyFrame::interpolate(float x, float y, float z)
{
	float nominator, denominator, w;
	nominator = denominator = 0.0;
	Point tmp(0, 0, 0, 0);
	for (int i = 0; i<data.size(); ++i) {
		tmp = data[i];
		if (tmp.x == x && tmp.y == y && tmp.z == z) return tmp.val;
		w = 1. / pow((x - tmp.x)*(x - tmp.x) + (y - tmp.y)*(y - tmp.y) + (z - tmp.z)*(z - tmp.z),1.5);
		nominator += tmp.val*w;
		denominator += w;
	}
	return nominator / denominator;
}

////////////////////////////////////////////////////////////////////////
// rysowanie na bitmapie
void GUIMyFrame::DrawMap(void) 
{
	wxNativePixelData data(MemoryBitmap);
	wxNativePixelData::Iterator p(data);
	float r, b, val;
	ShepardMethod();
	for (int i = 0; i < 50; ++i)
	{
		wxNativePixelData::Iterator rowStart = p;
		for (int j = 0; j < 50; ++j, ++p) {
			val = interpolated_data[50*i + j];
			r = ((val - m_min_val) / (m_max_val - m_min_val)) * 255;
			b = 255 - ((val - m_min_val) / (m_max_val - m_min_val)) * 255;
			p.Red() = r;
			p.Green() = 0;
			p.Blue() = b;
		}
		p = rowStart;
		p.OffsetY(data, 1);
	}
}

//////////////////////////////////////////////////////////////////////////






void GUIMyFrame::SaveFile(wxCommandEvent &event) {
	
	
	wxBitmap *my_bitmap_tmp = new wxBitmap(image);
	
	my_wxmemorydc->SelectObject(*my_bitmap_tmp);
	my_wxmemorydc->Blit(wxPoint(0, 0), Panel1->GetSize(), my_wxclientdc, wxPoint(-1, -1), wxCOPY, true, wxDefaultPosition);
	
	int dlg = FileDialog2->ShowModal();
	if (dlg == wxID_OK)
	{
	
		(*my_bitmap_tmp).SaveFile(FileDialog2->GetPath(), wxBITMAP_TYPE_BMP, NULL);

	}
	
	
	
}


///////////////////////////////////////////////////////////////////////

void GUIMyFrame::vector_function(wxCommandEvent& event) {
	DrawMap();
}

////////////////////////////////////////////////////////////////////////
void GUIMyFrame::ShepardMethod(void) {
	float step = (m_max - m_min) / 50;
	float val;
	interpolated_data.clear();
	for (int i = 0; i < 50; ++i)
		for (int j = 0; j < 50; ++j)
		{

			if (Choice2->GetSelection() == 0) //WARUNEK NA WEKTOR [1,0,0]
				val = interpolate(m_current_val, m_min + step * i, m_min + step * j);
			if (Choice2->GetSelection() == 1) //WARUNEK NA WEKTOR [0,1,0]
				val = interpolate(m_min + step * j, m_current_val, m_min + step * i);
			if (Choice2->GetSelection() == 2) //WARUNEK NA WEKTOR [0,0,1]
				val = interpolate(m_min + step * j, m_min + step * i, m_current_val);
			if (Choice2->GetSelection() == 3) //WARUNEK NA WEKTOR [1,1,0]
			{
				double min = m_min;
				double max = m_max;
				double x, this_step;
				if (m_current_val > 0) {
					min = m_min + m_current_val * sqrt(2);
					this_step = (max - min) / 50;
					x = min + this_step * j;
				}
				else {
					max = m_max + m_current_val * sqrt(2);
					this_step = (max - min) / 50;
					x = min + this_step * j;
				}
				val = interpolate(x, -x + (m_current_val)*sqrt(2), m_min + step * i);
			}
			if (Choice2->GetSelection() == 4) //WARUNEK NA WEKTOR [1,0,1]
			{
				double min = m_min;
				double max = m_max;
				double x, this_step;
				if (m_current_val > 0) {
					min = m_min + m_current_val * sqrt(2);
					this_step = (max - min) / 50;
					x = min + this_step * j;
				}
				else {
					max = m_max + m_current_val * sqrt(2);
					this_step = (max - min) / 50;
					x = min + this_step * j;
				}
				val = interpolate(x, m_min + step * i, -x + (m_current_val)*sqrt(2));
			}
			if (Choice2->GetSelection() == 5) //WARUNEK NA WEKTOR [0,1,1]
			{
				double min = m_min;
				double max = m_max;
				double y, this_step;
				if (m_current_val > 0) {
					min = m_min + m_current_val * sqrt(2);
					this_step = (max - min) / 50;
					y = min + this_step * j;
				}
				else {
					max = m_max + m_current_val * sqrt(2);
					this_step = (max - min) / 50;
					y = min + this_step * j;
				}
				val = interpolate(m_min + step * i, y, -y + (m_current_val)*sqrt(2));
			}
			interpolated_data.push_back(val);
			if (m_max_val < val) m_max_val = val;
			if (m_min_val > val) m_min_val = val;
		}
}


