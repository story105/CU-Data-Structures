#include <iostream>
#include <fstream>

using namespace std;

class GameofLife{
  private:
    string Extra;
    string StringToOutput; //Output type
    string FileOutput; //if necessary to print to a file
    int turnCount;
  public:
    GameofLife();
    ~GameofLife();

    void chooseMode(int& rows, int& columns, char**& board);//double pointer to get a two dimensional array "board"
    void selectModeSetting(); //Just outputs data choice
//all apersands meaning all references to rows and columns, once assigned to a #
//always relate back to that # instead of making a copy
    int normalmode(int rows, int columns, char**& board); //game types
    int doughnutmode(int rows, int columns, char**& board);
    int mirrormode(int rows, int columns, char**& board);

    void createUserBoard(string userInput); //file input
    void createBoard(int& rows, int& columns); //creating board from variables inputted
//FIGURE PRINTING TO SCREEN
    void printToScreen(string StringToOutput, int turnCount, char**& board, int rows, int columns);
};
