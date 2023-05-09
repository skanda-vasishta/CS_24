#include "Person.h"


Person::Person(const std::string& name, Gender& gender, Person* mother, Person* father) {
   this->personName = name;
    this->personGender = gender;
    this->momName = mother;
    this->dadName = father;
}

// Person Member Functions
 const std::string& Person::name()   const{

 }

  Gender             Person::gender() const{

  }
  
  Person*            Person::mother(){

  }

  Person*            Person::father(){

  }

  // Required Relationship Functions
  std::set<Person*> Person::ancestors(PMod pmod = PMod::ANY){

  }

  std::set<Person*> Person::aunts(PMod pmod = PMod::ANY, SMod smod = SMod::ANY){

  }

  std::set<Person*> Person::brothers(PMod pmod = PMod::ANY, SMod smod = SMod::ANY){

  }

  std::set<Person*> Person::children(){

  }

  std::set<Person*> Person::cousins(PMod pmod = PMod::ANY, SMod smod = SMod::ANY){

  }

  std::set<Person*> Person::daughters(){

  }

  std::set<Person*> Person::descendants(){

  }

  std::set<Person*> Person::grandchildren(){

  }

  std::set<Person*> Person::granddaughters(){

  }

  std::set<Person*> Person::grandfathers(PMod pmod = PMod::ANY){

  }

  std::set<Person*> Person::grandmothers(PMod pmod = PMod::ANY){

  }

  std::set<Person*> Person::grandparents(PMod pmod = PMod::ANY){

  }

  std::set<Person*> Person::grandsons(){

  }

  std::set<Person*> Person::nephews(PMod pmod = PMod::ANY, SMod smod = SMod::ANY){

  }

  std::set<Person*> Person::nieces(PMod pmod = PMod::ANY, SMod smod = SMod::ANY){

  }

  std::set<Person*> Person::parents(PMod pmod = PMod::ANY){

  }

  std::set<Person*> Person::siblings(PMod pmod = PMod::ANY, SMod smod = SMod::ANY){

  }

  std::set<Person*> Person::sisters(PMod pmod = PMod::ANY, SMod smod = SMod::ANY){

  }

  std::set<Person*> Person::sons(){

  }

  std::set<Person*> Person::uncles(PMod pmod = PMod::ANY, SMod smod = SMod::ANY){

  }
