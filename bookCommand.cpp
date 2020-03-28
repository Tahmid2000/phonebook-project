//
//  bookCommand.cpp
//  PhoneBook
//
//  Implementation of bookCommand
//

#include "bookCommand.h"
#include <iostream>
#include <string>
//constructor
bookCommand::bookCommand(std::istream &inStream, std::ostream &outStream)
   :  in(inStream), out(outStream)
{
}
//implementation of display
void bookCommand::display(const std::string word){
    //prints parameter using out
    out << word << std::endl;
}
//implementation of write
std::string bookCommand::write(const std::string word){
    std::string input;
    //prompts user with the parameter
    out << word << std::endl;
    //gets the user input using the istream member
    std::getline(in, input);
    return input;
}

