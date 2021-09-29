// llist.h
// Specifies a linked list abstract data type

#ifndef LLIST_H_INCLUDED
#define LLIST_H_INCLUDED

#include <string>

using std::string;   

class LinkedList {
    // This nested private Node struct is used internally
    struct Node {
        string data;   // A data element of the list
        Node *next;    // The node that follows this one
        Node *prev;    // The node that precedes this one
        // Constructor initializes the data element and
        // sets the next and prev pointers to null
        Node(const string& item);
    };

    Node *head;  // Dummy sentinel node on the front of the list
    Node *tail;  // Dummy sentinel node on the back of the list

    int len;     // Number of elements in the list

    // Clients have only indirect access to this nested Iterator class.
    class Iterator {
        Node *ptr;    // Keeps track of the position in the list
        friend LinkedList;  // Allows LinkedList methods to access ptr member
        Iterator(Node *p);
    public:
        using value_type = string;
        using pointer = value_type*;
        using reference = value_type&;
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;

        string& operator*();      // Evaluates to the current object
        Iterator& operator++();   // Preincrement the position
        Iterator operator++(int); // Postincrement the position
        Iterator& operator--();   // Predecrement the position
        Iterator operator--(int); // Postdecrement the position
        // Determines if another iterator pointers to the same
        // element in the list
        bool operator==(const Iterator& other);
        // Determines if another iterator pointers to a different
        // element in the list
        bool operator!=(const Iterator& other);
    };

public:
    // The constructor makes an initially empty list.
    // The list is empty when the head and tail 
    // sentinels directly point to each other.
    LinkedList();

    // Copy constructor makes a copy of the other object's list
    LinkedList(const LinkedList& other);

    // The destructor deallocates the memory held by the list
    ~LinkedList();

    // Assignment operator
    LinkedList& operator=(const LinkedList& other);

    // Returns an iterator to the first element in the list
    Iterator begin() const;

    // Returns an iterator to the position just past the end of the list
    Iterator end() const;

    // Inserts an item into the list before
    // the position indicated by the iterator.
    // To append an item to the back of list lst, use
    //      lst.insert(lst.end(), item);
    // To prepend an item to the front of list lst, use
    //      lst.insert(lst.begin(), item);
    // The insertion does not change the iterator's position. 
    void insert(const Iterator& iter, const string& item);

    // Removes the element at the position indicated by the iterator.
    // After the removal the iterator will point to the element after 
    // the removed element.
    void remove(Iterator& iter);

    // Returns an iterator to the first occurrence of the element
    // seek.  Returns the list's end iterator if seek is not present 
    // in the list.
    Iterator find(const string& seek) const;

    // Returns the number of elements in the linked list.
    int length() const;

    // Removes all the elements in the linked list.
    void clear();

    // Returns true if other contains the same elements,
    // in the same order; otherwise, returns false.
    bool operator==(const LinkedList& other) const;

    // Returns true if the content of the other list differs from 
    // this list (missing or extra elements, different element order, 
    // etc.; otherwise, returns false.
    bool operator!=(const LinkedList& other) const;
};


#endif

