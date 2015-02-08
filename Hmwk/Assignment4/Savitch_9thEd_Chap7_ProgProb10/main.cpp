/* 
 * File:   main.cpp
 * Author: Tati
 * Created on February 5, 2015, 6:53 PM
 * 
 * Homework:
 * Write a program that will allow two users to play tictactoe. The program 
 * should ask for moves alternately from player X and player o. The program 
 * displays the game positions as follows:
 *  1 2 3 
 *  4 5 6 
 *  7 8 9
 * 
 * The players enter their moves by entering the position number they wish to 
 * mark. After each move, the program displays the changed board. A sample 
 * board configuration is as follows:
 * X X O 
 * 4 5 6 
 * O 8 9
 * 
 */

#include <iostream>
using namespace std;

const int ROW = 3;
const int COL = 3;

bool boardIsFilled(char [ROW][COL]);
void fillBoard(char [ROW][COL], char, char);
bool taken(char);
void display(char [ROW][COL]);
void readInput(char, char &);

int main(int argc, char** argv) 
{
    char X = 'X'; // player X
    char O = 'O'; // player O
    char playerInput;   
    char board[ROW][COL] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    
    display(board);
    
    bool filled = false; // check if board is filled
    while (filled == false)
    {
        // End game when board is filled
        if ( boardIsFilled(board) )
            filled = true;
        else
        {
            // Do player X
            readInput(X, playerInput);
            fillBoard(board, X, playerInput);
            display(board);  
        }
        
        if ( boardIsFilled(board) )
            filled = true;
        else
        {
            // Do player O
            readInput(O, playerInput);
            fillBoard(board, O, playerInput);
            display(board);
        }
    }  
    return 0;
}

void readInput(char player, char &playerInput)
{
    cout << "Player " << player << " Turn. Fill Board at: ";
    cin  >> playerInput;
}

void display(char board[ROW][COL])
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}

bool taken(char boardAtIndex)
{
    if (boardAtIndex == 'X' || boardAtIndex == 'O')
        return true;
    else
        return false; 
}

void fillBoard(char board[ROW][COL], char player, char input)
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (board[i][j] == input)
                board[i][j] = player;           
        }
    }    
}

bool boardIsFilled(char board[ROW][COL])
{
    int indicesTtl = ROW * COL; // total number of indices on board
    int counter = 0; // counts how many 'X' and 'O' are on board
    
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if ( taken(board[i][j]) )
                counter++;
        }
    }
    if (counter == indicesTtl)
        return true;
    else
        return false;
}