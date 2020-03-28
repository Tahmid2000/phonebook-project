//
//  phoneBookEntry.cpp
//  PhoneBook
//
//  Implementation of phoneBookEntry
//

#include "phoneBookEntry.h"
#include <iomanip>
//implementation of constructors
phoneBookEntry::phoneBookEntry(){
    theName = "";
    theNum = "";
    theEmail = "";
}
phoneBookEntry::phoneBookEntry(const std::string &name, const std::string &number){
    theName = name;
    theNum = number;
    theEmail = "";
}
phoneBookEntry::phoneBookEntry(const std::string &name, const std::string &number,  const std::string &email){
    theName = name;
    theNum = number;
    theEmail = email;
}
//implementation of copy constructor
phoneBookEntry::phoneBookEntry(const phoneBookEntry &from){
    theName = from.theName;
    theNum = from.theNum;
    theEmail = from.theEmail;
}

std::ostream& operator<<(std::ostream &out, const phoneBookEntry &entry)
{
    
    //prints every member of phoneBook to out
    if(entry.email() != "")
        out << std::setw(31) << entry.name() << std::setw(16) << entry.phoneNumber() << entry.email();
    else
        out << std::setw(31) << entry.name() << std::setw(16) << entry.phoneNumber();
    return out;
}

