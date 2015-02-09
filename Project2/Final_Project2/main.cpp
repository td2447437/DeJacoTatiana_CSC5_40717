/* 
 * File:   main.cpp
 * Author: Tati
 * Created on February 8, 2015, 1:24 PM
 * Hangman Game Cleanup
 * 
 */

#include <iostream> // Reads Inputs
#include <iomanip>  // Formatting Output
#include <string.h>
#include <string> 
#include <fstream>  // Reads & Writes Files
using namespace std;

const char *WORD; // The word that the computer has chosen
enum FOUND_TYPE { NOT_FOUND, FOUND, ALREADY_FOUND }; // Used for comparing results

// Gets a random word from a file
void getRandomWordFromFile(int &); 
// Sets how many blanks the user has to fill
void setFillTheBlanks(char [], int);
// Play the game
void startGame(char [], int);
// Display game rules to player
void display();
// Display's an array
void display(char [], int);
// Output if the user won or lost
void display(bool, int, int);
// Give the user a hint when wanted
void giveHint(int, int &, int, int &);
// Searches for the letter given by user
FOUND_TYPE foundLetter(char [], char);
// Searches for the letter given by user
void foundLetter(char [], char, int &, int &);
// See if user completed word in less than 7 strikes
bool bonus(int);
// Output the word, # of strikes, and score to a file
void outputToFile(string, int, int);
// Asks if player wants to play again
bool repeatGame();

int main(int argc, char** argv) 
{
    // initialize random seed
    srand (time(NULL));
    
    // Declare Variables      
    int  wordLength = 0;            // Chosen word's length
    char fillTheBlanks[wordLength]; // the string user has to fill
    
    bool onRepeat = true; // assume player want to continue playing
    while (onRepeat)
    {
        getRandomWordFromFile(wordLength);
        cout << "Word is " << WORD << ". Length is " << wordLength << endl << endl;
        setFillTheBlanks(fillTheBlanks, wordLength);

        startGame(fillTheBlanks, wordLength);

        if ( !repeatGame() )
            onRepeat = false;
        else
            cout << endl;
    }   
}

void getRandomWordFromFile(int &wordLength)
{
    const int MAX_LINES_IN_FILE = 300;
    string    wordsInFile[MAX_LINES_IN_FILE]; // array of words from file
    int       wordCounter = 0;                // the number of words in file 
    
    // Computer will choose one word from the file of random words
    ifstream fin("randWords.txt"); // opening an input stream for file
    // Checking whether file could be opened or not. If file does not exist 
    // or don't have read permissions, file stream could not be opened.
    if(fin.is_open())
    {
        // this loop run until end of file (eof) does not occur
        while(!fin.eof() && wordCounter < MAX_LINES_IN_FILE)
        {
            // Read a complete line into the array. Each line
            // contains one word.
            getline(fin, wordsInFile[wordCounter]);
            wordCounter++;
        }
    }
    else //file could not be opened
        cout << "File could not be opened." << endl;
    
    // Pick a string from the list
    int index  = rand() % wordCounter;
    WORD       = wordsInFile[index].c_str(); // Set the rand string to be the word 
    wordLength = strlen(WORD);               // the length of the chosen word
}

void setFillTheBlanks(char a[], int wordLength)
{
    // Create empty string that will be filled as the user guesses correctly
    string space;
    for (int i = 0; i < wordLength; i++)
        space += "_";   
    
    const char *blanks = space.c_str(); // Create the empty string
    strcpy(a, blanks);
}

// Play the game
void startGame(char a[], int size)
{
    // Declare Variables
    char guess;        // user's guess
    int  strikes = 0;  // user's # of incorrect guesses
    int  hints   = 0;  // # of hints used
    int  score   = 0;  // user's score
        
    display();        // Display game rules
    display(a, size);  // display fill the blanks
    
    bool completedWord = false; // true if user completely filled the blanks
    while (completedWord == false)
    {    
        // Prompt user for input
        cout << "Your guess? "; 
        cin >> guess;

        // If user asks for a hint, give them one at random
        if (guess == '?')
            giveHint(size, hints, strikes, score);
        else if (guess == '/') // exit game when player types in '/'
            break;
        else
            foundLetter(a, guess, strikes, score);

        // Show user where their guess was filled in
        cout << endl; 
        display(a, size);

        // Check if the blanks are filled and matches the computer's word
        string usersWord = a;    // User's word
        string compsWord = WORD; // Comp's word
        
        if (usersWord == compsWord) // if blanks match the comp's word
            completedWord = true;
        else // blanks were not filled
        {
            if (strikes == 7) // Check if the user used up their strikes
                break;
        }
    }
    // Display results to user
    display(completedWord, strikes, score);
}

// Displays the rules of the game
void display()
{
    cout << "Hangman Game! Guess the letters of a Secret Word!"         << endl;
    cout << "Here are the Rules: "                                      << endl;
    cout << "1) You are allowed only 7 strikes. Once you have 7"        << endl;
    cout << "   strikes. You Lose."                                     << endl;
    cout << "2) If you are able to complete the word before 4 strikes." << endl;
    cout << "   you will be given 10 pts."                              << endl;
    cout << "3) For every correct answer, you will receive 5 pts."      << endl;
    cout << "4) For every incorrect answer, you will be deducted a pt." << endl;
    cout << "5) If your input is a '?' I will give you a hint but"      << endl;
    cout << "   you are only allowed 1 hint and you will lose 5 pts."   << endl;
    cout << "To end the game, type '/'."                                << endl;
    cout << endl;
}

// Display fill in the blanks
void display(char a[], int size)
{
    // Display the blanks
    cout << endl;
    for (int i = 0; i < size; i++)
        cout << " " << a[i];
    cout << endl;
}

// Display results of game and output results to a file
void display(bool completedWord, int strikes, int score)
{
    cout << endl;
    // Set Score and Output results
    if (completedWord == false) // Word wasn't completed
    {
        cout << "You Lose! The word was " << WORD;
        outputToFile("Lost", strikes, score);
    }
    else // Word was completed
    {
        if (bonus(strikes)) // user finished before 7 strikes
        {
            score += 10;
            cout << "Amazing! You completed the word before 4 strikes! ";            
        }
        else
            cout << "You have completed the game! Congratulations!";
        outputToFile("Won", strikes, score);
    }
    cout << endl << "Score: " << score << " Strikes: " << strikes << endl;
    cout << "Your results were outputted to file: hangman.docx";
}

void giveHint(int size, int &hints, int strikes, int &score)
{
    // If user asks for a hint, give them one at random
    if (hints == 0)
    {
        int vowels = 0; // # of vowels in the word
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
        score -=5;  
        cout << vowels << " vowel(s) is in this word." << endl;
        cout << "Score: " << score << " Strikes: " << strikes;
    }
    else
        cout << "No more hints are available." << endl;
    hints++;
}

FOUND_TYPE foundLetter(char a[], char guess)
{
    // If the guess letter is in the string fillTheBlanks then the user already 
    // guessed that character.
    char *cPter = strchr(a, guess); // char pointer
    if (cPter != NULL)
        return ALREADY_FOUND;

    // If it is NOT in the fillTheBlanks, then check if character is in the word
    cPter = strchr(WORD, guess);
    if (cPter == NULL)
        return NOT_FOUND;

    // If character WAS not in the fillTheBlanks and character WAS found, then 
    // it is in the word. So...get it's location in the word.
    while (cPter != NULL)   
    {  
        int indexFound = cPter - WORD; // Fill in the blank with the guess
        a[indexFound] = guess;       
        cPter = strchr(cPter + 1, guess); // Advance to the next location of guess WORD
    }
    return FOUND;
}

void foundLetter(char a[], char guess, int &strikes, int &score)
{
    // Find the letter guessed by user in the word
    FOUND_TYPE result = foundLetter(a, guess);
    
    if (result == NOT_FOUND)
    {
        cout << "Incorrect! "; 
        cout << "Score: " << --score << " Strikes: " << ++strikes;
    }
    else
    {
        if (result == FOUND)
        {
            score += 5;
            cout << "Correct! ";
            cout << "Score: " << score << " Strikes: " << strikes;
        }
        else
            cout << "Letter was already found.";             
    }
}

// See if user completed word in less than 7 strikes
bool bonus(int strikes)
{
    if (strikes < 4)
        return true;
    else 
        return false;
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
}

bool repeatGame()
{
    cout << endl << endl;
    bool valid = false;
    while ( !valid )
    {
        char input;
        cout << "Play Again? ";
        cin  >> input;  

        switch(input)
        {
            case 'Y':
            case 'y': { valid = true; return true;  break; }
            case 'N':
            case 'n': { valid = true; return false; break; }
            default:  { break; }
        }
    } 
    return false;
}