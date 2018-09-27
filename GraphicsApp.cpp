/***************************************************************
 * Name:      GraphicsApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Maria Pomarańska, Wojciech Majkut, Karol Pogwizd ()
 * Created:   2018-05-12
 * Copyright: Maria Pomarańska, Wojciech Majkut, Karol Pogwizd ()
 * License:
 **************************************************************/



//(*AppHeaders
#include "stdafx.h"
//*)

IMPLEMENT_APP(GraphicsApp);

bool GraphicsApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	wxFrame* Frame = new GUIMyFrame(NULL);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
