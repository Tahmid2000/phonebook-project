//
//  addUpdateCommand.hpp
//  PhoneBook
//
//  Implements the add/update command of the Phone Book.
//

#ifndef addUpdateCommand_h
#define addUpdateCommand_h

#include <stdio.h>
#include "bookCommand.h"
#include "phoneBook.h"
class addUpdateCommand: public bookCommand{
private:
    //member
    phoneBook &book;
public:
    //constructor
    addUpdateCommand(phoneBook &bookIn, std::istream &inStream, std::ostream &outStream);
    //overriden execute method from command class
    virtual void execute() override{
        //uses bookCommand class's write method to prompt user
        std::string theName = write("Enter name to add/update");
        std::string theNum = write("Enter phone number");
        std::string theMail = write("Enter e-mail address");
        //if there isn't an entry with specified name, new phoneBookEntry is added
        if(book.find(theName) != true){
            display("Adding phone book entry for " + theName);
            book.insert(theName, theNum, theMail);
        }
        //else entry is updated
        else{ 
            display("Updating phone book entry for " + theName);
            book.insert(theName, theNum, theMail);
        }
    }
};
#endif /* addUpdateCommand_h */
