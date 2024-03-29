/**
 * A sample code of Creating C++ linked lists,
 * Including definitions the list node class and linked list class,
 * and how to create a blank linked list and a one-node linked list.
 *
 * Outline: understand the definition and structure of the linked
 * list and build a linked list based on it.
 *
 *Assigntment Week 2
 *  Starting with my code for the single linked list in SLList.cpp, do the following:
 *      - Write an additional method called push_back(int) that will add an integer to the end of the list. You can modify the provided code.
 *      - Modify the Node class and LinkedList class so that you can access your parent node (double linked-list).
 */

#include <iostream>
#include <cstddef>

using std::cout;
using std::endl;




/* definition of the list node class */
class Node
{
    friend class LinkedList;
private:
    int value;
    Node *pNext;
    Node *pPrevious;
    
public:
    /* Constructors with No Arguments */
    Node(void)
    : pNext(NULL), pPrevious(NULL)
    { }
    
    /* Constructors with a given value */
    Node(int val)
    : value(val), pNext(NULL), pPrevious(NULL)
    { }
    
    /* Constructors with a given value and a link of the next node */
    Node(int val, Node* next, Node* previous)
    : value(val), pNext(next), pPrevious(previous)
    {}
    
    /* Getters */
    int getValue(void)
    { return value; }
    
    Node* getNext(void)
    { return pNext; }
    
    Node* getPrevious(void)
    { return pPrevious; }
};

/* definition of the linked list class */
class LinkedList
{
private:
    /* pointer of head node */
    Node *pHead;
    /* pointer of tail node */
    Node *pTail;
    
public:
    /* Constructors with No Arguments */
    LinkedList(void);
    /* Constructors with a given value of a list node */
    LinkedList(int val);
    /* Destructor */
    ~LinkedList(void);
    
    /* Traversing the list and printing the value of each node */
    void traverse_and_print();
    
    void push_back(int val);
};

LinkedList::LinkedList()
{
    /* Initialize the head and tail node */
    pHead = pTail = NULL;
}

LinkedList::LinkedList(int val)
{
    /* Create a new node, acting as both the head and tail node */
    pHead = new Node(val);
    pTail = pHead;
}

LinkedList::~LinkedList()
{
    
}

void LinkedList::traverse_and_print()
{
    Node *p = pHead;
    Node *t = pTail;
    
    /* The list is empty? */
    if (pHead == NULL) {
        cout << "The list is empty" << endl;
        return;
    }
    
    cout << "LinkedListForward: ";
    /* A basic way of traversing a linked list */
    while (p != NULL) { /* while there are some more nodes left */
        /* output the value */
        cout << p->value << " ";
        /* The pointer moves along to the next one */
        p = p->pNext;
    }
    cout << endl;
    
    cout << "LinkeListBackwards: ";
    while (t != NULL) {
        cout << t->value << " ";
        t= t->pPrevious;
    }
    cout << endl;
}

void LinkedList::push_back(int val){
    Node* newNode = new Node(val, NULL, pTail);
        
    if (pTail != NULL) 
    {
        pTail->pNext = newNode;
    }
    
    pTail = newNode;
    
    if (pHead == NULL)
    {
        pHead = newNode;
    }
    
}

int main(int argc, const char * argv[])
{
    /* Create an empty list */
    LinkedList list1;
    cout << "Created an empty list named list1." << endl;
    /* output the result */
    cout << "list1:" << endl;
    list1.traverse_and_print();
    
    /* Create a list with only one node */
    LinkedList list2(10);
    cout << "Created a list named list2 with only one node." << endl;
    /* output the result */
    cout << "list2:" << endl;
    list2.traverse_and_print();
    
    /*your testing code here*/
    for (int i = 0 ; i < 10; i++){
        list2.push_back(i);
    }
    list2.traverse_and_print();
    return 0;
}


