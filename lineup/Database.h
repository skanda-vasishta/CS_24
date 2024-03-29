#ifndef DATABASE_H
#define DATABASE_H

#include <vector>

#include "Report.h"
#include <unordered_map>
#include <string>
#include <unordered_set>
#include "Errors.h"
#include <algorithm>


class Database {
  // Member Variables
std::unordered_map<unsigned int, const Report*> database;
  // Helper Functions

public:
  static Database* create();

public:
  Database();
  ~Database();

  void insert(const Report* report);
  std::vector<const Report*> search(float age, float height, float weight) const;
  void remove(unsigned int id);
  bool within_range(const Report* report, float age, float height, float weight) const;
};

#endif
