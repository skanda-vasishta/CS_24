#ifndef BOARD_H
#define BOARD_H

#include "Move.h"

// I recommended writing a Board class to manage your game state.
// Here's some space for the class definition; member functions go in Board.cpp.
class Board {
private:
    char board[3][3];
    int moves;
    char turn;
    int size;
    bool win;
    char result;



public:
    Board(const Move& move);
    void play(const Move& move);
    bool check_winner();


};
#endif
