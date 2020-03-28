//
//  phoneBook.hpp
//  PhoneBook
//
//  This class contains the vector that hold each of the phone book entries.
//

#ifndef phoneBook_h
#define phoneBook_h
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include "phoneBookEntry.h"
#include "orderedLinkedList.h"
#include "linkedList.h"
class phoneBook{
private:
    //Vector that holds phonebookentries
    orderedLinkedList<phoneBookEntry> book;
public:
    //constructor
    phoneBook();
    //overloaded insert methods that use the overloaded constructors of phoneBookEntry
    void insert(const phoneBookEntry &entry);
    void insert(const std::string &name, const std::string &number, const std::string &email);
    void insert(const std::string &name, const std::string &number);
    //erases entry from vector
    bool erase(std::string name);
    //finds if the entry w/ specific name is in phoneBook
    bool find(std::string name);
    //overloaded print methods
    void print() const;
    void print(std::ostream &out) const;
    //helps programmer debug code
    void debug(std::ostream &out) const;
    //type definitons for easier coding
    typedef std::vector<phoneBookEntry> phoneBookEntryList;
    typedef phoneBookEntryList::iterator iterator;
    typedef phoneBookEntryList::const_iterator const_iterator;
    //iterator functions for phoneBook's private vector member
  /*  iterator begin(){
        return book.begin();
    }
    iterator end(){
        return book.end();
    } */
    //returns size of phoneBook
    std::size_t size() const{
        return book.size();
    }
};

#endif /* phoneBook_h */
