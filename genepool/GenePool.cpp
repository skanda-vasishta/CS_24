#include "GenePool.h"


//Constructor
GenePool::GenePool(std::istream& stream) {
    std::string line;
    while (std::getline(stream, line)) {
        if (line.empty() || line[0] == '#') {
            continue;
        }
        std::string personName, personGenderStr, momName, dadName;
        std::stringstream new_stream(line);
        std::getline(new_stream, personName, '\t');
        std::getline(new_stream, personGenderStr, '\t');
        std::getline(new_stream, momName, '\t');
        std::getline(new_stream, dadName);
        
        Gender personGender;
        if (personGenderStr == "male") {
            personGender = Gender::MALE;
        } else if (personGenderStr == "female") {
            personGender = Gender::FEMALE;
        }else {
            personGender= Gender::ANY;
        }
        Person*mom = nullptr;
        Person*dad = nullptr;
        if (momName != "???"){
            mom = pool[momName];
        }
        if (dadName != "???"){
            dad = pool[dadName];
        } 
        

        Person *p = new Person(personName, personGender, mom, dad);
        pool[personName] = p;
    }
}




//Destructor 
GenePool:: ~GenePool(){
    for (auto it = pool.begin(); it != pool.end(); ++it) {
        delete it->second;
    }
}

// GenePool Member Functions
 std::set<Person*> GenePool::everyone() const {

 }

Person* GenePool::find(const std::string& name) const{
    
}