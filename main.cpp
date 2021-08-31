#include <iostream>
#include "header/singlyNode.h"

int main()
{
    NODE *head = NULL;
    SLL::insertAtFront(head);
    SLL::display(head);
    return 0;
}