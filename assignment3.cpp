//
//  main.cpp
//  PhoneBook
//
//  Created by Tahmid Imran on 9/29/19.
//  Copyright © 2019 Tahmid Imran. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include "phoneBook.h"
#include "bookCommand.h"
#include "addUpdateCommand.h"
#include "eraseCommand.h"
#include "printCommand.h"
#include "menuList.h"
#include "orderedLinkedList.h"
#include "linkedList.h"

int main()
{
    
    //initialize the variables for add,erase, print
    std::istream& in = std::cin;
    std::ostream& out = std::cout;
    phoneBook book;
    
    // create the commands
    addUpdateCommand add(book, in, out);
    eraseCommand erase(book, in, out);
    printCommand print(book, in, out);
    
    menuList menu("Phone book menu:");
    // these are the actual menu entries for the application
    menuItem addItem('a', "add/update", add);
    menuItem eraseItem('e', "erase", erase);
    menuItem printItem('p', "print", print);
    
    // add the menuItem values to the menulist
    menu.add(addItem);
    menu.add(eraseItem);
    menu.add(printItem);

    std::cout << "Starting the Phone Book" << std::endl;
    std::cout << std::endl;

    // run the menu
    menu.start();
    return 0;
}


