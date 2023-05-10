
#include "Person.h"
#include <algorithm>



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

  const std::set<Person*>* Person::get_children() const {
    return &getchild;
  }
  void Person::addchild(Person* child){
    getchild.insert(child);
  }

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
    std::set<Person*> parent = this->parents(pmod);
    for (Person* par : parent){
      std::set<Person*> sister = this->sisters(pmod, smod);
      for (Person* sis : sister){
        result.insert(sis);
      }
    }
    return result;
  }

  std::set<Person*> Person::brothers(PMod pmod, SMod smod ){
    std::set<Person*> result;
    std::set<Person*> brother_set = this->siblings(pmod, smod);
    for (Person* brother: brother_set){
      if (brother->gender() == Gender::MALE){
        result.insert(brother);
      }
    }
    return result;

  }

  std::set<Person*> Person::children(){
    std::set<Person*> result;
    if (this->get_children() != nullptr){
      const std::set<Person*>& childrenSet = *(this->get_children());
      result.insert(childrenSet.begin(), childrenSet.end());
    }
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
    std::set<Person*>kids = this->children();
    for (Person* daughter: kids){
      if (daughter->gender() == Gender::FEMALE){
        result.insert(daughter);
      }
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

std::set<Person*> Person::grandchildren() {
    std::set<Person*> result;
    std::set<Person*> children_set = this->children();
    for (Person* child : children_set) {
        std::set<Person*> grandchildren_set = child->children();
        result.insert(grandchildren_set.begin(), grandchildren_set.end());
    }
    return result;
}


  std::set<Person*> Person::granddaughters(){
    std::set<Person*> result;
    std::set<Person*> grandkids = this->grandchildren();
    for (Person* kid : grandkids){
      if (kid->gender() == Gender::FEMALE){
        result.insert(kid);
      }
    }
    return result;
  }

std::set<Person*> Person::grandfathers(PMod pmod){
    std::set<Person*> result;
    if (pmod ==  PMod::MATERNAL || pmod == PMod::ANY){
        if (this->mother() != nullptr){
            if (this->mother()->father() != nullptr){
                result.insert(this->mother()->father());
            }
        }
    }
    if (pmod ==  PMod::PATERNAL || pmod == PMod::ANY){
        if (this->father() != nullptr){
            if (this->father()->father() != nullptr){
                result.insert(this->father()->father());
            }
        }
    }
    return result;
}

std::set<Person*> Person::grandmothers(PMod pmod){
    std::set<Person*> result;
    if (pmod ==  PMod::MATERNAL || pmod == PMod::ANY){
        if (this->mother() != nullptr){
            if (this->mother()->mother() != nullptr){
                result.insert(this->mother()->mother());
            }
        }
    }
    if (pmod ==  PMod::PATERNAL || pmod == PMod::ANY){
        if (this->father() != nullptr){
            if (this->father()->mother() != nullptr){
                result.insert(this->father()->mother());
            }
        }
    }
    return result;
}


  std::set<Person*> Person::grandparents(PMod pmod ){
    std::set<Person*> result;
    std::set<Person*> grandfathers = this->grandfathers(pmod);
    std::set<Person*> grandmothers = this->grandmothers(pmod);

    std::merge(grandfathers.begin(), grandfathers.end(), grandmothers.begin(), grandmothers.end(), std::inserter(result, result.end()));
    //result.std::merge(grandfathers);
    //result.std::merge(grandmothers);
    return result;

  }

  std::set<Person*> Person::grandsons(){
    std::set<Person*> result;
    std::set<Person*> grandkids = this->grandchildren();
    for (Person* kid : grandkids){
      if (kid->gender() == Gender::MALE){
        result.insert(kid);
      }
    }
    return result;
  }


  std::set<Person*> Person::nephews(PMod pmod , SMod smod){
    std::set<Person*> result;
    std::set<Person*> sibs = this->siblings(pmod,smod);
    for (Person* sib : sibs){
      std::set<Person*> kids = this->sons();
      for (Person* kid : kids){
        result.insert(kid);
      }
    }
    return result;
  }

  std::set<Person*> Person::nieces(PMod pmod , SMod smod){
    std::set<Person*> result;
    std::set<Person*> sibs = this->siblings(pmod,smod);
    for (Person* sib : sibs){
      std::set<Person*> kids = this->daughters();
      for (Person* kid : kids){
        result.insert(kid);
      }
    }
    return result;
  }

  std::set<Person*> Person::parents(PMod pmod) {
    std::set<Person*> result;
    if (pmod == PMod::MATERNAL || pmod == PMod::ANY) {
        if (this->mother() != nullptr) {
            result.insert(this->mother());
        }
    }
    if (pmod == PMod::PATERNAL || pmod == PMod::ANY) {
        if (this->father() != nullptr) {
            result.insert(this->father());
        }
    }
    return result;
}


std::set<Person*> Person::siblings(PMod pmod, SMod smod) {
    std::set<Person*> result;
    std::set<Person*> parent_set = this->parents();
    for (Person* parent : parent_set) {
        std::set<Person*> child_set = parent->children();
        for (Person* child : child_set) {
            if (child != this) {  
                if (pmod == PMod::MATERNAL && parent == this->mother()) {
                    if (smod == SMod::FULL) {
                        if (child->mother() == this->mother() && child->father() == this->father()
                                && child->mother() != nullptr && child->father() != nullptr) {
                            result.insert(child);
                        }
                    } else if (smod == SMod::HALF) {
                        if ((child->mother() == this->mother() && (child->father() == nullptr || child->father() != this->father()))
                                || (child->father() == this->father() && (child->mother() == nullptr || child->mother() != this->mother()))) {
                            result.insert(child);
                        }
                    } else {  
                        result.insert(child);
                    }
                } else if (pmod == PMod::PATERNAL && parent == this->father()) {
                    if (smod == SMod::FULL) {
                        if (child->mother() == this->mother() && child->father() == this->father()
                                && child->mother() != nullptr && child->father() != nullptr) {
                            result.insert(child);
                        }
                    } else if (smod == SMod::HALF) {
                        if ((child->mother() == this->mother() && (child->father() == nullptr || child->father() != this->father()))
                                || (child->father() == this->father() && (child->mother() == nullptr || child->mother() != this->mother()))) {
                            result.insert(child);
                        }
                    } else {  
                        result.insert(child);
                    }
                } else if (pmod == PMod::ANY && (parent == this->mother() || parent == this->father())) {
                    if (smod == SMod::FULL) {
                        if (child->mother() == this->mother() && child->father() == this->father()
                                && child->mother() != nullptr && child->father() != nullptr) {
                            result.insert(child);
                        }
                    } else if (smod == SMod::HALF) {
                        if ((child->mother() == this->mother() && (child->father() == nullptr || child->father() != this->father()))
                                || (child->father() == this->father() && (child->mother() == nullptr || child->mother() != this->mother()))) {
                            result.insert(child);
                        }
                    } else {  
                        result.insert(child);
                    }
                }
            }
        }
    }
    return result;
}



  std::set<Person*> Person::sisters(PMod pmod , SMod smod ){
    std::set<Person*> result;
    std::set<Person*> sister_set = this->siblings(pmod, smod);
    for (Person* sister: sister_set){
      if (sister->gender() == Gender::FEMALE){
        result.insert(sister);
      }
    }
    return result;

  }

  std::set<Person*> Person::sons(){
    std::set<Person*> result;
    std::set<Person*>kids = this->children();
    for (Person* son: kids){
      if (son->gender() == Gender::MALE){
        result.insert(son);
      }
    }
    return result;
  }

  std::set<Person*> Person::uncles(PMod pmod , SMod smod ){
    std::set<Person*> result;
    std::set<Person*> parent = this->parents(pmod);
    for (Person* par : parent){
      std::set<Person*> brother = this->brothers(pmod, smod);
      for (Person* bro : brother){
        result.insert(bro);
      }
    }
    return result;

  }
