/***************************************************************
 * Name:      ProjektApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Mateusz Wrzosek ()
 * Created:   2023-12-13
 * Copyright: Mateusz Wrzosek ()
 * License:
 **************************************************************/

#include "ProjektApp.h"

//(*AppHeaders
#include "ProjektMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(ProjektApp);

bool ProjektApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	ProjektDialog Dlg(0);
    	SetTopWindow(&Dlg);
    	Dlg.ShowModal();
    	wxsOK = false;
    }
    //*)
    return wxsOK;

}
