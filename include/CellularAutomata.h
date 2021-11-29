#include <iostream>
#include <vector>
#include <map>

class CellularAutomata
{
    private:
        // Holds the dimensions of the Cellular Automata.
        int _size;
        // Holds the data for the Cellular Automata.
        std::vector<int> _data;
        // Holds the legend information for the Cellular Automata.
        std::map<std::string, int> _legend;
        int _rows;
        int _columns;
    public:
        // Constructor for the class, calls the initialization to set up the Cellular Automata.
        CellularAutomata(int rows, int columns, std::map<std::string, int> legend, std::vector<int> data);
        // Another constructor for the class, sets up the vector using a range of states and an increment value.
        CellularAutomata(int rows, int columns, std::map<std::string, int> legend);
        void Initialize();
        void vn_neighborhood(int row, int column);
        void moore_neighborhood(int row, int column); 
        void print();
};
