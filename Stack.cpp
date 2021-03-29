#include "Stack.hpp"

void Stack::push(int value)
{
    this->addFront(value);
}

int Stack::pop()
{
    return this->removeFront();
}

int Stack::peek()
{
    return this->getNodeAtIndex(0)->getPayload();
}