#include "Madlib.h"
#include <iostream>
#include <vector>

using namespace std;

Madlib::Madlib() {};
void Madlib::addOpperator (string t) {
    types.push_back(t);
}
void Madlib::addSentence (string s) {
    strs.push_back(s);
}
void Madlib::getUserInput(string ins[]) {
    
}