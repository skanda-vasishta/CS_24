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
public:
  Dictionary(std::istream& stream);
  static Dictionary* create(std::istream& stream);
  std::vector<std::string> hop(const std::string& from, const std::string& to);
  ~Dictionary();

private:
  std::unordered_set<std::string> words_;
  std::unordered_set<std::string> validwords(const std::string& word);
};

#endif