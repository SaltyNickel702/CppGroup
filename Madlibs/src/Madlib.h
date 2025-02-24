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
        
        void addOpperator (string Type); //Adds filler word | Type is (noun, number, adjective, etc)
        void addSentence (string s); //Adds string between filler words

        void getUserInput(); //add list of all user inputs
        string getOutput(); //returns filled string

        static Madlib getFromFile (string fileName); //Ill try to get this to word as soon as everything else works
};

#endif