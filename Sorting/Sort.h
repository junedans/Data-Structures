//
//  File: Sort.h
//  Project: Cppdatastructures
//
//  Created by Juned Ansari on 1/25/14.
//  Copyright (c) 2014 Juned. All rights reserved.
//
//  NOTE: I have declared and implemented all the member functions here itself.
//        One can seperate the implementation into another .cpp file with reference
//        to the header class using #include.
//
///////////////////////////////////////////////////////////////////////
//  Sort.h - This is the header file for different sorting functions //
//                                                                   //
//  Created by Juned Ansari on 1/25/14.                              //
//  Site: www.junedansari.com                                        //
//                                                                   //
//  Version: v1.0                                                    //
//  Copyright (c) 2014 Juned. All rights reserved.                   //
///////////////////////////////////////////////////////////////////////

#ifndef Cppdatastructures_Sort_h
#define Cppdatastructures_Sort_h

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Sort
{
private:
    int size;
    vector< int > data;

public:
    //Constructor which will also initialize your vector
    Sort(int arraySize)
    {
        size = ((arraySize > 0) ? arraySize : 0);
        int temp = size/2*3;
        if (size > 0) {
            for (int i=0; i<size; i++) {
                //data.push_back(temp--);
                data.push_back(rand()%900);
            }
        }
    }
    
    // Compare adjacent elements and swap them. O(n2)
    void bubble_sort()
    {
        int n = size;
        do
        {
            for (int j = 1; j < n; j++)
            {
                if (data[j-1] > data[j])
                {
                    swap(data[j-1], data[j]);
                }
            }
            n=n-1;
        }while (n!=0);

    }
    
    //select each elem(0..n) and put them into its position : O(n2)
    void selection_sort()
    {
        int n = size;
        int index;
        for (int i = 0; i < n-1; i++)
        {
            index = i;
            for (int j = i+1 ; j < n; j++)
            {
                if (data[j] < data[index])
                {
                    index = j;
                }
            }
            if(index != i)
            {
                swap(data[index], data[i]);
            }
        }
    }
    
    // insertion sort method O(n or n2)
    void inserttion_sort()
    {
        int n = size;
        for (int i = 1;i < n; i++)
        {
            int j = i;
            while(j > 0 && data[j-1] > data[j])
            {
                swap(data[j-1], data[j]);
                j--;
            }
        }
    }
    
    //swap method helper
    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    
    //merge_sort helper function
    void merge(int *a, int*b,int low, int pivot, int high)
    {
        int h,i,j,k;
        h=low;
        i=low;
        j=pivot+1;
        
        // This is to merge 2 arrays one startign with index=h and other index=pivot+1
        while((h<=pivot)&&(j<=high))
        {
            if(a[h]<=a[j])
            {
                b[i]=a[h];
                h++;
            }
            else
            {
                b[i]=a[j];
                j++;
            }
            i++;
        }
        // Append to right, left/right arrays to the final array
        if(h>pivot)
        {
            for(k=j; k<=high; k++)
            {
                b[i]=a[k];
                i++;
            }
        }
        else
        {
            for(k=h; k<=pivot; k++)
            {
                b[i]=a[k];
                i++;
            }
        }
        //copy back to a[]
        for(k=low; k<=high; k++)
            a[k]=b[k];
    }
    
    // merge_sort recursive function O(nlogn)
    void merge_sort(int *unsorted, int *sorted,int low, int high)
    {
        int pivot;
        if(low<high)
        {
            pivot= (low+high)/2;
            merge_sort(unsorted, sorted,low, pivot);
            merge_sort(unsorted,sorted,(pivot+1),high);
            merge(unsorted, sorted,low,pivot,high);
        }
        
    }
    
    // The quicksort partition function
    int partition(int* input, int l, int r)
    {
        int pivot = input[r];
        
        while ( l <= r )
        {
            while ( input[l] < pivot )
                l++;
            
            while ( input[r] > pivot )
                r--;
            
            if ( input[l] == input[r] )
                l++;
            else if ( l < r )
            {
                int tmp = input[l];
                input[l] = input[r];
                input[r] = tmp;
            }
        }
        
        return r;
    }
    // The quicksort recursive function
    void quicksort(int* input, int l, int r)
    {
        int j = partition(input, l, r);
        if ( l < i-1)
        {
            quicksort(input, l, j-1);
            quicksort(input, j+1, r);
        }
    }
    
    //Print the elements of the vector
    void displayElements() const
    {
        for (int i = 0;  i < size; i++) {
            cout << data[i] << " ";
        }
    }
};
#endif
