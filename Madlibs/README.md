# Madlib C++ Build
## Build Info
Inside of ./build/, there will be an out.app file for MacOS users. We couldn't get the G++ compile statement to work, so the only way to compile is through CMake, which you have to install first<br>
<br>
To compile with CMake, just run sh buildCMake.sh<br>
<br>
## How we coded it
Madlip.h defines the Madlib class, which is used to store madlibs. Inside of the class, there are three c++ vectors, one for sentences, and an input type that gets appeneded between sentences. The third vector is for user inputs that replace the types. To get an output, we loop through the sentence vector, add each sentence to a string, then add the user input, then continue the loop.<br>
<br>
Also added a method that auto-populates the madlib class from a txt file stored in ${ROOT}/madlibs/. Inside of "example.txt", inputed words are signified using [brackets], with the type of word inside of the brackets. To populate the madlib instance, create an instance, and call .getFromFile("example").<br>
<br>
To get userinput, we simply call .getUserInput, which loops through all types, and askes the user for each type of word. The input is then stored in the inputs vector until needed.
<br>
## Contributors
- Niko: Madlib class coding
- Sean: Created the skiing Madlib and implemented it into the code
- Ulisses: Created Story selector and debugging