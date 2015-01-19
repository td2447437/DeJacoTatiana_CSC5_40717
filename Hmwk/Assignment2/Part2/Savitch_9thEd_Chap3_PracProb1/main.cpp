/* 
 * File:   main.cpp
 * Author: Tati
 * Created on January 14, 2015, 8:42 AM
 * 
 * Homework:
 * Write a program to score the paper-rock-scissor game. 
 * 1. Each of two users types in either P, R, or S. 
 * 
 * 2. The program then announces the winner as well 
 *    as the basis for determining the winner: 
 *    - Paper covers rock,
 *    - Rock breaks scissors,
 *    - Scissors cut paper, 
 *    - or Nobody wins. 
 * 
 * 3. Be sure to allow the users to use lowercase as well as uppercase letters. 
 *    Your program should include a loop that lets the user play again until   
 *    the user says she or he is done.
 */

#include <iostream>
#include <strings.h>
using namespace std;

char p1;          // player 1
int  p1Score = 0; // player 1's score
char p2;          // player 2
int  p2Score = 0; // player 2's score

bool repeat()
{
    string input;  // user input
    
    // Ask user if repeat is wanted
    cout << "Play Again? ";
    cin  >> input;
    
    while (true)
    {
        // Check if input is valid
        if (input == "yes")
            return true;
        else if (input == "no")
            return false;
        else
        {
            cout << "What was that? yes or no? ";
            cin  >> input;
        } 
    }  
}

bool checkInput(char p)
{
    // Check if input is correct
    if ( (p != 'P' && p != 'p') 
            && (p != 'R' && p != 'r') 
                && (p != 'S' && p != 's'))
        return true;
    
    return false; 
}

bool p1Winner()
{
    if ( (p1 == 'P' || p1 == 'p') 
            && (p2 == 'R' || p2 == 'r') )
    {
        p1Score++;
        cout << "Paper covers rock.";
    }
    else if ( (p1 == 'R' || p1 == 'r')  
            && (p2 == 'S' || p2 == 's') )
    {
        p1Score++;
        cout << "Rock breaks scissors. ";
    }
    else if ( (p1 == 'S' || p1 == 's')
            &&  (p2 == 'P' || p2 == 'p') )
    {
        p1Score++;
        cout << "Scissors cut paper. ";
    }
    else
        return false;
    
    return true;
}

bool p2Winner()
{
    if ( (p2 == 'P' || p2 == 'p') 
            && (p1 == 'R' || p1 == 'r') )
    {
        p2Score++;
        cout << "Paper covers rock. ";
    }
    else if ( (p2 == 'R' || p2 == 'r')  
            && (p1 == 'S' || p1 == 's') )
    {
        p2Score++;
        cout << "Rock breaks scissors. ";
    }
    else if ( (p2 == 'S' || p2 == 's')
            &&  (p1 == 'P' || p1 == 'p') )
    {
        p2Score++;
        cout << "Scissors cut paper. ";
    }
    else
        return false;
    
    return true;
}

int main(int argc, char** argv) 
{
    while (true)
    {
        // Each of two users types in either P, R, or S.
        cout << "Player One: ";
        cin  >> p1;
        checkInput(p1);
        cout << "Player Two: ";
        cin  >> p2;  
        checkInput(p2);
        
        // The program then announces the winner as well 
        // as the basis for determining the winner: Paper covers rock,
        // Rock breaks scissors,Scissors cut paper,or Nobody wins.
        if (p1Winner())
            cout << "P1 WINS! P1 Score: " << p1Score  << endl;
        else if (p2Winner())
            cout << "P2 WINS! P2 Score: "  << p2Score << endl;
        else
        {
            cout << "No Winner. P1 Score: " << p1Score; 
            cout << " P2 Score: " << p2Score << endl;
        }
        
        // Ask user if repeat is wanted and repeat if yes
        if (repeat())
            continue;
        else
            break;

        return 0;
    }
}

