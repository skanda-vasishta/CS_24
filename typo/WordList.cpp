#include "WordList.h"
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
    for (int i = 0; i < mWords.size(); i++){
        Point point = points.at(i);
        if (mWords[i].length() == sizeof(point) ){
            float total = 0;
            for (int j = 0; i < mWords[i].length(); j++){
                int index = mWords[i][j] - 65;
                Point alphabet = QWERTY[index];
                float euclid = sqrt(pow(alphabet.x - point.x, 2)+pow(alphabet.y - point.y, 2));
                float score = 1/(10 * pow(euclid, 2) +1);
                total+=score;
            }
            total = total/mWords[i].length();
            if (total > cutoff){
                wordlist.push(mWords[i], total);
            }
        }
    }

    
    return wordlist;
}