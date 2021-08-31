#include <iostream>
#include "../header/doublyNode.h"

void DLL::display(NODE *&head)
{
    std::cout << "\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";
    std::cout << "\nLinked List: \n";
    if (head == NULL)
    {
        std::cout << "The Linked List is Empty! " << std::endl;
        std::cout << "\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
        return;
    }
    NODE *temp = head;
    std::cout << "Head ->";
    while (temp != NULL)
    {
        temp->displayNode();
        temp = temp->next;
    }
    std::cout << " NULL";
    std::cout << "\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
}

void DLL::insertAtFront(NODE *&head)
{
    NODE *n = new NODE();
    if (head == NULL)
    {
        head = n;
        return;
    }
    NODE *temp = head;
    head = n;
    n->next = temp;
    temp->prev = n;
}

void DLL::insertAtEnd(NODE *&head)
{
    NODE *n = new NODE();
    if (head == NULL)
    {
        head = n;
        return;
    }
    NODE *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}

void DLL::deleteFromFront(NODE *&head)
{
    if (head == NULL)
    {
        return;
    }
    NODE *temp = head;
    head = temp->next;
    (temp->next)->prev = head;
    delete temp;
}

void DLL::deleteFromEnd(NODE *&head)
{
    if (head == NULL)
    {
        return;
    }
    NODE *temp = head;
    NODE *temp2 = head;
    int flag = 0;
    while (temp->next != NULL)
    {
        temp = temp->next;
        if (flag != 0)
        {
            temp2 = temp2->next;
        }
        flag = 1;
    }
    temp2->next = NULL;
    delete temp;
}

void DLL::insertAtPosition(NODE *&head)
{
    int k = head->getKeyForSearch();
    NODE *n = new NODE();
    if (head == NULL)
    {
        head = n;
        return;
    }
    NODE *temp = head;
    while (temp != NULL)
    {
        if (temp->val == k)
        {
            n->next = temp->next;
            temp->next = n;
            n->prev = temp;
            return;
        }
        temp = temp->next;
    }
}