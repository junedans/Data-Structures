//
//  File: TreeNode.h
//  Project: Cppdatastructures
//
//  NOTE: We have the templatised class Tree, which is our LinkedList class
//        defined as friend here, so that it can access the data members
//        of the TreeNode class.
//
//  More on Friend class:
//        The C++ Programming.Language.4th.Edition. Chapter 19 Section 19.4
//
///////////////////////////////////////////////////////////////////////
//  TreeNode.h- Is the header file for templatised class TreeNode    //
//                                                                   //
//  Created by Juned Ansari on 1/25/14.                              //
//  Site: www.junedansari.com                                        //
//  Phone: 315-396-4987                                              //
//                                                                   //
//  Version: v1.0                                                    //
//  Copyright (c) 2014 Juned. All rights reserved.                   //
///////////////////////////////////////////////////////////////////////


#ifndef Cppdatastructures_TreeNode_h
#define Cppdatastructures_TreeNode_h

template< typename NODETYPE > class Tree;

template <typename NODETYPE>
class TreeNode {
    friend class Tree< NODETYPE >;                  // TreeNode class-template defn.
    
public:
    TreeNode(const NODETYPE &d) : leftPtr(0), data (d), rightPtr(0)     // Constructor
    { }
    
    NODETYPE getData() const                        // Return copy of TreeNode's data
    {
        return data;
    }
    
private:
    TreeNode< NODETYPE > *leftPtr;
    NODETYPE data;
    TreeNode< NODETYPE > *rightPtr;
};

#endif
