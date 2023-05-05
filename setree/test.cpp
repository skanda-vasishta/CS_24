#include <iostream>
#include "Set.h"

int main() {
    // create an empty set
    Set s1;

    // insert some elements
    s1.insert("apple");
    s1.insert("banana");
    s1.insert("cherry");
    s1.insert("date");
    s1.insert("elderberry");
    s1.insert("fig");
    s1.insert("grape");

    // print out the set
    std::cout << "Set 1 after insertions: ";
    s1.print();
    std::cout << std::endl;

    // check if some elements are present
    std::cout << "Set 1 contains 'apple': " << s1.contains("apple") << std::endl;
    std::cout << "Set 1 contains 'cherry': " << s1.contains("cherry") << std::endl;
    std::cout << "Set 1 contains 'grape': " << s1.contains("grape") << std::endl;
    std::cout << "Set 1 contains 'kiwi': " << s1.contains("kiwi") << std::endl;

    // remove some elements
    s1.remove("apple");
    s1.remove("cherry");

    // print out the set
    std::cout << "Set 1 after removals: ";
    s1.print();
    std::cout << std::endl;

    // lookup some elements by index
    std::cout << "Set 1 element at index 0: " << s1.lookup(0) << std::endl;
    std::cout << "Set 1 element at index 1: " << s1.lookup(1) << std::endl;
    std::cout << "Set 1 element at index 2: " << s1.lookup(2) << std::endl;
    std::cout << "Set 1 element at index 3: " << s1.lookup(3) << std::endl;

    // create a copy of the set
    Set s2(s1);

    // print out the copied set
    std::cout << "Set 2 after copy constructor: ";
    s2.print();
    std::cout << std::endl;

    // clear the original set and print it out
    s1.clear();
    std::cout << "Set 1 after clear: ";
    s1.print();
    std::cout << std::endl;

    // print out the copied set again
    std::cout << "Set 2 after clear of Set 1: ";
    s2.print();
    std::cout << std::endl;

    return 0;
}
