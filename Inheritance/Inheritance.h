//
//  File: Inheritance.h
//  Project: Cppdatastructures
//
//
///////////////////////////////////////////////////////////////////////
//  Inheritance.h- To understand inheritance and polymorphism        //
//                                                                   //
//  Created by Juned Ansari on 1/25/14.                              //
//  Site: www.junedansari.com                                        //
//  Phone: 315-396-4987                                              //
//                                                                   //
//  Version: v1.0                                                    //
//  Copyright (c) 2014 Juned. All rights reserved.                   //
///////////////////////////////////////////////////////////////////////

#ifndef Cppdatastructures_Inheritance_h
#define Cppdatastructures_Inheritance_h

#include<iostream>

using namespace std;

class base{
public:
    base(void){ cout << "\n Base Constructor.\n";}

    void display()
    {
        cout << "This is Base Class Display().\n";
    }

    virtual void display2()
    {
        cout << "This is Base Class Display2().\n";
    }
    
    void display_base()
    {
        cout << "This is Base Class Display_base().\n";
    }
private:
    //int data;
};


class derived : public base {
public:
    derived(void){ cout << "\n Dervied Constructor.\n";}

    void display()
    {
        cout << "This is Derived Class Display.\n";
    }
    
    void display2()     // base class display function overridden
    {
        cout << "This is Derived Class Display2().\n";
    }
    
    void display_derived()
    {
        cout << "This is Dervied Class Display_derived().\n";
    }
private:
    
};

#endif
