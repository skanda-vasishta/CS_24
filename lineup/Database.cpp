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

std::vector<const Report*> Database::search(float age, float height, float weight) const {
  std::vector<const Report*> found;
  for (auto i : database){
    if (age > i->age.min && age < i->age.max && 
        height > i->height.min && height < i->height.max &&
        weight > i->weight.min && weight < i->weight.max) 
      {
        found.push_back(i);
      }
  }

  return found;
}

void Database::remove(unsigned int id){

}