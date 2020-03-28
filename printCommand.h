//
//  printCommand.hpp
//  PhoneBook
//
//  Implements the print command of the Phone Book.
//

#ifndef printCommand_h
#define printCommand_h

#include <stdio.h>
#include "bookCommand.h"
#include "phoneBook.h"
class printCommand: public bookCommand{
    private:
    //member
        phoneBook &book;
    public:
    //constructor
        printCommand(phoneBook &bookIn, std::istream &inStream, std::ostream &outStream);
    //overrides execute method from command
        virtual void execute() override{
            //uses phoneBook's print method
            book.print(out);
        }
};
#endif /* printCommand_h */
