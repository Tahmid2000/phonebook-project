//
//  addUpdateCommand.cpp
//  PhoneBook
//
//  Implementation of addUpdateCommand
//

#include "addUpdateCommand.h"
//Empty constructor
addUpdateCommand::addUpdateCommand(phoneBook &bookIn, std::istream &inStream, std::ostream &outStream)
  :  bookCommand(inStream, outStream), book(bookIn)
{
    
}
