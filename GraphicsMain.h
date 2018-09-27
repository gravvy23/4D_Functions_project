/***************************************************************
 * Name:      GraphicsMain.h
 * Purpose:   Defines Application Frame
 * Author:    Maria Pomarañska, Wojciech Majkut, Karol Pogwizd ()
 * Created:   2018-05-12
 * Copyright: Maria Pomarañska, Wojciech Majkut, Karol Pogwizd ()
 * License:
 **************************************************************/

#ifndef GRAPHICSMAIN_H
#define GRAPHICSMAIN_H

//(*Headers(GraphicsFrame)
#include <wx/button.h>
#include <wx/choice.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/slider.h>
#include <wx/stattext.h>
#include <wx/statusbr.h>
#include <wx/textctrl.h>
#include <wx/dcmemory.h>
#include <wx/dcclient.h>
#include <wx/filedlg.h>

//*)

class GraphicsFrame: public wxFrame
{
    public:

        GraphicsFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~GraphicsFrame();

	protected:
        //(*Handlers(GraphicsFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
		virtual void Panel_Repaint(wxUpdateUIEvent& event) { event.Skip(); }
		virtual void m_button_load_function_click(wxCommandEvent& event) { event.Skip(); }
		virtual void m_get_min(wxKeyEvent& event) { event.Skip(); }
		virtual void m_get_max(wxKeyEvent& event) { event.Skip(); }
		virtual void m_slice_count(wxCommandEvent& event) { event.Skip(); }
		virtual void Scroll_Updated(wxScrollEvent& event) { event.Skip(); }
		virtual void Scroll_Updated_mouse(wxMouseEvent& event) { event.Skip(); }
		virtual void SaveFile(wxCommandEvent &event) { event.Skip(); }
		virtual void vector_function(wxCommandEvent &event) { event.Skip(); }
		virtual void keyboard_events(wxKeyEvent& event) { event.Skip(); }
        //*)

        //(*Identifiers(GraphicsFrame)
        static const long ID_BUTTON1;
        static const long ID_STATICTEXT1;
        static const long ID_TEXTCTRL1;
        static const long ID_STATICTEXT2;
        static const long ID_TEXTCTRL2;
        static const long ID_STATICTEXT3;
        static const long ID_CHOICE1;
        static const long ID_BUTTON2;
        static const long ID_PANEL1;
        static const long ID_SLIDER1;
        static const long ID_STATICTEXT4;
		static const long ID_STATICTEXT5;
		static const long ID_STATICTEXT6;
		static const long ID_CHOICE2;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(GraphicsFrame)
        wxButton* Button1;
        wxButton* Button2;
        wxChoice* Choice1;
		wxChoice* Choice2;
        wxPanel* Panel1;
		wxMemoryDC* my_wxmemorydc;
        wxSlider* Slider1;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxStaticText* StaticText3;
        wxStaticText* StaticText4;
		wxStaticText* StaticText5;
		wxStaticText* StaticText6;
        wxStatusBar* StatusBar1;
        wxTextCtrl* TextCtrl1;
        wxTextCtrl* TextCtrl2;
		wxClientDC* my_wxclientdc;
		wxFileDialog* FileDialog2;
		


        //*)

        DECLARE_EVENT_TABLE()
};

#endif // GRAPHICSMAIN_H
