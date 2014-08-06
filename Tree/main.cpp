//
//  File: main.cpp
//  Project: Cppdatastructures
//
//  Created by Juned Ansari on 1/25/14.
//  Copyright (c) 2014 Juned. All rights reserved.
//
///////////////////////////////////////////////////////////////////////
//  main.cpp - Implementing Tree                                     //
//                                                                   //
//  Created by Juned Ansari on 1/25/14.                              //
//  Site: www.junedansari.com                                        //
//  Phone: 315-396-4987                                              //
//                                                                   //
//  Version: v1.0                                                    //
//  Copyright (c) 2014 Juned. All rights reserved.                   //
///////////////////////////////////////////////////////////////////////

#define Cppdatastructures_Tree_Main
#ifndef Cppdatastructures_Tree_Main
#include "Tree.h"

int main(int argc, const char * argv[])
{

    Tree< int > intTree;
    for (int i=0; i<10; i++)
    {
        intTree.insertNode((int)random()%10);
    }
    
    cout << "\nPre-Order Traversal\n";
    intTree.preOrderTraversal();
    
    cout << "\nIn-Order Traversal\n";
    intTree.inOrderTraversal();
    
    cout << "\nPost-Order Traversal\n";
    intTree.postOrderTraversal();
    
    cout << "\n Check if tree is balanced. \n";
    if(intTree.isBalanced())
        cout << "YES ! it is BALANCED.\n";
    else
        cout << "NO ! it is not BALANCED.\n";
    
    cout << "Search for 7 in the tree";
    if(intTree.findNode(7))
        cout << "\nFound 7\n";
    else
        cout << "\n7 Not Found\n";
    
    intTree.preOrderMy();
    
    return 0;
}
#endif