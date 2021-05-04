#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "personality_test.h"

using namespace std;

//Prints out welcome banner
void printBanner() {
    cout << "====================================" << endl;
    cout << "  Welcome to our Personality Test!" << endl;
    cout << "====================================" << endl << endl;
}

int main() {
    //initialize test object
    personality_test test;

    //initialize vector
    vector<string> questionList;

    //initialize file for questions
    ifstream inData("question.txt");
    
    //test if the file is open
    if(!inData)  {
        cout<<"Error opening question file.\n Please check if you have the 'questions.txt' file. "<< endl;
        system("pause");
        return -1;
    } 
    else {
        questionList = test.load_file(inData);
    }

     printBanner();

    for (int j = 0; j < questionList.size(); j++) {
        cout << questionList[j] << endl;
    }
    
    
    // questionList = load_file(inData);
    
    //test.printout();
    //test.run_test();

}

