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
  char progStartChoice;
  char **currentGrid;
  char **nextGrid;
  string fileName;
  int rowDimension;
  int columnDimension;
  double popDensity;
  bool valid; //used for error checking

  while(true)
  {
    cout << "Press a 'I' to import a map file or 'R' random assignment: ";
    cin >> progStartChoice;

    //If the user wants to import file
    if (toupper(progStartChoice) == 'I')
    {
      cout << "You chose " << progStartChoice << endl;
      cout << "Insert File name: " << endl;
      cin >> fileName;
      FileHelper helper(fileName);
      helper.setGrid();  //take out the print statements
      cout << "Importing map file..." << endl;
      currentGrid = helper.getCurrentGrid();
      nextGrid = helper.getNextGrid();
      rowDimension = helper.getRow();
      columnDimension = helper.getColumn();
      Simulation sim(currentGrid, nextGrid, rowDimension, columnDimension);
      sim.run();
      break;
    }

    else if (toupper(progStartChoice) == 'R')
    {
      cout << "You chose " << progStartChoice << endl;
  	  valid = false;
  	  while (!valid)
  	  {
  		    valid = true; //Assume the cin will be an integer.
  		    cout << "Enter Row Dimension" << endl;
  		    cin >> rowDimension;

  		    if(cin.fail()) //cin.fail() checks to see if the value in the cin
  					//stream is the correct type, if not it returns true,
  					//false otherwise.
  	    	{
            cin.clear(); //This corrects the stream.
  			    cin.ignore(); //This skips the left over stream data.
            cout << endl;
  			    cout << "Please enter an Integer only." << endl;
  			    valid = false; //The cin was not an integer so try again.
  		}
  	}
      valid = false;
      while (!valid)
      {
          valid = true;
          cout << "Enter Column Dimension" << endl;
          cin >> columnDimension;

          if(cin.fail())
          {
            cin.clear();
            cin.ignore();
            cout << endl;
            cout << "Please enter an Integer only." << endl;
            valid = false;
      }
    }
      valid = false;
      while (!valid)
      {
          valid = true;
          cout << "Enter initial population density decimal (0,1]";
          cin >> popDensity;
          if(cin.fail())
          {
            cin.clear();
            cin.ignore();
            cout << "Please enter a double only." << endl;
            valid = false;
          }
      }

      RandGrid grid(rowDimension, columnDimension, popDensity);
      currentGrid = grid.getCurrentGrid();
      nextGrid = grid.getNextGrid();
      Simulation sim(currentGrid, nextGrid, rowDimension, columnDimension);
      sim.run();
      break;


    }
    else{
      cout << "Incorrect input, try again" << endl;
    }
  }
  return 0;
}
