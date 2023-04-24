#include "Errors.h"
#include "Move.h"

// Space for implementing Move functions.

Move::Move(const std::string& input) {
    std::istringstream tic_stream(input);
    tic_stream >> number >> player >> row >> column;

    if (tic_stream.fail()) {
        throw ParseError("Parse error");
    }

    if (!tic_stream) {
        tic_stream >> hashtag >> comment;
    }

    if (tic_stream.fail()) {
        throw ParseError("Parse error");
    }

    player = toupper(player);
    row = toupper(row);
    

    if (!(num_checker(number) && player_checker(player) && row_checker(row) 
    && column_checker(column) && hashtag_checker(hashtag))){
        throw ParseError("Parse error");
    }
}

bool Move::num_checker(int num) {
    return num > 0;
}

bool Move::player_checker(char player) {
    return player == 'X' || player == 'O';
}

bool Move::row_checker(char row) { 
    return row >= 'A' && row <= 'C';
}

bool Move::column_checker(int column) {
    return column >= 1 && column <= 3;
}

bool Move::hashtag_checker(char hashtag) {
  return hashtag == '#';
}


std::ostream& operator<<(std::ostream& stream, const Move& move) {
    stream << move.number << " " << move.player << " " << move.row << " " << move.column;
    if (move.hashtag != '\0') {
        stream << " # " << move.comment;
    }
    return stream;
}
