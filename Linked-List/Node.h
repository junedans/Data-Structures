//
//  File: Node.h
//  Project: Cppdatastructures
//
//  NOTE: We have the templatised class List, which is our LinkedList class
//        defined as friend here, so that it can access the data members
//        of the Node class.
//
//  More on Friend class:
//        The C++ Programming.Language.4th.Edition. Chapter 19 Section 19.4
//
///////////////////////////////////////////////////////////////////////
//  Node.h - This is the header file for templatised class Node      //
//                                                                   //
//  Created by Juned Ansari on 1/25/14.                              //
//  Site: www.junedansari.com                                        //
//                                                                   //
//  Version: v1.0                                                    //
//  Copyright (c) 2014 Juned. All rights reserved.                   //
///////////////////////////////////////////////////////////////////////

#ifndef Cppdatastructures_Node_h
#define Cppdatastructures_Node_h

#include <iostream>
#include <string>

template <typename NODETYPE> class List;

template<typename NODETYPE>
class Node
{
    friend class List< NODETYPE >;  // Templatised class List
    
public:
    Node(const NODETYPE &);         // Constructor
    NODETYPE getData() const;       // Return Node value
    
private:
    NODETYPE data;                  // __Node value
    Node<NODETYPE> * next;          // __Pointing to the next Node
};

// Constructor
template <typename NODETYPE>
Node< NODETYPE >::Node(const NODETYPE &info): data(info), next(0)
{
}

// Return Node value
template <typename NODETYPE>
NODETYPE Node< NODETYPE >::getData() const {
    return data;
}

#endif
