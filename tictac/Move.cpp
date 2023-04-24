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

    /* if (!tic_stream) {
        tic_stream >> hashtag;
        if (tic_stream.fail() || !hashtag_checker(hashtag)) {
            throw ParseError("incorrect hashtag format");
        }
    }

    if (!tic_stream) {
        tic_stream >> whitespace;
        if (tic_stream.fail() || !whitespace_checker(hashtag)) {
            throw ParseError("incorrect comment format");
        }
    }

    if (!tic_stream) {
        tic_stream >> comment;
        if (tic_stream.fail() || !hashtag_checker(hashtag)) {
            throw ParseError("incorrect comment format");
        }
    } */
    std::string hashtag_and_comment;
    std::getline(tic_stream >> std::ws, hashtag_and_comment);
    if (!hashtag_and_comment.empty() && hashtag_and_comment[0] == '#') {
        if (hashtag_and_comment.size() > 1 && hashtag_and_comment[1] == ' ') {
            hashtag = '#';
            comment = hashtag_and_comment.substr(2);
        } else {
            throw ParseError("Incorrect comment format");
        }
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

bool Move::whitespace_checker(char whitespace){
    return whitespace == ' ';
}


std::ostream& operator<<(std::ostream& stream, const Move& move) {
    stream << move.number << " " << move.player << " " << move.row << move.column;
   //if (move.hashtag == '#') {
    //    stream << " # " << move.comment;
   // }
    return stream;
}
