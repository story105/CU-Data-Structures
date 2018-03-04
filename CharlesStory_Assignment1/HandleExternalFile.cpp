#include <sstream>
#include <fstream>
#include <string>
#include <iostream> //s and fstream allow readind and writing of files.

using namespace std;

//need an if stream
//FILEIN IS THE USER INPUTTED FILE

class DNACollection {
  string dna;
  int lineCount;
  double bigramCount;
  double nucleotideCount;
  double sum;
  double mean;
  double variance;
  double standardDev;
  double nucleotideTotal; //???
  double Achance;
  double Cchance;
  double Tchance;
  double Gchance; //all the nucleotide singular probabilities

  DNACollection();
  ~DNACollection(); //Construct and destruct

  void dnaInputFile(ifstream& inStream); //Take input from the file
	void ComputeCollection(ofstream& outStream); // (Sum/Mean/Variance/StandardDev)
	void nucleotideProbability(ofstream& outStream); //Probability of each Nucleotide
	void guassianDistribution(ofstream& outStream); //Newly generated sequences
};
