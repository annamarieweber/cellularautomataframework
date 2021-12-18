/*
  UC Berkeley - MSSE Program
  Chem 279-B  Introduction to Software Engineering
  Fall 2021
  This file, CellularAutomata.h, contains an API to the Cellular Automata class.
  being used in Chem 274-B final project.
*/

#ifndef CELLULAR_AUTOMATA
#define CELLULAR_AUTOMATA
#include <iostream>
#include <vector>
#include <map>
#include <utility>

class CellularAutomata
{
    private:
        // Holds the total area of the Cellular Automata matrix.
        int _size;

        // Holds the data for the Cellular Automata as a vector of vectors.
        std::vector<std::vector<int>> _data;

        // Holds the legend information for the Cellular Automata. Where the string passed in is the name of the state, and the integer is the value for that state.
        std::map<std::string, int> _legend;

        // Holds the legend information of the Cellular Automata as well as densities for each state. Where the string is the name of the state, the pair contains the value for that state (integer) and density (float, from 0.0-1.0).
        std::map<std::string, std::pair<int, float> > _legend_density;

        // Holds the number of possible states a cell can be in
        int _num_states;
        
        // Number of rows in the cellular automata, or its height.
        int _rows;

        // Number of columns in the cellular automata, or its width.
        int _columns;

        // The name of the state which is a product of any rules (ex. a tree burns to become charred, so charred would be the product).
        std::string _product;

        // The name of the state which is reacting with others to change them (ex. fire burns a tree so it becomes charred, so fire would be the reactor).
        std::string _reactor;

        // A pair of integers which signify the starting position to place the reactor state.
        std::pair<int, int> _starting_position;
        
    public:
        /**
         * @brief Construct a new Cellular Automata:: Cellular Automata object. Default Constructor.
         * 
         */
        CellularAutomata();
        
        /**
         * @brief Construct a new Cellular Automata:: Cellular Automata object. Constructor with data being passed in from the user.
         * 
         * @param rows Number of rows for the Cellular Automata matrix.
         * @param columns Number of columns for the Cellular Automata matrix.
         * @param legend A map including the name of the state as a string (key) and its corresponding integer value (value)
         * @param data A vector of vectors holding data for the Cellular Automata matrix.
         * @param product The name of the state which is a produced by rules acting on other states.
         * @param reactor The name of the state which acts on other states through rules.
         * @param starting_position The starting coordinates for the reactor state as a pair of integers.
         */
        CellularAutomata(int rows, int columns, std::map<std::string, int> legend, std::vector<std::vector<int> > data, std::string product, std::string reactor, std::pair<int, int> starting_position);

        /**
         * @brief Construct a new Cellular Automata:: Cellular Automata object. Constructor with no data where data is generated randomly.
         * 
         * @param rows Number of rows for the Cellular Automata matrix.
         * @param columns Number of columns for the Cellular Automata matrix.
         * @param legend A map including the name of the state as a string (key) and its corresponding integer value (value)
         * @param product The name of the state which is a produced by rules acting on other states.
         * @param reactor The name of the state which acts on other states through rules.
         * @param starting_position The starting coordinates for the reactor state as a pair of integers. 
         */
        CellularAutomata(int rows, int columns, std::map<std::string, int> legend, std::string product, std::string reactor, std::pair<int, int> starting_position);

        /**
         * @brief Construct a new Cellular Automata:: Cellular Automata object. Constructor with no data, and data is generated using density values passed in via legend.
         * 
         * @param rows Number of rows for the Cellular Automata matrix.
         * @param columns Number of columns for the Cellular Automata matrix.
         * @param legend A map including the name of the state as a string (key) and its value being a pair of integer and float, corresponding to the states integer value and density.
         * @param product The name of the state which is a produced by rules acting on other states.
         * @param reactor The name of the state which acts on other states through rules.
         * @param starting_position The starting coordinates for the reactor state as a pair of integers. 
         */
        CellularAutomata(int rows, int columns, std::map<std::string, std::pair<int, float> > legend, std::string product, std::string reactor, std::pair<int, int> starting_position);
        
        /**
         * @brief Copy Constructor to create a new Cellular Automata:: Cellular Automata object.
         * 
         * @param ca Cellular Automata object.
         */
        CellularAutomata(const CellularAutomata& ca);

        /**
         * @brief Function to initialize cellular automata data randomly.
         * 
         */
        void Initialize_Rand();

        /**
         * @brief Function to initialize cellular automata data using density.
         * 
         */
        void Initialize_Density();

        /**
         * @brief Code to evaluate Von Neumaan neighborhood where r = 1 with periodic bounds.
         * 
         * @param row Index of the row of the value you want to evaluate the Von Neumaan neighborhood for.
         * @param column Index of the column of the value you want to evaluate the Von Neumaan neighborhood for.
         * @return std::vector<int>, a vector containing all the neighbors in the order of North, West, East, and South.
         */
        std::vector<int> vn_neighborhood(int row, int column);

        /**
         * @brief Code to evaluate Moore neighborhood where r = 1 with periodic bounds.
         * 
         * @param row Index of the row of the value you want to evaluate the Von Neumaan neighborhood for.
         * @param column Index of the column of the value you want to evaluate the Von Neumaan neighborhood for.
         * @return std::vector<int>, a vector containing all the neighbors in the order of North West, North, North East, West, East, South West, South, South East.
         */
        std::vector<int> moore_neighborhood(int row, int column); 

        /**
         * @brief Update the value in the cell at x,y with the value n
         * 
         * @param x the x position of the cell
         * @param y the y position of the cell
         * @param n the value change the cell to
         */
        void update_cell(int x, int y, int n);

        /**
         * @brief gets the value of the cell at x, y
         * 
         * @param x the x position of the cell
         * @param y the y position of the cell
         * @return int the value of the cell
         */
        int get_cell(int x, int y);

        /**
         * @brief Get the number of rows in the CA
         * 
         * @return int number of rows
         */
        int get_rows();

        /**
         * @brief Get the number of columns in the CA
         * 
         * @return int number of columns
         */
        int get_columns();

        /**
         * @brief Get the total number of cells in the CA
         * 
         * @return int number of cells
         */
        int get_size();

        /**
         * @brief Get the number of possible states for a cell in the CA
         * 
         * @return int number of possible states
         */
        int get_num_states();

        /**
         * @brief Getter function to retreive the vector with Cellular Automata Data.
         * 
         * @return std::vector<std::vector<int>> 
         */
        std::vector<std::vector<int>> get_data();

        /**
         * @brief Gives information on the statistics of the states in the Cellular Automata.
         * 
         */
        void get_stats();

        /**
         * @brief Prints the formatted matrix out to the terminal using std::cout. Each row is printed with the first element of the Cellular Automata following an opening square bracket and all elements being seperated by commas. The last element of the Cellular Automata is also followed by a closing square bracket.
         * 
         */
        void print();
};
#endif
