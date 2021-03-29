#include "LinkedList.hpp"

class Stack : public LinkedList //Stack extends LinkedList as a public parent 
{
    public: 
        //Stack();
        void push(int value); //adds to the front of the list
        int pop(); //removes and returns front of the list
        int peek(); //returns the front of the list
};