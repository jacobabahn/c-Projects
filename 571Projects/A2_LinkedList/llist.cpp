// Jacob Bahn
// Assignment number: 1
// Assignment: Implementing a Linked List Abstract Data Type
// File name: llist.cpp
// Date last modified: September 28, 2021
// Honor statement: I have neither given nor received any unauthorized help on this assignment. 

#include "llist.h"

LinkedList::Node::Node(const string& item) : data(item), next(nullptr), prev(nullptr) {}

LinkedList::LinkedList() : head(new Node(std::string("*HEAD*"))), tail(new Node(std::string("*TAIL*"))), len(0) {
    head->next = tail;
    tail->prev = head;
}

// Copy constructor makes a copy of the other object's list
LinkedList::LinkedList(const LinkedList& other) : 
    head(new Node(std::string("*HEAD*"))), tail(new Node(std::string("*TAIL*"))), len(0) {
        head->next = tail;
        tail->prev = head;

    // checks if other is empty
    if (other.begin() == other.end()) {
        return;
    }

    Iterator i = other.begin();
    while (i != other.end()) {
        insert(end(), i.ptr->data);
        i++;
    }
}

// The destructor deallocates the memory held by the list
LinkedList::~LinkedList() {
    // deletes all of the non sentinel nodes
    clear();
    // deletes the sentinel nodes
    delete(head);
    delete(tail);
}

//Assignment operator
LinkedList& LinkedList::operator=(const LinkedList& other) {
    this->~LinkedList();
    // creates a new linked list and passes other into the copy constructor
    LinkedList *llist = new LinkedList(other);
    return *llist;
}


// Initializes the Iterator Class
LinkedList::Iterator::Iterator(Node *p) : ptr(p) {}

LinkedList::Iterator LinkedList::begin() const {
    return Iterator(head->next);
}


// Returns an iterator to the position just past the end of the list
LinkedList::Iterator LinkedList::end() const {
    return Iterator(tail);
}

void LinkedList::insert(const Iterator& iter, const string& item) {
    Node* newNode = new Node(item);

    newNode->prev = iter.ptr->prev;
    iter.ptr->prev->next = newNode;
    iter.ptr->prev = newNode;
    newNode->next = iter.ptr;
    len++;

}

void LinkedList::remove(Iterator& iter) {
    // makes sure that sentinel nodes aren't removed
    if (len == 0 || iter == end() || iter == --begin()) {
        return;
    }

    Node* temp = iter.ptr;
    iter.ptr->prev->next = iter.ptr->next;
    iter.ptr->next->prev = iter.ptr->prev;
    delete(temp);
    len--;
}

LinkedList::Iterator LinkedList::find(const string& seek) const {
    Iterator i = begin();
    while (i != end()) {
        if (seek.compare(i.ptr->data) == 0) {
            return i.ptr;
        }
        i++;
    }
    return Iterator(tail);
}

bool LinkedList::operator==(const LinkedList& other) const {
    Iterator llist = begin();
    Iterator llist2 = other.begin();

    if (length() != other.length()) {
        return false;
    }

    while (llist != end()) {
        if (llist.ptr->data.compare(llist2.ptr->data) != 0) {
            return false;
        }
        llist++;
        llist2++;
    }

    return true;
}

bool LinkedList::operator!=(const LinkedList& other) const {
    return !(*this == other);
}

int LinkedList::length() const {
    return len;
    // int len = 0;

    // Node* curr = head;

    // while(curr->data != "*TAIL*") {
    //     len += 1;
    //     curr = curr->next;
    // }
    
    // return len - 1;

}

void LinkedList::clear() {
    // deletes all nodes other than head and tail
    Iterator temp = begin();
    while(temp != end()) {
        Iterator nextNode = temp.ptr->next;
        delete(temp.ptr);
        temp = nextNode;
    }

    head->next = tail;
    tail->prev = head;
    len = 0;
}

string& LinkedList::Iterator::operator*() {
    return (ptr->data);
}

LinkedList::Iterator& LinkedList::Iterator::operator++() {
    ptr = ptr->next;
    return *this;
}

LinkedList::Iterator LinkedList::Iterator::operator++(int) {
    Iterator pointer = *this;
    ++(*this);
    return pointer;
}

LinkedList::Iterator& LinkedList::Iterator::operator--() {
    ptr = ptr->prev;
    return *this;
}

LinkedList::Iterator LinkedList::Iterator::operator--(int) {
    Iterator pointer = *this;
    --(*this);
    return pointer;
}

bool LinkedList::Iterator::operator==(const Iterator& other) {
    return ptr = other.ptr;
}

bool LinkedList::Iterator::operator!=(const Iterator& other) {
    return ptr != other.ptr;
}