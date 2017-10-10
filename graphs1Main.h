/***************************************************************
 * Name:      graphs1Main.h
 * Purpose:   Defines Application Frame
 * Author:    Shadoba, Marchewa, Michalik, Bob ()
 * Created:   2017-04-17
 * Copyright: Shadoba, Marchewa, Michalik, Bob ()
 * License:
 **************************************************************/

#ifndef GRAPHS1MAIN_H
#define GRAPHS1MAIN_H

#include "graphs.h"

//(*Headers(graphs1Dialog)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/statline.h>
#include <wx/panel.h>
#include <wx/filedlg.h>
#include <wx/choice.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class graphs1Dialog: public wxDialog
{
    public:

        graphs1Dialog(wxWindow* parent,wxWindowID id = -1);
        virtual ~graphs1Dialog();

    private:

        //(*Handlers(graphs1Dialog)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnTextCtrl2Text(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        void OnPanel1Paint(wxPaintEvent& event);
        void OnTextCtrl2Text1(wxCommandEvent& event);
        void OnTextCtrl1Text(wxCommandEvent& event);
        void OnButton1Click1(wxCommandEvent& event);
        //*)

        //(*Identifiers(graphs1Dialog)
        static const long ID_BUTTON1;
        static const long ID_STATICLINE1;
        static const long ID_STATICTEXT2;
        static const long ID_STATICTEXT3;
        static const long ID_TEXTCTRL2;
        static const long ID_STATICTEXT4;
        static const long ID_TEXTCTRL1;
        static const long ID_BUTTON2;
        static const long ID_STATICLINE2;
        static const long ID_STATICTEXT1;
        static const long ID_CHOICE1;
        static const long ID_BUTTON3;
        static const long ID_PANEL1;
        //*)

        //(*Declarations(graphs1Dialog)
        wxFileDialog* FileDialogLoad;
        wxButton* ButtonRandomGraph;
        wxStaticText* StaticText2;
        wxButton* ButtonLoadFile;
        wxFileDialog* FileDialogSave;
        wxButton* Button1;
        wxPanel* Panel1;
        wxStaticText* StaticText3;
        wxStaticLine* StaticLine2;
        wxStaticText* StaticText5;
        wxStaticLine* StaticLine1;
        wxTextCtrl* TextCtrl2;
        wxBoxSizer* BoxSizer1;
        wxTextCtrl* TextCtrl1;
        wxStaticText* StaticText4;
        wxChoice* Choice1;
        //*)
        void Paint();
        bool LoadedOrNot;
        int PeakCount=0;
        double EdgeCount=0;
        wxString type;
        AdjacencyMatrix AM;
        //AdjacencyList AL;
        //IncidanceMatrix IM;
        DECLARE_EVENT_TABLE()
};

#endif // GRAPHS1MAIN_H
