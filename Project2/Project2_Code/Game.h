/* 
 * File:   Game.h
 * Author: Tati
 * Created on February 11, 2015, 12:38 PM
 */

#ifndef GAME_H
#define	GAME_H

#define ROW 6
#define COL 2

struct Game
{
    int         wordLength;
    char        *fillTheBlanks;
    std::string hangman[ROW][COL]; 
    
    // Initializes variables    
    Game(int w)
    {
        wordLength    = w;
        fillTheBlanks = new char[w];
        for (int i = 0; i < ROW; i++) // Initialize the hangman string to empty
            for (int j = 0; j < COL; j++)
                hangman[i][j] = "";
    } 
};

#endif	/* GAME_H */