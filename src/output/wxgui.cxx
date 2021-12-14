#include "../../include/wxgui.h"
#include "../../include/CellularAutomata.h"
#include <map>
#include <iostream>
#include <vector>

wxIMPLEMENT_APP(cApp);

cMain::cMain(int rows, int columns) : wxFrame(nullptr, wxID_ANY, "Cellular Automata", wxPoint(30, 30), wxSize(1700, 1000))
{
    // Sets up the grid
    grid = new wxGrid( this, -1, wxPoint( 0, 0 ));

    // Sets up Colour database which will be used to convert wxString colours to wxColour
    colour = new wxColourDatabase();

    // Then we call CreateGrid to set the dimensions of the grid
    // (10 rows and 10 columns)
    grid->CreateGrid(rows, columns, wxGrid::wxGridSelectNone);

    // Prevents any editing from the user input
    grid->EnableEditing(false);
    
    // Makes the header labels disappear
    grid->SetRowLabelSize(0);
    grid->SetColLabelSize(0);

    // Sets the grind line between cells to black
    grid->SetGridLineColour	(*wxBLACK);

    // Prevent users to resizing the cells
    grid->DisableDragRowSize();
    grid->DisableDragColSize();

    // Setting size for the row and columns
    grid->SetDefaultColSize	(50);
    grid->SetDefaultRowSize	(50);

    // Set up grid colours based on Cellular automata states.
    std::vector<std::vector<int>> test = {{1, 1, 1}, {1, 0, 1}, {0, 1, 2}};
    std::map<int, std::string> test_map{{0, "White"}, {1, "Green"}, {2, "Red"}, {3, "Brown"}};

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            // Get string for color at that cell
            std::string color = test_map[test[i][j]];
            
            // Now convert the string to the wxString
            mystring = wxString(color);
            
            // Colour each cell in the grid with the colour associated with it
            // colour->find(mystring) is used to look up the wxColour associated with the name
            grid->SetCellBackgroundColour(i, j, colour->Find(mystring));
        }
    }
}

bool cApp::OnInit()
{   
    m_frame1 = new cMain(3, 3);
    m_frame1->Show();
    return true;
}