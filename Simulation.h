#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>

using namespace std;

/*Michael Kulinich
2328386
kulinich@chapman.edu
Matthew Nwerem
2277158
nwere100@mail.chapman.edu


Simulation.h
This is header file for the Simulation class that will take in grids of
inputted dimenions and run the Game of Life. Different methods contained in
this class update the current and next game board, update the board depending
on the type of board desired and conduct the type of pause that the user wanted
*/


class Simulation
{
  public:
    Simulation(); // constructor
    Simulation(char **&grid1, char **&grid2, int rowDim, int colDim); //overload constructor
    ~Simulation();
    void run();//runs the simulation and calls the gamemode methods
               //when it is needed to update the board
    void update(); // will handle updating the grid for classic gamemode
    void doughnut();
    void mirror();
    void conductPause();
    int rowDimension;
    int columnDimension;
    ofstream outFile;
    ofstream userFile;
    int countCells;
    int differenceCounter;
    char briefPause;
    char enterPause;
    char outToFile;
    bool briefPauseBool;
    bool enterPauseBool;
    string userFileName;

  private:
    char **currentGrid;
    char **nextGrid;




};
