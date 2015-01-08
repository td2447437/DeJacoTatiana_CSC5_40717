/* 
 * File:   main.cpp
 * Author: Tati
 * Created on January 6, 2015, 5:48 PM
 * 
 * Homework: 
 * Write a program that prints out C S ! in large block letters inside a border 
 * of *s followed by two blank lines then the message Computer Science is Cool 
 * Stuff. The output should look as follows:
   *****************************************************
        C C C            S S S S            !!
      C       C        S         S          !!
     C                S                     !!
    C                  S                    !!
    C                   S S S S             !!
    C                            S          !!
     C                            S         !!
      C       C         S        S
        C C C             S S S S           OO
   *****************************************************
      Computer Science is Cool Stuff!!!
 */

#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) 
{
    cout << "   *****************************************************" << endl;
    cout << "        C C C            S S S S            !!          " << endl;
    cout << "      C       C        S         S          !!          " << endl;
    cout << "     C                S                     !!          " << endl;
    cout << "    C                  S                    !!          " << endl;
    cout << "    C                   S S S S             !!          " << endl;
    cout << "    C                            S          !!          " << endl;
    cout << "     C                            S         !!          " << endl;
    cout << "      C       C         S        S                      " << endl;
    cout << "        C C C             S S S S           OO          " << endl;
    cout << "   *****************************************************" << endl;
    cout << "      Computer Science is Cool Stuff!!!" << endl;
    
    return 0;
}

