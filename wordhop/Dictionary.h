#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <istream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include "Errors.h"

class Dictionary {
  // Member Variables
//implement constructor
 // Dictionary();
  // Helper Functions
public:

  Dictionary(std::istream& stream);
  // The create function used by the autograder:

  static Dictionary* create(std::istream& stream);

public:
  // The function that does all the work:
  std::vector<std::string> hop(const std::string& from, const std::string& to);
  std::unordered_set<std::string> validwords(const std::string& word);



private:
  std::unordered_set<std::string> words_;
};



#endif
