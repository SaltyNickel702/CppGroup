#include <iostream>
#include <string>
#include "Madlib.h"
using namespace std;

void story2() {
    
    /*Skiing Adventure Mad Libs

One cold, wintery day, my friends and I decided to go skiing at (place). We were all so (emotion) because it was our first time skiing. As we got ready, I put on my (color) (piece of clothing) and grabbed my (noun). I couldn’t wait to hit the slopes!

The ski lift ride was (adjective) and we could see the entire (noun) from above. As we reached the top, my friend (name) said, "Let's race to the bottom!" We all (verb) down the mountain, but halfway down, I accidentally (verb) and crashed into a (noun)! It was (adjective), but I quickly got up and kept going.

At the end of the day, we were all (emotion) but had the best time ever! I can't wait to go skiing again with my (family member)!*/

}
int StorySelector() { // call This to ask the user what story they want to run (1 - 4). returns that integer.
    cout << "Type the number for your wanted story (1-4): "<< endl;
    cin >> story;
    return story;
}

int main() {
    //Demo of how to use files
    Madlib demo;
    demo.getFromFile("demo");
    demo.getUserInput();
    cout << demo.getOutput();

    return 0;
}