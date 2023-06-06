#include "Database.h"
#include <iterator>


// Database Member Functions

Database* Database::create() {
  return new Database();
}

Database::Database() {
}

Database::~Database() {
  for (auto const& pair : database) {
    delete pair.second;
  }
}

void Database::insert(const Report* report) {
  if (database.find(report->id) != database.end()) {
    throw DuplicateReport(report->id);
  }
  database.emplace(report->id, report);
}

bool Database::within_range(const Report* report, float age, float height, float weight) const {
  if (age >= report->age.min && age <= report->age.max &&
      height >= report->height.min && height <= report->height.max &&
      weight >= report->weight.min && weight <= report->weight.max) {
    return true;
  }
  return false;
}

std::vector<const Report*> Database::search(float age, float height, float weight) const {
  std::vector<const Report*> found;
  for (auto const& pair : database) {
    const Report* report = pair.second;
    if (within_range(report, age, height, weight)) {
      found.push_back(report);
    }
  }
  return found;
}

void Database::remove(unsigned int id) {
  auto iter = database.find(id);
  if (iter != database.end()) {
    const Report* report = iter->second;
    database.erase(iter);
    delete report;
  } else {
    throw NoSuchReport(id);
  }
}
