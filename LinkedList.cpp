#include "LinkedList.hpp"
#include <stdlib.h>
#include <iostream>

using namespace std;

LinkedList::LinkedList()
{
    this->head = NULL; //these could be 0s but NULL means absolute nothingness
    this->tail = NULL;
    this-> count = 0; 
}

void LinkedList::display()
{
    if(this->count == 0)
    {
        cout << "the empty list" << endl;
    }
    else 
    {
        Node* currNode = this->head; //curNode and head point to the same place in memory
        while(currNode->getNextNode() != NULL)
        {
            //cout << currNode << "->"; --this shows the memory addresses
            cout << currNode->getPayload() << "->";
            currNode = currNode->getNextNode();
        }
        cout << currNode->getPayload() << endl;

    }
}

void LinkedList::addEnd(int value)
{
    Node* n = new Node(value);
    if(head == NULL)
    {
        //we have the empty list
        this->head = n;
        this->tail = n;
    }
    else 
    {
        //we have a list with at least one element in it, and we know that tail points to the
        //end of the list
        this->tail->setNextNode(n);
        this->tail = n;
    }
    this->count++;
}

int LinkedList::removeEnd()
{
    if(this-> count > 0)
    {
        Node* n = this->tail;
        int value = n->getPayload();

        if(this->count == 1)
        {
            this->head = NULL;
            this->tail = NULL;
        }  
        else
        {
            Node* currNode = this->head;
            while(currNode->getNextNode() != tail)
            {
                currNode = currNode->getNextNode();
            }
            this->tail = currNode;
            this->tail->setNextNode(NULL);
        }


        this->count--;
        delete(n);
        return value;
    }
}
void LinkedList::addFront(int value)
{
    if(head == NULL)
    {
        //same thing if head == NULL in addEnd()
        this->addEnd(value);

    }
    else 
    {
        Node* n = new Node(value);
        n->setNextNode(this->head);
        this->head = n;
        this->count++;
    }
}

int LinkedList::removeFront()
{
    if(this-> count > 0)
    {
        Node* n = this->head;
        int value = n->getPayload();

        if(this->count == 1)
        {
            this->head = NULL;
            this->tail = NULL;
        }  
        else
        {
            Node* currNode = this->head;
            currNode = this->head->getNextNode();
            this->head = currNode;
        }


        this->count--;
        delete(n);
        return value;
    }
}

int LinkedList::removeAtIndex(int index)
    {
        if(this->head)
        {
            if(index < 0 || index >= this-> count)
            {
                cout << "ArrayIndexOutofBoundException" << endl;
            }
            else
            {
                if(index == 0)
                {
                    return this->removeFront();
                }
                else if(index == this->count - 1)
                {
                    return this->removeEnd();
                }
                else
                {
                    //we are removing from somewhere in the middle
                    Node* prevDude = this->head;
                    Node* dudeToRemove = this->head;

                    //run dudeToRemove to the correct index
                    for(int i = 0; i  < index; i++)
                    {
                        dudeToRemove = dudeToRemove->getNextNode();

                    }

                    //make prevDude point at the place right before dudeToRemove
                    while(prevDude->getNextNode() != dudeToRemove)
                    {
                        prevDude = prevDude->getNextNode();
                    }

                    prevDude->setNextNode(dudeToRemove->getNextNode());
                    dudeToRemove->setNextNode(NULL);
                    int valueToReturn = dudeToRemove->getPayload();
                    delete(dudeToRemove);
                    this->count--;
                    return valueToReturn;
                    
                }
            }
        }
        else
        {
            cout << "Nothing to remove from the empty list" << endl;
        }
    }
void LinkedList::addAtIndex(int index, int value)
{
    if(index < 0 || index >= this-> count)
    {
        cout << "ArrayIndexOutofBoundException" << endl;
    }
    else
    {
        if(index == 0)
        {
            this->addFront(value);
        }
        else if(index == this->count)
        {
            this->addEnd(value);
        }
        else
        {
            //we are removing from somewhere in the middle
            Node* prevDude = this->head;
            Node* dudeToAdd = new Node(value);

            //run dudeToRemove to the correct index
            for(int i = 0; i  < index-1; i++)
            {
                prevDude = prevDude->getNextNode();

            }
            dudeToAdd->setNextNode(prevDude->getNextNode());
            prevDude->setNextNode(dudeToAdd);
            this->count++;
            
        }
    }
}

Node* LinkedList::getNodeAtIndex(int index)
{
    if(index >= 0 && index < this->count) 
    {
        //return the node at that poistion in the list 
        Node* currentNode = this->head;
        for(int i = 0; i < index; i++)
        {
            currentNode = currentNode->getNextNode();
        }
        return currentNode;
    }
    return NULL; //this means that index is not legal (not needed but good programming practice)
}

void LinkedList::insertionSort() 
{
    //does this list need to potentially be sorted? 
    if(this->count > 1)
    {
        Node* theFollowerNode;
        Node* swapNode;
        Node* beforeSwapNode;
        int theFollowerPos;

        for(int currPos = 1; currPos < this->count; currPos++)
        {
            theFollowerPos = currPos;
            theFollowerNode = this->getNodeAtIndex(theFollowerPos);

            while(theFollowerPos > 0 && theFollowerNode->getPayload() < this->getNodeAtIndex(theFollowerPos-1)->getPayload())
            {
                swapNode = this->getNodeAtIndex(theFollowerPos-1);

                if(this->head == swapNode)
                {
                    swapNode->setNextNode(theFollowerNode->getNextNode());
                    theFollowerNode->setNextNode(head);
                    this->head = theFollowerNode;
                }
                else
                {
                    beforeSwapNode = this->head;
                    while(beforeSwapNode->getNextNode() != swapNode)
                    {
                        beforeSwapNode = beforeSwapNode->getNextNode();
                    }
                    swapNode->setNextNode(theFollowerNode->getNextNode());
                    theFollowerNode->setNextNode(swapNode);
                    beforeSwapNode->setNextNode(theFollowerNode);   

                }
                if(this->tail == theFollowerNode)
                {
                    this->tail = swapNode;
                }
                theFollowerPos--;

        }
    }

}
}   
