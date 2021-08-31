#ifndef _SINGLY_LINKED_
#define _SINGLY_LINKED_

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
};
#endif