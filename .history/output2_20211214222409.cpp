  6 #include <iostream>
  7 #include <iomanip>
  8 #include <fstream>
  9 #include <stdlib.h>
 10 #include <unistd.h>
 11 #include <time.h>
 12 #include "ansi.h"
 13
 14 using namespace std;
 15
 16 #define GRID_WIDTH 80
 17 #define GRID_HEIGHT 24
 18 #define DELAY 500000
 19
 20 void initGrid(bool grid[][GRID_WIDTH]);
 21 void initGrid(const char* fileName, bool [][GRID_WIDTH]);
 22 void renderGrid(bool [][GRID_WIDTH]);
 23 void nextGeneration(bool cur[][GRID_WIDTH], bool next[][GRID_WIDTH]);
 24
 25 int main(int argc, char **argv)
 26 {
 27   bool grid1[GRID_HEIGHT][GRID_WIDTH];
 28   bool grid2[GRID_HEIGHT][GRID_WIDTH];
 29   int generation = 1;
 30
 31   //initialize the grid
 32   if(argc==2)
 33   {
 34      initGrid(argv[1], grid1);
 35   }
 36   else
 37   {
 38      initGrid(grid1);
 39   }
 40  
 41   //run the generations, until the user presses ctrl+c
 42   while(true)
 43   {
 44     //show the appropriate grid, and generate the next population
 45     if(generation++ % 2)
 46     {
 47       //odd numbered generation
 48       renderGrid(grid1);
 49       nextGeneration(grid1, grid2);
 50     }
 51     else
 52     {
 53       //even numbered generation
 54       renderGrid(grid2);
 55       nextGeneration(grid2, grid1);
 56     }
 57
 58     //wait awhile before doing it again
 59     usleep(DELAY);
 60   }
 61
 62   return 0;
 63 }
 64
 65 //initialize the grid with random cells
 66 void initGrid(bool grid[][GRID_WIDTH])
 67 {
 68   //get the random number seeded with our present time
 69   srand(time(0));
 70
 71   //loop through each row
 72   for(int y=0; y < GRID_HEIGHT; y++)
 73   {
 74     //loop through each column
 75     for(int x=0; x < GRID_WIDTH; x++)
 76     {
 77       //1/3 of the cells are alive
 78       grid[y][x] = (rand() % 3) == 1;
 79     }
 80   }
 81 }
 82
 83 //initialize the grid from a file
 84 void initGrid(const char* fileName, bool grid[][GRID_WIDTH])
 85 {
 86   ifstream file;
 87   char c;
 88
 89   file.open(fileName);
 90
   //we are just going to assume that the file is valid
   //this is bad but in the interest of time, its okay
   for(int y=0; y < GRID_HEIGHT; y++)
   {
     for(int x=0; x < GRID_WIDTH; x++)
     {
       c=file.get();

       if(c=='\n')
       {
         c=file.get();
       }

       grid[y][x]= c =='*';
     }
   }

   file.close();
 }

 //render the grid
 void renderGrid(bool grid[][GRID_WIDTH])
 {
   //loop through the grid, rendering as we go
   for(int y=0; y < GRID_HEIGHT; y++)
   {
     for(int x=0; x < GRID_WIDTH; x++)
     {
       //go to the position
       cout << cursorPosition(x+1, y+1);

       //print the ' ' or '*'
       cout << (grid[y][x] ? '*' : ' ');
     }
   }
 }

 //create the next generation. The cur grid generates the next grid
 void nextGeneration(bool cur[][GRID_WIDTH], bool next[][GRID_WIDTH])
 {

   int count;


   for(int y=0; y < GRID_HEIGHT; y++)
   {
     for(int x=0; x < GRID_WIDTH; x++)
     {
       count = 0;

       //checks grid for asteriks
       if((cur[y - 1][x]) == '*')
       {
         count = count + 1;
       }
       else if((cur[y + 1][x]) == '*')
       {
         count = count + 1;
       }
       else if((cur[y - 1][x - 1]) == '*')
       {
         count = count + 1;
       }
       else if((cur[y + 1][x + 1]) == '*')
       {
         count = count + 1;
       }
       else if((cur[y][x - 1]) == '*')
       {
         count = count + 1;
       }
       else if((cur[y][x + 1]) == '*')
       {
         count = count + 1;
       }
       else if((cur[y - 1][x + 1]) == '*')
       {
         count = count + 1;
       }
       else if((cur[y + 1][x - 1]) == '*')
       {
         count = count + 1;
       }

       //less than 2 living neighbors - cell dies: starvation
       if((cur[y][x]) == '*' && (count < 2))
       {
         next[y][x] = ' ';
         cout << "h" << "\n";
       }
       //more than 3 living neighbors - cell dies: overcrowding
       else if((cur[y][x]) == '*' && (count > 3))
       {
         next[y][x] = ' ';
         cout << "i" << "\n";
       }
       //2 or 3 living neighbors - cell stays alive: stability
       else if((cur[y][x]) == '*' && count == 2 || count == 3)
       {
         next[y][x] = '*';
         cout << "j" << "\n";
       }
       //dead cell with exactly 3 neighbors - cell is reborn: reproduction
       else if((cur[y][x]) == ' ' && count == 3)
       {
         next[y][x] = '*';
         cout << "j" << "\n";
       }

     }
   }
 }