 //s and fstream allow readind and writing of files.
#include <fstream> //Reading writing
#include <string>
#include <iostream>

using namespace std;

//need an if stream
//FILEIN IS THE USER INPUTTED FILE

class DNACollection {
private:
  string DNA;
  int lineCount;
  double nucleotideCount;
  double sum;
  double mean;
  double variance;
  double standardDev;
  double nucleotideTotal; //to have a total for all files inputted
  double Achance;
  double Cchance;
  double Tchance;
  double Gchance; //all the nucleotide singular probabilities
public: //I WAS AVING SO MANY ERRORS "DNACollection is private BY DEFAULT APPARENTLY"
  void DNAInputFile(ifstream& inStream); //Take input from the file
	void ComputeCollection(ofstream& outStream); // (Sum/Mean/Variance/StandardDev) output
	void nucleotideProbability(ofstream& outStream); //Probability of each Nucleotide
	void guassianDistribution(ofstream& outStream); //Newly generated sequences

  void ErrorControl(ofstream& outStream); //I dunno if I know how to exception handle properly

  DNACollection();
  ~DNACollection(); //Construct and destruct

}; //end needs semi
