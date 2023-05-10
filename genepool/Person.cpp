
#include "Person.h"


Person::Person(const std::string& name, Gender& gender, Person* mother, Person* father) {
   this->personName = name;
    this->personGender = gender;
    this->momName = mother;
    this->dadName = father;
}

// Person Member Functions
 const std::string& Person::name()   const{
    return this->personName;
 }

  Gender             Person::gender() const{
    return this->personGender;
  }
  
  Person*            Person::mother(){
    return this->momName;
  }

  Person*            Person::father(){
    return this->dadName;
  }

  /*void Person::add_child(Person* child) const{
    getchild->insert(child);
  }
  const std::set<Person*>* Person::get_children() const {
    return this->getchild;
}*/

  // Required Relationship Functions
  std::set<Person*> Person::ancestors(PMod pmod){
    std::set<Person*> result;
    if (this->mother() != nullptr){
        result.insert(this->mother());
    }
    if (this->father() != nullptr){
        result.insert(this->father());
    }
    return result;

  }

  std::set<Person*> Person::aunts(PMod pmod, SMod smod){
    std::set<Person*> result;
    if (this->mother() != nullptr){
        result.insert(this->mother());
    }
    if (this->father() != nullptr){
        result.insert(this->father());
    }
    return result;

  }

  std::set<Person*> Person::brothers(PMod pmod, SMod smod ){
    std::set<Person*> result;
    if (this->mother() != nullptr){
        result.insert(this->mother());
    }
    if (this->father() != nullptr){
        result.insert(this->father());
    }
    return result;

  }

  std::set<Person*> Person::children(){
    std::set<Person*> result;
    /*if (getchild){
      for (auto child: *getchild){
        if (child){
          result.insert(child);
        }
      }  
  }*/
  return result;
}

  std::set<Person*> Person::cousins(PMod pmod, SMod smod ){
    std::set<Person*> result;
    if (this->mother() != nullptr){
        result.insert(this->mother());
    }
    if (this->father() != nullptr){
        result.insert(this->father());
    }
    return result;

  }

  std::set<Person*> Person::daughters(){
    std::set<Person*> result;
    if (this->mother() != nullptr){
        result.insert(this->mother());
    }
    if (this->father() != nullptr){
        result.insert(this->father());
    }
    return result;

  }

  std::set<Person*> Person::descendants(){
    std::set<Person*> result;
    if (this->mother() != nullptr){
        result.insert(this->mother());
    }
    if (this->father() != nullptr){
        result.insert(this->father());
    }
    return result;

  }

  std::set<Person*> Person::grandchildren(){
    std::set<Person*> result;
    if (this->mother() != nullptr){
        result.insert(this->mother());
    }
    if (this->father() != nullptr){
        result.insert(this->father());
    }
    return result;

  }

  std::set<Person*> Person::granddaughters(){
    std::set<Person*> result;
    if (this->mother() != nullptr){
        result.insert(this->mother());
    }
    if (this->father() != nullptr){
        result.insert(this->father());
    }
    return result;

  }

  std::set<Person*> Person::grandfathers(PMod pmod){
    std::set<Person*> result;
    if (this->father()->father() != nullptr){
        result.insert(this->father()->father());
    }
    return result;
  }

  std::set<Person*> Person::grandmothers(PMod pmod){
    std::set<Person*> result;
    if (this->mother()->mother() != nullptr){
        result.insert(this->mother()->mother());
    }
    return result;

  }

  std::set<Person*> Person::grandparents(PMod pmod ){
    std::set<Person*> result;
    
    return result;

  }

  std::set<Person*> Person::grandsons(){
    std::set<Person*> result;
    if (this->mother() != nullptr){
        result.insert(this->mother());
    }
    if (this->father() != nullptr){
        result.insert(this->father());
    }
    return result;

  }

  std::set<Person*> Person::nephews(PMod pmod , SMod smod){
    std::set<Person*> result;
    if (this->mother() != nullptr){
        result.insert(this->mother());
    }
    if (this->father() != nullptr){
        result.insert(this->father());
    }
    return result;

  }

  std::set<Person*> Person::nieces(PMod pmod , SMod smod){
    std::set<Person*> result;
    if (this->mother() != nullptr){
        result.insert(this->mother());
    }
    if (this->father() != nullptr){
        result.insert(this->father());
    }
    return result;

  }

  std::set<Person*> Person::parents(PMod pmod){
    std::set<Person*> result;
    if (this->mother() != nullptr){
        result.insert(this->mother());
    }
    if (this->father() != nullptr){
        result.insert(this->father());
    }
    return result;


  }

  std::set<Person*> Person::siblings(PMod pmod, SMod smod ){
    std::set<Person*> result;
    if (this->mother() != nullptr){
        result.insert(this->mother());
    }
    if (this->father() != nullptr){
        result.insert(this->father());
    }
    return result;

  }

  std::set<Person*> Person::sisters(PMod pmod , SMod smod ){
    std::set<Person*> result;
    if (this->mother() != nullptr){
        result.insert(this->mother());
    }
    if (this->father() != nullptr){
        result.insert(this->father());
    }
    return result;

  }

  std::set<Person*> Person::sons(){
    std::set<Person*> result;
    if (this->mother() != nullptr){
        result.insert(this->mother());
    }
    if (this->father() != nullptr){
        result.insert(this->father());
    }
    return result;

  }

  std::set<Person*> Person::uncles(PMod pmod , SMod smod ){
    std::set<Person*> result;
    if (this->mother() != nullptr){
        result.insert(this->mother());
    }
    if (this->father() != nullptr){
        result.insert(this->father());
    }
    return result;

  }