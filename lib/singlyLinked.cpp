#include <iostream>
#include "../header/singlyNode.h"

void SLL::display(NODE *&head)
{
    std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
    if (head == NULL)
    {
        std::cout << "The Linked List is Empty! " << std::endl;
        std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
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
    std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
}

void SLL::insertAtFront(NODE *&head)
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

void SLL::insertAtEnd(NODE *&head)
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
}

void SLL::deleteFromFront(NODE *&head)
{
    if (head == NULL)
    {
        return;
    }
    NODE *temp = head;
    head = temp->next;
    delete temp;
}

void SLL::deleteFromEnd(NODE *&head)
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

void SLL::insertAtPosition(NODE *&head)
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
            return;
        }
        temp = temp->next;
    }
}

void SLL::deleteFromPosition(NODE *&head)
{
    int k = head->getKeyForSearch();
    NODE *temp = head;
    if (head->val == k)
    {
        head = temp->next;
        delete temp;
        return;
    }
    NODE *temp2 = head;
    int flag = 0;
    while (temp != NULL)
    {
        if (temp->val == k)
        {
            temp2->next = temp->next;
            delete temp;
            return;
        }
        temp = temp->next;
        if (flag != 0)
        {
            temp2 = temp2->next;
        }
        flag = 1;
    }
}