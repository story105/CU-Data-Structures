#include "Header.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <math.h>
#include <unistd.h>
#include <ctime>
#include <stdio.h> //print
#include <stdlib.h> //atoi (string to int)

using namespace std;

GameofLife::GameofLife(){ //CONSTRUCTION OF DECLARATIONS
  string StringToOutput = "";
  string Extra = "";
  string FileOutput = "";
  int turnCount = 0;
}

GameofLife::~GameofLife(){ //destruction!!
}
//What kind of mode? char = D (doughnut)

void GameofLife::chooseMode(int& rows, int& columns, char**& board){
    char mode;
    bool checkLoop = true;

    while (checkLoop == true){
      cout << "Select game mode: 'N' (normal), 'M' (mirror), 'D' (doughnut): "<< endl;
      cin >> mode;
      if ((mode == 'N') || (mode == 'n')){
        normalmode(rows, columns, board);
        checkLoop = false;
      }
      else if ((mode == 'M') || (mode == 'm')){
        mirrormode(rows, columns, board);
        checkLoop = false;
     }
    else if ((mode == 'D') || (mode == 'd')){
        doughnutmode(rows, columns, board);
        checkLoop = false;
   }
        else{
      cout << "Nice try, guys \n" << endl;
      checkLoop = true; //looping reassurance
      }
    }
}

void GameofLife::selectModeSetting(){ //select settings
  string selection = "";
  bool checker = true;
  bool impendingSex = true;
  while (impendingSex == true){
    cout << "How would you like your data outputted ('enter', 'pause', or 'outputfile')? " << endl;
    cin >> StringToOutput;
    if((StringToOutput == "enter")|| (StringToOutput == "Enter")){ //If Rene tryna be fancy with the capitalization
      impendingSex = false;
    }
    else if ((StringToOutput == "pause") || (StringToOutput == "Pause")){
      impendingSex = false;
    }
    else if ((StringToOutput == "outputfile")|| (StringToOutput == "Outputfile")){
      cout << "what file should be printed to? "<< endl;
      cin >> FileOutput;
      impendingSex = false;
    }
    else if ((StringToOutput == "outPutFile") || (StringToOutput == "outputFile")){
      cout << "what file should be printed to? "<< endl;
      cin >> FileOutput;
      impendingSex = false;
    }
    else {
      impendingSex = true; //KEEP THIS LOOP GOING UNTIL RENE IS DOWN XD
      cout << "Ay yo, I asked specific options: let's be real." << endl;
    }
  }
  //another while loop because need all answers answered
  while (checker == true){
    string ownFile = "";
    cout << "Want a random board or do you have your own? (CHOOSE 'random' or 'own')" << endl;
    cin >> selection; //initiated above
    if ((selection == "random")||(selection == "Random")){
      int rows = 0;
      int columns = 0; //Starter variables to start
      createBoard(rows, columns); //random starts,
      checker = false;
    }
    else if ((selection == "own") || (selection=="Own")){
      cout << "What is the name of the file? \n";
      cin >> ownFile;
      createUserBoard(ownFile); //userinput board starts
      checker = false; //exit, right answer
    }
    else{
      cout << "I guess we don't know what selection you want... " << endl;
      checker = true; //Loops again
    }
  }
}

void GameofLife::printToScreen(string StringToOutput, int turnCount, char**& board, int rows, int columns){
	bool pause = true; //The variable StringToOutput gets accepted with "chooseMode()" functionn
	if((StringToOutput == "pause")||(StringToOutput == "Pause")){ //PAUSE PRINTING TO TERMINAL
		sleep(1);
		cout << "Turn count: " << turnCount << "\n";
		for(int i = 0; i < rows; ++i) {
			for (int j = 0; j < columns; ++j) {
				cout << board[i][j];
			}
			cout << "\n";
		}
	}else if((StringToOutput == "enter")||(StringToOutput == "Enter")){ //Prints upon enter key
		cout << "Press enter key to continue" << endl;
		cin.get();
		if (cin.get()){
			pause = false; //reverses initial pause
		} //If they want to just continue right away, any key inputted starts if-statement
		if (pause == false){
			cout << "Turn count: " << turnCount << "\n"; //genius code comin up v proud
			for(int i = 0; i < rows; ++i) {
				for (int j = 0; j < columns; ++j) {
					cout << board[i][j];
				}
				cout << "\n"; //BOOOM AFTER COLUMNS (first array) ITERATION THENNNN NEW LINE!! ayyy
			}
		}
	}
} //end

void GameofLife::createBoard(int& rows, int& columns){
  double randomChecks = 0.0;
  bool whileLoop = false;
  int numberOfBoxes = 0;
  int randRows = 0;
  int randColumns = 0;
  //set em allll to 0!
  cout << "What would you like the length of your board to be? " << endl;
  cin >> rows;
  cout << "What would you like the width of your board to be? " << endl;
  cin >> columns;
  //How many boxes are filled

  while (whileLoop == false){
    cout << "Enter a number between 0 and 1: " << endl;
    cin >> randomChecks;

    if ((randomChecks >= 0.0) && (randomChecks < 1.0)){
      cout << "good number" << endl;
      whileLoop = true;
    }else{
      cout << "bad number" << endl;
      whileLoop = false; //I dunno if I should just leave it, but I'll confirm its false
      }
    }

    char** makeNextBoard = new char*[rows];
    //this will initialize the first array of rows, then later per row make the randColumns
    for (int x = 0; x < rows; ++x){
      makeNextBoard[x] = new char[columns]; //BOOM no * because
      //pointer is assigned already
    }

    numberOfBoxes = round(randomChecks*rows*columns); //round gives an int! rounde    cout << "make next board is set" << endl;

    for (int y = 0; y < rows; y++){
		    for (int z = 0; z < columns; z++){
			     makeNextBoard[y][z] = '-'; //makes em allll - next function will change to X's
		}
	}
  srand(time(NULL)); //this is in Readme, about creating a more random number EACH TIME

  for (int a = 0; a < numberOfBoxes; a++){ //increment before, so -1 not 0
    randRows = rand()%rows;
    randColumns = rand()%columns;
    int numberBoxes = 1;
    while (numberBoxes > 0) {
      if (makeNextBoard[randRows][randColumns] == '-'){
         makeNextBoard[randRows][randColumns] = 'X';
         numberBoxes = numberBoxes -1; //makes sure this loops only goes once
    }
    else{ //this needs to happen in order that incase the random number finds a filled box
         randRows = rand()%rows; //This just generates a new random box to jump to
         randColumns = rand()%columns; //and then make it a X

      }
    }
  }
  chooseMode(rows, columns, makeNextBoard); //will go input this into the chosen mode!
}


//do while exception catch if-else itll do again
void GameofLife::createUserBoard(string userInput){ //really bad variable but I dont wanna risk changing now
  ifstream inputString;
  inputString.open(userInput.c_str()); //opens file that user input
  int rows = 0;
  int columns = 0;
  int counter = 0;
  string line = "";

  while(!inputString.eof()){
    getline(inputString, line);
    if (counter == 0){
      rows = atoi(line.c_str()); //first row is # randRows
    }
    else if (counter == 1){
      columns = atoi(line.c_str()); //atoi is string to int (input type is string)
    }
    else {
      break; //while loop no longer necessary after first 2 lines for this
    }
    counter++;
  }

  counter = 0;
  char** makeNextBoard = new char* [rows]; //sets first pointer of array next board to the rows pointer, will hve to assign next columns
  for (int b = 0; b < rows; ++b){ //HEY CHEC THIS CHARLIE
    makeNextBoard[b] = new char[columns]; //BOOM set the pointer of rows array to have a new columns array within
  }
  for (int a = 0; a < rows; a++){
    for (int c = 0; c < columns; c++){
      makeNextBoard[a][c] = '-';
    }
  }
  inputString.seekg(0, inputString.beg); //Go find the beginning of file
  int width = 0;
  while(!inputString.eof()){
    getline(inputString, line); //will change per line, first two lines of your file will NOT be the  board but specifications
    if (counter == 0){
      cout << "Skipping first line of inputfile" << endl;
    }
    else if( counter == 1){
      //do nothing here bc ^
      cout << "Skipping second??? line of inputfile" << endl;
    }
    else {
      for(int i = 0; i < columns; i++){
        char inBox = line[i]; //pulls the char in the spot at I
       //if (inBox == 'X' || inBox == 'x'){ //just added, see if it upper cases em all
      //    inBox = 'X';
      //  } //Check for UppserCase
        makeNextBoard[width][i] = inBox;
      }
      width++; //now will go to next "line"
    }
    counter++; //so basically counter counts to 2 before the ELSE statement runs (skips two lines of ur file)
  }
  cout << "It madeit to ChooseMode();" << endl;
  chooseMode(rows, columns, makeNextBoard); //making the next board be the set board.

} //END

int GameofLife::normalmode(int rows, int columns, char**& board){
  int counter = 0;
  int turnCount = 1;
  bool finished = false;

  char** nextTurnboard = new char*[rows]; //creating next board as a result of first board dimensions
  for (int i = 0; i < rows; ++i){
    nextTurnboard[i] = new char [columns]; //just created new instance of
    //next board, setting up rows and columns (double array)
  }

  while (finished == false) { //while loops keep iteration until the game is finished
    for (int i = 0; i < rows; i++){
      for (int j = 0; j < columns; j++){
       counter = 0; //reset each time for's run to check life in boxes
        if (i == 0 && j == 0){
          if (board[i+1][j] == 'X'){
            counter++;
          }
          if (board[i][j+1] == 'X'){ //I just went and got rid of EVERY else if
            counter++;
          }
          if (board[i+1][j+1] == 'X'){
            counter++;
            }
          } //end of first corner
          else if (i == 0 && j == (columns-1)){ //down-wards size corner
          if (board[i][j-1] == 'X'){
            counter++;
          }
            if (board[i+1][j-1] == 'X'){
            counter++;
          }
            if (board[i+1][j] == 'X'){
            counter++;
          }
        }
           else if (i == (rows-1) && j == 0){
          if (board[i-1][j] == 'X'){
            counter++;
          }
            if (board[i-1][j+1] == 'X'){
            counter++;
          }
            if (board[i][j+1] == 'X'){
            counter++;
          }
        }
        else if ((i==(rows-1))&&(j==(columns-1))){
          if (board[i-1][j]== 'X'){
            counter++;
          }
            if (board[i-1][j-1]== 'X'){
            counter++;
          }
            if (board[i][j-1]== 'X'){
            counter++;
          }
        } //NOW TO CHECK SIDES
        else if(i == 0){
          if (board[i+1][j]=='X'){
            counter++;
          }
            if (board[i+1][j+1]=='X'){
            counter++;

          }
            if (board[i+1][j-1]=='X'){
            counter++;

          }
            if (board[i][j+1]=='X'){
            counter++;

          }
            if (board[i][j-1]=='X'){
            counter++;

          }
        }
        else if (j==0){
          if(board[i+1][j]=='X'){
            counter++;
          }
            if(board[i-1][j]=='X'){
            counter++;
          }
            if(board[i+1][j+1]=='X'){
            counter++;
          }
            if(board[i-1][j+1]=='X'){
            counter++;
          }
            if(board[i][j+1]=='X'){
            counter++;
          }
        }
        else if (i == (rows-1)){
          if(board[i][j-1]=='X'){
            counter++;
          }
            if(board[i][j+1]=='X'){
            counter++;
          }
            if(board[i-1][j+1]=='X'){
            counter++;
          }
            if(board[i-1][j-1]=='X'){
            counter++;
          }
            if(board[i-1][j]=='X'){
            counter++;
          }
        }
        else if (j == (columns-1)){
          if(board[i][j-1]=='X'){
            counter++;
          }
            if(board[i+1][j-1]=='X'){
            counter++;
          }
            if(board[i-1][j-1]=='X'){
            counter++;
          }
            if(board[i+1][j]=='X'){
            counter++;
          }
            if(board[i-1][j]=='X'){
            counter++;
          }
        }//finished sides, now to check middle
        else{//HAHA just "else it"
          if (board[i+1][j]=='X'){
            counter++;
          }
            if (board[i-1][j]=='X'){
            counter++;
          }
            if (board[i][j+1]=='X'){
            counter++;
          }
            if (board[i][j-1]=='X'){
            counter++;
          }
            if (board[i+1][j+1]=='X'){
            counter++;
          }
            if (board[i+1][j-1]=='X'){
            counter++;
          }
            if (board[i-1][j+1]=='X'){
            counter++;
          }
            if (board[i-1][j-1]=='X'){
            counter++;
          }//end of middle stuff, now to check
        }
          //COUNTER check at end to kill or live!
          if (counter < 2){
            nextTurnboard[i][j] = '-'; //doesn't change old board
          } //not sure if using swap yet
          else if (counter == 2){
            nextTurnboard[i][j] = board[i][j];
          }else if (counter == 3){
            nextTurnboard[i][j] = 'X';
          }
            else if(counter > 3){
              nextTurnboard[i][j] = '-';
            }
        } /* if(!(reading >> rows)){
          successful = false; //check this
          cout << "error could ot read file" << endl;
        }
        */
      } // double for loop end
      //check to see if game is finished
      int value = 0;
      for (int i=0; i < rows; i++){
        for (int j=0; j < columns;j++){
          if (nextTurnboard[i][j] == board[i][j]){
            value++;
          }
          else{
            finished = false;
          } //keep going through the game (not done)
        }
      }
      if (value == (rows*columns)){
        finished = true;

        cout << "\n\n game is finished! Thanks for playing!\n\n\n"<<endl;
        cout <<"...dont come again"<< endl;
      }


      if (finished == false){ //FIX THIS CHARLIE NVM ITS GOOD DOUBLE CHECK IF GAME NOT DONE
        std::stringstream stringstrm;  //string stream
    		stringstrm << "Turn: " << turnCount << "\n";
        Extra += stringstrm.str();

           if (turnCount == 1){ //for the very first board

            	for(int i = 0; i < rows; ++i){
      				   for(int j = 0; j < columns; ++j){
      				      std::stringstream stringstrm; //have to call another instance of string stream
   						      stringstrm << board[i][j];
   						      Extra += stringstrm.str();
   					}
   					std::stringstream stringstrm;
   					stringstrm << "\n"; //This is simply after each iteration through first array, \n
   					Extra += stringstrm.str();
  				}
      printToScreen(StringToOutput, turnCount, board, rows, columns);
      for(int i = 0; i < rows; ++i){ //THIS IS MOST LIKELY THE ISSUE
      	 for(int j = 0; j < columns; ++j){ //WITH CCOPYING Board
      		  board[i][j] = nextTurnboard[i][j]; //GGBDHBAGKBGJGJe
      				}
      			}
            }else { //any other turn other than 1

            	for(int i = 0; i < rows; ++i){
      				      for(int j = 0; j < columns; ++j){
      					           board[i][j] = nextTurnboard[i][j];
      					           std::stringstream stringstrm;
      					           stringstrm << board[i][j]; //This saves current game, while updating next turn board
      					           Extra += stringstrm.str();
      				}
      			std::stringstream stringstrm;
   					stringstrm << "\n";
   					Extra += stringstrm.str();
      			}
      			printToScreen(StringToOutput, turnCount, board, rows, columns);
      		}
    	}
      turnCount++; //THIS COULD HAVE BEEN THE ISSUE
    }
    //need implementation
  if (FileOutput != ""){
      ofstream printFile;
      printFile.open(FileOutput.c_str());
      printFile << Extra << "\n";
      printFile.close();
      }

  return 0;
}

int GameofLife::mirrormode(int rows, int columns, char** &board){
  int count = 0;
  int turnCount = 1;
  bool finished = false;

  char** nextTurnboard = new char*[rows]; //creating next board as a result of first board dimensions
  for (int a = 0; a < rows; ++a){
    nextTurnboard[a] = new char [columns]; //just created new instance of
    //next board, setting up rows and columns (double array)
  }
  while (finished == false){
    for (int a = 0; a < rows; a++){
      for (int b = 0; b < columns; b++){ // this is all basically copy paste from normal mode
        count = 0; //reset counter value
        //check corners, then sides, then middle (else)
        if (a == 0 && b == 0){ //should have kept i and j
          if (board[a][b] == 'X'){
            count=count+3; //it's reflected 3 times into the corner
          } //Im also fairly sure theres like a count+=3; thing but Im not sure
            if (board[a+1][b] == 'X'){
            count = count +2; //reflected 1 and is a neighbor
          }
            if (board[a][b+1] == 'X'){
            count = count +2; //neighbor below, and is a mirrored
          }
            if (board [a+1][b+1]){
            count++; //just one neighbor
          }
        }
        else if (a==rows-1 && b == 0){
          if (board[a][b] == 'X'){
            count = count +3;
          }
            if (board[a-1][b] == 'X'){
            count = count +2;
          }
            if (board[a][b+1] == 'X'){
            count = count +2;
          }
            if (board[a-1][b+1] == 'X'){
            count++;
          }
        }
        else if (a == 0 && b == columns-1){
          if (board[a][b] == 'X'){
            count = count +3;
          }
            if (board[a+1][b] == 'X'){
            count = count +2;
          }
            if (board[a][b-1] == 'X'){
            count = count +2;
          }
            if (board[a+1][b-1] == 'X'){
            count = count +1;
          }
        }
        else if (a == rows -1 && b == columns - 1){
          if (board[a][b] == 'X'){
            count = count+ 3;
          }
            if (board[a-1][b] == 'X'){
            count = count +2;
          }
            if (board[a-1][b-1] == 'X'){
            count = count +1;
          }
            if (board[a][b-1] == 'X'){
            count = count +2;
          }
        }//Last corner, not sides

        else if (a == 0) { //the specific  [0][0] has already been dealt
          if (board[a][b] == 'X'){
            count = count +1; //only one refelction
          }
            if (board[a+1][b] == 'X'){
            count = count +1;
          }
            if (board[a+1][b-1] == 'X'){
            count = count +1;
          }
            if (board[a+1][b+1] == 'X'){
            count = count +1; //these are the 3 inside edges
          }
            if (board[a][b-1] == 'X'){
            count = count +2; //two reflections for above and below
          }
            if (board[a][b+1] == 'X'){
            count = count +2;
          }
        }
        else if (b==0){
          if (board[a][b] == 'X'){
            count = count +1; //only one refelction
          }
            if (board[a+1][b] == 'X'){
            count = count +2;
          }
            if (board[a-1][b] == 'X'){ //check up and down
            count = count +2;
          }
            if (board[a][b+1] == 'X'){
            count = count +1; //only one refelction
          }
            if (board[a+1][b+1] == 'X'){ //inside squares, no reflections
          }
            if (board[a-1][b+1] == 'X'){
            count = count +1; //only one refelction
          }
        }
        else if (a == (rows - 1)){
          if (board[a][b] == 'X'){
            count++;
          }
            if (board[a][b+1=='X']){
            count = count +2;
          }
            if (board[a][b-1]=='X'){
            count = count +2;
          }
            if (board[a-1][b-1]=='X'){
            count++;
          }
            if (board[a-1][b]=='X'){
            count++;
          }
            if (board[a-1][b+1]=='X'){
            count++;
          }
        }
        else if (b == (columns - 1)){
          if(board[a][b] == 'X'){
            count++;
          }
            if(board[a+1][b]=='X'){
            count = count +2;
          }
            if(board[a-1][b]=='X'){
            count = count +2;
          }
            if(board[a+1][b-1]=='X'){
            count++;
          }
            if(board[a-1][b-1]=='X'){
            count++;
          }
            if(board[a][b-1]=='X'){
            count++;
          }
        } //FINISHED SIDES NOW MIDDLE IS (ELSE)

        else{//HAHA just "else it" //straight copy pasted from normal, cause it's literally the same
          if (board[a+1][b]=='X'){
            count++;
          }
          if (board[a-1][b]=='X'){
            count++;
          }
          if (board[a][b+1]=='X'){
            count++;
          }
          if (board[a][b-1]=='X'){
            count++;
          }
          if (board[a+1][b+1]=='X'){
            count++;
          }
          if (board[a+1][b-1]=='X'){
            count++;
          }
          if (board[a-1][b+1]=='X'){
            count++;
          }
          if (board[a-1][b-1]=='X'){
            count++;
          }//end of middle stuff, now to check
        }
        if (count < 2) {
          nextTurnboard[a][b] = '-';
        }
        else if (count == 2){
          nextTurnboard[a][b] = board[a][b];
        }
        else if (count == 3){
          nextTurnboard[a][b]= 'X';
        }
        else if (count > 3){
          nextTurnboard[a][b] = '-';
        }

      }
    }
    int checkStable = 0;
    for (int i = 0; i < rows; i++){
      for (int j = 0; j < columns; j++){
        if (nextTurnboard[i][j] == board[i][j]){
          checkStable++;
        }
        else {
          finished = false; //keep initial while loop going
        }
      }
    }
    if (checkStable == (rows*columns)){
      finished = true; //exit
      cout << " \n Game is finished, thanks for playing Mirror mode \n" << endl;
    }
    //file printing
    if ( finished == false){
      std::stringstream strstm;
      strstm << "Turn count: " << turnCount << "\n"; //not sure if rinting endl works?
      Extra += strstm.str();
      if (turnCount == 1){
        for(int i = 0; i < rows; ++i){
          for (int j = 0; j < columns; ++j){
            std::stringstream strstm;
            strstm << board[i][j];
            Extra += strstm.str();
          }
          std::stringstream strstm;
          strstm << "\n";
          Extra += strstm.str();
        }
        printToScreen(StringToOutput, turnCount, board, rows, columns);
        for(int i = 0; i < rows; ++i){
          for (int j = 0; j < columns; ++j){
            board[i][j] = nextTurnboard[i][j];
          }
        }
      }
      else { //any other turn than 1
        for(int i = 0; i < rows; ++i){
          for (int j = 0; j < columns; ++j){
            board[i][j] = nextTurnboard[i][j];
            std::stringstream strstm;
            strstm << board[i][j];
            Extra += strstm.str();
          }
          std::stringstream strstm;
          strstm << "\n";
          Extra += strstm.str();
        }
        printToScreen(StringToOutput, turnCount, board, rows, columns);
      }
    }
    turnCount++; //after the screen is outputted, then increment the turn
  } //While loop close bracket
  if (FileOutput != ""){
    ofstream fileoutput;
    fileoutput.open(FileOutput.c_str());
    fileoutput << Extra << "\n";
    fileoutput.close();
  }
return 0;
}

int GameofLife::doughnutmode(int rows, int columns, char**& board){

  int count = 0;
  int turnCount = 1;
  bool finished = false;

  char** nextTurnboard = new char*[rows]; //creating next board as a result of first board dimensions
  for (int a = 0; a < rows; ++a){
    nextTurnboard[a] = new char [columns]; //just created new instance of
    //next board, setting up rows and columns (double array)
  }
  while (finished == false){
    for (int i = 0; i < rows; i++){
      for (int j = 0; j < columns; j++){ // this is all basically copy paste from normal mode
        count = 0; //reset counter value
        //check corners, then sides, then middle (else)
        if (i == 0 && j == 0){ //should have kept i and j
          if (board[i+1][j] == 'X') count++; //IVE STREAMLINED THE PROCESS
          if (board[i+1][j+1] == 'X') count++;
          if (board[i+1][columns-1] == 'X') count++; //stinkin doughnut logic
          if (board[i][j+1] == 'X') count++;
          if (board[i][columns-1] == 'X') count++;
          if (board[rows-1][j+1] == 'X') count++; //Bottom row
          if (board[rows-1][columns-1] == 'X') count++; //OFC THIS ONE
          if (board[rows-1][j] == 'X') count++; //opposide bottom
        }
        else if (i == 0 && (columns - 1)){
          if(board[i+1][j] == 'X') count++; //normal bordering
					if(board[i][j-1] == 'X') count++;
					if(board[i+1][j-1] == 'X') count++;
					if(board[rows-1][j] == 'X') count++; //flip to opposite sides
					if(board[rows-1][j-1] == 'X') count++;
					if(board[rows-1][j] == 'X') count++;
					if(board[i][0] == 'X') count++; //Opposite Corner
					if(board[i+1][0] == 'X') count++;
        }
        else if (i == (rows-1) && j == 0){
          if(board[i-1][j] == 'X') count++;
					if(board[i][j+1] == 'X') count++;
					if(board[i-1][j+1] == 'X') count++;
					if(board[0][j] == 'X') count++;
					if(board[0][j+1] == 'X') count++;
					if(board[0][columns-1] == 'X') count++;
					if(board[i-1][columns -1] == 'X') count++;
					if(board[i][columns-1] == 'X') count++;
        }
        else if (i == (rows-1) && j == (columns-1)){
          if(board[i-1][j] == 'X') count++;
					if(board[i][j-1] == 'X') count++;
					if(board[i-1][j-1] == 'X') count++;
					if(board[0][j-1] == 'X') count++;
					if(board[0][j] == 'X') count++;
					if(board[0][0] == 'X') count++;
					if(board[i][0] == 'X') count++;
					if(board[i-1][0] == 'X') count++;
        }
        else if (j == 0) {
					if(board[i-1][j] == 'X') count++;
					if(board[i+1][j] == 'X') count++;
					if(board[i][j+1] == 'X') count++;
					if(board[i+1][j+1] == 'X') count++;
					if(board[i-1][j+1] == 'X') count++;
					if(board[i-1][columns-1] == 'X') count++;
					if(board[i][columns-1] == 'X') count++;
					if(board[i+1][columns-1] == 'X') count++;
				}
				else if (i == 0) {
					if(board[i+1][j] == 'X') count++;
					if(board[i][j+1] == 'X') count++;
					if(board[i+1][j+1] == 'X') count++;
					if(board[i][j-1] =='X') count++;
					if(board[i+1][j-1] == 'X') count++;
					if(board[rows-1][j-1] == 'X') count++;
					if(board[rows-1][j] == 'X') count++;
					if(board[rows-1][j+1] == 'X') count++;
        	    }
            	else if (i == (rows - 1)) {
					if(board[i-1][j] == 'X') count++;
					if(board[i][j+1] == 'X') count++;
					if(board[i-1][j+1] == 'X') count++;
					if(board[i][j-1] =='X') count++;
					if(board[i-1][j-1] == 'X') count++;
					if(board[0][j-1] == 'X') count++;
					if(board[0][j] == 'X') count++;
					if(board[0][j+1] == 'X') count++;
				}
				else if (j == (columns - 1)) {
					if(board[i-1][j] == 'X') count++;
					if(board[i+1][j] == 'X') count++;
					if(board[i][j-1] == 'X') count++;
					if(board[i+1][j-1] == 'X') count++;
					if(board[i-1][j-1] == 'X') count++;
					if(board[i-1][0] == 'X') count++;
					if(board[i][0] == 'X') count++;
					if(board[i+1][0] == 'X') count++;
				}
				else {
					if(board[i+1][j] == 'X') count++;
					if(board[i][j+1] == 'X') count++;
					if(board[i+1][j+1] == 'X') count++;
					if(board[i][j-1] =='X') count++;
					if(board[i-1][j] == 'X') count++;
					if(board[i-1][j-1] == 'X') count++;
					if(board[i+1][j-1] =='X') count++;
					if(board[i-1][j+1] == 'X') count++;
				}
        if (count < 2) {
           			nextTurnboard[i][j] = '-';
        		}
	        	else if (count == 2) {
    	        	nextTurnboard[i][j] = board[i][j];
        		}
	        	else if (count == 3) {
    	        	nextTurnboard[i][j] = 'X';
        		}
        		else if (count > 3) {
            		nextTurnboard[i][j] = '-';
      }
    }
  }

  int checkStable = 0;
  for (int i = 0; i < rows; ++i){
    for (int j = 0; j < columns; ++j){
      if (nextTurnboard[i][j] == board[i][j]){
        checkStable++;
      }
      else {
        finished = false; //keep initial while loop going
      }
    }
  }
  if (checkStable == (rows*columns)){
    finished = true; //exit
    cout << " \n Game is finished, thanks for playing Mirror mode \n" << endl;
  }
  //file printing
  if ( finished == false){
    std::stringstream sstm;
    sstm << "Turn count: " << turnCount << "\n"; //not sure if rinting endl works?
    Extra += sstm.str();
    if (turnCount == 1){
      for(int i = 0; i < rows; ++i){
        for (int j = 0; j < columns; ++j){
          std::stringstream sstm;
          sstm << board[i][j];
          Extra += sstm.str();
        }
        std::stringstream sstm;
        sstm << "\n";
        Extra += sstm.str();
      }
      printToScreen(StringToOutput, turnCount, board, rows, columns);
      for(int i = 0; i < rows; ++i){
        for (int j = 0; j < columns; ++j){
          board[i][j] = nextTurnboard[i][j];
        }
      }
    }
    else { //any other turn than 1
      for(int i = 0; i < rows; ++i){
        for (int j = 0; j < columns; ++j){
          board[i][j] = nextTurnboard[i][j];
          std::stringstream sstm;
          sstm << board[i][j];
          Extra += sstm.str();
        }
        std::stringstream sstm;
        sstm << "\n";
        Extra += sstm.str();
      }
      printToScreen(StringToOutput, turnCount, board, rows, columns);
    }
  }
  turnCount++; //after the screen is outputted, then increment the turn
} //While loop close bracket
if (FileOutput != ""){
  ofstream fileoutput;
  fileoutput.open(FileOutput.c_str());
  fileoutput << Extra << "\n";
  fileoutput.close();
}
  return 0;
}
