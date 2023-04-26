#include "Errors.h"
#include "Move.h"

// Space for implementing Move functions.

Move::Move(const std::string& input) {
    std::istringstream tic_stream(input);
    
    if (!isdigit(tic_stream.peek())){
        throw ParseError("Incorrect whitespace format");
    }

    tic_stream >> number;
    if (tic_stream.fail() || !num_checker(number)){
        throw ParseError("Incorrect number format");
    }

    if (!(tic_stream.get(whitespace))|| !(std::isspace(whitespace))) {
        throw ParseError("Missing whitespace");
    }
 
    tic_stream >> player;
    player = toupper(player);
    if (tic_stream.fail() || !player_checker(player)){
        throw ParseError("incorrect player format");
    }

    if (!(tic_stream.get(whitespace))|| !(std::isspace(whitespace))) {
        throw ParseError("Missing whitespace");
    }

    tic_stream >> row;
    row = toupper(row);
    if (tic_stream.fail() || !row_checker(row)) {
        throw ParseError("incorrect row format");
    }

    if (isspace(tic_stream.peek())){
        throw ParseError("Incorrect whitespace format");
    }

    tic_stream >> column;
    if (tic_stream.fail() || !column_checker(column)){
        throw ParseError("incorrect column format");
    }

    if (isspace(tic_stream.peek())){
        tic_stream >> std::ws;
        if (tic_stream.peek() == '#') {
            tic_stream >> hashtag;
            if (tic_stream.fail() || !hashtag_checker(hashtag)) {
                throw ParseError("incorrect hashtag format");
            } else {
                std::getline(tic_stream >> std::ws, comment);
                if (comment.empty()) {
                    throw ParseError("incorrect comment format");
                } 
            }
        } else {
            while (tic_stream){
                if (!isspace(tic_stream.peek())){
                    throw ParseError("incorrect comment format");
                }
            }
            
        }
    } else if (!isspace(tic_stream.peek())) {
        if (tic_stream){
            throw ParseError("incorrect comment format");
        }
    }
    /*if (!tic_stream) {
        if (!(tic_stream.get(whitespace))|| !(std::isspace(whitespace))) {
            throw ParseError("Missing whitespace");
        }
        if (!isspace(tic_stream.peek())){
            throw ParseError("Incorrect whitespace format");
        }
        tic_stream >> hashtag;
        if (tic_stream.fail() || !hashtag_checker(hashtag)) {
            throw ParseError("incorrect hashtag format");
        } else {
            std::getline(tic_stream >> std::ws, comment);
            if (tic_stream.fail()) {
                throw ParseError("incorrect comment format");
            } 
        }
    } */

}

bool Move::num_checker(int num) {
    return num >0 && num <=9;
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
    return stream;
}
