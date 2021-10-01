#include <iostream>
#include "header/doublyNode.h"

int main()
{
    NODE *head = NULL;
    CDLL::insertAtEnd(head);
    CDLL::display(head);

    CDLL::insertAtEnd(head);
    CDLL::display(head);

    CDLL::insertAtEnd(head);
    CDLL::display(head);
    CDLL::insertAtEnd(head);
    CDLL::display(head);
    CDLL::insertAtEnd(head);
    CDLL::display(head);

    CDLL::deleteFromPosition(head);
    CDLL::display(head);

    CDLL::deleteFromPosition(head);
    CDLL::display(head);

    CDLL::deleteFromPosition(head);
    CDLL::display(head);

    CDLL::deleteFromPosition(head);
    CDLL::display(head);
    CDLL::deleteFromPosition(head);
    CDLL::display(head);

    return 0;
}
