#include <iostream>
#include <utility>
#include "CellularAutomata.h"
#include "myutils.h"

// Getter function to retreive the vector 
std::vector<std::vector<int>> CellularAutomata::get_data()
{
    std::vector<std::vector<int>> return_data;
    return_data.resize(_rows);
    for (int i = 0; i < _rows; i++)
    {
        for (int j = 0; j < _columns; j++)
        {
            return_data[i].push_back(_data[i][j]);
        }
    }
    return return_data;
}

// Gives information on the stats of the states in the Cellular Automata.
void CellularAutomata::get_stats()
{
    if (_legend.empty() == false)
    {
        for(const auto &it : _legend)
        {   
            int counter = 0;
            for (int i = 0; i < _rows; i++)
            {
                for (int j = 0; j < _columns; j++)
                {
                    if (_data[i][j] == it.second)
                    {
                        counter++;
                    }
                }
            }
            std::cout << "The state: " << it.first << " occupied " << counter << " cells" << std::endl;
        }
    }
    else
    {
        for(const auto &it2 : _legend_density)
        {   
            int counter2 = 0;
            for (int i = 0; i < _rows; i++)
            {
                for (int j = 0; j < _columns; j++)
                {
                    if (_data[i][j] == it2.second.first)
                    {
                        counter2++;
                    }
                }
            }
            std::cout << "The state: " << it2.first << " occupied " << counter2 << " cells" << std::endl;
        }
    }
}