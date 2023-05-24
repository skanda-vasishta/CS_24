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
   Heap wordlist(maxcount);
    size_t pointsLen = points.size();

    for (const auto& word : mWords) {
        size_t wordLen = word.length();
        if (wordLen != pointsLen) {
            continue;
        }

        float totalScore = 0.0;
        for (size_t i = 0; i < wordLen; i++) {
            int index = word[i] - 'a';
            Point alphabet = QWERTY[index];
            float euclidean = sqrt(pow(alphabet.x - points[i].x, 2) + pow(alphabet.y - points[i].y, 2));
            float score = 1.0 / (10 * pow(euclidean, 2) + 1);
            totalScore += score;
        }

        float avgScore = totalScore / wordLen;
        if (avgScore > cutoff) {
            wordlist.push(word, avgScore);
        }
    }

    return wordlist;
}