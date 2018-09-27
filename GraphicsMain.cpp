/***************************************************************
 * Name:      GraphicsMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Maria Pomarañska, Wojciech Majkut, Karol Pogwizd ()
 * Created:   2018-05-12
 * Copyright: Maria Pomarañska, Wojciech Majkut, Karol Pogwizd ()
 * License:
 **************************************************************/

#include "stdafx.h"


//(*InternalHeaders(GraphicsFrame)

//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(GraphicsFrame)
const long GraphicsFrame::ID_BUTTON1 = wxNewId();
const long GraphicsFrame::ID_STATICTEXT1 = wxNewId();
const long GraphicsFrame::ID_TEXTCTRL1 = wxNewId();
const long GraphicsFrame::ID_STATICTEXT2 = wxNewId();
const long GraphicsFrame::ID_TEXTCTRL2 = wxNewId();
const long GraphicsFrame::ID_STATICTEXT3 = wxNewId();
const long GraphicsFrame::ID_CHOICE1 = wxNewId();
const long GraphicsFrame::ID_BUTTON2 = wxNewId();
const long GraphicsFrame::ID_PANEL1 = wxNewId();
const long GraphicsFrame::ID_SLIDER1 = wxNewId();
const long GraphicsFrame::ID_STATICTEXT4 = wxNewId();
const long GraphicsFrame::ID_STATICTEXT5 = wxNewId();
const long GraphicsFrame::ID_STATICTEXT6 = wxNewId();
const long GraphicsFrame::ID_CHOICE2 = wxNewId();
const long GraphicsFrame::idMenuQuit = wxNewId();
const long GraphicsFrame::idMenuAbout = wxNewId();
const long GraphicsFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(GraphicsFrame,wxFrame)
END_EVENT_TABLE()

GraphicsFrame::GraphicsFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(GraphicsFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(750,620));
    Button1 = new wxButton(this, ID_BUTTON1, _("Wczytaj z pliku"), wxPoint(564,24), wxSize(144,30), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("MIN"), wxPoint(564,72), wxSize(40,20), 0, _T("ID_STATICTEXT1"));
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, _("-2.0"), wxPoint(612,72), wxSize(96,30), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("MAX"), wxPoint(564,114), wxSize(40,20), 0, _T("ID_STATICTEXT2"));
    TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, _("2.0"), wxPoint(612,114), wxSize(96,30), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Wybierz krok:"), wxPoint(564,152), wxSize(144,20), 0, _T("ID_STATICTEXT3"));
    Choice1 = new wxChoice(this, ID_CHOICE1, wxPoint(564,176), wxSize(144,30), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
    Choice1->Append(_("2"));
    Choice1->Append(_("3"));
    Choice1->Append(_("4"));
    Choice1->Append(_("5"));
    Choice1->Append(_("10"));
    Choice1->Append(_("20"));
	Choice1->SetSelection(1);
    Button2 = new wxButton(this, ID_BUTTON2, _("Zapisz do pliku"), wxPoint(564,308), wxSize(144,30), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(24,24), wxSize(500,500), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    Slider1 = new wxSlider(this, ID_SLIDER1, 50, 0, 100, wxPoint(96,534), wxSize(344,30), 0, wxDefaultValidator, _T("ID_SLIDER1"));
	StaticText6 = new wxStaticText(this, ID_STATICTEXT5, _("0.0"), wxPoint(450, 534), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Przekroje:"), wxPoint(24,534), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Wybierz wektor:"), wxPoint(564, 224), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	Choice2 = new wxChoice(this, ID_CHOICE2, wxPoint(564, 248), wxSize(144, 30), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
	Choice2->Append(_("[1, 0, 0]"));
	Choice2->Append(_("[0, 1, 0]"));
	Choice2->Append(_("[0, 0, 1]"));
	Choice2->Append(_("[1, 1, 0]"));
	Choice2->Append(_("[1, 0, 1]"));
	Choice2->Append(_("[0, 1, 1]"));
	Choice2->SetSelection(0);
	MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
	////////////////////////////
	FileDialog2 = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, _("BMP files|*.bmp|JPEG files|*.jpeg|XPM files|*.xpm"), wxFD_SAVE | wxFD_OVERWRITE_PROMPT, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
	//////////////////////////////


    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&GraphicsFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&GraphicsFrame::OnAbout);
	Panel1->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(GraphicsFrame::Panel_Repaint), NULL, this);
	Button1->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(GraphicsFrame::m_button_load_function_click), NULL, this);
	TextCtrl1->Connect(wxEVT_COMMAND_TEXT_UPDATED, wxKeyEventHandler(GraphicsFrame::m_get_min), NULL, this);
	TextCtrl2->Connect(wxEVT_COMMAND_TEXT_UPDATED, wxKeyEventHandler(GraphicsFrame::m_get_max), NULL, this);
	Choice1->Connect(wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler(GraphicsFrame::m_slice_count), NULL, this);
	
	Slider1->Connect(wxEVT_SCROLL_TOP, wxScrollEventHandler(GraphicsFrame::Scroll_Updated), NULL, this);
	Slider1->Connect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(GraphicsFrame::Scroll_Updated), NULL, this);
	Slider1->Connect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(GraphicsFrame::Scroll_Updated), NULL, this);
	Slider1->Connect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(GraphicsFrame::Scroll_Updated), NULL, this);
	Slider1->Connect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(GraphicsFrame::Scroll_Updated), NULL, this);
	Slider1->Connect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(GraphicsFrame::Scroll_Updated), NULL, this);
	Slider1->Connect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(GraphicsFrame::Scroll_Updated), NULL, this);
	Slider1->Connect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(GraphicsFrame::Scroll_Updated), NULL, this);
	Slider1->Connect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(GraphicsFrame::Scroll_Updated), NULL, this);
	Connect(wxEVT_KEY_UP, wxKeyEventHandler(GraphicsFrame::keyboard_events), NULL, this);
	Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(GraphicsFrame::keyboard_events), NULL, this);
	Panel1->Connect(wxEVT_KEY_UP, wxKeyEventHandler(GraphicsFrame::keyboard_events), NULL, this);
	Panel1->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(GraphicsFrame::keyboard_events), NULL, this);
	Choice1->Connect(wxEVT_KEY_UP, wxKeyEventHandler(GraphicsFrame::keyboard_events), NULL, this);
	Choice1->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(GraphicsFrame::keyboard_events), NULL, this);
	Choice2->Connect(wxEVT_KEY_UP, wxKeyEventHandler(GraphicsFrame::keyboard_events), NULL, this);
	Choice2->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(GraphicsFrame::keyboard_events), NULL, this);
	Button1->Connect(wxEVT_KEY_UP, wxKeyEventHandler(GraphicsFrame::keyboard_events), NULL, this);
	Button1->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(GraphicsFrame::keyboard_events), NULL, this);
	Button2->Connect(wxEVT_KEY_UP, wxKeyEventHandler(GraphicsFrame::keyboard_events), NULL, this);
	Button2->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(GraphicsFrame::keyboard_events), NULL, this);
	Panel1->Connect(wxEVT_RIGHT_DOWN, wxMouseEventHandler(GraphicsFrame::Scroll_Updated_mouse), NULL, this);
	Panel1->Connect(wxEVT_LEFT_DOWN, wxMouseEventHandler(GraphicsFrame::Scroll_Updated_mouse), NULL, this);
	Button2->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(GraphicsFrame::SaveFile), NULL, this);
	Choice2->Connect(wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler(GraphicsFrame::vector_function), NULL, this);
    
}

GraphicsFrame::~GraphicsFrame()
{
    //(*Destroy(GraphicsFrame)
	Panel1->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(GraphicsFrame::Panel_Repaint), NULL, this);
	Button1->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(GraphicsFrame::m_button_load_function_click), NULL, this);
	TextCtrl1->Disconnect(wxEVT_COMMAND_TEXT_UPDATED, wxKeyEventHandler(GraphicsFrame::m_get_min), NULL, this);
	TextCtrl2->Disconnect(wxEVT_COMMAND_TEXT_UPDATED, wxKeyEventHandler(GraphicsFrame::m_get_max), NULL, this);
	Choice1->Disconnect(wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler(GraphicsFrame::m_slice_count), NULL, this);

	Slider1->Disconnect(wxEVT_SCROLL_TOP, wxScrollEventHandler(GraphicsFrame::Scroll_Updated), NULL, this);
	Slider1->Disconnect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(GraphicsFrame::Scroll_Updated), NULL, this);
	Slider1->Disconnect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(GraphicsFrame::Scroll_Updated), NULL, this);
	Slider1->Disconnect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(GraphicsFrame::Scroll_Updated), NULL, this);
	Slider1->Disconnect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(GraphicsFrame::Scroll_Updated), NULL, this);
	Slider1->Disconnect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(GraphicsFrame::Scroll_Updated), NULL, this);
	Slider1->Disconnect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(GraphicsFrame::Scroll_Updated), NULL, this);
	Slider1->Disconnect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(GraphicsFrame::Scroll_Updated), NULL, this);
	Slider1->Disconnect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(GraphicsFrame::Scroll_Updated), NULL, this);
	Panel1->Disconnect(wxEVT_RIGHT_DOWN, wxMouseEventHandler(GraphicsFrame::Scroll_Updated_mouse), NULL, this);
	Panel1->Disconnect(wxEVT_LEFT_DOWN, wxMouseEventHandler(GraphicsFrame::Scroll_Updated_mouse), NULL, this);
    //*)
}

void GraphicsFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void GraphicsFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}
