#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <limits>
#include "personality_test.h"

using namespace std;

//load file to get questions
vector<string> personality_test::load_file(string fileName) {
    vector<string> questionLoad; 
    
    //initialize file for questions
    ifstream inData;
    string line;
    inData.open(fileName);

    while (getline(inData, line)) 
    {
        if(line.size() > 0)
            questionLoad.push_back(line);
    }
    
    inData.close();

    return questionLoad;
}

//Run the test and find personality type
string personality_test::analyze_personality(vector<string> questions) {
 
    //string for personality type
    string personalityType = "";

    //8 subtypes
    int I = 0, E = 0, N = 0, S = 0, F = 0, T = 0, P = 0, J = 0;
    
    //create vector to hold answers
    vector<bool> answerVector;
    bool input;

    //ask questions and save responses
    for (int i = 0; i < questions.size(); i++) {
        for (;;) {
            cout << questions[i] << endl;
            if (cin >> input) {
                answerVector.push_back(input);
                break;
            } else {
                cout << "Invalid response" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
            }
        }
    }

    //increment personality subtype scores based on response
    for (int k = 0; k < answerVector.size(); k++) {
        if (questions[k].at(0) == '$') {
            if (answerVector[k] == 0) {
                E += 1;
            } else {
                I += 1;
            }
        }
        else if (questions[k].at(0) == '1') {
            if (answerVector[k] == 0) {
                I += 1;
            } else {
                E += 1;
            }
        }
        else if (questions[k].at(0) == '!') {
            if (answerVector[k] == 0) {
                N += 1;
            } else {
                S += 1;
            }
        }
        else if (questions[k].at(0) == '2') {
            if (answerVector[k] == 0) {
                S += 1;
            } else {
                N += 1;
            }
        }
        else if (questions[k].at(0) == '@') {
            if (answerVector[k] == 0) {
                T += 1;
            } else {
                F += 1;
            }
        }
        else if (questions[k].at(0) == '3') {
            if (answerVector[k] == 0) {
                F += 1;
            } else {
                T += 1;
            }
        }
        else if (questions[k].at(0) == '%') {
            if (answerVector[k] == 0) {
                J += 1;
            } else {
                P += 1;
            }
        }
        else if (questions[k].at(0) == '4') {
            if (answerVector[k] == 0) {
                P += 1;
            } else {
                J += 1;
            }
        }
    }
    
    //finalize personality type based on test and create personality type string
    if (I >= 2) {
        personalityType += "I";
    }
    if (E >= 2) {
        personalityType += "E";
    }
    if (S >= 2) {
        personalityType += "S";
    }
    if (N >= 2) {
        personalityType += "N";
    }
    if (F >= 2) {
        personalityType += "F";
    }
    if (T >= 2) {
        personalityType += "T";
    }
    if (P >= 2) {
        personalityType += "P";
    }
    if (J >= 2) {
        personalityType += "J";
    }
    
    return personalityType;
}

/* 1) Read in the analysis.txt file
 * 2) Provided a user's personality type, print out to console the user's personality description */
void personality_test::categorize_output(string myPersonality) {
    vector<string> personalityTypes;
    ifstream inData("analysis.txt");
    string line ="";
    string category;
    string type;
    string description;

    while (getline(inData, line)) 
    {
        if(line.size() > 0)
            personalityTypes.push_back(line);
    }
    inData.close();
    

    for (int i = 0; i < personalityTypes.size(); i++) {
       istringstream iss(personalityTypes.at(i));
       string first_word;
       iss >> first_word;
       if (first_word == myPersonality) {
           iss >> category >> type;
           getline(iss, description);
       }
}
 
    

    cout << "====================" << endl; 
    cout << "Your personality type: " << myPersonality << endl;
    cout << "The category is: " << category << endl;
    cout << "You are: The " << type << endl;
    cout << "Description: " << description << endl;

}

/* 1) Ask user to save or not
 * 2) If yes, ask for a file name and save the results
 */
void personality_test::save_output(string output) {
    //TODO
}
