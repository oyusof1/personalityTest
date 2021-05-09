#ifndef _PERSONALITY_TEST_H
#define _PERSONALITY_TEST_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// personality test class
class personality_test {
public:
    vector<string> load_file(string fileName);
    string analyze_personality(vector<string> questions);
    void categorize_output(string);
private:
    
};

#endif
