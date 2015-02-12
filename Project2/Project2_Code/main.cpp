/* 
 * File:   main.cpp
 * Author: Tati
 * Created on February 8, 2015, 1:24 PM
 * Hangman Game
 */

// System Libraries
#include <iostream> // Reads Inputs
#include <iomanip>  // Formatting Output
#include <string.h> 
#include <fstream>  // Read & Write files
#include <vector>
using namespace std;

//User Libraries
#include "Game.h"
#include "Player.h"

#define MAX_WORD_LENGTH 50

// Global Constants
char WORD[MAX_WORD_LENGTH];
enum FOUND_TYPE { NOT_FOUND, FOUND, ALREADY_FOUND }; // Used for comparing results

// Function Prototypes
void       getRandomWordFromFile(int &);               // Gets a random word from a file
void       setFillTheBlanks(char [], int);             // Sets how many blanks the user has to fill
void       initPlayer(Player *);                       // Initialize player without initializing allScores and allWords
void       startGame(Game *, Player *);                // Play the game
void       display();                                  // Display game rules to player
void       display(char [], int);                      // Display's an array
void       display(Player *, bool);                    // Output if the user won or lost
void       initHangman(string [][COL]);                // initialize hangman drawing
void       drawHangman(Game *, Player *);              //  Draws Hangman
void       giveHint(Player *, int);                    // Give the user a hint when wanted
int        search(char [], char, int);                 // Linear Search through array for target
FOUND_TYPE foundLetter(char [], char);                 // Searches for the letter given by user
void       foundLetter(Game *, Player *, char);        // Searches for the letter given by user 
void       selectionSort(Player *);                    // Sorts player's results
int        getIndexOfLargestValue(vector<int> &, int); // Used in and for selection sorting
void       swap(vector<int> &, int, int);              // Swaps the values: for scores
void       swap(vector<string> &, int, int);           // Swaps the values: for words
void       outputToFile(Player *, ofstream &);         // Output the word, # of strikes, and score to a file
bool       repeatGame();                               // Returns whether or not they want to play again

// Execution Here
int main(int argc, char** argv) 
{
    // initialize random seed
    srand (time(NULL));

    // Declare Variables
    Game   *game;
    Player *player;     // Create player database 
    int wordLength = 0; // the length of the word selected
            
    // Open/Create a new file
    ofstream myfile; // Output file for the hangman results
    myfile.open("hangman.txt");
    
    display(); // Display game rules
    
    bool onRepeat = true; // assume player want to continue playing
    player = new Player;  // initialize database
    while (onRepeat)
    {
        initPlayer(player);
        getRandomWordFromFile(wordLength);
        game = new Game(wordLength); // Initialize game
        setFillTheBlanks(game->fillTheBlanks, game->wordLength);
        startGame(game, player);

        // Place score in vector
        player->allScores.push_back(player->currentScore);
        player->allWords.push_back(WORD);
        player->allResults.push_back(player->currentResult);
        
        if ( !repeatGame() )
            onRepeat = false;
        else
            cout << endl;
    }    
    cout << endl;
    cout << "Your results were outputted to file: hangman.txt" << endl;
    
    selectionSort(player);        // Sort player's results
    outputToFile(player, myfile); // output results
    
    // Close the hangman file
    myfile.close();
}

/******************************************************
 * Gets a random word from a file
 * @param wordLength - the length of the random word
 ******************************************************/
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
    else // file could not be opened
        cout << "File could not be opened." << endl;
    
    // Pick a string from the list
    int index  = rand() % wordCounter;
    strcpy(WORD, wordsInFile[index].c_str()); // Set the rand string to be the word
    wordLength = strlen(WORD);                // the length of the chosen word
}

/*********************************************************
 * Create the fill in the blanks that user will fill 
 * throughout the game
 * @param fillTheBlanks - character array to initialize
 * @param wordLength - the length of the selected word
 *********************************************************/
void setFillTheBlanks(char fillTheBlanks[], int wordLength)
{
    // Create empty string that will be filled as the user guesses correctly
    string space;
    for (int i = 0; i < wordLength; i++)
        space += "_";   
    
    const char *blanks = space.c_str(); // Create the empty string
    strcpy(fillTheBlanks, blanks);
}

/***********************************************************************
 * Initializes all variables in struct Player
 * @param player - player to be initialized
 ***********************************************************************/
void initPlayer(Player *player)
{
    player->currentScore  = 0;
    player->strikes       = 0;
    player->hints         = 0;
    player->currentResult = "";
}

/***********************************************************************
 * Begin the game
 * @param game   - game variables
 * @param player - player variables
 ***********************************************************************/
void startGame(Game *game, Player *player)
{
    // Declare Variables
    char guess; // User's guess
    
    initHangman(game->hangman);                     // Initialize Hangman
    //cout << "WORD was " << WORD << endl;          // Debugging purposes
    display(game->fillTheBlanks, game->wordLength); // display fill the blanks
    
    bool completedWord = false; // true if user completely filled the blanks
    do
    {    
        // Prompt user for input
        cout << "Your guess? "; 
        cin >> guess;

        // If user asks for a hint, give them one at random
        if (guess == '?')
            giveHint(player, game->wordLength);
        else if (guess == '/') // exit game when player types in '/'
            break;
        else
            foundLetter(game, player, guess);

        // Check if the blanks are filled and matches the computer's word
        string usersWord = game->fillTheBlanks; // User's word
        string compsWord = WORD;                // Comp's word
        
        if (usersWord == compsWord) // if blanks match the comp's word           
            completedWord = true;
        else // blanks were not filled
        {
            if (player->strikes == 6) // Check if the user used up their strikes
                break;
        }
        display(game->fillTheBlanks, game->wordLength); // display blanks
    }
    while (completedWord == false);
    
    display(player, completedWord); // Display results to user
}

/****************************************************************************
 * Display the rules of the game
 ****************************************************************************/
void display()
{
    cout << "Hangman Game! Guess the letters of a Secret Word!"     << endl;
    cout << "Here are the Rules: "                                  << endl;
    cout << "1) When the hangman drawing is completed, you lose."   << endl;
    cout << "2) For every correct answer, you will receive 5 pts."  << endl;
    cout << "3) For every incorrect answer, you will be deducted"   << endl;
    cout << "   a pt."                                              << endl;
    cout << "4) If your input is a '?' I will give you a hint but"  << endl;
    cout << "   you are only allowed 1 hint and you will lose    "  << endl;
    cout << "   3 pts."                                             << endl;
    cout << "To end the game, type '/'."                            << endl;
    cout << endl;
}

/****************************************************************************
 * Displays the fill in the blanks
 * @param fillTheBlanks - character array to display
 * @param wordLength    - the length of the word
 ****************************************************************************/
void display(char fillTheBlanks[], int wordLength)
{
    // Display the blanks
    cout << endl;
    for (int i = 0; i < wordLength; i++)
        cout << " " << fillTheBlanks[i];
    cout << endl;
}

/****************************************************************************
 * Displays the user's results when game is over
 * @param player        - player variables
 * @param completedWord - True if user completed the word else false
 ****************************************************************************/
void display(Player *player, bool completedWord)
{
    cout << endl;
    // Set Score and Output results
    if (completedWord == false) // Word wasn't completed
    {
        cout << "You Lose! The word was " << WORD;
        player->currentResult = "Lost";
    }
    else // Word was completed
    {
        cout << "You have completed the game! Congratulations!";
        player->currentResult = "Won";
    }
    cout << endl;
    cout << "Score: " << player->currentScore;
}

/****************************************************************************
 * Initialize the hangman drawing
 * @param hangman - 2D array used to draw the hangman
 ****************************************************************************/
void initHangman(string hangman[][COL])
{
    hangman[0][0] = "  _____"; hangman[0][1] = "_____";
    hangman[1][0] = "  |    "; hangman[1][1] = "    |";
    hangman[2][0] = "  |    "; hangman[2][1] = "   ";
    hangman[3][0] = "  |    "; hangman[3][1] = "   ";
    hangman[4][0] = "  |    "; hangman[4][1] = "   ";
    hangman[5][0] = "__|____"; hangman[5][1] = "________";
}

/****************************************************************************
 * Draw parts of the hangman as the user guesses wrong
 * @param game   - game variables
 * @param player - player variables
 ****************************************************************************/
void drawHangman(Game *game, Player *player)
{
    string head     = "( )";
    string leftArm  = "/";
    string body     = "|";
    string rightArm = "\\";
    string leftLeg  = "/";
    string rightLeg = " \\";
    bool completedDrawing = false;
    
    switch (player->strikes)
    {
        case 0:  break;
        case 1:  { game->hangman[2][1] += head;     break; };
        case 2:  { game->hangman[3][1] += leftArm;  break; };
        case 3:  { game->hangman[3][1] += body;     break; };
        case 4:  { game->hangman[3][1] += rightArm; break; };
        case 5:  { game->hangman[4][1] += leftLeg;  break; };
        case 6:  { game->hangman[4][1] += rightLeg; break; };
        default: { completedDrawing = true; break;         };
    };
    
    // Display Drawing if not complete
    if (completedDrawing == false)
    {
        for (int i = 0; i < ROW; i++)
        {
            for (int j = 0; j < COL - 1; j++)
                cout << game->hangman[i][j] 
                     << game->hangman[i][j+1] << endl;
        }
    }
}

/****************************************************************************
 * Gives a hint to the user when wanted
 * @param player     - player variables
 * @param wordLength - the length of the selected word
 ****************************************************************************/
void giveHint(Player *player, int wordLength)
{
    // If user asks for a hint, give them one at random
    if (player->hints == 0)
    {
        int vowels = 0; // # of vowels in the word
        
        // Go through the WORD and count how many vowels are in there
        for (int i = 0; i < wordLength; i++)
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
        player->currentScore -= 3;  
        cout << "The word has: " << vowels << " vowel(s)." << endl;
        cout << "Score: "        << player->currentScore;
    }
    else
        cout << "No more hints are available." << endl;
    player->hints++;
}

/****************************************************************************
 * A Linear Search for target in a character array
 * @param a      - character array to search through
 * @param target - character to search for
 * @param index  - where to begin the search
 * @return -1 if the character was not found
 ****************************************************************************/
int search(char a[], char target, int index = 0)
{
    int size = strlen(a);
    for (int i = index; i < size; i++)
    {
        if (target == a[i])
            return i;
    }
    return -1;
}

/****************************************************************************
 * Searches for guess and returns if found, already found, or not found
 * @param fillTheBlanks - character array to search through
 *                        to check if character was already found
 * @param guess         - search target
 * @return FOUND_TYPE 
 ****************************************************************************/
FOUND_TYPE foundLetter(char fillTheBlanks[], char guess)
{
    // Check first if letter was already found
    int i = search(fillTheBlanks, guess);
    if (i != -1) // if not NULL
        return ALREADY_FOUND;

    // Check if letter was not found in fills
    i = search(WORD, guess);
    if (i == -1) // if null
        return NOT_FOUND; 

    // Check if letter was found in the WORD
    while (i != -1)
    {
        int indexFound = i;
        fillTheBlanks[indexFound] = guess; // fill in the blanks
        i = search(WORD, guess, i+1);
    }
    return FOUND;
}

/****************************************************************************
 * Increments/Decrements score or strikes depending on search results
 * @param game   - game variables
 * @param player - player variables
 * @param guess  - user's guess
 ****************************************************************************/
void foundLetter(Game *game, Player *player, char guess)
{  
    // Find the letter guessed by user in the word
    FOUND_TYPE result = foundLetter(game->fillTheBlanks, guess);
    if (result == NOT_FOUND)
    {
        player->currentScore--;
        player->strikes++;
        // Draw hangman when user guess wrong
        drawHangman(game, player);
        cout << "\nIncorrect! "; 
        cout << "Score: " << player->currentScore << endl;
    }
    else
    {
        if (result == FOUND)
        {
            player->currentScore += 5;
            cout << "Correct! ";
            cout << "Score: " << player->currentScore << endl;
        }
        else
            cout << "Letter was already found." << endl;             
    }
}

/****************************************************************************
 * Selection Sorts player: scores, words, results
 * @param player - player variables
 ****************************************************************************/
void selectionSort(Player *player)
{     
    int indexOfLargerValue;
    int size = player->allScores.size();
    
    for (int index = 0; index < (size-1); index++)
    {
        indexOfLargerValue = getIndexOfLargestValue(player->allScores, index);
        swap(player->allScores,  index, indexOfLargerValue);
        swap(player->allWords,   index, indexOfLargerValue);
        swap(player->allResults, index, indexOfLargerValue);
    }
}

/****************************************************************************
 * Grabs the index of the largest value in vector
 * @param allScores - the vector to sort
 * @param index     - index of current larger value
 * @return the index of the larger value
 ****************************************************************************/
int getIndexOfLargestValue(vector<int> &allScores, int index) 
{
    int larger = allScores[index];
    int indexOfLargerValue = index;

    // Go through the array and compare the next values in the array
    // to the current smaller value.
    for (int nextIndex = index + 1; nextIndex < allScores.size(); nextIndex++)
    {
        // If the value of smaller is greater than that of a[nextIndex]
        // assign smaller to the next index's value and
        // assign the index of the smaller value to be the next index.
        if (larger < allScores[nextIndex])
        {
            larger = allScores[nextIndex];
            indexOfLargerValue = nextIndex;
        }
    }
    return indexOfLargerValue;
}

/****************************************************************************
 * Swaps values in a vector
 * @param a - vector to sort
 * @param i - index to sort
 * @param j - next index to sort
 ****************************************************************************/
void swap(vector<int> &a, int i, int j) 
{
   // swaps values.
   int temp = a[i];
   a[i] = a[j];
   a[j] = temp;
}

/****************************************************************************
 * Swaps values in a vector
 * @param a - vector to sort
 * @param i - index to sort
 * @param j - next index to sort
 ****************************************************************************/
void swap(vector<string> &a, int i, int j) 
{
   // swaps values.
   string temp = a[i];
   a[i] = a[j];
   a[j] = temp;
}

/****************************************************************************
 * Output the user's results to a file
 * @param player - player variables
 * @param myfile - the file to output into
 ****************************************************************************/
void outputToFile(Player *player, ofstream &myfile)
{
    // Output a file when game is complete
    myfile << "Your Results per Game Played: " << endl << endl;
    myfile << setw(15) << left << "Word";
    myfile << setw(10) << left << "Result"; 
    myfile << setw(4)  << "Score" << endl;
    
    for (int i = 0; i < player->allScores.size(); i++)
    {
        myfile << setw(15) << left << player->allWords[i];
        myfile << setw(10) << left << player->allResults[i]; 
        myfile << setw(4)  << player->allScores[i] << endl;
    }
    myfile << endl;
}

/****************************************************************************
 * Asks user if they would like to play again
 * @return true if user wants to repeat game else false
 ****************************************************************************/
bool repeatGame()
{
    cout << endl << endl;
    bool valid = false;
    while ( !valid )
    {
        char input;
        cout << "Play Again(y/n)? ";
        cin  >> input;  

        switch(input)
        {
            case 'Y':
            case 'y': { valid = true; return true;  break; }
            case 'N':
            case 'n': { valid = true; return false; break; }
            default:  { break; }
        };
    } 
    return false;
}