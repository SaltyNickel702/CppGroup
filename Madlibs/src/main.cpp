#include <iostream>
#include <string>
#include "Madlib.h"
using namespace std;

int StorySelector() {
    cout << "Select One of the following stories: "<< endl;
    cout << "   1: Space" << endl;
    cout << "   2: Skiing" << endl;
    cout << "   3: Jumanji" << endl;
    cout << "   4: Wizard" << endl;
    int story;
    cin >> story;
    return story;
}
void story1() {
    Madlib space;
    space.getFromFile("Space");
    space.getUserInput();
    cout << space.getOutput();
}
void story2() {
    Madlib story2;
    story2.getFromFile("skiing");
    story2.getUserInput();
    cout << story2.getOutput();
}
void story3() {
    Madlib jumanji;
    jumanji.getFromFile("EscapeRoom");
    jumanji.getUserInput();
    cout << jumanji.getOutput();
}
void story4() { //Placeholder until David makes a mad lib
    Madlib wizard;
    wizard.getFromFile("Wizard");
    wizard.getUserInput();
    cout << wizard.getOutput();
}


int main() {
    bool running = true;
    while (running) {
        int SelectedStory = StorySelector();
        switch (SelectedStory) {
            case 1:
                //story 1 not generated
                cout << "Space Story Selected" << endl;
                story1();
                break;
            case 2:
                cout << "Skiing Story Selected" << endl;
                story2();
                break;
            case 3:
            // story 3 not generated
                cout << "Jumanji Story Selected" << endl;
                story3();
                break;
            case 4:
            // Story 4 not generated yet
                cout << "Wizard Story Selected" << endl;
                story4();
                break;
            default:
                cout << SelectedStory << " was not recognized" << endl;
                continue;
        }
        cout << endl << "Do you want to play again? (Y/N)" << endl << "? ";
        char i;
        cin >> i;
        if (!(i == 'Y' || i == 'y')) {
            if (!(i == 'N' || i =='n')) cout << i << " was not recognized" << endl;
            cout << "Exiting" << endl;
            running = false;
        } else cout << endl;
    }
    

    return 0;
}
