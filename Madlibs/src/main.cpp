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
void story1() {

}
void story2() {
    Madlib story2;
    story2.getFromFile("skiing");
    story2.getUserInput();
    cout << story2.getOutput();
}
void story3() {

}
void story4() {
    
}


int main() {
    int SelectedStory = StorySelector();
    switch (SelectedStory) {
        case 1:
        //story 1 not generated
        cout << "TBD Story Selected" << endl;
        story1();
          break;
        case 2:
        cout << "Skiing Story Selected" << endl;
        story2();
          break;
        case 3:
        // story 3 not generated
        cout << "TBD Story Selected" << endl;
        story3();
          break;
        case 4:
        // Story 4 not generated yet
        cout << "TBD Story Selected" << endl;
        story4();
          break;
    }
    //Demo of how to use files
    Madlib demo;
    demo.getFromFile("demo");
    cout << demo.getOutput();

    return 0;
}