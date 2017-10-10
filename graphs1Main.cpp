/***************************************************************
 * Name:      graphs1Main.cpp
 * Purpose:   Code for Application Frame
 * Author:    Shadoba, Marchewa, Michalik, Bob ()
 * Created:   2017-04-17
 * Copyright: Shadoba, Marchewa, Michalik, Bob ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "graphs1Main.h"
#include <wx/msgdlg.h>
#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "graphs.h"
#include <wx/filefn.h>

//(*InternalHeaders(graphs1Dialog)
#include <wx/intl.h>
#include <wx/string.h>
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

//(*IdInit(graphs1Dialog)
const long graphs1Dialog::ID_BUTTON1 = wxNewId();
const long graphs1Dialog::ID_STATICLINE1 = wxNewId();
const long graphs1Dialog::ID_STATICTEXT2 = wxNewId();
const long graphs1Dialog::ID_STATICTEXT3 = wxNewId();
const long graphs1Dialog::ID_TEXTCTRL2 = wxNewId();
const long graphs1Dialog::ID_STATICTEXT4 = wxNewId();
const long graphs1Dialog::ID_TEXTCTRL1 = wxNewId();
const long graphs1Dialog::ID_BUTTON2 = wxNewId();
const long graphs1Dialog::ID_STATICLINE2 = wxNewId();
const long graphs1Dialog::ID_STATICTEXT1 = wxNewId();
const long graphs1Dialog::ID_CHOICE1 = wxNewId();
const long graphs1Dialog::ID_BUTTON3 = wxNewId();
const long graphs1Dialog::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(graphs1Dialog,wxDialog)
    //(*EventTable(graphs1Dialog)
    //*)
END_EVENT_TABLE()

graphs1Dialog::graphs1Dialog(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(graphs1Dialog)
    wxBoxSizer* BoxSizer4;
    wxBoxSizer* BoxSizer6;
    wxBoxSizer* BoxSizer5;
    wxBoxSizer* BoxSizer7;
    wxBoxSizer* BoxSizer8;
    wxStaticText* StaticText1;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer9;
    wxBoxSizer* BoxSizer3;

    Create(parent, wxID_ANY, _("wxWidgets app"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(1000,600));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    BoxSizer4 = new wxBoxSizer(wxVERTICAL);
    StaticText1 = new wxStaticText(this, wxID_ANY, _("Graph From File Generator"), wxDefaultPosition, wxDLG_UNIT(this,wxSize(84,16)), wxST_NO_AUTORESIZE|wxALIGN_CENTRE, _T("wxID_ANY"));
    BoxSizer4->Add(StaticText1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ButtonLoadFile = new wxButton(this, ID_BUTTON1, _("Load"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer4->Add(ButtonLoadFile, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);
    StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxDefaultPosition, wxSize(300,3), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    BoxSizer4->Add(StaticLine1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(BoxSizer4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer5 = new wxBoxSizer(wxVERTICAL);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Random Graph Generator"), wxDefaultPosition, wxSize(124,22), 0, _T("ID_STATICTEXT2"));
    StaticText2->SetMinSize(wxSize(-1,-1));
    StaticText2->SetMaxSize(wxSize(-1,-1));
    BoxSizer5->Add(StaticText2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer8 = new wxBoxSizer(wxVERTICAL);
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Number of Vertices"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    BoxSizer8->Add(StaticText3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, _("0"), wxDefaultPosition, wxSize(100,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    TextCtrl2->SetMinSize(wxSize(-1,-1));
    TextCtrl2->SetMaxSize(wxSize(-1,-1));
    BoxSizer8->Add(TextCtrl2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer6->Add(BoxSizer8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer9 = new wxBoxSizer(wxVERTICAL);
    StaticText5 = new wxStaticText(this, ID_STATICTEXT4, _("p/l"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    BoxSizer9->Add(StaticText5, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, _("0"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    TextCtrl1->SetMinSize(wxSize(-1,-1));
    TextCtrl1->SetMaxSize(wxSize(-1,-1));
    BoxSizer9->Add(TextCtrl1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer6->Add(BoxSizer9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer5->Add(BoxSizer6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ButtonRandomGraph = new wxButton(this, ID_BUTTON2, _("Generate"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer5->Add(ButtonRandomGraph, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticLine2 = new wxStaticLine(this, ID_STATICLINE2, wxDefaultPosition, wxSize(300,3), wxLI_HORIZONTAL, _T("ID_STATICLINE2"));
    BoxSizer5->Add(StaticLine2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(BoxSizer5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxFIXED_MINSIZE, 5);
    BoxSizer7 = new wxBoxSizer(wxVERTICAL);
    StaticText4 = new wxStaticText(this, ID_STATICTEXT1, _("Save as"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    BoxSizer7->Add(StaticText4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Choice1 = new wxChoice(this, ID_CHOICE1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
    Choice1->Append(_("Adjacency Matrix"));
    Choice1->Append(_("Adjacency List"));
    Choice1->Append(_("Incidance Matrix"));
    BoxSizer7->Add(Choice1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button1 = new wxButton(this, ID_BUTTON3, _("Convert"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    BoxSizer7->Add(Button1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);
    BoxSizer2->Add(BoxSizer7, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_TOP|wxSHAPED, wxDLG_UNIT(this,wxSize(5,0)).GetWidth());
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxSize(600,600), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer3->Add(Panel1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer3, 2, wxALL|wxALIGN_TOP, 5);
    SetSizer(BoxSizer1);
    FileDialogLoad = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, wxFileSelectorDefaultWildcardStr, wxFD_OPEN, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
    FileDialogSave = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, wxFileSelectorDefaultWildcardStr, wxFD_SAVE|wxFD_OVERWRITE_PROMPT, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
    SetSizer(BoxSizer1);
    Layout();

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&graphs1Dialog::OnButton1Click);
    Connect(ID_TEXTCTRL2,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&graphs1Dialog::OnTextCtrl2Text1);
    Connect(ID_TEXTCTRL2,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&graphs1Dialog::OnTextCtrl2Text);
    Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&graphs1Dialog::OnTextCtrl1Text);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&graphs1Dialog::OnButton2Click);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&graphs1Dialog::OnButton1Click1);
    //*)
    FileDialogLoad->SetWildcard("Adjacency Matrix (*.AM)|*.AM|Incidance Matrix (*.IM)|*.IM|Adjacency List (*.AL)|*.AL");
    FileDialogSave->SetWildcard("Adjacency Matrix (*.AM)|*.AM|Incidance Matrix (*.IM)|*.IM|Adjacency List (*.AL)|*.AL");
}

graphs1Dialog::~graphs1Dialog()
{
    //(*
       Destroy();
    //*)
}

void graphs1Dialog::OnQuit(wxCommandEvent& event)
{
    Close();
}

void graphs1Dialog::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to graphs"));
}

void graphs1Dialog::OnTextCtrl2Text(wxCommandEvent& event)
{
    if (TextCtrl2)
    {
        wxString tmp = TextCtrl2->GetValue();
        double tmp2;
        tmp.ToDouble(&tmp2);
        PeakCount=tmp2;
    }
}

bool Cmp(wxString A, wxString B)
{
    if(A.Find(B)!= wxNOT_FOUND) return 1; else return 0;
}

void graphs1Dialog::OnButton1Click(wxCommandEvent& event)
{
    LoadedOrNot=1;
    if (FileDialogLoad->ShowModal()==wxID_OK)
    {
        std::ifstream in(FileDialogLoad->GetPath().ToAscii());
        if(Cmp(FileDialogLoad->GetFilename(),wxString("AM")))
        {
            type=wxString("AM");
            std::vector<std::vector<int>> tmp;

            if (in.is_open())
            {
                AM = AdjacencyMatrix(in);
            }
        }
        if(Cmp(FileDialogLoad->GetFilename(),wxString("IM")))
        {
            type=wxString("IM");
            std::vector<std::vector<int>> tmp;
            std::ifstream in(FileDialogLoad->GetPath().ToAscii());

            if (in.is_open())
            {
                IncidanceMatrix IM = IncidanceMatrix(in);
                AdjacencyList AL = AdjacencyList(IM);
                AM = AdjacencyMatrix(AL);
            }
        }
        if(Cmp(FileDialogLoad->GetFilename(),wxString("AL")))
        {
            type=wxString("AL");
            std::vector<std::vector<int>> tmp;
            std::ifstream in(FileDialogLoad->GetPath().ToAscii());

            if (in.is_open())
            {
                AdjacencyList AL = AdjacencyList(in);
                AM = AdjacencyMatrix(AL);
            }
        }
        in.close();
    }
    Paint();
}

void graphs1Dialog::OnButton2Click(wxCommandEvent& event)
{
    if (PeakCount>0)
    {
        LoadedOrNot=0;
        Paint();
    }
}

void graphs1Dialog::Paint()
{
    wxClientDC dc(Panel1);
    dc.SetBackground(wxBrush(RGB(255,255,255)));
    dc.Clear();
    int w,h;

    Panel1->GetSize(&w,&h);
    int w1=w/2;
    int h1=h/2-50;

    dc.SetPen(*wxGREEN_PEN);
    if(!LoadedOrNot)
    {
        AM.Clear();
        AdjacencyMatrix::GenarateRandomGraph_N_L(AM,PeakCount,EdgeCount);
    }
    double x1,x2,y1,y2;
    double Angle = 6.283/(double)AM.getPeakCount();
    double r=w1-80;
    int i=0;
    std::vector<std::vector<int>>tmp = AM.getMatrix();

    for(i; i<AM.getPeakCount()-1; i++)
    {
        x1=w/2+r*cos(Angle*i);
        y1=h/2-r*sin(Angle*i);

        dc.DrawText(wxString::Format(wxT("%d"), i), w/2-5+1.08*r*cos(Angle*i), h/2-6-1.08*r*sin(Angle*i));
        for(int j = i+1; j<AM.getPeakCount(); j++)
        {
            if (tmp[i][j] !=0)
            {
                x2=w/2+r*cos(Angle*j);
                y2=h/2-r*sin(Angle*j);
                dc.DrawLine(x1,y1,x2,y2);
            }
        }
        dc.SetPen(wxPen(RGB(200, 50, 50)));
        dc.DrawCircle(x1,y1,4);
        dc.SetPen(*wxGREEN_PEN);

    }
    dc.DrawText(wxString::Format(wxT("%d"), i), w/2-5+1.08*r*cos(Angle*i), h/2-6-1.08*r*sin(Angle*i));
    dc.SetPen(wxPen(RGB(200, 50, 50)));
    dc.DrawCircle(w/2+r*cos(Angle*i),h/2-r*sin(Angle*i) ,4);
}

void graphs1Dialog::OnPanel1Paint(wxPaintEvent& event)
{
    Paint();
}

void graphs1Dialog::OnTextCtrl2Text1(wxCommandEvent& event)
{
    if (TextCtrl2)
    {
        wxString tmp = TextCtrl2->GetValue();
        double tmp2;
        tmp.ToDouble(&tmp2);
        PeakCount=tmp2;
    }
}

void graphs1Dialog::OnTextCtrl1Text(wxCommandEvent& event)
{
    if (TextCtrl1)
    {
        wxString tmp = TextCtrl1->GetValue();
        double tmp2;
        tmp.ToDouble(&tmp2);
        EdgeCount=tmp2;
    }
}

void graphs1Dialog::OnButton1Click1(wxCommandEvent& event)
{
        int Selection = Choice1->GetSelection();
        switch(Selection)
        {
            case 0 :
                {
                    FileDialogSave->SetWildcard("Adjacency Matrix (*.AM)|*.AM");
                    if (FileDialogSave->ShowModal()==wxID_OK)
                    {
                        std::ofstream out(FileDialogSave->GetPath().ToAscii());
                        std::vector<std::vector<int>> tmp = AM.getMatrix();
                        int peaktmp = AM.getPeakCount();
                        for(int i=0; i<peaktmp; i++)
                        {
                            for(int j=0; j<peaktmp; j++)
                            {
                                if (j!=(peaktmp-1))
                                out<<tmp[i][j]<<' ';
                                else
                                out<<tmp[i][j];
                            }
                            if(i!=(peaktmp-1))out<<'\n';
                        }
                    break;
                    }
                }
            case 1 :
                {
                    FileDialogSave->SetWildcard("Adjacency List (*.AL)|*.AL");
                    if (FileDialogSave->ShowModal()==wxID_OK)
                    {
                        std::ofstream out(FileDialogSave->GetPath().ToAscii());
                        IncidanceMatrix IM(AM);
                        AdjacencyList AL(IM);
                        std::vector<std::vector<int>> tmp = AL.getList();
                        int peaktmp = AL.getNodeCount();
                        for(int i=0; i<peaktmp; i++)
                        {
                            for(int j=0; j<tmp[i].size(); j++)
                            {
                                if (j!=(tmp[i].size()-1))
                                out<<tmp[i][j]<<' ';
                                else
                                out<<tmp[i][j];

                            }
                            if(i!=(peaktmp-1))out<<'\n';
                        }

                    }
                    break;
                }
            case 2 :
                {
                    FileDialogSave->SetWildcard("Incidance Matrix (*.IM)|*.IM");
                    if (FileDialogSave->ShowModal()==wxID_OK)
                    {
                        std::ofstream out(FileDialogSave->GetPath().ToAscii());
                        IncidanceMatrix IM(AM);
                        std::vector<std::vector<int>> tmp = IM.getMatrix();
                        int peaktmp = IM.getPeakCount();
                        int edgetmp = IM.getEdgeCount();
                        for(int i=0; i<peaktmp; i++)
                        {
                            for(int j=0; j<edgetmp; j++)
                            {
                                if (j!=(edgetmp-1))
                                out<<tmp[i][j]<<' ';
                                else
                                out<<tmp[i][j];

                            }
                            if(i!=(peaktmp-1))out<<'\n';
                        }
                        break;
                    }
                }
            }
}
