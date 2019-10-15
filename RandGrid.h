/*Michael Kulinich
2328386
kulinich@chapman.edu
Matthew Nwerem
2277158
nwere100@mail.chapman.edu


RandGrid.h
This is header file for the RandGrid class, a class that is used when the user
asks for a random grid to be created rather than an imported one.
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

class RandGrid
{
  public:
    RandGrid(int rowDim, int colDim, double randProb);
    //Deconstructor of RandGrid is not needed; the grid is deleted in Simulation

    char** getCurrentGrid();
    char** getNextGrid();

    int rowDimension;
    int columnDimension;
    double randProbability;

  private:
    char **myCurrentGrid;
    char **myNextGrid;
};
