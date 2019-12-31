//We worked on the game of life project together. 
//We want to try the graphics.

// importing libraries 
#include <iostream>
#include <cstdlib>
#include <string>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::chrono;


// declaring constant variables 
const int row = 30;
const int column = 35;

//Declaring functions 
void copyGrid(bool gridOne[row][column]);
void determineState(bool gridOne[row][column]);
void setUpTheGrid(bool  gridOne[row][column]); 
void printGrid(bool gridOne[row][column]);

//Driver method 
int main(){
    bool gridOne[row][column] = {};
    int x,y,n;
    string nc;
    string start;
    string filename;

    setUpTheGrid(gridOne);
     
    while (true)
	    {
	        // Pauses for 2 second 
            this_thread::sleep_for(chrono::seconds(2));
            
            cout << "\n";
            //prints initial grid 
            printGrid(gridOne);
            determineState(gridOne);
        }
        
    return 0;
    
}


// Sets initial coordinates on alive cells 
void setUpTheGrid(bool gridOne[row][column]){
    gridOne[5][5] = true;
    gridOne[6][4] = true;
    gridOne[6][5] = true;
    gridOne[6][6] = true;
    gridOne[7][6] = true;
    gridOne[7][4] = true;
    gridOne[8][5] = true;
    gridOne[15][14] = true;


}

// Prints grid with 'L' in set coordinates
void printGrid(bool gridOne[row][column]){
    for(int a = 1; a < row; a++)
        {
        for(int b = 1; b < column; b++)
        {
            if(gridOne[a][b] == true)
            {
                cout << " L ";
            }
            else
            {
                cout << " * ";
            }
            if(b == column-1)
            {
                cout << endl;
            }
        }
    }
}

// Copies one grid into another 
void copyGrid (bool gridOne[row][column], bool gridTwo[row][column]){
    for(int a =0; a < row; a++)
    {   
        for(int b = 0; b < column; b++)
        {
                gridTwo[a][b] = gridOne[a][b];
        }
    }
}


// Checks neighbors and revive the cell or kills it 
void determineState(bool gridOne[row][column]){
    bool gridTwo[row][column] = {};
    
    //Copying grid 
    copyGrid(gridOne, gridTwo);
    

    // loop which will count alive nearby cells
    for(int a = 1; a < row; a++)
    {   
        for(int b = 1; b < column; b++)
        {
            int alive = 0; // variable to count alive nearby cells
            for(int c = -1; c < 2; c++)
            {
                for(int d = -1; d < 2; d++)
                {
                    if(!(c == 0 && d == 0))//checks outer for cells
                    {
                        if(gridTwo[a+c][b+d])
				        {
					        ++alive;
				        }
                    }
                }
            }
            // If has less than 2 alive neighbors then the cell dies
            if(alive < 2)
            {
                gridOne[a][b] = false;
            }
            // if has 3 alive neighbors then cell is alive
            else if(alive == 3)
            {
                gridOne[a][b] = true;
            }
            // If has more than 3 alive neighbors then the cell dies 
            else if(alive > 3)
            {
                gridOne[a][b] = false;
            }
        }
    }
}