#include <iostream>
#include <cmath>
#include <cstdlib>
#include "FileHelper.h"
#include "RandGrid.h"
#include "Simulation.h"



using namespace std;

int main(int argc, char const *argv[]) {


  cout << "------------- Welcome to the Game of Life -------------" << endl;
  cout << "Designed in the 1970s: A Simulation of Bacterial Life Cycle" << endl;
  cout << "\n" << endl;
  cout << "\n" << endl;
  cout << "Press a 'I' to import a map file or 'R' random assignment: ";
  char progStartChoice;
  cin >> progStartChoice;
  char **currentGrid;
  char **nextGrid;
  string fileName;
  int rowDimension;
  int columnDimension;


  if (progStartChoice == 'I')
  {
    cout << "You chose " << progStartChoice << endl;
    cout << "Insert File name: " << endl;
    cin >> fileName;

    FileHelper helper(fileName);
    helper.setGrid();  //take out the print statements
    currentGrid = helper.getCurrentGrid();
    nextGrid = helper.getNextGrid();

    rowDimension = helper.getRow();
    columnDimension = helper.getColumn();

    Simulation sim(currentGrid, nextGrid, rowDimension, columnDimension);
    sim.run();

    cout << "Importing map file..." << endl;
  }

  else if (progStartChoice == 'R')
  {
    cout << "You chose " << progStartChoice << endl;
    cout << "Enter Row Dimension" << endl;
    cin >> rowDimension;
    cout << "Enter Column Dimension" << endl;
    cin >> columnDimension;
    cout << "Enter initial population density decimal (0,1]";
    double popDensity;
    cin >> popDensity;
    RandGrid grid(rowDimension, columnDimension, popDensity);
    currentGrid = grid.getCurrentGrid();                         //is this sketch?? memory leak
    nextGrid = grid.getNextGrid();
    Simulation sim(currentGrid, nextGrid, rowDimension, columnDimension);
    sim.run();


  }



//  int mode;
  //cout << "What kind of gamemode will you want"      ask in run







  return 0;
}
