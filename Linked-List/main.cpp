//
//  File: main.cpp
//  Project: Cppdatastructures
//
//  Created by Juned Ansari on 1/25/14.
//  Copyright (c) 2014 Juned. All rights reserved.
//
///////////////////////////////////////////////////////////////////////
//  main.cpp - Implementing LinkedList                               //
//                                                                   //
//  Created by Juned Ansari on 1/25/14.                              //
//  Site: www.junedansari.com                                        //
//  Phone: 315-396-4987                                              //
//                                                                   //
//  Version: v1.0                                                    //
//  Copyright (c) 2014 Juned. All rights reserved.                   //
///////////////////////////////////////////////////////////////////////

#define Cppdatastructures_LL_Main
#ifndef Cppdatastructures_LL_Main
#include "List.h"

int main(int argc, const char * argv[])
{
    // insert code here...
    cout << "Hello,LINKED LIST World!\n";
#define Unique_LL
#ifdef Unique_LL
    List<int> intergerList;
    intergerList.insertAtFront(5);
    intergerList.insertAtFront(7);
    intergerList.insertAtBack(3);
    intergerList.insertAtFront(4);
    intergerList.insertAtBack(1);
    intergerList.insertAtFront(6);
    intergerList.insertAtFront(2);
    intergerList.insertAtBack(8);
#endif
#ifndef Unique_LL
    List<int> intergerList;
    intergerList.insertAtFront(1);
    intergerList.insertAtFront(2);
    intergerList.insertAtFront(1);
    intergerList.insertAtFront(3);
    intergerList.insertAtBack(4);
    intergerList.insertAtFront(2);
    intergerList.insertAtFront(3);
    intergerList.insertAtBack(4);
#endif
    cout << "\n Original LL \n";
    intergerList.print();
    
    cout << "\n After Removing Duplicates \n";
    intergerList.removeDuplications();
    intergerList.print();
    
    cout << "\n Kth Last Element is ( K=3) \n" << intergerList.kthLastElement(3);
    
    cout << "\n Sorting with X=4 \n";
    intergerList.partitionLL(4);
    intergerList.print();
    
    
    return 0;
}
#endif