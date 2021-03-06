#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "personality_test.h"


using namespace std;

void printBanner() {
    cout << "====================================" << endl;
    cout << "  Welcome to our Personality Test!" << endl;
    cout << "      12 Questions to Analyze      " << endl;
    cout << "          Your Personality!         " << endl;
    cout << "====================================" << endl << endl;
}

//Prints out instructions
void printInstructions() {
    cout << "*Note*" << endl;
    cout << "Answer each question with \"1\" for true, and \"0\" for false"
        << " based on your preference." << endl << endl;
}

bool thankYou() {
    bool playAgain = false;
    cout << "  Thank You for Taking Our Test" << endl;
    cout << " Enter 0 to Take Again or 1 to Exit " << endl;
    cout << "====================================" << endl << endl;

    cin >> playAgain;
    return playAgain;
}

int main() {

    bool playAgain = false;
    while (!playAgain) {
    //initialize test object
    personality_test test;

    //initialize vector
    vector<string> questionList;

    //initialize file for questions and test if both files are loaded
    string fileName = "questions.txt";
    ifstream inData(fileName);
    ifstream inData2("analysis.txt");


    //test if the file is open and redirect if file not found
    if(!inData || !inData2)  {
        cout << "Error opening question file.\n Please check if you have the 'questions.txt' and 'analysis.txt' file." << endl;
        system("pause");
        return -1;
    } 
    else {
        questionList = test.load_file(fileName);
    }

    //call banner and instructions output
    printBanner();
    printInstructions();

    //start test and save string output 
    string personalityType = test.analyze_personality(questionList);


    //clear screen and display output
    cout << string( 100, '\n' );
    test.categorize_output(personalityType);
    playAgain = thankYou();
    }
        
}

