#include "Errors.h"
#include "Board.h"

// Space for implementing Board functions.
Board::Board(){
    size = 3;
    moves = 1;
    result = ' ';
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            board[i][j] = ' ';
        }
    }
}

void Board::play(const Move& move){
    current_player = move.player;
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

    if (board[rownum][newcol] == 'X' || board[rownum][newcol] == 'O') {
        throw InvalidMove("Invalid square");
    }
    if (move.number != moves){
        throw InvalidMove("Wrong move number");
    }
   board[rownum][newcol] = current_player;

  if (check_winner()){
    result = current_player;
   }
   if (moves == 9 && !check_winner()){
     result = 'D';
   }
   moves++;

}

bool Board::check_winner() {
     for (int i = 0; i < size; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < size; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return true;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return true;
    }

    return false;

}

int Board::get_size() const {
    return size;
}
int Board::get_moves() const {
    return moves;
}

char Board::get_result() const {
    return result;
}
char Board::get_player() const {
    return current_player;
}