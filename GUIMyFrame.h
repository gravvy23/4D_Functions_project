#ifndef __GUIMyFrame__
#define __GUIMyFrame__

#include "GraphicsMain.h"

#include <fstream>
#include <string>
#include <wx/filedlg.h>
#include <wx/dcmemory.h>
#include <wx/dcclient.h>
#include <wx/dcbuffer.h>
#include <wx/rawbmp.h>
#include <memory>

struct Point;

class GUIMyFrame : public GraphicsFrame
{
private:
	std::vector<Point> data; //dane wczytane z pliku
	std::vector<float> interpolated_data; //dane wyinterpolowane przez interpolate()
	int m_slice_c; //liczba przekrojow
	float m_current_val; //obecna wartosc zmiennej
	float m_min, m_max; //min i max wartosc zmiennej
	float m_max_val, m_min_val; //min i max wartosc funkcji do Sheprad()
	float interpolate(float x, float y, float z); //aplikacja 'czystego' kodu algorytmu Sheparda
	void ShepardMethod(void); //wyznaczanie wartosci punktow dla zadanego wektora 
protected:
	// Handlers for GraphicsFrame events.
	void Panel_Repaint(wxUpdateUIEvent& event); //odsiezanie panelu
	void m_button_load_function_click(wxCommandEvent& event); //wczytywanie danych
	void m_get_min(wxKeyEvent& event); //wczytywanie wartosci maksymalnej na przekroju
	void m_get_max(wxKeyEvent& event); //wczytywanie wartosci minimalnej na przekroju
	void m_slice_count(wxCommandEvent& event); //wczytywanie liczby przekrojow
	void Scroll_Updated(wxScrollEvent& event); //obsluga scroll button
	void Scroll_Updated_mouse(wxMouseEvent& event); //obsluga myszy
	void SaveFile(wxCommandEvent &event); //zapis pliku
	void vector_function(wxCommandEvent &event); //funckja do wyboru wektorow
	void keyboard_events(wxKeyEvent& event); //strzalki w gore i w dol na klawiaturze

public:
	/** Constructor */
	GUIMyFrame(wxWindow* parent);
	wxBitmap MemoryBitmap;
	wxImage image;
	//// end generated class members
	void Repaint();
	void DrawMap();
};


#endif