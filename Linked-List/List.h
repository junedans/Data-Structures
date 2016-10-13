//
//  File: LinkedList.h
//  Project: Cppdatastructures
//
//  Created by Juned Ansari on 1/25/14.
//  Copyright (c) 2014 Juned. All rights reserved.
//
//  NOTE: I have declared and implemented all the member functions here itself.
//        One can seperate the implementation into another .cpp file with reference
//        to the header class using #include.
//
//  More on Friend class:
//        The C++ Programming.Language.4th.Edition. Chapter 19 Section 19.4
//
///////////////////////////////////////////////////////////////////////
//  List.h - This is the header file for templatised class List      //
//                                                                   //
//  Created by Juned Ansari on 1/25/14.                              //
//  Site: www.junedansari.com                                        //
//                                                                   //
//  Version: v1.0                                                    //   
//  Copyright (c) 2014 Juned. All rights reserved.                   //
///////////////////////////////////////////////////////////////////////

#ifndef Cppdatastructures_LinkedList_h
#define Cppdatastructures_LinkedList_h

#include <iostream>
#include "Node.h"

using namespace std;

template <typename NODETYPE>
class List {
public:
    List();                                     // Constructor
    ~List();                                    // Destructor
    void insertAtFront(const NODETYPE &);       // Insert Node at the Front of the List
    void insertAtBack(const NODETYPE &);        // Insert Node at the Bottom of the List
    bool removeFromFront(NODETYPE &);           // Remove a Node from the Front of the List
    bool removeFromBack(NODETYPE &);            // Remove a Node from the Bottom of the List
    int myLength() const;                       // Scans through first to last node to calculate the length
    void removeDuplications();                  // Write code to remove duplicates from an unsorted linked list
    NODETYPE kthLastElement(const int k) const; // Implement an algorithm to find the kth to last element of a singly linked list
    void partitionLL(const NODETYPE &);         // Write code to partition a linked list around a value x, such that all nodes less than x come before all              nodes greater than or equal to x
    bool isEmpty() const;                       // True if the List is empty
    void print() const;                         // Prints all the node
    
private:
    Node< NODETYPE > *firstPtr;                 // __Pointer to the first Node
    Node< NODETYPE > *lastPtr;                  // __Pointer to the last Node
    
    Node< NODETYPE > *getNewNode(const NODETYPE &); // __Creates a new Node
};

// Constructor
template <typename NODETYPE>
List<NODETYPE>::List(): firstPtr(0), lastPtr(0)
{
    
}

// Destructor
template <typename NODETYPE>
List<NODETYPE>::~List()
{
    if(!isEmpty())
    {
        cout << "Destroying Node ...\n";
        
        Node<NODETYPE> *currentPtr = firstPtr;
        Node<NODETYPE> *tempPtr;
        
        while (currentPtr!=0) {
            tempPtr = currentPtr;
            cout << tempPtr->data << '\n';
            currentPtr = currentPtr->next;
            delete tempPtr;
        }
    }
    cout << "All Nodes Destroyes.\n\n";
}

// __Creates a new Node
template <typename NODETYPE>
Node< NODETYPE > * List< NODETYPE >::getNewNode(const NODETYPE &value)
{
    return new Node< NODETYPE >(value);
}

// True if the List is empty
template <typename NODETYPE>
bool List< NODETYPE > :: isEmpty() const{
    return (firstPtr == 0);
}

// Insert Node at the Front of the List
template <typename NODETYPE>
void List< NODETYPE >:: insertAtFront(const NODETYPE &value) {
    Node< NODETYPE > *newPtr = getNewNode(value);
    
    if(isEmpty())
    {
        firstPtr = lastPtr = newPtr;
    }
    else
    {
        newPtr->next = firstPtr;
        firstPtr = newPtr;
    }
}

// Insert Node at the Bottom of the List
template < typename NODETYPE>
void List< NODETYPE > :: insertAtBack(const NODETYPE &value) {
    Node<NODETYPE> *newPtr = getNewNode(value);
    
    if (isEmpty()) {
        firstPtr = lastPtr = newPtr;
    }
    else
    {
        lastPtr->next = newPtr;
        lastPtr = newPtr;
    }
}

// Remove a Node from the Front of the List
template <typename NODETYPE >
bool List< NODETYPE >::removeFromFront(NODETYPE &value) {
    if (isEmpty()) {
        return false;
    }
    else
    {
        Node< NODETYPE > *tempPtr = firstPtr;
        
        if (firstPtr == lastPtr)
            lastPtr = firstPtr = 0;
        else
            firstPtr = firstPtr->next;
        
        value = tempPtr->data;
        delete tempPtr;
        return true;
    }
}

// Remove a Node from the Bottom of the List
template <typename NODETYPE>
bool List< NODETYPE >::removeFromBack(NODETYPE &value) {
    if(isEmpty()) {
       return false;
    }
    else
    {
        Node< NODETYPE > *tempPtr = lastPtr;
        
        if (lastPtr == firstPtr)
            lastPtr = firstPtr = 0;
        else
        {
            Node< NODETYPE > * currentPtr = firstPtr;
            
            while (currentPtr->next != lastPtr) {
                currentPtr = currentPtr->next;
            }
            lastPtr = currentPtr;
            currentPtr->next = 0;
        }
        value   = tempPtr->data;
        delete tempPtr;
        return true;
    }
}

// Prints all the node
template <typename NODETYPE>
void List< NODETYPE > ::print() const {
    if (firstPtr == 0) {
        cout << "LinkedList is empty. \n";
        return;
    }
    else
    {
        Node< NODETYPE > *currentPtr = firstPtr;
        cout << "The List is : \n";
        while (currentPtr != 0) {
            cout << currentPtr->data << " - ";
            currentPtr = currentPtr->next;
        }
    }
}

// Write code to find the length of a Linked List
// Scans through first to last node to calculate the length
template <typename NODETYPE>
int List< NODETYPE >::myLength() const {
    if( firstPtr == 0)
        return 0;
    Node< NODETYPE > *currentPtr = firstPtr;
    int len=0;
    while (currentPtr != 0) {
        len++;
        currentPtr = currentPtr->next;
    }
    return len;
}

// Write code to remove duplicates from an unsorted linked lis
template <typename NODETYPE>
void List< NODETYPE >::removeDuplications()
{
#define removeDuplications_Hashtable
#ifndef removeDuplications_Hashtable
    if (firstPtr == 0) {
        cout << "LinkedList is empty. \n";
        return;
    }
    else
    {
        hashtable ht = new hashtable();
        Node<NODETYPE> *currentPtr = firstPtr;
        Node<NODETYPE> *previousPtr = 0;
        
        while (currentPtr != 0) {
            if(hashtable.contains(currentPtr->data))
            {
                previousPtr->next=currentPtr->next;
            }
            else
            {
                hashtable.insert(currentPtr->data, true);
                previousPtr = currentPtr;
            }
            currentPtr=currentPtr->next;
        }
        
    }
#endif
    
#ifdef removeDuplications_Hashtable
    if (firstPtr == 0) {
        cout << "LinkedList is empty. \n";
        return;
    }
    else
    {
        Node<NODETYPE> *currentPtr = firstPtr;
        
        while (currentPtr != 0) {
            Node< NODETYPE > *temp = currentPtr;
            while (temp->next != 0) {
                if (currentPtr->data == temp->next->data) {
                    temp->next = temp->next->next;
                }
                else
                    temp = temp->next;
            }
            currentPtr = currentPtr->next;
        }
    }
#endif
}               // end of the function removeDuplications


// Implement an algorithm to find the kth to last element of a singly linked list
template <typename NODETYPE>
NODETYPE List<NODETYPE>:: kthLastElement(const int k) const
{
    if(k > myLength())
    {
        cout << "\nERROR : List_Length is less than 'K'\n";
        return 0;
    }
    else
    {
        Node< NODETYPE > *kahead = firstPtr;
        Node< NODETYPE > *kbehind = firstPtr;
        
        for (int i=1; i< k; i++) {
            kahead = kahead->next;
        }
        while (kahead->next != 0) {
            kahead = kahead->next;
            kbehind = kbehind->next;
        }
        
        return kbehind->data;
    }
}

// Write code to partition a linked list around a value x, such that all nodes less than x come before all nodes greater than or equal to x
template <typename NODETYPE>
void List< NODETYPE >::partitionLL(const NODETYPE &xValue)
{
    Node< NODETYPE > *xNode = getNewNode(xValue);
    Node< NODETYPE > *xFirstPtr = xNode;
    Node< NODETYPE > *xLastPtr = xNode;
    
    Node< NODETYPE > *currentPtr = firstPtr;
    while (currentPtr != 0) {
        Node< NODETYPE > *nextPtr = currentPtr->next;
        if(currentPtr->data < xValue)
        {
            Node< NODETYPE > *temp = currentPtr;
            temp->next = xFirstPtr;
            xFirstPtr = temp;
        }
        else if (currentPtr->data > xValue)
        {
            Node< NODETYPE > *temp = currentPtr;
            xLastPtr->next = temp;
            xLastPtr = temp;
        }
        currentPtr = nextPtr;
    }
    firstPtr = xFirstPtr;
    lastPtr = xLastPtr;
}
#endif














