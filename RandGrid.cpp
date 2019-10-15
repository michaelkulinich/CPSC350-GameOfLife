#include "RandGrid.h"
#include <cmath>
#include <cstdlib>
using namespace std;



RandGrid::RandGrid(int rowDim, int colDim, double popDensity)
{
  int rowDimension = rowDim;
  int columnDimension = colDim;
  double randProbability;

// Declaring the current grid
  myCurrentGrid = new char*[rowDimension+2];
  for(int i = 0; i < rowDimension+2; ++i)
      myCurrentGrid[i] = new char[columnDimension+2];

// Declaring the next grid
  myNextGrid = new char*[rowDimension+2];
  for(int i = 0; i < rowDimension+2; ++i)
      myNextGrid[i] = new char[columnDimension+2];


// Filling up the rows and columns of current grid and next grid
// based off of the random probability and comparing it to the population
// density that was inputted by the user
  for (int i = 0; i<rowDimension+2; ++i)
  {
    for (int j = 0; j<columnDimension+2; ++j)
    {
// Initially, each grid is first filled fully with -'s
      randProbability = (RAND_MAX - rand())/ static_cast<double>(RAND_MAX);
      if(i == 0){
        myCurrentGrid[i][j] = '-';
        myNextGrid[i][j] = '-';
      }
      else if(j == 0){
        myCurrentGrid[i][j] = '-';
        myNextGrid[i][j] = '-';
      }
      else if (j == columnDimension + 1){
        myCurrentGrid[i][j] = '-';
        myNextGrid[i][j] = '-';
      }
      else if( i == rowDimension + 1){
        myCurrentGrid[i][j] = '-';
        myNextGrid[i][j] = '-';
      }

// Fills grid with X's based on the comparison between a random probability
// and the population density desired by the user
      else if (randProbability < popDensity)
      {
        myCurrentGrid[i][j] = 'X';
        myNextGrid[i][j] = 'X';
      }

      else if(randProbability > popDensity)
      {
        myCurrentGrid[i][j] = '-';
        myNextGrid[i][j] = '-';
      }

    }
  }
}

char** RandGrid::getCurrentGrid()
{
  return myCurrentGrid;
}

char** RandGrid::getNextGrid()
{
  return myNextGrid;
}
