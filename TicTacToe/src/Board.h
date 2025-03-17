#ifndef BOARD_H
#define BOARD_H
#include <string>
#include <vector>
using namespace std;

class Board
{
private:
    vector<string> board0 = {"############################"};
    vector<string> board1 = {"#","        ","#","        ","#","        ","#"};
    vector<string> board2 = {"#","        ","#","        ","#","        ","#"};
    vector<string> board3 = {"#","        ","#","        ","#","        ","#"};
    vector<string> board4 = {"#","        ","#","        ","#","        ","#"};
    vector<string> board5 = {"############################"};
    vector<string> board6 = {"#","        ","#","        ","#","        ","#"};
    vector<string> board7 = {"#","        ","#","        ","#","        ","#"};
    vector<string> board8 = {"#","        ","#","        ","#","        ","#"};
    vector<string> board9 = {"#","        ","#","        ","#","        ","#"};
    vector<string> board10 = {"############################"};
    vector<string> board11 = {"#","        ","#","        ","#","        ","#"};
    vector<string> board12 = {"#","        ","#","        ","#","        ","#"};
    vector<string> board13 = {"#","        ","#","        ","#","        ","#"};
    vector<string> board14 = {"#","        ","#","        ","#","        ","#"};
    vector<string> board15 = {"############################"};
    vector<vector<string>> gameVec = {
        {" ", " ", " "},
        {" ", " ", " "},
        {" ", " ", " "}
    };
public:
    Board();
    
    bool checkGameDraw();
    void resetBoard();
    void dispGL();
    void refreshBoard();
    void drawX1();
    void drawX2();
    void drawX3();
    void drawX4();
    void drawX5();
    void drawX6();
    void drawX7();
    void drawX8();
    void drawX9();
    void drawO1();
    void drawO2();
    void drawO3();
    void drawO4();
    void drawO5();
    void drawO6();
    void drawO7();
    void drawO8();
    void drawO9();
    bool checkXWin();
    bool checkOWin();
};
#endif