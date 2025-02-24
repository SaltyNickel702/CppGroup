#include <vector>
#include <iostream>
using namespace std;

#ifndef MADLIB_H
#define MADLIB_H

class Madlib {
    private:
        vector<string> types;
        vector<string> inputs;
        vector<string> strs;

        int inputIndex = 0;
    public:
        Madlib();
        
        void addOperator (string Type); //Adds filler word | Type is (noun, number, adjective, etc)
        void addSentence (string s); //Adds string between filler words

        void getUserInput(); //add list of all user inputs
        string getOutput(); //returns filled string

        int getFromFile (string madlibName); //create a new madlib, and call this method to fill in all values | madlibName does not include .txt | returns -1 if errors
};

#endif
