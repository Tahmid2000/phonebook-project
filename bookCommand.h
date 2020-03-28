//
//  bookCommand.hpp
//  PhoneBook
//
//  Sub class of command, that is the base class for addUpdateCommand, printCommand, and eraseCommand.
//  Implements basic functions to implemetn the subclasses.
//

#ifndef bookCommand_h
#define bookCommand_h
#include "command.h"
#include <stdio.h>
#include <iostream>

class bookCommand: public command
{
protected:
    //members of isteam and ostream
    std::istream &in;
    std::ostream &out;
    //method that ouputs statement to console using ostream member
    void display(const std::string word);
    //method that writes string to istream member
    std::string write(const std::string word);
public:
    //constructor
    bookCommand(std::istream &in, std::ostream &out);
    
};
#endif /* bookCommand_h */
