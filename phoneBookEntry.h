//
//  phoneBookEntry.hpp
//  PhoneBook
//
//  This is the class that takes in an individual phone book entry, which is later put into phoneBook.
//

#ifndef phoneBookEntry_h
#define phoneBookEntry_h
#include <iostream>
#include <stdio.h>
class phoneBookEntry{
private:
    //data members of a phonebook entry
    std::string theName;
    std::string theNum;
    std::string theEmail;
public:
    //overloaded constructors
    phoneBookEntry();
    phoneBookEntry(const std::string &name, const std::string &number);
    phoneBookEntry(const std::string &name, const std::string &number,  const std::string &email);
    //copy constructor
    phoneBookEntry(const phoneBookEntry &from);
    //accessors
    std::string name() const{
        return theName;
    }
    std::string phoneNumber() const{
        return theNum;
    }
    std::string email() const{
        return theEmail;
    }
    //mutators
    void phoneNumber(const std::string &newNumber){
        theNum = newNumber;
    }
    void email(const std::string &newEmail){
        theEmail = newEmail;
    }
public:
    bool operator==(const phoneBookEntry &entry) const{return theName == entry.theName;}
    bool operator!=(const phoneBookEntry &entry) const{return theName != entry.theName;}
    bool operator<(const phoneBookEntry &entry) const{return theName < entry.theName;}
    bool operator<=(const phoneBookEntry &entry) const{return theName <= entry.theName;}
    bool operator>(const phoneBookEntry &entry) const{return theName > entry.theName;}
    bool operator>=(const phoneBookEntry &entry) const{return theName >= entry.theName;}
};
std::ostream& operator<<(std::ostream &out, const phoneBookEntry &entry);
#endif /* phoneBookEntry_h */
