//Author: Prajwal Patil
//Program: Circular Singly Linked List.
#include <iostream>
#include "../header/singlyNode.h"

void CSLL::display(NODE *&head)
{
    std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
    std::cout << "Linked List: " << std::endl;
    if (head == NULL)
    {
        std::cout << "The Linked List is empty!";
        std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
        return;
    }
    NODE *temp = head;
    std::cout << "Head -> ";
    while (temp->next != head)
    {
        temp->displayNode();
        temp = temp->next;
    }
    temp->displayNode();
    std::cout << " Head";
}

void CSLL::insertAtFront(NODE *&head)
{
    NODE *n = new NODE();
    if (head == NULL)
    {
        head = n;
        n->next = head;
        return;
    }
    NODE *temp = head;
    n->next = temp;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    head = n;
    temp->next = head;
}

void CSLL::insertAtEnd(NODE *&head)
{
    NODE *n = new NODE();
    if (head == NULL)
    {
        head = n;
        n->next = head;
        return;
    }
    NODE *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    n->next = head;
    temp->next = n;
}

void CSLL::deleteFromFront(NODE *&head)
{
    if (head == NULL)
    {
        return;
    }
    NODE *temp = head;
    NODE *temp2 = head;
    if (temp2->next == head)
    {
        head = NULL;
        delete temp;
        return;
    }
    while (temp2->next != head)
    {
        temp2 = temp2->next;
    }
    head = temp->next;
    temp2->next = head;
    delete temp;
}

void CSLL::deleteFromEnd(NODE *&head)
{
    if (head == NULL)
    {
        return;
    }
    NODE *temp = head;
    NODE *temp2 = head;
    int flag = 0;
    if (temp->next == head)
    {
        head = NULL;
        delete temp;
        return;
    }
    while (temp->next != head)
    {
        temp = temp->next;
        if (flag)
        {
            temp2 = temp2->next;
        }
        flag = 1;
    }
    temp2->next = head;
    delete temp;
}

void CSLL::insertAtPosition(NODE *&head)
{
    NODE *n = new NODE();
    if (head == NULL)
    {
        head = n;
        n->next = head;
        return;
    }
    int k = head->getKeyForSearch();
    NODE *temp = head;
    while (temp->next != head)
    {
        if (temp->val == k)
        {
            n->next = temp->next;
            temp->next = n;
            return;
        }
        temp = temp->next;
    }
    if (temp->next == head && temp->val == k)
    {
        n->next = head;
        temp->next = n;
        return;
    }
}

void CSLL::deleteFromPosition(NODE *&head)
{
    //Please forgive me if i have obfuscated 😓
    if (head == NULL)
    {
        return;
    }
    int k = head->getKeyForSearch();
    NODE *temp = head;
    if (temp == head && temp->next == head && temp->val == k)
    {
        head = NULL;
        delete temp;
        return;
    }
    NODE *temp2 = head;
    if (temp->val == k)
    {
        while (temp2->next != head)
        {
            temp2 = temp2->next;
        }
        head = temp->next;
        temp2->next = head;
        delete temp;
        return;
    }
    int flag = 0;
    do
    {
        if (temp->val == k)
        {
            temp2->next = temp->next;
            delete temp;
            return;
        }
        temp = temp->next;
        if (flag)
        {
            temp2 = temp2->next;
        }
        flag = 1;
    } while (temp != head);
    if (temp2 == head && temp == head && temp->val == k)
    {
        head = NULL;
        delete temp;
        return;
    }
}
