//
//  eraseCommand.cpp
//  PhoneBook
//
//  Implemenation of eraseCommand.
//

#include "eraseCommand.h"
//empty constructor
eraseCommand::eraseCommand(phoneBook &bookIn, std::istream &inStream, std::ostream &outStream)
  :  bookCommand(inStream, outStream), book(bookIn)
{
    
}
