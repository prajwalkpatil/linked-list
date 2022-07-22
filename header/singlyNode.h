#pragma once
#include <iostream>
class NODE
{
public:
    int val;
    NODE *next;

    NODE()
    {
        std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
        std::cout << "\nEnter the value to be inserted: ";
        std::cin >> val;
        std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
        next = NULL;
    }
    void displayNode()
    {
        std::cout << " " << val << " ";
        std::cout << "->";
    }
    int getKeyForSearch()
    {
        int k;
        std::cout << "\nEnter the key: ";
        std::cin >> k;
        return k;
    }
};

namespace SLL
{
    void insertAtFront(NODE *&);
    void insertAtEnd(NODE *&);
    void insertAtPosition(NODE *&);
    void deleteFromFront(NODE *&);
    void deleteFromEnd(NODE *&);
    void deleteFromPosition(NODE *&);
    void display(NODE *&);
}
namespace CSLL
{
    void insertAtFront(NODE *&);
    void insertAtEnd(NODE *&);
    void insertAtPosition(NODE *&);
    void deleteFromFront(NODE *&);
    void deleteFromEnd(NODE *&);
    void deleteFromPosition(NODE *&);
    void display(NODE *&);
}
