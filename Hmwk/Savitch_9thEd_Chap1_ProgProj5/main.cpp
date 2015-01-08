/* 
 * File:   main.cpp
 * Author: Tati
 * Created on January 6, 2015, 7:28 PM
 * 
 * Homework: 
 * Write a program that inputs a character from the keyboard and then outputs a 
 * large block letter “C” composed of that character. For example, if the user 
 * inputs the character “X,” then the output should look as follows:
    X X X 
   X    X
  X 
  X 
  X 
  X 
  X
   X    X 
    X X X
 */

#include <iostream>
using namespace std;

int main(int argc, char** argv) 
{
    char input;
    cout << "Input a letter: ";
    cin  >> input;
    
//    cout << "    X X X" << endl;
//    cout << "   X    X" << endl;
//    cout << "  X" << endl;
//    cout << "  X" << endl;
//    cout << "  X" << endl;
//    cout << "  X" << endl;
//    cout << "  X" << endl;
//    cout << "   X    X" << endl;
//    cout << "    X X X" << endl;
    
    cout << "    " << input << " " << input << " " << input << endl;
    cout << "   " << input << "    " << input << endl;
    cout << "  " << input << endl;
    cout << "  " << input << endl;
    cout << "  " << input << endl;
    cout << "  " << input << endl;
    cout << "  " << input << endl;
    cout << "   " << input << "    " << input << endl;
    cout << "    " << input << " " << input << " " << input << endl; 

    return 0;
}