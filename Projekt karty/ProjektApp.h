/***************************************************************
 * Name:      ProjektApp.h
 * Purpose:   Defines Application Class
 * Author:    Mateusz Wrzosek ()
 * Created:   2023-12-13
 * Copyright: Mateusz Wrzosek ()
 * License:
 **************************************************************/

#ifndef PROJEKTAPP_H
#define PROJEKTAPP_H

#include <wx/app.h>

class ProjektApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // PROJEKTAPP_H
