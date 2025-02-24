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
string Madlib::getOut() {
    string out;
    for (int i = 0; i < strs.size(); i++) {
        out.append(strs.at(i) + " ");
        if (i < inputs.size()) {
            out.append(inputs.at(i) + " ");
        } else if (i < types.size()) {
            out.append("[" + types.at(i) + "] ");
        } else {
            out.append("[null] ");
        }
    }
    return out;
}