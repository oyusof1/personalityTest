#include <iostream>

using namespace std;


//Prints out welcome banner
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