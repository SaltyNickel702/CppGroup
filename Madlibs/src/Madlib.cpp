#include "Madlib.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

Madlib::Madlib() {};
void Madlib::addOperator (string t) {
    types.push_back(t);
}
void Madlib::addSentence (string s) {
    strs.push_back(s);
}
void Madlib::getUserInput() {
    for (int i = 0; i < types.size(); i++) {
        cout << "Give me a " << types.at(i) << ": ";
        string in;
        getline(cin,in);
        inputs.push_back(in);
    }
}
string Madlib::getOutput() {
    string out;
    for (int i = 0; i < strs.size(); i++) {
        out.append(strs.at(i));
        if (i < inputs.size()) {
            out.append(inputs.at(i));
        } else if (i < types.size()) {
            out.append("[" + types.at(i) + "]");
        }
    }
    return out;
}
int Madlib::getFromFile (string madlibName) {
    string line;
    ifstream file("../madlibs/" + madlibName + ".txt");
    if (!file.is_open()) {
        cout << "Error: Did not find madlib file" << endl;
        return -1;
    };
    bool appendToLast = false; //in case string is multiple lines long
    while (getline(file,line)) {
        bool sent = true; //look for sentence or word identifier
        string cur = "";
        if (line.size()<=0) {continue;} // Fix error if the line is empty
        for (int i = 0; i < line.size(); i++) {
            char c = line.at(i);
            if (sent) {
                //look for [
                if (c == '[') {
                    if (appendToLast) {
                        strs.back().append(cur);
                        appendToLast = false;
                    } else addSentence(cur);
                    cur = "";
                    sent = false;
                } else cur+=c;
            } else {
                //look for ]
                if (c == ']') {
                    addOperator(cur);
                    cur = "";
                    sent = true;
                } else cur+=c;
            }
        }
        
        if (cur != "") {
            addSentence(cur);
            appendToLast = true;
        }
        strs.back() += '\n';
    }

    return 0;
}
