#ifndef _PERSONALITY_TEST_H
#define _PERSONALITY_TEST_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

// personality test class
class personality_test {
public:
    vector<string> load_file(ifstream& fileName);
    void run_test();
    string analyze_personality();
    void categorize_output(string);
    void save_output(string);
    

private:
    
};

#endif
