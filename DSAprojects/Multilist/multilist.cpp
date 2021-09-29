//  Name: Jacob Bahn
//  Assignment number: 3
//  Assignment: Multilists
//  File name: multilist.cpp
//  Date last modified: October 5, 2020
//  Honor statement: I have neither given nor received any unauthorized help on this assignment. 

#include <iostream>
#include "multilist.h"



Multilist::Node::Node(int id, std::string name, int age) :
    id(id), name(name), age(age) {}

Multilist::Multilist(): first(new Node(0, "", 0)),
                        last(new Node(0, "", 0)){

    first->next_id = last;
    first->prev_id = nullptr;
    first->next_name = last;
    first->prev_name = nullptr;
    first->next_age = last;
    first->prev_age = nullptr;

    last->next_id = nullptr;
    last->prev_id = first;
    last->next_name = nullptr;
    last->prev_name = first;
    last->next_age = nullptr;
    last->prev_age = first;
}

Multilist::~Multilist() {
    for (Node* p = last; p != first; p = p->prev_age) {
        delete p;
    }
    delete first;

}

bool Multilist::insert(int id, std::string name, int age) {
    for (char& c : name) {
        c = toupper(c);
    }

    Node* temp = new Node(id, name, age);

    for (Node* p = first; p != last; p = p->next_id) {
        if (id == p->next_id->id) {
            return false;
        }
        else if (id < p->next_id->id || p->next_id == last)
        {
            temp->prev_id = p;
            temp->next_id = p->next_id;
            p->next_id->prev_id = temp;
            p->next_id = temp;
            break;
        }
    }

    for (Node* p = first; p != last; p = p->next_name) {
        
        if (name < p->next_name->name || p->next_name == last) {
            temp->next_name = p->next_name;
            temp->prev_name = p;
            p->next_name->prev_name = temp;
            p->next_name = temp;
            break;
        }

    }


    for (Node* p = first; p != last; p = p->next_age) {
        if (age < p->next_age->age || p->next_age == last) {
            temp->next_age = p->next_age;
            temp->prev_age = p;
            p->next_age->prev_age = temp;
            p->next_age = temp;
            break;
        }
    }
    return true;
}

bool Multilist::remove(int id) {
    for (Node* p = first; p != last; p = p->next_id) {
        if (p->id == id) {
            p->next_id->prev_id = p->prev_id;
            p->prev_id->next_id = p->next_id;
            p->next_age->prev_age = p->prev_age;
            p->prev_age->next_age = p->next_age;
            p->next_name->prev_name = p->prev_name;
            p->prev_name->next_name = p->next_name;
            delete p;
            return true;
        }
    }
    return false;
}

void Multilist::print_by_ID() {
    for (Node* p = first->next_id; p != last; p = p->next_id) {
        std::cout << "(" << p->name << "," << p->id << "," << p->age << ")" << "\n";
    }
}

void Multilist::print_by_ID_reverse() {
    for (Node* p = last->prev_id; p != first; p = p->prev_id) {
        std::cout << "(" << p->name << "," << p->id << "," << p->age << ")" << "\n";
    }
}

void Multilist::print_by_name() {
    for (Node* p = first->next_name; p != last; p = p->next_name) {
        std::cout << "(" << p->name << "," << p->id << "," << p->age << ")" << "\n";
    }
}

void Multilist::print_by_name_reverse() {
    for (Node* p = last->prev_name; p != first; p = p->prev_name) {
        std::cout << "(" << p->name << "," << p->id << "," << p->age << ")" << "\n";
    }
}

void Multilist::print_by_age() {
    for (Node* p = first->next_age; p != last; p = p->next_age) {
        std::cout << "(" << p->name << "," << p->id << "," << p->age << ")" << "\n";
    }
}

void Multilist::print_by_age_reverse() {
    for (Node* p = last->prev_age; p != first; p = p->prev_age) {
        std::cout << "(" << p->name << "," << p->id << "," << p->age << ")" << "\n";
    }
}