#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) {

	ofstream myfile;
	ifstream inputted;

  myfile.open ("Fasta_read.out");

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

      string DNA;
			length = 0;
			string len= "len=";
			char c;
			while(!inStream.eof()) { //iterated through whole file until end
				if(len == "len=") { //seeing code that uses single quotes not double
					length++; //adds to the total
				}
				for (i=0; i<5; ++i){
					userFile.get(c); //grabs individual char
				}
				DNA += c; //adds the nucleotide to the string DNA
			}

      inputted.close(); //Make sure reading stops so it can write
    }
	}
}
