#ifndef MADLIB_H
#define MADLIB_H

#include <vector>
#include <iostream>
using namespace std;

class Madlib {
    private:
        vector<string> types;
        vector<string> inputs;
        vector<string> strs;

        int inputIndex = 0;
    public:
        Madlib();
        
        void addOpperator (string type); //Adds filler word | Type is (noun, number, adjective, etc)
        void addSentence (string s); //Adds string between filler words


        void fill(string ins[]); //add list of all user inputs
        string getOut(); //returns filled string
};

#endif