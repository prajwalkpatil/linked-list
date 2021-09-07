#include <iostream>
#include "../header/doublyNode.h"

void CDLL::display(NODE *&head)
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

void CDLL::insertAtFront(NODE *&head)
{
    NODE *n = new NODE();
    if (head == NULL)
    {
        n->next = n;
        n->prev = n;
        head = n;
        return;
    }
    NODE *temp = head;
    n->prev = temp->prev;
    n->next = temp;
    (temp->prev)->next = n;
    temp->prev = n;
    head = n;
}

void CDLL::insertAtEnd(NODE *&head)
{
    NODE *n = new NODE();
    if (head == NULL)
    {
        n->next = n;
        n->prev = n;
        head = n;
        return;
    }
    NODE *temp = head;
    n->prev = temp->prev;
    (temp->prev)->next = n;
    n->next = temp;
    temp->prev = n;
}

void CDLL::deleteFromEnd(NODE *&head)
{
    if (head == NULL)
    {
        return;
    }
    NODE *temp = head;
    if (temp->next == temp)
    {
        head = NULL;
        delete temp;
        return;
    }
    temp = temp->prev;
    NODE *temp2 = temp->prev;
    temp2->next = head;
    head->prev = temp2;
    delete temp;
}

void CDLL::deleteFromFront(NODE *&head)
{
    if (head == NULL)
    {
        return;
    }
    NODE *temp = head;
    if (temp->next == temp)
    {
        head = NULL;
        delete temp;
        return;
    }
    NODE *temp2 = head;
    temp2 = temp2->prev;
    (temp->next)->prev = temp2;
    temp2->next = temp->next;
    head = temp->next;
    delete temp;
}

void CDLL::insertAtPosition(NODE *&head)
{

    NODE *n = new NODE();
    if (head == NULL)
    {
        n->next = n;
        n->prev = n;
        head = n;
        return;
    }
    int k = head->getKeyForSearch();
    NODE *temp = head;
    NODE *temp2 = head;
    int flag = 0;
    if (temp->next == head && temp->val == k)
    {
        n->next = temp;
        n->prev = temp;
        temp->next = n;
        return;
    }
    while (temp->next != head)
    {
        if (temp->val == k)
        {
            n->next = temp->next;
            (temp->next)->prev = n;
            n->prev = temp;
            temp->next = n;
            return;
        }
        temp = temp->next;
    }
    if (temp->next == head && temp->val == k)
    {
        n->next = head;
        n->prev = temp;
        head->prev = n;
        temp->next = n;
        return;
    }
}

void CDLL::deleteFromPosition(NODE *&head)
{
    if (head == NULL)
    {
        return;
    }
    int k = head->getKeyForSearch();
    NODE *temp = head;
    NODE *temp2 = head;
    if (temp->next == head && temp->val == k)
    {
        head = NULL;
        delete temp;
        return;
    }
    while (temp->next != head)
    {
        if (temp->val == k)
        {
            if (temp == head)
            {
                (temp->prev)->next = temp->next;
                (temp->next)->prev = temp->prev;
                head = temp->next;
                delete temp;
                return;
            }
            (temp->prev)->next = temp->next;
            (temp->next)->prev = temp->prev;
            delete temp;
            return;
        }
        temp = temp->next;
    }
    if (temp->next == head && temp->val == k)
    {
        (temp->prev)->next = head;
        head->prev = temp->prev;
        delete temp;
        return;
    }
}