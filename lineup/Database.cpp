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
  for (auto i : database){
    if (i == report){
      throw DuplicateReport(report->id);
    }
  }
  database.emplace(report);
}

std::vector<const Report*> Database::search(float age, float height, float weight) const {
  std::vector<const Report*> temp;
  return temp;
}

void Database::remove(unsigned int id){

}