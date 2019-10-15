/*Michael Kulinich
2328386
kulinich@chapman.edu
Matthew Nwerem
2277158
nwere100@mail.chapman.edu


FileHelper.cpp
This is cpp file for FileHelper class
*/

#include "FileHelper.h"


using namespace std;

FileHelper::FileHelper(string fileName)
{
  inputFile = fileName;

}

void FileHelper::setGrid()
{
  string line; //used to read line by line from file
  int lineCount = 0; //find what line is being read in the file
  inFile.open(inputFile);

  if(!inFile)
  {
    cout << "unable to open file: " << inputFile << endl;
    exit(1);
  }

  while (inFile >> line)
  {
      if(lineCount == 0)
      {
        rowDimension = stoi(line);
        ++lineCount;
      }
      else
      {
        columnDimension = stoi(line);
        lineCount = 0;
        break;
      }

  }

  myCurrentGrid = new char*[rowDimension+2];
  for(int i = 0; i < rowDimension+2; ++i){
      myCurrentGrid[i] = new char[columnDimension+2];
    }

  myNextGrid = new char*[rowDimension+2];
  for(int i = 0; i < rowDimension+2; ++i){
      myNextGrid[i] = new char[columnDimension+2];
    }
    while (inFile >> line)
    {
      for (int i = 0; i<line.size(); ++i)
      {
        myCurrentGrid[lineCount+1][i+1] = line[i];
        myNextGrid[lineCount+1][i+1] = line[i];

      }
      ++lineCount;

    }
inFile.close();

}

char** FileHelper::getCurrentGrid()
{
  return myCurrentGrid;
}

char** FileHelper::getNextGrid()
{
  return myNextGrid;
}

int FileHelper::getColumn(){
  return columnDimension;
}

int FileHelper::getRow(){
  return rowDimension;
}

FileHelper::~FileHelper(){
  // for(int i = 0; i < rowDimension + 2; ++i) {
  //     delete [] myCurrentGrid[i];
  //     delete [] myNextGrid[i];
  //
  // }
  // delete [] myCurrentGrid;
  // delete [] myNextGrid;
}
