#include "HandleExternalFile.h" //share class
#include <iostream>
#include <math.h> //sqrt stuff
#include <string>
#include <fstream>
#include <stdlib.h> //Handles random number generation

using namespace std;

DNACollection::DNACollection() { //constructor with relevant variables
  string DNA; //This is the original class and Im making current variables of Each declared
  int lineCount = 0; //no need for double for just simple counts
  double nucleotideCount = 0.0;
  double sum = 0.0;
  double mean = 0.0;
  double variance = 0.0;
  double standardDev = 0.0;
  double nucleotideTotal = 0.0; //???
  double Achance = 0.0;
  double Cchance = 0.0;
  double Tchance = 0.0;
  double Gchance = 0.0; //all the nucleotide singular probabilities
}

DNACollection::~DNACollection(){ //Not sure if placement of this matters
} //deconstructor

void DNACollection::DNAInputFile(ifstream& inStream) { //reads from user inputted file
	lineCount = 0;
	char c;
	while(!inStream.eof()) { //iterated through whole file until end
		if(c == '\n') { //seeing code that uses single quotes not double
			lineCount++; //checks for everything but new line
		}
		inStream.get(c); //grabs individual char
		DNA += c; //adds the nucleotide to the string DNA
	}
}

void DNACollection::ComputeCollection(ofstream& outStream) { //outstream goes to CharlesStory.txt
	int count = 0;
	double nucleotideCount = 0.0;
	//Calculate the Sum and the Mean
	for(int i = 0; i < DNA.size(); ++i) { //u taught us to ++i
		if(DNA[i] != '\n') { //THIS READS THE STRING OF ALL INPUTTED LETTERS
			nucleotideTotal += 1;
		}
		else {
			count += 1;
			if(count == lineCount) { //
				sum = nucleotideTotal;
				mean = sum/lineCount;
				count = 0;
				break;
			}
		}
	}
	outStream << "\nSum: " << sum << "\n";
	outStream << "Mean: " << mean;


	for(int x = 0; x < DNA.size(); ++x) {
		if(DNA[x] != '\n') {
			nucleotideCount += 1;
		}
		else {
			variance += pow((nucleotideCount - mean), 2);
			nucleotideCount = 0;
			count += 1;
			if(count == lineCount) { //Math for variance
				variance = variance/nucleotideTotal;
				standardDev = sqrt(variance); //standardDev ez to get < sqrt why math imported
				break;
			}
		}
	}

	outStream << "\nVariance: " << variance << "\n";
	outStream << "Standard Deviation: " << standardDev << "\n";
} //The program will then compute the sum, mean, variance, and
  //standard deviation of the length of the DNA strings in the list

void DNACollection::nucleotideProbability(ofstream& outStream){
  double AchancewithA = 0.0; //You wanted us to make SO MANY OF THSE
  double AchancewithC = 0.0;
  double AchancewithT = 0.0;
  double AchancewithG = 0.0;
  double CchancewithA = 0.0;
  double CchancewithC = 0.0;
  double CchancewithT = 0.0;
  double CchancewithG = 0.0; //so many...
  double TchancewithA = 0.0;
  double TchancewithC = 0.0;
  double TchancewithT = 0.0;
  double TchancewithG = 0.0;
  double GchancewithA = 0.0;
  double GchancewithC = 0.0;
  double GchancewithT = 0.0;
  double GchancewithG = 0.0; //TOOO MANYY

  for (int i=0; i < DNA.size(); ++i){
    if (DNA[i] == 'a' || DNA[i] == 'A') { //bc I dunno how to lower case them all
      Achance += 1;
      if (DNA[i+1] != '\n'){ //Make sure not end of a line
        if (DNA[i+1] == 'a' || DNA[i+1] == 'A'){ //now to iterate through all combos that might appear
          nucleotideCount += 1; //Nucleotides are 2 DNA things
          AchancewithA += 1;
        }
        else if (DNA[i+1] == 'c' || DNA[i+1] == 'C'){ //now to iterate through all combos that might appear
          nucleotideCount += 1; //Nucleotides are 2 DNA things
          AchancewithC += 1;
        }
        else if (DNA[i+1] == 't' || DNA[i+1] == 'T'){ //now to iterate through all combos that might appear
          nucleotideCount += 1; //Nucleotides are 2 DNA things
          AchancewithT += 1;
        }
        else if (DNA[i+1] == 'g' || DNA[i+1] == 'G'){ //now to iterate through all combos that might appear
          nucleotideCount += 1; //Nucleotides are 2 DNA things
          AchancewithG += 1;
        }
      }
    }
    if (DNA[i] == 'c' || DNA[i] == 'C') { //bc I dunno how to lower case them all
      Cchance += 1;
      if (DNA[i+1] != '\n'){ //Make sure not end of a line
        if (DNA[i+1] == 'a' || DNA[i+1] == 'A'){ //now to iterate through all combos that might appear
          nucleotideCount += 1; //Nucleotides are 2 DNA things
          CchancewithA += 1;
        }
        else if (DNA[i+1] == 'c' || DNA[i+1] == 'C'){ //now to iterate through all combos that might appear
          nucleotideCount += 1; //Nucleotides are 2 DNA things
          CchancewithC += 1;
        }
        else if (DNA[i+1] == 't' || DNA[i+1] == 'T'){ //now to iterate through all combos that might appear
          nucleotideCount += 1; //Nucleotides are 2 DNA things
          CchancewithT += 1;
        }
        else if (DNA[i+1] == 'g' || DNA[i+1] == 'G'){ //now to iterate through all combos that might appear
          nucleotideCount += 1; //Nucleotides are 2 DNA things
          CchancewithG += 1;
        }
      }
    }
    if (DNA[i] == 't' || DNA[i] == 'T') { //bc I dunno how to lower case them all
      Tchance += 1;
      if (DNA[i+1] != '\n'){ //Make sure not end of a line
        if (DNA[i+1] == 'a' || DNA[i+1] == 'A'){ //now to iterate through all combos that might appear
          nucleotideCount += 1; //Nucleotides are 2 DNA things
          TchancewithA += 1;
        }
        else if (DNA[i+1] == 'c' || DNA[i+1] == 'C'){ //now to iterate through all combos that might appear
          nucleotideCount += 1; //Nucleotides are 2 DNA things
          TchancewithC += 1;
        }
        else if (DNA[i+1] == 't' || DNA[i+1] == 'T'){ //now to iterate through all combos that might appear
          nucleotideCount += 1; //Nucleotides are 2 DNA things
          TchancewithT += 1;
        }
        else if (DNA[i+1] == 'g' || DNA[i+1] == 'G'){ //now to iterate through all combos that might appear
          nucleotideCount += 1; //Nucleotides are 2 DNA things
          TchancewithG += 1;
        }
      }
    }
    if (DNA[i] == 'g' || DNA[i] == 'G') { //bc I dunno how to lower case them all
      Gchance += 1;
      if (DNA[i+1] != '\n'){ //Make sure not end of a line
        if (DNA[i+1] == 'a' || DNA[i+1] == 'A'){ //now to iterate through all combos that might appear
          nucleotideCount += 1; //Nucleotides are 2 DNA things
          GchancewithA += 1;
        }
        else if (DNA[i+1] == 'c' || DNA[i+1] == 'C'){ //now to iterate through all combos that might appear
          nucleotideCount += 1; //Nucleotides are 2 DNA things
          GchancewithC += 1;
        }
        else if (DNA[i+1] == 't' || DNA[i+1] == 'T'){ //now to iterate through all combos that might appear
          nucleotideCount += 1; //Nucleotides are 2 DNA things
          GchancewithT += 1;
        }
        else if (DNA[i+1] == 'g' || DNA[i+1] == 'G'){ //now to iterate through all combos that might appear
          nucleotideCount += 1; //Nucleotides are 2 DNA things
          GchancewithG += 1;
        }
      }
    }
  } //iterate through file }
  Achance = ((Achance/nucleotideCount)*100); //Calculate the probabilities
  Cchance = ((Cchance/nucleotideCount)*100);
  Tchance = ((Tchance/nucleotideCount)*100);
  Gchance = ((Gchance/nucleotideCount)*100);
  AchancewithA = ((AchancewithA/nucleotideCount)*100); //Here we go again...
  AchancewithC = ((AchancewithC/nucleotideCount)*100);
  AchancewithT = ((AchancewithT/nucleotideCount)*100);
  AchancewithG = ((AchancewithG/nucleotideCount)*100);
  CchancewithA = ((CchancewithA/nucleotideCount)*100);
  CchancewithC = ((CchancewithC/nucleotideCount)*100);
  CchancewithT = ((CchancewithT/nucleotideCount)*100);
  CchancewithG = ((CchancewithG/nucleotideCount)*100);
  TchancewithA = ((TchancewithA/nucleotideCount)*100);
  TchancewithC = ((TchancewithC/nucleotideCount)*100);
  TchancewithT = ((TchancewithT/nucleotideCount)*100);
  TchancewithG = ((TchancewithG/nucleotideCount)*100);
  GchancewithA = ((GchancewithA/nucleotideCount)*100);
  GchancewithC = ((GchancewithC/nucleotideCount)*100);
  GchancewithT = ((GchancewithT/nucleotideCount)*100);
  GchancewithG = ((GchancewithG/nucleotideCount)*100);
//And now once this is all calculated, it'll print to the file.
//It will also compute the relative probability of each nucleotide
//(A,C,T, or G), as well as the probability of each nucleotide bigram (AA, AC,
//AT, AG, CA, CC, CT, CG, etc) across the entire collection.
  outStream << "Probability of A: " << Achance << "% C: " << Cchance << "%  T: " << Tchance << "% G: " << Gchance << "%";
  outStream <<"\n Probability of AA: " << AchancewithA << "% AC: " << AchancewithC <<  "% AT: " << AchancewithT << "% AG: " << AchancewithG << "%\n";
  outStream <<"\n Probability of CA: " << CchancewithA << "% CC: " << CchancewithC <<  "% CT: " << CchancewithT << "% CG: " << CchancewithG << "%\n";
  outStream <<"\n Probability of TA: " << TchancewithA << "% TC: " << TchancewithC << "% TT: " << TchancewithT << "% TG: " << TchancewithG << "%\n";
  outStream <<"\n Probability of GA: " << GchancewithA << "% GC: " << GchancewithC <<  "% GT: " << GchancewithT << "% GG: " << GchancewithG << "%\n \n";

}

void DNACollection::guassianDistribution(ofstream& outStream){
  double x = ((double) rand()/(RAND_MAX));
  double y = ((double) rand()/(RAND_MAX));
  double z = (sqrt(-2*log(x)))*(cos(2*(M_PI)*y));
  double a = (standardDev*z)+ mean;

  for (int i = 0; i < 1000; ++i){ //creating 1000 lines appended onto file
    for (int b = 0; b < a; ++b){ //iterates through each single string a gaussian amount
      double size = rand() % 100; //Sets a random size from 1-100 (left over from division)
      if (size <= Achance) {
				outStream << "A";
			}
			else if (size <= (Achance + Cchance)) {
				outStream << "C";
			}
			else if (size <= (Achance + Cchance + Tchance)) {
				outStream << "T";
			}
			else if (size <= 100) {
				outStream << "G"; //Guassian building a string, size being of distribution
			}
		}
		outStream << "\n";
  }
}
