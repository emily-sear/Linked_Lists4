
//#include "LinkedList.hpp"
#include "Stack.hpp"
#include <iostream> 
#include <stdlib.h>

using namespace std;

void insertionSort(int ar[], int length);
void displayIntArray(int ar[]);

#define ARRAY_LENGTH 10 //called a macro 

int main(int argc, char** argv)
{
    //this gives you actual random numbers --> you have to see the random number generator
    /**srandom(time(NULL));

    long val;
    int ar[10];
    cout << sizeof(ar) / sizeof(int) << endl; //how you find the acutal length of an array
    for (int i  = 0; i < ARRAY_LENGTH; i++)
    {
        val = random();
        val = val % 1000; //the numbers between 0 and 999
        ar[i] = val;
    }
    displayIntArray(ar);
    insertionSort(ar, ARRAY_LENGTH);
    cout << endl;
    displayIntArray(ar);
    **/
   

    LinkedList* ll = new LinkedList();
    
    ll->addEnd(4);
    ll->addEnd(6);
    ll->addEnd(8);
    ll->addEnd(2);
    ll->addEnd(3);
    ll->addEnd(12);
    ll->addFront(13);
    ll->display();

    ll->insertionSort();
    ll->display();


    Stack* s = new Stack();
    s->push(2);
    s->push(3);
    s->display();

    return 0;
}

//insertion sort with ints 
void insertionSort(int ar[], int length)
{
    int tempSwap;
    int theFollower;

    for(int currStart = 0; currStart < length; currStart++)
    {
        theFollower = currStart;
        while(theFollower > 0 && ar[theFollower] < ar[theFollower -1])
        {
            tempSwap = ar[theFollower];
            ar[theFollower] = ar[theFollower - 1];
            ar[theFollower - 1] = tempSwap;
            theFollower--;
        }
    }
}

void displayIntArray(int ar[])
{
    for(int i = 0; i < ARRAY_LENGTH; i++)
    {
        cout << ar[i] << endl;
    }
}