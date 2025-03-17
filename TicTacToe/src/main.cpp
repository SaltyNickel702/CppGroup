#include <iostream>
#include "Board.h"
using namespace std;

int main()
{
    Board game;
    bool play = true;
    bool run = true;
    cout << "Welcome to Tic Tac Toe"<< endl;
    cout << "input Q to leave game."<< endl;
    while(run)
    {
        game.refreshBoard();
        while(play){
            cout<<"Board is positioned 1-9. type Number + x or o "<<endl;
            cout<<"Middle Square Example : 5x"<<endl;
            game.dispGL();
            string input;
            cin >> input;
            if(input == "q" || input == "Q")
            {
                cout << "Exiting Game" << endl;
                play = false;
            }
            if (input == "1x")
            {
                game.drawX1();
                input.clear();
            }
            if (input == "2x")
            {
                game.drawX2();
                input.clear();
            }
            if (input == "3x")
            {
                game.drawX3();
                input.clear();
            }
            if (input == "4x")
            {
                game.drawX4();
                input.clear();
            }
            if (input == "5x")
            {
                game.drawX5();
                input.clear();
            }
            if (input == "6x")
            {
                game.drawX6();
                input.clear();
            }
            if (input == "7x")
            {
                game.drawX7();
                input.clear();
            }
            if (input == "8x")
            {
                game.drawX8();
                input.clear();
            }
            if (input == "9x")
            {
                game.drawX9();
                input.clear();
            }
            if (input == "1o")
            {
                game.drawO1();
                input.clear();
            }
            if (input == "2o")
            {
                game.drawO2();
                input.clear();
            }
            if (input == "3o")
            {
                game.drawO3();
                input.clear();
            }
            if (input == "4o")
            {
                game.drawO4();
                input.clear();
            }
            if (input == "5o")
            {
                game.drawO5();
                input.clear();
            }
            if (input == "6o")
            {
                game.drawO6();
                input.clear();
            }
            if (input == "7o")
            {
                game.drawO7();
                input.clear();
            }
            if (input == "8o")
            {
                game.drawO8();
                input.clear();
            }
            if (input == "9o")
            {
                game.drawO9();
                input.clear();
            }
            if (game.checkXWin() || game.checkOWin() || game.checkGameDraw()){
                cout<<"Game over."<<endl;
                play = false;
            }
            game.refreshBoard();
        }
        string inpt;
        cout<<"would you like to play again? (y/n)"<< endl;
        cin>>inpt;
        if (inpt == "y" || inpt == "Y"){
            cout<<"Resetting Game."<< endl;
            game.resetBoard();
            play = true;
        } else if (inpt == "n" || inpt == "N"){
            cout<<"Exiting Game."<<endl;
            return 0;
        } else{
            cout<<"enter a valid response"<<endl;
        }
    }
    return 0;
}