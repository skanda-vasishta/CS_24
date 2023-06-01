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
  struct graph{};
public:

  Dictionary(std::istream& stream);
  static Dictionary* create(std::istream& stream);

public:
  std::vector<std::string> hop(const std::string& from, const std::string& to);
  std::unordered_set<std::string> validWords(const std::string& word);

private:
  std::unordered_set<std::string> words_;
  std::unordered_map<std::string, std::unordered_set<std::string>> validWordsMap_;
};

#endif
