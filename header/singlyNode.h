#ifndef _SINGLY_LINKED_
#define _SINGLY_LINKED_
#include <iostream>
class NODE
{
public:
    int val;
    NODE *next;

    NODE()
    {
        NODE::readDetails();
        next = NULL;
    }
    void readDetails()
    {
        std::cout << "Enter the value to be inserted: ";
        std::cin >> val;
    }
    void displayNode()
    {
        std::cout << " " << val << " ";
    }
};

#endif