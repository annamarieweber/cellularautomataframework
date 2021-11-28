#include <math.h>
#include <vector>

#include <stdio.h>
#include <limits.h>
#include <iostream>


 
typedef unsigned long long ull;
#define N  (10)
#define B(x) (1ULL << (x))

class State{


ull* state_encoding;
int size = 9;
int radius = 1;


    public: 
void transition_fn(int rule)
{
	int i;
    int j;
	ull st;


    

    for (i = N; i--;){
        st = state_encoding[i];
        for(j = N; j--;)putchar(st & B(j) ? '#' : '.');
        putchar('\n');
    }
 
	printf("Rule %d:\n", rule);

 
		for (int i = 0; i < N; i++){
            st = state_encoding[i];
            for(int j = 0; j < N; j++){
                //basically each one should have a 
                if (rule & B(7 & (st>>(i-1) | st<<(N+1-i))))
				state_encoding[j] |= B(i);
            }
        }

    


    for (i = N; i--;){
        st = state_encoding[i];
        for(j = N; j--;)putchar(st & B(j) ? '#' : '.');
        putchar('\n');
    }
        

}
 


/**
 * cellState
 * returns the next state of the call located at index i
 * 
 * @param i the index of the cell to calculate the state for
 * @returns the next state
 **/ 
// std::string State::cellState(int i){
//     std::string next_state;
//     //the radius of the neighborhood as the number of preceding elems
//     int r = (int)(pow(2,2*radius+1)*0.5);
//     if(i-r >= 0 && i+r < state_str.length()){
//         std::string cell_state_key = state_str.substr(i-r, i+r);
//         next_state = rules[cell_state_key];
//     }
//     else{
//         // todo: implement strategy for handling wrap around/ edges depending on rules being used
//         next_state = state_str.substr(i,i);
//     }

//     return next_state;
// }


    State(ull* start){
        state_encoding = start;
        std::cout << start << std::endl;
    }
};

int main(){

    ull state_thing[] = {B(N/2),B(0),B(N/2),B(N/2),B(N/2),B(N/2),B(N/2),B(N/2),B(N/2),B(N/2)};
    State s1 = State(state_thing);


	s1.transition_fn(2); // well, enjoy the fireworks

 
	return 0;

}

//can we scale by using each CA as a building block for larger CA?
/**
 * cell_position = (r,c)
 * cell_state_encoded into 8 b
 * 
 **/


/** where neighborhood has n elements that can be in m different states we can model the neighborhood using an n digit number in base m  such that the ith nieghbor neighborhood[i] = state(i)*m^(n-i) 
 * 
 * input: 
 * 
 * 
 * compute:
 * 
 *      the next state can be determined by taking a summation of all calls in the neighborhood and then checking.
 *      for an example the below neighborhood:
 * 
 *      013
 *      320
 *      011
 * 
 *      would be represented by 0133320011
 * `
 * 
 *      needs:
 *         - change of bases ability to model in different bases dependent on how many possible states a cell can have     
 * output: 
 *  use input params to determine how to map the n digit states to whatver they need to be for the output format
 *         - we could maybe just return hex codes then those can go directly into the output service so no furhter computation is needed.
 * 
 * 