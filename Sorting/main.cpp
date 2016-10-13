//
//  File: main.cpp
//  Project: Cppdatastructures
//
//  Created by Juned Ansari on 1/25/14.
//  Copyright (c) 2014 Juned. All rights reserved.
//
///////////////////////////////////////////////////////////////////////
//  main.cpp - Implementing Sorting                                  //
//                                                                   //
//  Created by Juned Ansari on 1/25/14.                              //
//  Site: www.junedansari.com                                        //
//                                                                   //
//  Version: v1.0                                                    //
//  Copyright (c) 2014 Juned. All rights reserved.                   //
///////////////////////////////////////////////////////////////////////

#define Cppdatastructures_Sort_h_Main
#ifndef Cppdatastructures_Sort_h_Main
#include "Sort.h"

int main(int argc, const char * argv[])
{
    Sort sortMe(10);
    
    cout << "Unsorted Array:" << endl;
    sortMe.displayElements();
    cout << endl << endl;
    
    sortMe.bubble_sort();
    //sortMe.selection_sort();
    
    //sortMe.inserttion_sort();
    
    cout << "Sorted Array:" << endl;
    sortMe.displayElements();
    cout << endl << endl;
    
    /*
    // Merge sort
    int a[] = {12,10,43,23,-78,45,123,56,98,41,90,24};
    int num;
    
    num = sizeof(a)/sizeof(int);
    
    int b[num];
    
    //merge_sort_start(b,0,num-1);
    
    for(int i=0; i<num; i++)
        cout<<a[i]<<" ";
    cout<<endl;
     */
  
    return 0;
}
#endif
