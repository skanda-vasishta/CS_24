#include "WordList.h"
WordList::WordList(std::istream& stream){
    //parse stream into mWords
    std::string stream_string;
    while (stream>>stream_string)
    {
        bool lower = true;
        for (int i = 0; i < stream_string.size(); i ++){
            if (!islower(stream_string[i])){
                lower = false;
                break;
            }
        }
        if (lower){
            mWords.push_back(stream_string);
        }
    }
    
}

Heap WordList::correct(const std::vector<Point>& points, size_t maxcount, float cutoff) const{
    return Heap(maxcount);
}