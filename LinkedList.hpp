#include "Node.hpp"

class LinkedList
{
    private: 
        Node* head;
        Node* tail;
        int count;
        
    protected: 
        Node* getNodeAtIndex(int index);

    public: 
        LinkedList();
        void display();
        void addEnd(int value);
        int removeEnd();
        void addFront(int value);
        int removeFront();
        int removeAtIndex(int index);
        void addAtIndex(int index, int value);
        void insertionSort();
     

};