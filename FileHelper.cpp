#include "FileHelper.h"
#include <fstream>

using namespace std;

FileHelper::FileHelper(string fileName)
{
  inputFile = fileName;

}

void FileHelper::setGrid()
{
  string line;
  int lineCount = 0;

  inFile.open(inputFile);

  if(!inFile)
  {
    cout << "unable to open file: " << inputFile;
    exit(1);
  }

  while (inFile >> line)
  {
      if(lineCount == 0)
      {
        rowDimension = stoi(line); //????????????????????????????
        ++lineCount;
      }
      else
      {
        columnDimension = stoi(line);//???????????????????
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
