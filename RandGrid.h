#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

class RandGrid
{
  public:
    RandGrid(int rowDim, int colDim, double randProb);
    ~RandGrid();

    char** getCurrentGrid();
    char** getNextGrid();


    int rowDimension;
    int columnDimension;
    double randProbability;
  private:
    char **myCurrentGrid;
    char **myNextGrid;

  //  char updateGrid();
  //  char printGrid();



};
