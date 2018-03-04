#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "HandleExternalFile.h"
using namespace std;
//fstream to read and write from files, iostream for outputinput
int main(int argc, char** argv) {

	ofstream myfile;
	ifstream inputted;

  myfile.open ("CharlesStory.out");
if(myfile.is_open() == true){
  myfile << "Charles Story \n";
  myfile << "2272488 \n";
  myfile << "CPSC 350 Assignment 1 \n \n";
  }
else {
  cout << "Unable to open that file I guess... \n";
  }



  while (true){
    char userInput;
    string userFile;
    cout << "Do you want this program to read a file? (Y/N) " << endl;
    cin >> userInput;
    if (userInput == 'n' || userInput == 'N'){
      cout << "cool, we done here" << endl;
    }
    else if (userInput == 'y' || userInput == 'Y'){
      cout << "What is the name of this file? " << endl;
      cin >> userFile;
      inputted.open(userFile.c_str()); // Opening the file

      DNACollection DNA;
      DNA.DNAInputFile(inputted); //Each either read
      DNA.ComputeCollection(myfile); //Or output out to the file CharlesStory.out
      DNA.nucleotideProbability(myfile);
      DNA.guassianDistribution(myfile); //Last function to run so it'll clear stored values

      inputted.close(); //Make sure reading stops so it can write
    }
    bool anotherwhileloop = true;
    while (anotherwhileloop){
      cout << "Is another .txt file in order? (Y/N)" << endl;
			char anotherinput;
      cin >> anotherinput;
			if ((anotherinput == 'n') || (anotherinput == 'N')){
				myfile.close();
				cout << "COMPLETED AYYYYY \n"; //Having trouble with Ubuntu....
				return 0; //returns false so boolean loop ends!
			}
			else if ((anotherinput == 'y') || (anotherinput == 'Y')){
				cout << "Cool, remember: consent is always needed." << endl;
				break; //Goes back to original while loop, WHICH JUST ENDS AYY
			}
			else {
				cout << "Enter a proper file, foo... " << endl;
				cout << "bar... " << endl;
			}
    }
    inputted.close(); //Make sure reading stops so it can write

  }
  return 0; //Read in book good practice to return 0 at end
}
