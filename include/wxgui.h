#pragma once
// wxWidgets "Hello World" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
    #include <wx/grid.h>
    #include<wx/gdicmn.h>
    #include <wx/string.h>
#endif

class cMain : public wxFrame
{

private:
    wxGrid *grid;
    wxString mystring;
    wxColourDatabase *colour;
    
public:
    cMain(int rows, int columns);

};

class cApp : public wxApp
{    
    private:
        cMain* m_frame1 = nullptr;

    public:
        virtual bool OnInit();
};



