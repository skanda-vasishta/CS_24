#include "Database.h"
#include <iterator>


// Database Member Functions

Database* Database::create() {
  return new Database();
}

Database::Database(){
  
}

Database::~Database(){
  for (auto i : database){
    delete i;
  }
}

void Database::insert(const Report* report){
  if (database.find(report) != database.end()){
    throw DuplicateReport(report->id);
  }
  database.emplace(report);
}

bool Database::within_range(const Report* report, float age, float height, float weight) const{
  if (age >= report->age.min && age <= report->age.max && 
        height >= report->height.min && height <= report->height.max &&
        weight >= report->weight.min && weight <= report->weight.max) {
          return true;
  }
  return false;
}

std::vector<const Report*> Database::search(float age, float height, float weight) const {
  std::vector<const Report*> found;
  for (auto const i : database){
    if (within_range(i, age, height, weight)) {
        //if (std::find(found.begin(), found.end(), i) == found.end()){
          found.push_back(i);
        //}
      }
  }

  return found;
}

void Database::remove(unsigned int id){
  for (auto const i : database){
    if (i->id == id){
      database.erase(i);
      delete i;
      return;
    }
  }
  throw NoSuchReport(id);
}