#include <iostream>
#include <vector>
#include <map>
#include <utility>


rnd_data = np.random.normal(_rows, 1, (500, 100, 100));

fig, ax = plt.subplots(figsize=(12,10))

def my_func(i):
    sns.heatmap(rnd_data[i])

anim = matplotlib.animation.FuncAnimation(fig=fig, func=my_func, frames=200, interval=500, blit=False)
plt.show()








class CellularAutomata
{
    private:
        // Holds the dimensions of the Cellular Automata.
        int _size;

        // Holds the data for the Cellular Automata as a vector of vectors.
        std::vector<std::vector<int> > _data;

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
        // Constructor for the class, requires all data for the Cellular Automata to be passed in.
        CellularAutomata(int rows, int columns, std::map<std::string, int> legend, std::vector<std::vector<int> > data, std::string product, std::string reactor, std::pair<int, int> starting_position);

        // Another constructor for the class, calls the initialization to set up the Cellular Automata randomly.
        CellularAutomata(int rows, int columns, std::map<std::string, int> legend, std::string product, std::string reactor, std::pair<int, int> starting_position);

        // Another constructor for the class, calls the initialization to set up the Cellular Automata using density values passed in.
        CellularAutomata(int rows, int columns, std::map<std::string, std::pair<int, float> > legend, std::string product, std::string reactor, std::pair<int, int> starting_position);

        // Intiatlize function to create a cellular automata randomly.
        void Initialize_Rand();

        // Intialize function to create a cellular automata using density values.
        void Initialize_Density();

        // Code to evaluate von neumaan neighborhood where r=1.
        std::vector<int> vn_neighborhood(int row, int column);

        // Code to evaluate moore neighborhood where r=1.
        std::vector<int> moore_neighborhood(int row, int column); 
        
        //code to get the appropriate neighborhood
        std::vector<int> get_neighborhood(int x, int y,int neighborhood_num);
        
        // Code to run Cellular Automata Simulation
        void run(int num_steps, int rule_num, int neighborhood_num);
        
        //logic for taking a single step of the CA simluation todo: document the funciton
        void step(int rule_num, int neighborhood_num);
        
        // code to apply transition rule using neighborhood data
        int transition_function(int x, int y, int rule_num, std::vector<int> neighborhood);

        // logic for the majority rule todo:  add additional function documentation
        int majority_rule(int x, int y, std::vector<int> neighborhood);
        
        // logic for the purity rule todo:  add additional function documentation
        int purity_rule(int x, int y, std::vector<int> neighborhood);

        // Function to print out the Cellular Automata.
        void print();
};
