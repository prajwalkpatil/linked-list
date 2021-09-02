#include <iostream>
#include "../header/doublyNode.h"

void DLL::display(NODE *&head)
{
    NODE *temp;
    NODE *temp2 = NULL;
    temp = head;
    std::cout << "\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";
    std::cout << "\nLinked List: \n";
    if (head == NULL)
    {
        std::cout << "The Linked List is Empty! " << std::endl;
        std::cout << "\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
        return;
    }
    std::cout << "Head <->";
    while (temp != NULL)
    {
        //?Check if the prev links of nodes are correct
        if (temp->prev == temp2)
        {
            temp->displayNode();
        }
        else
        {
            std::cout << "\nError! with previous links " << std::endl;
            return;
        }
        temp2 = temp;
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
    if (temp->next != NULL)
    {
        (temp->next)->prev = NULL;
    }
    delete temp;
}

void DLL::deleteFromEnd(NODE *&head)
{
    if (head == NULL)
    {
        return;
    }
    NODE *temp = head;
    if (temp->next == NULL)
    {
        head = NULL;
        delete temp;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    (temp->prev)->next = NULL;
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

void DLL::deleteFromPosition(NODE *&head)
{
    int k = head->getKeyForSearch();
    NODE *temp = head;
    if (temp->val == k && temp->next == NULL)
    {
        head = NULL;
        delete temp;
        return;
    }
    else if (temp->val == k)
    {
        head = temp->next;
        (temp->next)->prev = NULL;
        delete temp;
        return;
    }
    NODE *temp2 = head;
    int flag = 0;
    while (temp != NULL)
    {
        if (temp->val == k)
        {
            if (temp->next == NULL)
            {
                temp2->next = NULL;
                delete temp;
                return;
            }
            temp2->next = temp->next;
            (temp->next)->prev = temp2;
            delete temp;
            return;
        }
        temp = temp->next;
        if (flag)
        {
            temp2 = temp2->next;
        }
        flag = 1;
    }
}