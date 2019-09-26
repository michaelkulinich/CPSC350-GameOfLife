#include "Simulation.h"

using namespace std;
//should it print the 2nd geneation that is the same?
Simulation::Simulation(){
  //default constructor
}

Simulation::Simulation(char **&grid1, char **&grid2, int rowDim, int colDim){
   currentGrid = grid1;            //IS THIS SKETCH??
   nextGrid = grid2;
   rowDimension = rowDim;
   columnDimension = colDim;
}

void Simulation::run(){
  int mode;
  int gen = 0;
  int differenceCounter = 0; //if the generations are the same, program should end;
  int countCells = 0;   //counts the number of X's around the cell
  cout << "What Kind of gamemode will you like to run?(type in the number)\n(1)Classic\n(2)Doughnut\n(3)Mirror\n";
  cin >> mode;

  if (mode == 1){
    //code for classic

    cout << "Initial Grid: gen 0" << endl;
      for(int i = 0; i < rowDimension+2; ++i){
        for(int j = 0; j < columnDimension+2; ++j){
            cout << currentGrid[i][j];
      }
      cout << endl;
    }
    while(gen < 100){
      differenceCounter = 0; //set the counter to 0 before each update generation
    //create a method call check!!!!! make this less repetitive
        for(int i = 1; i < rowDimension+1; ++i){
          for(int j = 1; j < columnDimension+1; ++j){


            for(int k = -1; k <= 1 ; k++){
              for(int m = -1; m <= 1; m++){
                if((i + k == i) && (j + m == j)){
                  // do nothing becasue it is at the index in which we are checking neighbors FOR
                }
                else if(currentGrid[i+k][j+m] == 'X'){
                  countCells++;
                }
              }
            }
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

    cout <<"Generation: " << gen+1 << endl;
    for(int i = 1; i < rowDimension+1; ++i){
      for(int j = 1; j < columnDimension+1; ++j){
        cout << nextGrid[i][j];
      }
    cout << endl;
    }


    //check if the generations are the same
      for(int i = 1; i < rowDimension+1; ++i){
        for(int j = 1; j < columnDimension+1; ++j){
          if( !(currentGrid[i][j] == nextGrid[i][j])){
            differenceCounter++;
          }
        }
      }

    // cout << "new current grid"<< endl;;
    // //copy the next grid into the current grid, the boundary will always stay -
      for(int i = 0; i < rowDimension+2; ++i){
        for(int j = 0; j < columnDimension+2; ++j){
          currentGrid[i][j] = nextGrid[i][j];


        }
      }
      if(differenceCounter == 0){
        cout << "THIS GENERATION IS THE SAME THE LAST" << endl;
        cout << "THE PROGRAM STOPS BECAUSE NO CHANGE WILL EVER HAPPEN AGAIN!!!" << endl;
        break;
      }
      gen++;
    }
  }









  else if (mode == 2){
    //code for doughnut
    //after each generation, we will need to update the boundary


      //set the boundary for row 0 and last
    for(int i = 1; i < columnDimension+1;++i){
      currentGrid[0][i] = currentGrid[rowDimension][i];
      currentGrid[rowDimension+1][i] = currentGrid[1][i];
    }

    //set boudary for column
    for(int i = 1; i < rowDimension+1;++i){
      currentGrid[i][0] = currentGrid[i][columnDimension];
      currentGrid[i][columnDimension+1] = currentGrid[i][1];
    }

    cout << "Initial Grid: gen 0" << endl;
      for(int i = 0; i < rowDimension+2; ++i){
        for(int j = 0; j < columnDimension+2; ++j){
            cout << currentGrid[i][j];
      }
      cout << endl;
    }

    while(gen < 100){
      differenceCounter = 0;
    //create a method call check!!!!! make this less repetitive
        for(int i = 1; i < rowDimension+1; ++i){
          for(int j = 1; j < columnDimension+1; ++j){


            for(int k = -1; k <= 1 ; k++){
              for(int m = -1; m <= 1; m++){
                if((i + k == i) && (j + m == j)){
                  // do nothing becasue it is at the index in which we are checking neighbors FOR
                }
                else if(currentGrid[i+k][j+m] == 'X'){
                  countCells++;
                }
              }
            }
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

    cout <<"Generation: " << gen+1 << endl;
    for(int i = 1; i < rowDimension+1; ++i){
      for(int j = 1; j < columnDimension+1; ++j){
        cout << nextGrid[i][j];
      }
    cout << endl;
    }

    //check if the generations are the same
      for(int i = 1; i < rowDimension+1; ++i){
        for(int j = 1; j < columnDimension+1; ++j){
          if( !(currentGrid[i][j] == nextGrid[i][j])){
            differenceCounter++;
          }
        }
      }

    // cout << "new current grid"<< endl;;
    // //copy the next grid into the current grid, the boundary will always stay -
      for(int i = 0; i < rowDimension+2; ++i){
        for(int j = 0; j < columnDimension+2; ++j){
          currentGrid[i][j] = nextGrid[i][j];

        }
      }
      if(differenceCounter == 0){
        cout << "THIS GENERATION IS THE SAME THE LAST" << endl;
        cout << "THE PROGRAM STOPS BECAUSE NO CHANGE WILL EVER HAPPEN AGAIN!!!" << endl;
        break;
      }
      gen++;
    }
  }
  else{
    //code for mirror
    //after each generation, we will need to update the boundary


  //set boudary for column
  for(int i = 1; i < rowDimension+1;++i){
    currentGrid[i][0] = currentGrid[i][columnDimension];
    currentGrid[i][columnDimension+1] = currentGrid[i][1];
  }

  cout << "Initial Grid: gen 0" << endl;
    for(int i = 0; i < rowDimension+2; ++i){
      for(int j = 0; j < columnDimension+2; ++j){
          cout << currentGrid[i][j];
    }
    cout << endl;
  }

  while(gen < 100){
    differenceCounter = 0;// set counter to 0 before every generation update
  //create a method call check!!!!! make this less repetitive
      for(int i = 1; i < rowDimension+1; ++i){
        for(int j = 1; j < columnDimension+1; ++j){


          for(int k = -1; k <= 1 ; k++){
            for(int m = -1; m <= 1; m++){
              if((i + k == i) && (j + m == j)){
                // do nothing becasue it is at the index in which we are checking neighbors FOR
              }
              else if(currentGrid[i+k][j+m] == 'X'){
                countCells++;
              }
            }
          }
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

  cout <<"Generation: " << gen+1 << endl;
  for(int i = 1; i < rowDimension+1; ++i){
    for(int j = 1; j < columnDimension+1; ++j){
      cout << nextGrid[i][j];
    }
  cout << endl;
  }
//check if the generations are the same
  for(int i = 1; i < rowDimension+1; ++i){
    for(int j = 1; j < columnDimension+1; ++j){
      if( !(currentGrid[i][j] == nextGrid[i][j])){
        differenceCounter++;
      }
    }
  }

  // cout << "new current grid"<< endl;;
  // //copy the next grid into the current grid, the boundary will always stay -
    for(int i = 0; i < rowDimension+2; ++i){
      for(int j = 0; j < columnDimension+2; ++j){
        currentGrid[i][j] = nextGrid[i][j];

      }
    }
    if(differenceCounter == 0){
      cout << "THIS GENERATION IS THE SAME THE LAST" << endl;
      cout << "THE PROGRAM STOPS BECAUSE NO CHANGE WILL EVER HAPPEN AGAIN!!!" << endl;
      break;
    }
    gen++;
  }

  }

}

//might not even need the methods
void Simulation::classic(){

}

void Simulation::doughnut(){

}
void Simulation::mirror(){

}

Simulation::~Simulation(){
  for(int i = 0; i < rowDimension+2; ++i) {
      delete [] currentGrid[i];
      delete [] nextGrid[i];
  }
  delete [] currentGrid;
  delete [] nextGrid;

}
