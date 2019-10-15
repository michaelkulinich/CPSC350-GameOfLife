/*Michael Kulinich
2328386
kulinich@chapman.edu
Matthew Nwerem
2277158
nwere100@mail.chapman.edu

Simulation.cpp is the cpp file for Simulation Class
*/

#include "Simulation.h"
#include <stdio.h>
#include <stdlib.h>

using namespace std;
Simulation::Simulation()
{
  //default constructor
}
Simulation::Simulation(char **&grid1, char **&grid2, int rowDim, int colDim)
{
   currentGrid = grid1;
   nextGrid = grid2;
   rowDimension = rowDim;
   columnDimension = colDim;
}

void Simulation::run()
{
  int mode;
  int gen = 1;
  string anyKey; // used for exiting the program
  differenceCounter = 0; //if the generations are the same, program should end;
  countCells = 0;   //counts the number of X's around the cell

  cout << "What kind of gamemode will you like to run?" << endl;
  bool valid = false;
  while (!valid)
  {
      valid = true; //Assume the cin will be an integer.
      cout << "(type in the number)\n(1) Classic\n(2) Doughnut\n(3) Mirror\n" << endl;

      cin >> mode;

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
    if(mode < 1 || mode > 3){
      cout << "incorrect int input\n";
      exit(1);
    }


  cout << "Would you like a brief pause in between generations? (Y/N)" << endl;
  cin >> briefPause;

  if((toupper(briefPause) != 'Y') && (toupper(briefPause) != 'N')){
    cout << "incorrect input\n";
    exit(1);
  }
  //if the user wants a brief pause, briefPauseBool will be true
  if (toupper(briefPause) == 'Y')
  {
    briefPauseBool = true;
  }

  else
  {
    briefPauseBool = false;
  }

  //if the user doesn't want a brief pause, then we ask what they would like to do
  if(toupper(briefPause) != 'Y')
  {
    cout << "Would you like to press 'Enter' key to display generations? (Y/N)" << endl;
    cin >> enterPause;
    if(toupper(enterPause) != 'Y' && toupper(enterPause) != 'N'){
      cout << "incorrect input\n";
      exit(1);
    }

    if (toupper(enterPause) == 'Y')
    {
      enterPauseBool = true;
    }
    else
    {
      enterPauseBool = false;
    }

    //if the user doesn't want press enter, so ask if they want to print to file
    if(toupper(enterPause) != 'Y')
    {
      cout << "Would you like to press output everything to a file? (Y/N)" << endl;
      cin >> outToFile;
      if(toupper(outToFile) != 'Y' && toupper(outToFile) != 'N'){
        cout << "incorrect input\n";
        exit(1);
      }

      if (toupper(outToFile) == 'Y')
      {
        cout << "Enter the file name, no spaces: " << endl;
        cin >> userFileName;
        userFile.open(userFileName);
        cout << "printing to file\n";

      }
      else
      {
        cout << "You have no desire for anything\n";
        exit(1);
      }
    }
  }



//CLASSIC MODE
  if (mode == 1)
  {
    //prints to console
    if(outToFile != 'Y'){
      cout << 0 << endl;
      for(int i = 1; i < rowDimension+1; ++i)
        {
          for(int j = 1; j < columnDimension+1; ++j)
          {
              cout << currentGrid[i][j];
          }
        cout << endl;
      }
    }
    else {
      userFile << 0 << endl;
      for(int i = 1; i < rowDimension+1; ++i)
        {
          for(int j = 1; j < columnDimension+1; ++j)
          {
              userFile << currentGrid[i][j];
          }
        userFile << endl;
      }
    }
    while(gen < 2001)
    {
      if(gen == 2000){
        cout << "The generations have stabilized, exiting...\n";
        exit(1);
      }
      differenceCounter = 0; //set the counter to 0 before each update generation
    //create a method call check!!!!! make this less repetitive
      conductPause();
      update();
      if(differenceCounter == 0)
      {
        cout << "THE PROGRAM STOPS BECAUSE THE BOARD WILL NO LONGER CHANGE" << endl;
        cout << "Press any key then 'enter' to exit program" << endl;
        cin >> anyKey;
        cout << "Exiting..\n";
        break;
      }
      if(outToFile != 'Y'){
        cout << "generation " << gen << endl;
        for(int i = 1; i < rowDimension+1; ++i)
          {
            for(int j = 1; j < columnDimension+1; ++j)
            {
                cout << currentGrid[i][j];
            }
          cout << endl;
        }
      }
      else {
        userFile << "generation " << gen << endl;
        for(int i = 1; i < rowDimension+1; ++i)
          {
            for(int j = 1; j < columnDimension+1; ++j)
            {
                userFile << currentGrid[i][j];
            }
          userFile << endl;
        }
      }

    // //copy the next grid into the current grid, the boundary will always stay -
      for(int i = 0; i < rowDimension+2; ++i)
      {
        for(int j = 0; j < columnDimension+2; ++j)
        {
          currentGrid[i][j] = nextGrid[i][j];
        }
      }
      gen++;
    }
  }






  else if (mode == 2)
  {
    //code for doughnut

    //set the corner boundaries
    //the corner boundaries are equal to the actual board boundaries
    currentGrid[0][columnDimension+1] = currentGrid[rowDimension][1];
    currentGrid[0][0] = currentGrid[rowDimension][columnDimension];
    currentGrid[rowDimension+1][0] = currentGrid[1][columnDimension];
    currentGrid[rowDimension+1][columnDimension+1] = currentGrid[1][1];



      //set the boundary for row 0 and last
    for(int i = 1; i < columnDimension+1;++i)
    {
      currentGrid[0][i] = currentGrid[rowDimension][i];
      currentGrid[rowDimension+1][i] = currentGrid[1][i];
    }

    //set boudary for column
    for(int i = 1; i < rowDimension+1;++i)
    {
      currentGrid[i][0] = currentGrid[i][columnDimension];
      currentGrid[i][columnDimension+1] = currentGrid[i][1];
    }

    if(outToFile != 'Y'){
      cout << 0 << endl;
      for(int i = 1; i < rowDimension+1; ++i)
        {
          for(int j = 1; j < columnDimension+1; ++j)
          {
              cout << currentGrid[i][j];
          }
        cout << endl;
      }
    }
    else {
      userFile << 0 << endl;
      for(int i = 1; i < rowDimension+1; ++i)
        {
          for(int j = 1; j < columnDimension+1; ++j)
          {
              userFile << currentGrid[i][j];
          }
        userFile << endl;
      }
    }

    while(gen < 2001)
    {
      if(gen == 2000){
        cout << "The generations have stabilized, exiting...\n";
        exit(1);
      }
      differenceCounter = 0;
    //create a method call check!!!!! make this less repetitive
        conductPause();
        update();
      if(differenceCounter == 0)
      {
        cout << "THE PROGRAM STOPS BECAUSE THE BOARD WILL NO LONGER CHANGE" << endl;
        cout << "Press any key then 'enter' to exit program" << endl;
        cin >> anyKey;
        cout << "Exiting..\n";
        break;
      }

      if(outToFile != 'Y'){
        cout << "generation number " << gen << endl;
        for(int i = 1; i < rowDimension+1; ++i)
          {
            for(int j = 1; j < columnDimension+1; ++j)
            {
                cout << currentGrid[i][j];
            }
          cout << endl;
        }
      }
      else {
        userFile << "generation number " << gen << endl;
        for(int i = 1; i < rowDimension+1; ++i)
          {
            for(int j = 1; j < columnDimension+1; ++j)
            {
                userFile << currentGrid[i][j];
            }
          userFile << endl;
        }
      }

      for(int i = 0; i < rowDimension+2; ++i)
      {
        for(int j = 0; j < columnDimension+2; ++j)
        {
          currentGrid[i][j] = nextGrid[i][j];
        }
      }

      //set the corner boundaries
      currentGrid[0][columnDimension+1] = currentGrid[rowDimension][1];
      currentGrid[0][0] = currentGrid[rowDimension][columnDimension]; //  DOUBLE CHECK IF THE LOGIC HERE IS CURRECT. IF this is the right place to set boundaries
      currentGrid[rowDimension+1][0] = currentGrid[1][columnDimension];
      currentGrid[rowDimension+1][columnDimension+1] = currentGrid[1][1];

      gen++;
    }
  }
  else if(mode == 3)
  {
    //code for mirror
    currentGrid[0][columnDimension+1] = currentGrid[1][columnDimension];
    currentGrid[0][0] = currentGrid[1][1];
    currentGrid[rowDimension+1][0] = currentGrid[rowDimension][1];
    currentGrid[rowDimension+1][columnDimension+1] = currentGrid[rowDimension][columnDimension];

    //set boudary for column
    for(int i = 1; i < rowDimension+1;++i)
    {
      currentGrid[i][0] = currentGrid[i][1];
      currentGrid[i][columnDimension+1] = currentGrid[i][columnDimension];
    }
    for(int i = 1; i < columnDimension+1;++i)
    {
      currentGrid[0][i] = currentGrid[1][i];
      currentGrid[rowDimension+1][i] = currentGrid[rowDimension][i];
    }

    if(outToFile != 'Y'){
      cout << 0 << endl;
      for(int i = 1; i < rowDimension+1; ++i)
        {
          for(int j = 1; j < columnDimension+1; ++j)
          {
              cout << currentGrid[i][j];
          }
        cout << endl;
      }
    }
    else {
      userFile << 0 << endl;
      for(int i = 1; i < rowDimension+1; ++i)
        {
          for(int j = 1; j < columnDimension+1; ++j)
          {
              userFile << currentGrid[i][j];
          }
        userFile << endl;
      }
    }

    while(gen < 2001)
    {
      if(gen == 2000){
        cout << "The generations have stabilized, exiting...\n";
        exit(1);
      }
      differenceCounter = 0;// set counter to 0 before every generation update
        conductPause();
        update();
      if(differenceCounter == 0)
      {
        cout << "THE PROGRAM STOPS BECAUSE NO THE BOARD WILL NO LONGER CHANGE" << endl;
        cout << "Press any key, then 'enter' to exit program" << endl;
        cin >> anyKey;
        cout << "Exiting..\n";
        break;
      }


      if(outToFile != 'Y'){
        cout << "generation " << gen << endl;
        for(int i = 1; i < rowDimension+1; ++i)
          {
            for(int j = 1; j < columnDimension+1; ++j)
            {
                cout << currentGrid[i][j];
            }
          cout << endl;
        }
      }
      else {
        userFile << "generation " << gen << endl;
        for(int i = 1; i < rowDimension+1; ++i)
          {
            for(int j = 1; j < columnDimension+1; ++j)
            {
                userFile << currentGrid[i][j];
            }
          userFile << endl;
        }
      }

    // //copy the next grid into the current grid, the boundary will always stay -
      for(int i = 0; i < rowDimension+2; ++i)
      {
        for(int j = 0; j < columnDimension+2; ++j)
        {
          currentGrid[i][j] = nextGrid[i][j];
        }
      }

      //code for mirror
      currentGrid[0][columnDimension+1] = currentGrid[1][columnDimension];
      currentGrid[0][0] = currentGrid[1][1];
      currentGrid[rowDimension+1][0] = currentGrid[rowDimension][1];
      currentGrid[rowDimension+1][columnDimension+1] = currentGrid[rowDimension][columnDimension];
      gen++;
    }
  }
    userFile.close();
  }


//might not even need the methods
void Simulation::update(){
  //iterate through the actual board, not the boundaries
  for(int i = 1; i < rowDimension+1; ++i){
    for(int j = 1; j < columnDimension+1; ++j){

      //this iterates the 8 cells around each cell were inspecting
      for(int k = -1; k <= 1 ; k++){
        for(int m = -1; m <= 1; m++){
          if((i + k == i) && (j + m == j)){
            // do nothing becasue it is at the index in which we are checking neighbors FOR
          }
          //count the number of X around each cell
          else if(currentGrid[i+k][j+m] == 'X'){
            countCells++;
          }
        }
      }
      //depending on how many cells are X's, determines if the cell lives or dies
      switch(countCells){
        case 0:
        case 1:
          nextGrid[i][j] = '-';
          countCells = 0;
          break;
        case 2:
          nextGrid[i][j] = currentGrid[i][j];
          countCells = 0;
          break;
        case 3:
          nextGrid[i][j] = 'X';
          countCells = 0;
          break;
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
          nextGrid[i][j] = '-';
          countCells = 0;
          break;
        default:
          cout << ":(";
      }
    }
  }
//check if the generations are the same, if differenceCounter = 0, the program will end
for(int i = 1; i < rowDimension+1; ++i){
  for(int j = 1; j < columnDimension+1; ++j){
    if( !(currentGrid[i][j] == nextGrid[i][j])){
      differenceCounter++;
    }
  }
}

}


void Simulation::conductPause()
{
  if(briefPauseBool)
  {
    this_thread::sleep_for(chrono::seconds(1));
  }

  else if(enterPauseBool)
  {
    cout << "Press Enter to Continue...\n" << endl;
    getchar();
  }



}

Simulation::~Simulation(){
  for(int i = 0; i < rowDimension+2; ++i) {
      delete [] currentGrid[i];
      delete [] nextGrid[i];
  }
  delete [] currentGrid;
  delete [] nextGrid;

}
