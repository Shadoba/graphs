/***************************************************************
 * Name:      graphs1App.cpp
 * Purpose:   Code for Application Class
 * Author:    Shadoba, Marchewa, Michalik, Bob ()
 * Created:   2017-04-17
 * Copyright: Shadoba, Marchewa, Michalik, Bob ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "graphs1App.h"

//(*AppHeaders
#include "graphs1Main.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(graphs1App);

bool graphs1App::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	graphs1Dialog Dlg(0);
    	SetTopWindow(&Dlg);
    	Dlg.ShowModal();
    	wxsOK = false;
    }
    //*)
    return wxsOK;

}
