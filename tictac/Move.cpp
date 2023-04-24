#include "Errors.h"
#include "Move.h"

// Space for implementing Move functions.

Move::Move(const std::string& input) {
    std::istringstream tic_stream(input);
    tic_stream >> number;
    if (tic_stream.fail() || !num_checker(number)){
        throw ParseError("Incorrect number format");
    }

    tic_stream >> player;
    player = toupper(player);
    if (tic_stream.fail() || !player_checker(player)){
        throw ParseError("incorrect player format");
    }

    tic_stream >> row;
    row = toupper(row);
    if (tic_stream.fail() || !row_checker(row)){
        throw ParseError("incorrect row format");
    }

    tic_stream >> column;
    if (tic_stream.fail() || !column_checker(column)){
        throw ParseError("incorrect column format");
    }

     if (!tic_stream) {
        tic_stream >> hashtag;
        if (tic_stream.fail() || !hashtag_checker(hashtag)) {
            throw ParseError("incorrect hashtag format");
        } else {
            tic_stream >> comment;
            if (tic_stream.fail()) {
            throw ParseError("incorrect comment format");
        } 
        }
    } 


 /*   if (tic_stream.fail()) {
        throw ParseError("Parse error");
    }

    if (!tic_stream) {
        tic_stream >> hashtag >> comment;
    }

    if (tic_stream.fail()) {
        throw ParseError("Parse error");
    }

    player = toupper(player);
    row = toupper(row); */


   /* if (!(num_checker(number) && player_checker(player) && row_checker(row) 
    && column_checker(column) && hashtag_checker(hashtag))){
        throw ParseError("Parse error");
    } */
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
    stream << move.number << " " << move.player << " " << move.row << move.column;
   // if (move.hashtag == "#") {
        //stream << " # " << move.comment;
    //}
    return stream;
}
