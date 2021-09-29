// listmain.cpp

#include <iostream>
#include <algorithm>   // For std::for_each
#include "llist.h"   


int main() {
    std::cout << "Starting program\n";
    // Make an empty list
    LinkedList my_list;
    // Insert some elements
    my_list.insert(my_list.end(), "Fred");
    my_list.insert(my_list.end(), "Wilma");
    my_list.insert(my_list.end(), "Betty");
    my_list.insert(my_list.end(), "Dino");
    my_list.insert(my_list.end(), "Barney");
    // Print the list with a loop
    std::cout << "Print the list with a for loop: \n";
    for (string elem : my_list) {
        std::cout << elem << ' ';
    }
    std::cout << '\n';
    std::cout << "Length of list: " << my_list.length() << "\n\n";


    // Print the list with a standard algorithm!
    std::cout << "Print the list with std::for_each: \n";
    std::for_each(my_list.begin(), my_list.end(),
        [](const string& s) { std::cout << s << ' '; });
    std::cout << '\n';
    std::cout << "Length of list: " << my_list.length() << "\n\n";

    // Remove Dino
    std::cout << "Remove Dino: \n";
    auto p = my_list.find("Dino");
    my_list.remove(p);
    std::cout << "Print the list with std::for_each: \n";
    std::for_each(my_list.begin(), my_list.end(),
        [](const string& s) { std::cout << s << ' '; });
    std::cout << '\n';
    std::cout << "Length of list: " << my_list.length() << "\n\n";

    //Insert Matthew one from end
    std::cout << "Adding Matthew to one prior to end\n";
    my_list.insert(--my_list.end(), "Matthew");
    std::cout << "Print the list with std::for_each: \n";
    std::for_each(my_list.begin(), my_list.end(),
        [](const string& s) { std::cout << s << ' '; });
    std::cout << '\n';
    std::cout << "Length of list: " << my_list.length() << "\n\n";

    //remove end
    std::cout << "removing end \n";
    my_list.remove(--my_list.end());
    std::cout << "Print the list with std::for_each: \n";
    std::for_each(my_list.begin(), my_list.end(),
        [](const string& s) { std::cout << s << ' '; });
    std::cout << '\n';
    std::cout << "Length of list: " << my_list.length() << "\n\n";

    //try to remove sentinal end node
    std::cout << "removing end+1 \n";
    my_list.remove(++(--my_list.end()));
    std::for_each(my_list.begin(), my_list.end(),
        [](const string& s) { std::cout << s << ' '; });
    std::cout << '\n';
    std::cout << "Length of list: " << my_list.length() << "\n\n";

    //try to remove sentinal beginning node
    std::cout << "removing beginning-1 \n";
    my_list.remove(--(my_list.begin()));
    std::for_each(my_list.begin(), my_list.end(),
        [](const string& s) { std::cout << s << ' '; });
    std::cout << '\n';
    std::cout << "Length of list: " << my_list.length() << "\n\n";

    // Print the list with a standard algorithm!
    std::cout << "print with standard algo: \n";
    std::for_each(my_list.begin(), my_list.end(),
        [](const string& s) { std::cout << s << ' '; });
    std::cout << "\n\n";

    // Print the list backwards
    std::cout << "Print backwards: \n";
    p = my_list.end();
    while (p-- != my_list.begin()) {
        std::cout << *p << ' ';
    }
    std::cout << "\n\n";

    //clear list and print it again
    std::cout << "Clearing list then printing it again. \n";
    my_list.clear();
    std::for_each(my_list.begin(), my_list.end(),
        [](const string& s) { std::cout << s << ' '; });
    std::cout << "Length of list: " << my_list.length() << "\n";
    std::cout << '\n';

    //add another item to the list now that it has been cleared, then print again
    my_list.insert(my_list.begin(), "Hi kids");
    std::for_each(my_list.begin(), my_list.end(),
        [](const string& s) { std::cout << s << ' '; });
    std::cout << "\n";
    std::cout << "Length of list: " << my_list.length() << "\n\n";
    std::cout << '\n';

    // Implement some tests to ensure that the program desctrucst properly.


    // test LinkedList == operator
    LinkedList test1;
    LinkedList test2;
    std::cout << std::boolalpha << "Testing if two empty lists are equal: " << (test1 == test2) << "\n";
    test1.insert(test1.end(), "testtest");
    std::cout << std::boolalpha << "Adding item to one list and checking again: " << (test1 == test2) << "\n";
    auto q = test1.find("testtest");
    test1.remove(q);
    std::cout << std::boolalpha << "Removing item from the list and checking again: " << (test1 == test2) << "\n\n";

    //why can't I do this: test1.remove(test1.find("test"));

    // test LinkedList != operator
    LinkedList test3;
    LinkedList test4;
    std::cout << std::boolalpha << "Testing if two empty lists are not equal: " << (test3 != test4) << "\n";
    test3.insert(test3.end(), "testtest");
    std::cout << std::boolalpha << "Adding item to one list and checking again: " << (test3 != test4) << "\n\n";

    //testing copy constructor
    LinkedList test5;
    test5.insert(test5.end(), "test1");
    test5.insert(test5.end(), "test2");
    test5.insert(test5.end(), "test3");

    LinkedList test6{ test5 };

    std::cout << std::boolalpha << "Testing if a copied list is equal to its parent: " << (test5 == test6) << "\n";
    test5.insert(test5.end(), "test4");
    std::cout << std::boolalpha << "Adding item to one list and checking again: " << (test5 == test6) << "\n";
    std::cout << std::boolalpha << "Printing both lists:" << "\n";
    std::for_each(test5.begin(), test5.end(),
        [](const string& s) { std::cout << s << ' '; });
    std::cout << "\n";
    std::for_each(test6.begin(), test6.end(),
        [](const string& s) { std::cout << s << ' '; });
    std::cout << "\n";



    //test huge list
    std::cout << std::boolalpha << "Testing if a huge list works. adding 10000, removing 9995" << "\n";
    LinkedList huge_list;
    for (int i = 0; i < 10000; i++) {
        huge_list.insert(huge_list.begin(), std::to_string(i));
    }
    for (int i = 0; i < 9995; i++) {
        huge_list.remove(--(huge_list.end()));
    }
    std::for_each(huge_list.begin(), huge_list.end(),
        [](const string& s) { std::cout << s << ' '; });
    std::cout << "\n";
    
    std::cout << std::boolalpha << "adding 10000 more, then clearing, then adding a couple strings" << "\n";
    for (int i = 0; i < 10000; i++) {
        huge_list.insert(huge_list.begin(), std::to_string(i));
    }
    huge_list.clear();
    huge_list.insert(huge_list.end(), "test");
    huge_list.insert(huge_list.end(), "test2");
    std::for_each(huge_list.begin(), huge_list.end(),
        [](const string& s) { std::cout << s << ' '; });
    std::cout << "\n";
    std::cout << "Length of huge list (should be 2): " << huge_list.length() << "\n\n";

    // Print the empty list backwards
    LinkedList empty;
    std::cout << "Print empty backwards: \n";
    std::cout << '[';
    p = empty.end();
    while (p-- != empty.begin()) {
        std::cout << *p << ' ';
    }
    std::cout << "]\n";





    std::cout << "*** Add lots more test code to convince yourself that ";
    std::cout << "your code is correct. ***\n";


    std::cout << "Program finished\n";
}