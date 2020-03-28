//
//  printCommand.cpp
//  PhoneBook
//
//  Implementation of printCommand.
//

#include "printCommand.h"
//empty constructor
printCommand::printCommand(phoneBook &bookIn, std::istream &inStream, std::ostream &outStream)
  :  bookCommand(inStream, outStream), book(bookIn)
{
    
}
