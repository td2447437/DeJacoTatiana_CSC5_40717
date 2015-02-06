/* 
 * File:   main.cpp
 * Author: Tati
 * Created on January 28, 2015, 10:12 PM
 * Hangman Game Cleanup
 */

#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
using namespace std;

const char *WORD; // The string that the computer has chosen
enum FOUND_TYPE { NOT_FOUND, FOUND, ALREADY_FOUND }; // Used for comparing results

// Displays the rules of the game
void display();
// Run the game
void runGame(char fillTheBlanks[], int, char,int, int, int); // Pass in the blanks to be filled,
                                                             // it's size, guess, hints, strikes, & score
// Display the fill in the blanks 
void display(char fillTheBlanks[], int);
// Look for the letter given by user
FOUND_TYPE foundLetter(char, char fillTheBlanks[]); // Pass in guess, the blanks to be filled
// See if user completed word in less than 7 strikes
bool bonus(int); // Pass in their number of strikes
// Output if the user won or lost
void display(bool, int, int); // Pass in if word was completed, # of strikes, & score
// Output the word, # of strikes, and score to a file
void outputToFile(string, int, int); // Pass in their result, their # of strikes, and ttl score

int main(int argc, char** argv) 
{
    // initialize random seed
    srand (time(NULL));
    
    // Declare Variables
    char guess;     // the user's guess
    int  score   = 0; // the user's score
    int  strikes = 0; // how many times they guessed wrong 
    int  hints   = 0; // how many hints the user used up
    
    const int MAX_LINES_IN_FILE = 300;
    string wordArray[MAX_LINES_IN_FILE]; // allocating an array of 1kb
    int wordCount = 0; // counts the number of word in file 
    // Computer will choose one word from the file of random words
    ifstream fin("randWords.txt"); // opening an input stream for file
    // Checking whether file could be opened or not. If file does not exist 
    // or don't have read permissions, file stream could not be opened.
    if(fin.is_open())
    {
        // this loop run until end of file (eof) does not occur
        while(!fin.eof() && wordCount < MAX_LINES_IN_FILE)
        {
            // Read a complete line into the array. Each line
            // contains one word.
            getline(fin, wordArray[wordCount]);
            wordCount++;
        }
    }
    else //file could not be opened
        cout << "File could not be opened." << endl;
    
    // Display a random word from file
    // Pick a string from the list
    int index = rand() % wordCount;
    WORD = wordArray[index].c_str(); // Set the rand string to be the word  
    int wordLen = strlen(WORD);      // the length of the chosen string
    
    // Create empty string that will be filled as the user guesses correctly
    string space;
    for (int i = 0; i < wordLen; i++)
        space += "_";   
    const char *blanks = space.c_str(); // Create the empty string
    char fillTheBlanks[wordLen]; // The user will fill as they guess correctly
    strcpy(fillTheBlanks, blanks);

    runGame(fillTheBlanks, wordLen, guess, hints, strikes, score);
    return 0;
}

// Displays the rules of the game
void display()
{
    cout << "Hangman Game! Guess the letters of a Secret Word!"         << endl;
    cout << "Here are the Rules: "                                      << endl;
    cout << "1) You are allowed only 7 strikes. Once you have 7"        << endl;
    cout << "   strikes. You Lose."                                     << endl;
    cout << "2) If you are able to complete the word before 7 strikes." << endl;
    cout << "   you will be given 10 pts."                              << endl;
    cout << "3) For every correct answer, you will receive 5 pts."      << endl;
    cout << "4) For every incorrect answer, you will be deducted a pt." << endl;
    cout << "5) If you input a '?' I will give you a hint, however,"    << endl;
    cout << "   you are only allowed 1 hint and you will lose 5 pts."   << endl;
    cout << endl;
}

// Run the game
void runGame(char fillTheBlanks[], int size, char guess, int hints, int strikes, int score)
{
    // Display the rules of the game
    display();
    // Display how many letters are in the word
    display(fillTheBlanks, size);
    
    bool completedWord = false; // true if user completely filled the blanks
    while (completedWord == false)
    {
        // Prompt user for input
        cout << "Your guess? "; 
        cin >> guess;
        
        // If user asks for a hint, give them one at random
        if (guess == '?')
        {
            if (hints == 0)
            {
                // Tell them how many vowels are in the word
                int vowels;
                // Go through the WORD and count how many vowels are in there
                for (int i = 0; i < size; i++)
                {
                    switch(WORD[i])
                    {
                        case 'a': { vowels++; break; }
                        case 'i': { vowels++; break; }
                        case 'u': { vowels++; break; }
                        case 'e': { vowels++; break; }
                        case 'o': { vowels++; break; }
                        default: break;
                    };
                }
                cout << vowels << " vowel(s) is in this word." << endl;
                cout << "-5 pts" << endl;
                score -=5;
            }
            else
                cout << "No more hints are available." << endl;
            
            hints++;
        }
        else // if user didn't ask for a hint
        {
            // Find the letter guessed by user in the word
            FOUND_TYPE result = foundLetter(guess, fillTheBlanks);
            if (result == NOT_FOUND)
            {
                cout << "Incorrect! -1 pt.";
                score--;
                strikes++;
            }
            else
            {
                if (result == FOUND)
                {
                    cout << "Correct! +5 pts.";
                    score += 5;
                }
                else
                    cout << "Letter was already found.";             
            }
            cout << endl << endl;
    
            // Show user where their guess was filled in
            display(fillTheBlanks, size);

            // Check if the blanks are filled and matches the computer's word
            string usersWord = fillTheBlanks; // User's word
            string compsWord = WORD;          // Comp's word
            if (usersWord == compsWord) // if blanks match the comp's word
                completedWord = true;
            else // blanks were not filled
            {
                if (strikes == 7) // Check if the user used up their strikes
                    break;
            }
        }        
    }
    // Display results to user
    display(completedWord, strikes, score);
}

// Display fill in the blanks
void display(char fillTheBlanks[], int size)
{
    // Display the blanks
    for (int i = 0; i < size; i++)
        cout << " " << fillTheBlanks[i];
    cout << endl;
}

// Look for the letter given by user
FOUND_TYPE foundLetter(char guess, char fillTheBlanks[])
{
    // If the guess letter is in the string fillTheBlanks 
    // then the user already guessed that character.
    char *cPter = strchr(fillTheBlanks, guess); // char pointer
    if (cPter != NULL)
        return ALREADY_FOUND;
    
    // If it is NOT in the fillTheBlanks, 
    // then check if character is in the word
    cPter = strchr(WORD, guess);
    if (cPter == NULL)
        return NOT_FOUND;
    
    // If character WAS not in the fillTheBlanks
    // and character WAS found, then it is in the word.
    // So...get it's location in the word.
    while (cPter != NULL)   
    {  
        // FIll in the blank with the guess
        int indexFound = cPter - WORD;
        fillTheBlanks[indexFound] = guess;
        // Advance to the next location of guess WORD
        cPter = strchr(cPter + 1, guess);
    }
    return FOUND;
}

// See if user completed word in less than 7 strikes
bool bonus(int strikes)
{
    if (strikes < 7)
        return true;
    else 
        return false;
}

// Display results of game and output results to a file
void display(bool completedWord, int strikes, int score)
{
    cout << endl;
    // Set Score and Output results
    if (completedWord == false) // Word wasn't completed
    {
        cout << "You Lose!"; 
        cout << " The word was " << WORD;
        outputToFile("Lost", strikes, score);
    }
    else // Word was completed
    {
        if (bonus(strikes)) // user finished before 7 strikes
        {
            cout << "Amazing! You completed the word before 7 strikes! ";
            cout << "+10 pts!";
            score += 10;
        }
        else
            cout << "You have completed the game! Congratulations!";
        outputToFile("Won", strikes, score);
    }
}

// Output the word, # of strikes, and score to a file
void outputToFile(string result, int strikes, int score)
{
    // Output a file when game is complete
    ofstream myfile;
    myfile.open("hangman.docx");
    myfile << "You " << result << " the game!"  << endl;
    myfile << "The word was: " << WORD          << endl;
    myfile << "You used up "   << strikes       << " strikes" << endl;
    myfile << "Your score = "  << score         << endl;
    myfile.close();
    // Tell User their result was outputted to a file
    cout << endl;
    cout << "Your score was printed to a file";
    cout << "...Go check out your score!" << endl;
}