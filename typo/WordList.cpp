#include "WordList.h"
#include <math.h> 

WordList::WordList(std::istream& stream){
    std::string stream_string;
    while (stream>>stream_string)
    {
        bool lower = true;
        int str_len = stream_string.length();
        for (int i = 0; i < str_len; i ++){
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
    //given vector of points, make sure words from mWords is of the same length, and
    // then score using euclidean distance and scoring equation 
    Heap wordlist = Heap(maxcount);
    int mLen = mWords.size();
    int pLen = points.size();
    
    for (int i = 0; i < mLen; i++){
        float total = 0;
        int strLen = mWords[i].length();
        if (strLen != pLen) {
            continue;
        }
        for (int j = 0; j < strLen; j++){
            int index = mWords[i][j] - 'a';
            Point alphabet = QWERTY[index];
            float euclid = sqrt(pow(alphabet.x - points.at(j).x, 2)+pow(alphabet.y - points.at(j).y, 2));
            float score = 1/(10 * pow(euclid, 2) +1);
            total+=score;
        }
        float avg = total/strLen;
        if (avg >= cutoff){
            if (wordlist.count() == maxcount){
                if (avg >= wordlist.top().score){
                    wordlist.pushpop(mWords[i], avg);
                }
            } else {
                wordlist.push(mWords[i], avg);
            } 
        }
    }

    
    return wordlist;
}