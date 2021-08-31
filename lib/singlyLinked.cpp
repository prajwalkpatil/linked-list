#include <iostream>
#include "../header/singlyNode.h"

namespace SLL
{
    void insertAtFront();
    void insertAtEnd();
    void insertAtPosition();
    void deleteFromFront();
    void deleteFromEnd();
    void deleteFromPosition();
    void display();
}

void SLL::display(NODE *head)
{
    std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
    if (head == NULL)
    {
        std::cout << "The Linked List is Empty! " << std::endl;
        std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
        return;
    }
    NODE *temp = head;
    while (temp != NULL)
    {
        temp->displayNode();
        temp = temp->next;
    }
    std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
}

void SLL::insertAtFront(NODE *head)
{
    NODE *n = new NODE();
    if (head == NULL)
    {
        head = n;
        return;
    }
    NODE *temp = head;
    temp = n;
    n->next = temp;
}