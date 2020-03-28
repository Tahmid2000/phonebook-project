//
//  phoneBook.cpp
//  PhoneBook
//
//  Implementaion of phoneBook.
//

#include "phoneBook.h"
#include <iomanip>

phoneBook::phoneBook(){}
//implementation of overloaded insert functions
void phoneBook::insert(const phoneBookEntry &entry){
    linkedListIterator<phoneBookEntry> current = book.begin();
    bool done = false;
    while (!done && current != book.end())
    {
        if (current.data().name() == entry.name())
        {
            current.data().phoneNumber(entry.phoneNumber());
            current.data().email(entry.email());
            done = true;
        }
        else
            current++;
    }
    if(done == false)
        book.insert(entry);
}

void phoneBook::insert(const std::string &name, const std::string &number, const std::string &email){
    linkedListIterator<phoneBookEntry> current = book.begin();
    bool done = false;
    while (!done && current != book.end())
    {
        if (current.data().name() == name){
            current.data().phoneNumber(number);
            current.data().email(email);
            done = true;
        }
            
        else
            current++;
    }
    if(done == false)
        book.insert(phoneBookEntry(name, number, email));
}

void phoneBook::insert(const std::string &name, const std::string &number){
    linkedListIterator<phoneBookEntry> current = book.begin();
    bool done = false;
    while (!done && current != book.end())
    {
        if (current.data().name() == name){
            current.data().phoneNumber(number);
            done = true;
        }
            
        else
            current++;
    }
    if(done == false)
        book.insert(phoneBookEntry(name, number));
}
//implementaion of erase
bool phoneBook::erase(std::string name){
    bool result = find(name);
    if(result == true)
    {
        linkedListIterator<phoneBookEntry> current = book.begin();
        bool done = false;
        while (!done && current != book.end())
        {
            if (current.data().name() == name)
            {
                book.erase(phoneBookEntry(current.data().name(), current.data().phoneNumber(), current.data().email()));
                return true;
            }
            else
                current++;
        }
    }
    return false;
}
//implementation of find
bool phoneBook::find(std::string name){
    linkedListIterator<phoneBookEntry> current = book.begin();
    bool done = false;
    while (!done && current != book.end())
    {
        if (current.data().name() == name)
            done = true;
        else
            current++;
    }
    if(done == true)
        return true;
    return false;
}
//implementaion of print methods
void phoneBook::print() const{
    book.print();
}

void phoneBook::print(std::ostream &out) const{
    out << std::left;
    out << std::setw(31) << "Name: " << std::setw(16) << "Phone Number: " << "E-Mail:" << std::endl;
    book.print(out);
}
//implementation of debug
void phoneBook::debug(std::ostream &out) const{
    book.debug(out);
}

