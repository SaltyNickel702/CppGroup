#include "Board.h"
#include <iostream>
using namespace std;

Board::Board() {};

void Board::refreshBoard()
{
    cout<<board0[0]<<endl;
    cout <<board1[0]<<board1[1]<<board1[2]<<board1[3]<<board1[4]<<board1[5]<<board1[6]<<endl;
    cout <<board2[0]<<board2[1]<<board2[2]<<board2[3]<<board2[4]<<board2[5]<<board2[6]<<endl;
    cout <<board3[0]<<board3[1]<<board3[2]<<board3[3]<<board3[4]<<board3[5]<<board3[6]<<endl;
    cout <<board4[0]<<board4[1]<<board4[2]<<board4[3]<<board4[4]<<board4[5]<<board4[6]<<endl;
    cout<<board5[0]<<endl;
    cout <<board6[0]<<board6[1]<<board6[2]<<board6[3]<<board6[4]<<board6[5]<<board6[6]<<endl;
    cout <<board7[0]<<board7[1]<<board7[2]<<board7[3]<<board7[4]<<board7[5]<<board7[6]<<endl;
    cout <<board8[0]<<board8[1]<<board8[2]<<board8[3]<<board8[4]<<board8[5]<<board8[6]<<endl;
    cout <<board9[0]<<board9[1]<<board9[2]<<board9[3]<<board9[4]<<board9[5]<<board9[6]<<endl;
    cout<<board10[0]<<endl;
    cout <<board11[0]<<board11[1]<<board11[2]<<board11[3]<<board11[4]<<board11[5]<<board11[6]<<endl;
    cout <<board12[0]<<board12[1]<<board12[2]<<board12[3]<<board12[4]<<board12[5]<<board12[6]<<endl;
    cout <<board13[0]<<board13[1]<<board13[2]<<board13[3]<<board13[4]<<board13[5]<<board13[6]<<endl;
    cout <<board14[0]<<board14[1]<<board14[2]<<board14[3]<<board14[4]<<board14[5]<<board14[6]<<endl;
    cout << board15[0]<< endl;
};

bool Board::checkGameDraw(){
    int counter = 0;
    int gvloc1 = gameVec[0][0].find(" ");
    if (gvloc1 != string::npos){
        counter += 1;
    }
    int gvloc2 = gameVec[0][1].find(" ");
    if (gvloc2 != string::npos){
        counter += 1;
    }
    int gvloc3 = gameVec[0][2].find(" ");
    if (gvloc3 != string::npos){
        counter += 1;
    }
    int gvloc4 = gameVec[1][0].find(" ");
    if (gvloc4 != string::npos){
        counter += 1;
    }
    int gvloc5 = gameVec[1][1].find(" ");
    if (gvloc5 != string::npos){
        counter += 1;
    }
    int gvloc6 = gameVec[1][2].find(" ");
    if (gvloc6 != string::npos){
        counter += 1;
    }
    int gvloc7 = gameVec[2][0].find(" ");
    if (gvloc7 != string::npos){
        counter += 1;
    }
    int gvloc8 = gameVec[2][1].find(" ");
    if (gvloc8 != string::npos){
        counter += 1;
    }
    int gvloc9 = gameVec[2][2].find(" ");
    if (gvloc9 != string::npos){
        counter += 1;
    }
    if (counter == 0){
        return true;
    } else {
        return false;
    }
};

void Board::resetBoard(){
    board1[1] = "        "; board1[3] = "        "; board1[5] = "        ";
    board2[1] = "        "; board2[3] = "        "; board2[5] = "        ";
    board3[1] = "        "; board3[3] = "        "; board3[5] = "        ";
    board4[1] = "        "; board4[3] = "        "; board4[5] = "        ";
    board6[1] = "        "; board6[3] = "        "; board6[5] = "        ";
    board7[1] = "        "; board7[3] = "        "; board7[5] = "        ";
    board8[1] = "        "; board8[3] = "        "; board8[5] = "        ";
    board9[1] = "        "; board9[3] = "        "; board9[5] = "        ";
    board11[1] = "        "; board11[3] = "        "; board11[5] = "        ";
    board12[1] = "        "; board12[3] = "        "; board12[5] = "        ";
    board13[1] = "        "; board13[3] = "        "; board13[5] = "        ";
    board14[1] = "        "; board14[3] = "        "; board14[5] = "        ";
    gameVec[0][0] = " ";
    gameVec[0][1] = " ";
    gameVec[0][2] = " ";
    gameVec[1][0] = " ";
    gameVec[1][1] = " ";
    gameVec[1][2] = " ";
    gameVec[2][0] = " ";
    gameVec[2][1] = " ";
    gameVec[2][2] = " ";
};

bool Board::checkXWin(){
    bool xWin = false;
    if(gameVec[0][0] == "X" && gameVec[0][1] == "X" && gameVec[0][2] == "X"){
        xWin = true;
        return xWin;
    }
    if(gameVec[1][0] == "X" && gameVec[1][1] == "X" && gameVec[1][2] == "X"){
        xWin = true;
        return xWin;
    }
    if(gameVec[2][0] == "X" && gameVec[2][1] == "X" && gameVec[2][2] == "X"){
        xWin = true;
        return xWin;
    }
    if(gameVec[0][0] == "X" && gameVec[1][0] == "X" && gameVec[2][0] == "X"){
        xWin = true;
        return xWin;
    }
    if(gameVec[0][1] == "X" && gameVec[1][1] == "X" && gameVec[2][1] == "X"){
        xWin = true;
        return xWin;
    }
    if(gameVec[0][2] == "X" && gameVec[1][2] == "X" && gameVec[2][2] == "X"){
        xWin = true;
        return xWin;
    }
    if(gameVec[0][0] == "X" && gameVec[1][1] == "X" && gameVec[2][2] == "X"){
        xWin = true;
        return xWin;
    }
    if(gameVec[0][2] == "X" && gameVec[1][1] == "X" && gameVec[2][0] == "X"){
        xWin = true;
        return xWin;
    }
    return xWin;
};

bool Board::checkOWin(){
    bool OWin = false;
    if(gameVec[0][0] == "O" && gameVec[0][1] == "O" && gameVec[0][2] == "O"){
        OWin = true;
        return OWin;
    }
    if(gameVec[1][0] == "O" && gameVec[1][1] == "O" && gameVec[1][2] == "O"){
        OWin = true;
        return OWin;
    }
    if(gameVec[2][0] == "O" && gameVec[2][1] == "O" && gameVec[2][2] == "O"){
        OWin = true;
        return OWin;
    }
    if(gameVec[0][0] == "O" && gameVec[1][0] == "O" && gameVec[2][0] == "O"){
        OWin = true;
        return OWin;
    }
    if(gameVec[0][1] == "O" && gameVec[1][1] == "O" && gameVec[2][1] == "O"){
        OWin = true;
        return OWin;
    }
    if(gameVec[0][2] == "O" && gameVec[1][2] == "O" && gameVec[2][2] == "O"){
        OWin = true;
        return OWin;
    }
    if(gameVec[0][0] == "O" && gameVec[1][1] == "O" && gameVec[2][2] == "O"){
        OWin = true;
        return OWin;
    }
    if(gameVec[0][2] == "O" && gameVec[1][1] == "O" && gameVec[2][0] == "O"){
        OWin = true;
        return OWin;
    }
    return OWin;
};

void Board::dispGL(){
    cout<<gameVec[0][0]<<gameVec[0][1]<<gameVec[0][2]<<endl;
    cout<<gameVec[1][0]<<gameVec[1][1]<<gameVec[1][2]<<endl;
    cout<<gameVec[2][0]<<gameVec[2][1]<<gameVec[2][2]<<endl;
};

void Board::drawX1()
{
    int gvloc = gameVec[0][0].find(" ");
    if (gvloc != string::npos){
        gameVec[0][0] = "X";
    }
    int bp1 = board1[1].find("        ");
    if(bp1 != string::npos)
    {
        board1[1].replace(0,8,"  \\  /  ");
    }
    
    int bp2 = board2[1].find("        ");
    if(bp2 != string::npos)
    {
        board2[1].replace(0,8,"   \\/   ");
    }
     
    int bp3 = board3[1].find("        ");
    if(bp3 != string::npos)
    {
        board3[1].replace(0,8,"   /\\   ");
    }
    
    int bp4 = board4[1].find("        ");
    if(bp4 != string::npos)
    {
        board4[1].replace(0,8,"  /  \\  ");
    }
};

void Board::drawX2()
{
    int gvloc = gameVec[0][1].find(" ");
    if (gvloc != string::npos){
        gameVec[0][1] = "X";
    }
    int bp1 = board1[3].find("        ");
    if(bp1 != string::npos)
    {
        board1[3].replace(0,8,"  \\  /  ");
    }
    
    int bp2 = board2[3].find("        ");
    if(bp2 != string::npos)
    {
        board2[3].replace(0,8,"   \\/   ");
    }
     
    int bp3 = board3[3].find("        ");
    if(bp3 != string::npos)
    {
        board3[3].replace(0,8,"   /\\   ");
    }
    
    int bp4 = board4[3].find("        ");
    if(bp4 != string::npos)
    {
        board4[3].replace(0,8,"  /  \\  ");
    }
};

void Board::drawX3()
{
    int gvloc = gameVec[0][2].find(" ");
    if (gvloc != string::npos){
        gameVec[0][2] = "X";
    }
    int bp1 = board1[5].find("        ");
    if(bp1 != string::npos)
    {
        board1[5].replace(0,8,"  \\  /  ");
    }
    
    int bp2 = board2[5].find("        ");
    if(bp2 != string::npos)
    {
        board2[5].replace(0,8,"   \\/   ");
    }
     
    int bp3 = board3[5].find("        ");
    if(bp3 != string::npos)
    {
        board3[5].replace(0,8,"   /\\   ");
    }
    
    int bp4 = board4[5].find("        ");
    if(bp4 != string::npos)
    {
        board4[5].replace(0,8,"  /  \\  ");
    }
};

void Board::drawX4()
{
    int gvloc = gameVec[1][0].find(" ");
    if (gvloc != string::npos){
        gameVec[1][0] = "X";
    }
    int bp1 = board6[1].find("        ");
    if(bp1 != string::npos)
    {
        board6[1].replace(0,8,"  \\  /  ");
    }
    
    int bp2 = board7[1].find("        ");
    if(bp2 != string::npos)
    {
        board7[1].replace(0,8,"   \\/   ");
    }
     
    int bp3 = board8[1].find("        ");
    if(bp3 != string::npos)
    {
        board8[1].replace(0,8,"   /\\   ");
    }
    
    int bp4 = board9[1].find("        ");
    if(bp4 != string::npos)
    {
        board9[1].replace(0,8,"  /  \\  ");
    }
};

void Board::drawX5()
{
    int gvloc = gameVec[1][1].find(" ");
    if (gvloc != string::npos){
        gameVec[1][1] = "X";
    }
    int bp1 = board6[3].find("        ");
    if(bp1 != string::npos)
    {
        board6[3].replace(0,8,"  \\  /  ");
    }
    
    int bp2 = board7[3].find("        ");
    if(bp2 != string::npos)
    {
        board7[3].replace(0,8,"   \\/   ");
    }
     
    int bp3 = board8[3].find("        ");
    if(bp3 != string::npos)
    {
        board8[3].replace(0,8,"   /\\   ");
    }
    
    int bp4 = board9[3].find("        ");
    if(bp4 != string::npos)
    {
        board9[3].replace(0,8,"  /  \\  ");
    }
};

void Board::drawX6()
{
    int gvloc = gameVec[1][2].find(" ");
    if (gvloc != string::npos){
        gameVec[1][2] = "X";
    }
    int bp1 = board6[5].find("        ");
    if(bp1 != string::npos)
    {
        board6[5].replace(0,8,"  \\  /  ");
    }
    
    int bp2 = board7[5].find("        ");
    if(bp2 != string::npos)
    {
        board7[5].replace(0,8,"   \\/   ");
    }
     
    int bp3 = board8[5].find("        ");
    if(bp3 != string::npos)
    {
        board8[5].replace(0,8,"   /\\   ");
    }
    
    int bp4 = board9[5].find("        ");
    if(bp4 != string::npos)
    {
        board9[5].replace(0,8,"  /  \\  ");
    }
};

void Board::drawX7()
{
    int gvloc = gameVec[2][0].find(" ");
    if (gvloc != string::npos){
        gameVec[2][0] = "X";
    }
    int bp1 = board11[1].find("        ");
    if(bp1 != string::npos)
    {
        board11[1].replace(0,8,"  \\  /  ");
    }
    
    int bp2 = board12[1].find("        ");
    if(bp2 != string::npos)
    {
        board12[1].replace(0,8,"   \\/   ");
    }
     
    int bp3 = board13[1].find("        ");
    if(bp3 != string::npos)
    {
        board13[1].replace(0,8,"   /\\   ");
    }
    
    int bp4 = board14[1].find("        ");
    if(bp4 != string::npos)
    {
        board14[1].replace(0,8,"  /  \\  ");
    }
};

void Board::drawX8()
{
    int gvloc = gameVec[2][1].find(" ");
    if (gvloc != string::npos){
        gameVec[2][1] = "X";
    }
    int bp1 = board11[3].find("        ");
    if(bp1 != string::npos)
    {
        board11[3].replace(0,8,"  \\  /  ");
    }
    
    int bp2 = board12[3].find("        ");
    if(bp2 != string::npos)
    {
        board12[3].replace(0,8,"   \\/   ");
    }
     
    int bp3 = board13[3].find("        ");
    if(bp3 != string::npos)
    {
        board13[3].replace(0,8,"   /\\   ");
    }
    
    int bp4 = board14[3].find("        ");
    if(bp4 != string::npos)
    {
        board14[3].replace(0,8,"  /  \\  ");
    }
};

void Board::drawX9()
{
    int gvloc = gameVec[2][2].find(" ");
    if (gvloc != string::npos){
        gameVec[2][2] = "X";
    }
    int bp1 = board11[5].find("        ");
    if(bp1 != string::npos)
    {
        board11[5].replace(0,8,"  \\  /  ");
    }
    
    int bp2 = board12[5].find("        ");
    if(bp2 != string::npos)
    {
        board12[5].replace(0,8,"   \\/   ");
    }
     
    int bp3 = board13[5].find("        ");
    if(bp3 != string::npos)
    {
        board13[5].replace(0,8,"   /\\   ");
    }
    
    int bp4 = board14[5].find("        ");
    if(bp4 != string::npos)
    {
        board14[5].replace(0,8,"  /  \\  ");
    }
};

void Board::drawO1()
{
    int gvloc = gameVec[0][0].find(" ");
    if (gvloc != string::npos){
        gameVec[0][0] = "O";
    }
    int bp1 = board1[1].find("        ");
    if(bp1 != string::npos)
    {
        board1[1].replace(0,8," .----. ");
    }
    
    int bp2 = board2[1].find("        ");
    if(bp2 != string::npos)
    {
        board2[1].replace(0,8,"|      |");
    }
     
    int bp3 = board3[1].find("        ");
    if(bp3 != string::npos)
    {
        board3[1].replace(0,8,"|      |");
    }
    
    int bp4 = board4[1].find("        ");
    if(bp4 != string::npos)
    {
        board4[1].replace(0,8," '----' ");
    }
};

void Board::drawO2()
{
    int gvloc = gameVec[0][1].find(" ");
    if (gvloc != string::npos){
        gameVec[0][1] = "O";
    }
    int bp1 = board1[3].find("        ");
    if(bp1 != string::npos)
    {
        board1[3].replace(0,8," .----. ");
    }
    
    int bp2 = board2[3].find("        ");
    if(bp2 != string::npos)
    {
        board2[3].replace(0,8,"|      |");
    }
     
    int bp3 = board3[3].find("        ");
    if(bp3 != string::npos)
    {
        board3[3].replace(0,8,"|      |");
    }
    
    int bp4 = board4[3].find("        ");
    if(bp4 != string::npos)
    {
        board4[3].replace(0,8," '----' ");
    }
};

void Board::drawO3()
{
    int gvloc = gameVec[0][2].find(" ");
    if (gvloc != string::npos){
        gameVec[0][2] = "O";
    }
    int bp1 = board1[5].find("        ");
    if(bp1 != string::npos)
    {
        board1[5].replace(0,8," .----. ");
    }
    
    int bp2 = board2[5].find("        ");
    if(bp2 != string::npos)
    {
        board2[5].replace(0,8,"|      |");
    }
     
    int bp3 = board3[5].find("        ");
    if(bp3 != string::npos)
    {
        board3[5].replace(0,8,"|      |");
    }
    
    int bp4 = board4[5].find("        ");
    if(bp4 != string::npos)
    {
        board4[5].replace(0,8," '----' ");
    }
};

void Board::drawO4()
{
    int gvloc = gameVec[1][0].find(" ");
    if (gvloc != string::npos){
        gameVec[1][0] = "O";
    }
    int bp1 = board6[1].find("        ");
    if(bp1 != string::npos)
    {
        board6[1].replace(0,8," .----. ");
    }
    
    int bp2 = board7[1].find("        ");
    if(bp2 != string::npos)
    {
        board7[1].replace(0,8,"|      |");
    }
     
    int bp3 = board8[1].find("        ");
    if(bp3 != string::npos)
    {
        board8[1].replace(0,8,"|      |");
    }
    
    int bp4 = board9[1].find("        ");
    if(bp4 != string::npos)
    {
        board9[1].replace(0,8," '----' ");
    }
};

void Board::drawO5()
{
    int gvloc = gameVec[1][1].find(" ");
    if (gvloc != string::npos){
        gameVec[1][1] = "O";
    }
    int bp1 = board6[3].find("        ");
    if(bp1 != string::npos)
    {
        board6[3].replace(0,8," .----. ");
    }
    
    int bp2 = board7[3].find("        ");
    if(bp2 != string::npos)
    {
        board7[3].replace(0,8,"|      |");
    }
     
    int bp3 = board8[3].find("        ");
    if(bp3 != string::npos)
    {
        board8[3].replace(0,8,"|      |");
    }
    
    int bp4 = board9[3].find("        ");
    if(bp4 != string::npos)
    {
        board9[3].replace(0,8," '----' ");
    }
};

void Board::drawO6()
{
    int gvloc = gameVec[1][2].find(" ");
    if (gvloc != string::npos){
        gameVec[1][2] = "O";
    }
    int bp1 = board6[5].find("        ");
    if(bp1 != string::npos)
    {
        board6[5].replace(0,8," .----. ");
    }
    
    int bp2 = board7[5].find("        ");
    if(bp2 != string::npos)
    {
        board7[5].replace(0,8,"|      |");
    }
     
    int bp3 = board8[5].find("        ");
    if(bp3 != string::npos)
    {
        board8[5].replace(0,8,"|      |");
    }
    
    int bp4 = board9[5].find("        ");
    if(bp4 != string::npos)
    {
        board9[5].replace(0,8," '----' ");
    }
};

void Board::drawO7()
{
    int gvloc = gameVec[2][0].find(" ");
    if (gvloc != string::npos){
        gameVec[2][0] = "O";
    }
    int bp1 = board11[1].find("        ");
    if(bp1 != string::npos)
    {
        board11[1].replace(0,8," .----. ");
    }
    
    int bp2 = board12[1].find("        ");
    if(bp2 != string::npos)
    {
        board12[1].replace(0,8,"|      |");
    }
     
    int bp3 = board13[1].find("        ");
    if(bp3 != string::npos)
    {
        board13[1].replace(0,8,"|      |");
    }
    
    int bp4 = board14[1].find("        ");
    if(bp4 != string::npos)
    {
        board14[1].replace(0,8," '----' ");
    }
};

void Board::drawO8()
{
    int gvloc = gameVec[2][1].find(" ");
    if (gvloc != string::npos){
        gameVec[2][1] = "O";
    }
    int bp1 = board11[3].find("        ");
    if(bp1 != string::npos)
    {
        board11[3].replace(0,8," .----. ");
    }
    
    int bp2 = board12[3].find("        ");
    if(bp2 != string::npos)
    {
        board12[3].replace(0,8,"|      |");
    }
     
    int bp3 = board13[3].find("        ");
    if(bp3 != string::npos)
    {
        board13[3].replace(0,8,"|      |");
    }
    
    int bp4 = board14[3].find("        ");
    if(bp4 != string::npos)
    {
        board14[3].replace(0,8," '----' ");
    }
};

void Board::drawO9()
{
    int gvloc = gameVec[2][2].find(" ");
    if (gvloc != string::npos){
        gameVec[2][2] = "O";
    }
    int bp1 = board11[5].find("        ");
    if(bp1 != string::npos)
    {
        board11[5].replace(0,8," .----. ");
    }
    
    int bp2 = board12[5].find("        ");
    if(bp2 != string::npos)
    {
        board12[5].replace(0,8,"|      |");
    }
     
    int bp3 = board13[5].find("        ");
    if(bp3 != string::npos)
    {
        board13[5].replace(0,8,"|      |");
    }
    
    int bp4 = board14[5].find("        ");
    if(bp4 != string::npos)
    {
        board14[5].replace(0,8," '----' ");
    }
};