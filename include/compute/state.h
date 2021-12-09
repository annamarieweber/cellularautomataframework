#include <iostream>

typedef unsigned long long ull;

class State{
    private:
        std::string state_str;
        std::string cellState(int index);
        
    public:
        State();
        State(ull state);
        State nextState();
        void transition_fn(int rule);
};