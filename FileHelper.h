/*Michael Kulinich
2328386
kulinich@chapman.edu
Matthew Nwerem
2277158
nwere100@mail.chapman.edu


FileHelper.h
This is a header file for FileHelper Class that
reads from the user input file of the initial generation
and creates the 2d arrays that will be used in simulation
*/

#include <iostream>
#include <fstream>
using namespace std;

class FileHelper
{
  public:

    //constructer
    //string parameter that is set to inputFile
    FileHelper(string fileName);

    //destructor
    //deletes myCurrentGrid and myNextGrid
    ~FileHelper();

    //opens the inputFile using ifstream and
    //reads through line by line to create
    //the initial grid that will be used for the simulation
    //it initializes myNextGrid and myCurrentGrid
    void setGrid();

    //returns the myCurrentGrid
    char** getCurrentGrid();

    //return the myNextGrid
    char** getNextGrid();

    //returns the rowDimension of the grid
    int getRow();

    //returns the columnDimension of the grid
    int getColumn();
    ifstream inFile;
    string inputFile;

    //the number of rows in the grid
    int rowDimension;

    //the number of columns in the grid
    int columnDimension;

  private:
    //2d array
    char **myCurrentGrid;

    //2d array that is a copy of myCurrentGrid
    char **myNextGrid;

};
