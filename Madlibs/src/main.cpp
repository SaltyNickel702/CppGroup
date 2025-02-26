#include <iostream>
#include <string>
#include "Madlib.h"
using namespace std;

int StorySelector() {
    cout << "Select One of the following stories: "<< endl;
    cout << "   1: TDB" << endl;
    cout << "   2: Skiing" << endl;
    cout << "   3: TDB" << endl;
    cout << "   4: TDB" << endl;
    int story;
    cin >> story;
    return story;
}
void story2() {
    Madlib story2;
    story2.getFromFile("skiing");
    story2.getUserInput();
    cout << story2.getOutput();
}


int main() {
    //Demo of how to use files
    Madlib demo;
    demo.getFromFile("demo");
    cout << demo.getOutput();

    return 0;
}