#include <iostream>
#include <string>
#include "Madlib.h"
using namespace std;

int StorySelector(){
    int story;
    cout << "Select A story: " << endl;
    cout << "1,2,3,4,5" << endl;
    cin >> story;
    return story;
}

int main()
{
    cout<< "Welcome to the Madlibs App." << endl;
    StorySelector();
    return 0;
}