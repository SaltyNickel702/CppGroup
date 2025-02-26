#include <iostream>
#include <string>
#include "Madlib.h"
using namespace std;

int StorySelector() {
    cout << "Type the number for your wanted story (1-4): "<< endl;
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
    int storySelection
    //Demo of how to use files
    Madlib demo;
    demo.getFromFile("demo");
    demo.getUserInput();
    cout << demo.getOutput();

    return 0;
}