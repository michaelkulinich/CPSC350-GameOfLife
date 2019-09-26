#include <iostream>
#include <fstream>
using namespace std;

class FileHelper
{
  public:

    FileHelper(string fileName);
    ~FileHelper();

    void setGrid();
    ifstream inFile;
    string inputFile;
    int rowDimension;
    int columnDimension;
    char** getCurrentGrid();
    char** getNextGrid();
    int getRow();
    int getColumn();


  private:
    char **myCurrentGrid;
    char **myNextGrid; //do i need to make these private??

};
