//
//  File: main.cpp
//  Project: Cppdatastructures
//
//  Created by Juned Ansari on 1/25/14.
//  Copyright (c) 2014 Juned. All rights reserved.
//
///////////////////////////////////////////////////////////////////////
//  main.cpp - Implementing Inheritance                              //
//                                                                   //
//  Created by Juned Ansari on 1/25/14.                              //
//  Site: www.junedansari.com                                        //
//                                                                   //
//  Version: v1.0                                                    //
//  Copyright (c) 2014 Juned. All rights reserved.                   //
///////////////////////////////////////////////////////////////////////

#define Cppdatastructures_Inheritence_h_Main
#ifndef Cppdatastructures_Inheritence_h_Main
#include "Inheritance.h"

int main(int argc, const char * argv[])
{
    base* b = new base;
    b->display();       // Calls base::display()
    b->display2();      // Calls base::display2()
    b->display_base();
    
    cout << "------------------------------";
    derived* d= new derived;
    d->display();       // Calls derived::display()
    d->display2();      // Calls derived::display2()
    d->display_base();
    d->display_derived();
    
    cout << "------------------------------";
    base* db = new derived;     // Will always call the base class functions
    db->display();      // Calls base::display() as the base class display() is not virtual it takes the base class disply()
    db->display2();     // Calls derived::display() as display2() in base calls is virtual
    db->display_base();
     
    return 0;
}
#endif
