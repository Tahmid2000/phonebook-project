//
//  eraseCommand.hpp
//  PhoneBook
//
//  Implements the erase command of the Phone Book.
//

#ifndef eraseCommand_h
#define eraseCommand_h

#include <stdio.h>
#include "bookCommand.h"
#include "phoneBook.h"
class eraseCommand: public bookCommand{
    private:
    //member
        phoneBook &book;
    public:
    //constructor
        eraseCommand(phoneBook &bookIn, std::istream &inStream, std::ostream &outStream);
    //overriden execute method from command class
        virtual void execute() override{
            //uses bookCommand class's write method to prompt user
            std::string theName = write("Enter name to erase");
            //if there isn't an entry with specified name, nothing is erased
            if(book.find(theName) != true){
                display("Phone book entry " + theName + " was not erased");
            }
            //else entry is erased
            else{
                display("Phone book entry " + theName + " was erased");
                book.erase(theName);
            }
        }
};
#endif /* eraseCommand_h */
