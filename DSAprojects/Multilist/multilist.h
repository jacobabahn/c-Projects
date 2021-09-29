#ifndef MULTILIST_H_
#define MULTILIST_H_

#include <string>

// Multilist represents a 3-way doubly-linked linear list

class Multilist {
    // Nested class, not accessible outside of Multilist
    struct Node {
        int id;           // ID number
        std::string name; // Last name
        int age;          // Age
        Node *prev_id,    // Previous ID, numerically
             *next_id,    // Next ID, numerically
             *prev_name,  // Previous name, alphabetically
             *next_name,  // Next name, alphabetically
             *prev_age,   // Previous age, numerically
             *next_age;   // Next name, numerically
        // Creates a new Node object with the given fields.
        // The pointer fields are null.
        Node(int id, std::string name, int age);
    };

    Node *first,  // Points to the sentinel node at the head of the list
         *last;   // Points to the sentinel node at the tail of the list

public:
    // Creates a new empty multilist
    Multilist();
    // Properly deallocates the space held by a multilist
    ~Multilist();
    // Adds a new person to the list with the given last name,
    // ID number, and age.  Duplicate IDs are not allowed.  Returns
    // true if the person was successfully inserted; 
    // otherwise, returns false.
    bool insert(int id, std::string name, int age);
    // Removes the person with the given ID number.  Returns
    // true if the person was removed; otherwise, return false
    bool remove(int id);
    // Print the contents in order by ID number
    void print_by_ID();
    // Print the contents in reverse order by ID number
    void print_by_ID_reverse();
    // Print the contents in order by last name
    void print_by_name();
    // Print the contents in reverse order by last name
    void print_by_name_reverse();
    // Print the contents in order from oldest to youngest
    void print_by_age();
    // Print the contents in order from youngest to oldest
    void print_by_age_reverse();
};

#endif
