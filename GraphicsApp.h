/***************************************************************
 * Name:      GraphicsApp.h
 * Purpose:   Defines Application Class
 * Author:    Maria Pomarañska, Wojciech Majkut, Karol Pogwizd ()
 * Created:   2018-05-12
 * Copyright: Maria Pomarañska, Wojciech Majkut, Karol Pogwizd ()
 * License:
 **************************************************************/

#ifndef GRAPHICSAPP_H
#define GRAPHICSAPP_H

#include <wx/app.h>

class GraphicsApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // GRAPHICSAPP_H
