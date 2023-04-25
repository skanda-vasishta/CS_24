#include "Errors.h"
#include "Board.h"

// Space for implementing Board functions.
Board::Board(const Move& move){
    size = 3;
    moves = 0;
    current_player = move.player;
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; i++){
            board[i][j] = ' ';
        }
    }
}

void Board::play(const Move& move){
   //takes move object as parameter and applies move on board
   char newrow = move.row;
   int rownum;
   if (newrow == 'A'){
    rownum = 0; 
   } else if (newrow == 'B'){
    rownum = 1;
   } else if (newrow == 'C'){
    rownum = 2;
   }
   int newcol = move.column - 1;
    
   if (board[newrow][newcol] == 'X' || board[newrow][newcol] == 'O') {
        throw InvalidMove("Invalid square");
    }
   board[newrow][newcol] = current_player;

   if (check_winner()){
     result = move.player;
   }
   if (moves == 9 && !check_winner()){
     result = 'D';
   }
   moves++;

}

bool Board::check_winner() {
    for (int i = 0; i < size; i++) {
        bool win = true;
        for (int j = 1; j < size; j++) {
            if (board[i][j] != board[i][0]) {
                win = false;
                break;
            }
        }
        if (win) {
            return true;
        }
    }

    for (int i = 0; i < size; i++) {
        bool win = true;
        for (int j = 1; j < size; j++) {
            if (board[j][i] != board[0][i]) {
                win = false;
                break;
            }
        }
        if (win) {
            return true;
        }
    }

    bool win = true;
    for (int i = 1; i < size; i++) {
        if (board[i][i] != board[0][0]) {
            win = false;
            break;
        }
    }
    if (win) {
        return true;
    }

    win = true;
    for (int i = 1; i < size; i++) {
        if (board[size - i - 1][i] != board[size - 1][0]) {
            win = false;
            break;
        }
    }
    if (win) {
        return true;
    }

    return false;
}
