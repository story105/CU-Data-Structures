//Charles Story
//Assignment 3
#include "HeaderfileGenstack.h"
#include <iostream>
#include <stack>
#include <string>
#include <fstream>

using namespace std;


int main(int argc, char **argv){
GenStack<char> gs(100);



//Getting user file and then calculated the code
  string userInputted;
  cout << "Enter a source code file: ";
  cin >> userInputted;
	ifstream inputted;
  inputted.open(userInputted.c_str()); // Opening the file
  if (inputted.is_open()){
    bool done = false;
    while (done == false){
      int lineNumber = 1;
      string fileInput;

            bool mainLoop = true;

      while (getline(inputted, fileInput)){
        if (mainLoop == false) {
          break; //Will get out of the while!
        }
        for (int x = 0; x < fileInput.size(); ++x){ //Iterate through all the code PER LINE
          if ((fileInput[x] == '(') || (fileInput[x] == ')') || (fileInput[x] == '[') || (fileInput[x] == ']') || (fileInput[x] == '{') || (fileInput[x] == '}')){
            //If any one the inputs are the delimeters
            if ((gs.peek() == '(') && (fileInput[x] == ')')){
              gs.pop();
            }
            else if ((gs.peek() == '{') && (fileInput[x] == '}')){
              gs.pop();
            }
            else if ((gs.peek() == '[') && (fileInput[x] == ']')){
              gs.pop();
            }
            else if ((gs.peek() == '(') && ((fileInput[x] == ']') || (fileInput[x] == '}'))){
              cout << "Error on line " << lineNumber << ". Missing ')'" << endl;
              mainLoop = false;
              break; //Exits the for loop
            }
            else if ((gs.peek() == '[') && ((fileInput[x] == ')') || (fileInput[x] == '}'))){
              cout << "Error on line " << lineNumber << ". Missing ']'" << endl;
              mainLoop = false;
              break;
            }
            else if ((gs.peek() == '{') && ((fileInput[x] == ']') || (fileInput[x] == ')'))){
              cout << "Error on line " << lineNumber << ". Missing '}'" << endl;
          //    break;
              mainLoop = false;
              break;
            }
            else if ((fileInput[x] == '[') || (fileInput[x] == '{') || (fileInput[x] == '(')){
              gs.push(fileInput[x]); //After all other conditions are checked, then it will add to the stack.
            }
          }
      //  } //WhileMainLoop
        }
      lineNumber++; //So that the line count should be accurate
      }
      if (gs.isEmpty() == false){
        cout << "Expected delimiter for '" << gs.peek() << "' not found." << endl;
        done == false;
        return 0;
      }
      else if (gs.isEmpty() == true){
        char choice = '\0';
        cout << "No errors found. Would you like to process another file? (Y/N)" << endl;
        cin >> choice;
        bool choicedone = false;
        while (choicedone == false){
        if (choice == 'Y' || choice == 'y'){
          done = false;
          choicedone = true;
          continue;
        }
        else if (choice == 'N' || choice == 'n'){
          done = true;
          choicedone = true;
        }
        else {
          cout << "Uhm naw I caught this!" << endl;
          choicedone = false;
          done = false;
          }
        } //CHoicedone while loop
      }
    }
  }
  else {
    cout << "Could not open said file..." << endl;
  }

return 0;
}
