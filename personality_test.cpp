#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "personality_test.h"

using namespace std;

vector<string> personality_test::load_file(ifstream& fileName) {
    vector<string> questionLoad; 
    int i = 0;
    string line;

    while (getline(fileName, line, '?')) 
    {
        if(line.size() > 0)
            questionLoad.push_back(line);
    }
    
    fileName.close();

    return questionLoad;
}


void personality_test::run_test() {
    //create string to output
    string output = analyze_personality();

    //output string to console
    categorize_output(output);
}


/* Analyze Personality Method
 * 1) Ask user one question at a time
 * 2) Read in user's response and construct a vector containing the responses
 * 3) Analyze the responses to construct a personality type (eg. ENFJ)
 * @param None
 * @return string
 * */
string personality_test::analyze_personality() {
    
    string output = "";
    return output;
}

/* Categorize Output Method
 * 1) Read in the analysis.txt file
 * 2) Provided a user's personality type, print out to console the user's personality description
 * @param Personality type string (eg. "ENFJ")
 * @return None, Text to console
 */
void personality_test::categorize_output(string my_personality) {
    //TODO
}

/* Save Output
 * 1) Ask user to save or not
 * 2) If yes, ask for a file name and save the results
 * @param string (the thing to write)
 * @return None, creates a file
 */
void personality_test::save_output(string output) {
    //TODO
}
