/* 
 * File:   Player.h
 * Author: Tati
 * Created on February 9, 2015, 10:36 PM
 * Database for player
 */

#ifndef PLAYER_H
#define	PLAYER_H

#include <vector>
#include <string>
#include <string.h>

struct Player
{
    // Initializes variables
    Player(): currentScore(0), strikes(0), hints(0), currentResult("") {}
    // Current Game Variables
    int                 currentScore;   // User's score
    int                 strikes;        // User's strikes
    int                 hints;          // User's number of hints used 
    std::string         currentResult;  // User's result
    // All Game Variables
    std::vector<int>    allScores;  
    std::vector<string> allWords;  
    std::vector<string> allResults;
};

#endif	/* PLAYER_H */