#include "Database.h"

// Database Member Functions

Database* Database::create() {
  return new Database();
}

Database::Database(){

}

Database::~Database(){
  
}

void Database::insert(const Report* report){

}

std::vector<const Report*> Database::search(float age, float height, float weight) const {
  std::vector<const Report*> temp;
  return temp;
}

void Database::remove(unsigned int id){

}