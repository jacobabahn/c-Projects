// File testmultilist.cpp

#include <iostream>
#include "multilist.h"

// Interactive program useful for experimenting with the
// Multilist 3-way, doubly-linked list class.

int main() {
    Multilist list;
    bool done = false;
    int id, age;
    char command;
    std::string name;
    while (!done) {
        std::cin >> command;
        switch (command) {
           case '+':   // Insert new person data
               std::cin >> id >> name >> age;
               std::cout << "Inserting " << id << ", " << name
                         << ", " << age << '\n';
               if (!list.insert(id, name, age))
                   std::cout << "Cannot insert " << name << '\n';
               break;
           case '-':   // Remove a person by ID number
               std::cin >> id;
               std::cout << "Removing " << id << '\n';
               if (!list.remove(id))
                   std::cout << "Cannot remove " << id << '\n';
               break;
           case 'n':  // Print contents in name order
               std::cout << "Printing by name " << '\n';
               list.print_by_name();
               break;
           case 'N':  // Print contents in reverse name order
               std::cout << "Printing by name reverse " << '\n';
               list.print_by_name_reverse();
               break;
           case 'i':  // Print contents in ID number order 
               std::cout << "Printing by ID number " << '\n';
               list.print_by_ID();
               break;
           case 'I':  // Print contents in reverse ID number order
               std::cout << "Printing by ID number reverse\n";
               list.print_by_ID_reverse();
               break;
           case 'a':  // Print contents, youngest to oldest
               std::cout << "Printing youngest to oldest\n";
               list.print_by_age();
               break;
           case 'A':  // Print contents, oldest to youngest
               std::cout << "Printing oldest to youngest\n";
               list.print_by_age_reverse();
               break;
           case 'Q':  // Quit the program
           case 'q':
               done = true;
               break;
           default:   // Unknown command, flush input stream
               std::cout << "Unknown command\n";
               std::cin.ignore(100, '\n');
        }
    }
}
