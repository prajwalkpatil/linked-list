#include <iostream>
#include "../header/singlyNode.h"

NODE::NODE()
{
    NODE::readDetails();
    next = NULL;
}

void NODE::readDetails()
{
    std::cout << "Enter the value to be inserted: ";
    std::cin >> val;
}
