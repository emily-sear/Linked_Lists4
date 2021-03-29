#include "Node.hpp"
#include <stdlib.h>

using namespace std;

Node::Node(int payload)
{
    this->payload = payload;
    this->nextNode = NULL;
}

void Node::setNextNode(Node* n)
{
    this->nextNode = n;
}

Node* Node::getNextNode()
{
    return this->nextNode;
}

int Node::getPayload()
{
    return this->payload;
}