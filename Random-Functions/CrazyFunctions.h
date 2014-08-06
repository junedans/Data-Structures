//
//  CrazyFunctions.h
//  Cppdatastructures
//
//  Created by Juned Ansari on 2/22/14.
//  Copyright (c) 2014 Juned. All rights reserved.
//

#ifndef Cppdatastructures_CrazyFunctions_h
#define Cppdatastructures_CrazyFunctions_h

#include <stdio.h>
#include <string>
#include <iostream>
#include <math.h>
#include <map>
using namespace std;
#include <iomanip>

//Write a program (WAP) to print christmas tree with height n
void printChristmas(int n)
{
    if(n<=0)
    {
        cout<<"Error: Tree Height<=0\n";
        return;
    }
    
    for (int i=0; i<n; i++) {
        cout << setfill(' ') << setw(n-i) << "*" << setfill('*') << setw(2*i+1) << " " <<  endl;
    }
    cout << setfill(' ')  << setw(n) << "I" << endl;
}

// Get Reverse helper functions
int _getRev(int num){
    
    int rev=0,r;
    
    while(num!=0){
        r= num%10;
        rev= rev*10+r;
        num = num/10;
    }
    return rev;
}

//WAP to count integer palindromes upto n
int countPalindromesUptoN(int n)
{
    if(n <=0)
        return false;
    int count=0;
    for (int i=1; i<=n; i++) {
        if(i == _getRev(i)) {
            //cout  << i <<" ";
            count++;
        }
    }
    
    return count;
}

// Print all the Prime Numbers upto n, T:O(n2)
void PrimeToN(int n)
{
    bool isPrime;
    for(int i=2; i<=n; i++)
    {
        isPrime=true;
        for (int j=2; j<i; j++) {
            if(i%j==0)
            {
                isPrime =false;
                break;
            }
        }
        if(isPrime)
            cout << i << ' ';
    }
}

// WAP to implement pow(a,b) without using pow
double power(const double &a,const int &b)
{
    /*
    int pow=a;
    for(int i=1; i<b; i++)
    {
        pow *=a;
    }
    return pow;
     */
    
    // y = exp(b*ln(a)) is the log way to calculate
    double result;
    result = exp(b*log(a));
    
    return result;
}

// WAP to implement my own atoi
int myAtoi(string str)
{
    if (str == " ")
        return 0;
    bool isNeg = false;
    int i=0;
    if(str[i]=='-')
    {
        isNeg=true;
        i++;
    }
    int res=0;
    
    for(; str[i]!='\0';i++)
    {
        res = res*10 + (str[i] - '0');
    }
    if (isNeg) {
        return -res;
    }
    return res;
}

// WAP to implement my own itoa
string myItoa(int num)
{
    bool isNeg=false;
    int i=0;
    string str;
    if(num==0)
    {
        str[i++]='0';
        str[i]='\0';
        return  str;
    }
    
    if(num<0)
    {
        isNeg=true;
        num=-num;
            str[i++] = '-';
    }

    while (num!=0) {
        int rem = num%10;
        str[i++]=rem+'0';
        num=num/10;
    }
    
    str[i]='\0';
    
    //reverse(str,i);     // implement reverse(), too bored will implement later
    
    return str;           // return the reversed string
    
}

/*
 Validate a given IP is valid or not. 0-255.0-255.0-255.0-255 IPv4 32 bit
 */
#define DELIM "."
bool _validate_digits(char *input_str)
{
    while(*input_str)
    {
        if(*input_str >= '0' && *input_str <= '9')
            ++input_str;
        else
            return false;
    }
    return true;
}

// Validate input IP string
bool validating_IP(char *input_str)
{
    if(input_str == NULL)
        return false;
    
    int num, dots=0;
    char *ptr;
    
    ptr = strtok(input_str, DELIM);
    if(ptr == NULL)
        return false;
    
    while(ptr)
    {
        if(!_validate_digits(ptr))
            return false;
        
        num = atoi(ptr);
        
        if(num >= 0 && num <=255)
        {
            ptr = strtok(NULL, DELIM);
            if(ptr != NULL)
                ++dots;
        }
        else
            return false;
    }
    /* valid IP string must contain 3 dots */
    if (dots != 3)
        return false;
    
    return true;
}

/* Check for substring */
bool isSubstring(string str1, string str2)
{
    if (str1.length() <=0 or str2.length() <=0)
        return true;
    
    int i=0, j=0;
    while(i<str1.length() && j<str2.length())
    {
        if (str1[i]==str2[j]) {
            while (str1[i+j]==str2[j] && j<str2.length() && (i+j)<str1.length()) {
                j++;
            }
            if((j=(int)str2.length()))
                return true;
        }
        i=i+j;
        j=0;
    }
    return false;
}

// abcd
// aabbccde
// aaaa
string Compress(string str)
{
    if(str.length() < 1)
        return NULL;
	string newstr = "";
	int cnt = 1;
	char prev = str[0];
    
	for (int i = 1; i <= str.length() - 1; i++)
	{
		if (prev == str[i])
		{
			cnt++;
		}
		else
		{
			newstr.append(1, prev);
			newstr.append(to_string(cnt));
			cnt = 1;
		}
		prev = str[i];
	}
	newstr.append(1, prev);
	newstr.append(to_string(cnt));
	return newstr;
}

/**
 * Given a nested list of integers, returns the sum of all integers in the list weighted by their depth
 * For example, given the list {{1,1},2,{1,1}} the function should return 10 (four 1's at depth 2, one 2 at depth 1)
 * Given the list {1,{4,{6}}} the function should return 27 (one 1 at depth 1, one 4 at depth 2, one 6 at depth2)
 */
int NestedListSum(string list)
{
    // Implement a stack that would store measure the depth based and store the brackets
    // For each height compute the temporary sum and On change of brackets update
    // the main sum with temp_sum*depth
    
    // For the case where we have numbers spread out we can do one depth at a time method
    // Eg: {1, {2,3},{4.5},5}
    
    if(list.length() < 2 || list[0] != '{')
        return -1;
    
    int size = 0;
    int total_sum=0;

    map<int,int> mymap;
    int depth=0;
    
    
    while(size < list.length())
    {
        if(list[size] == '{')
        {
            depth++;
            size++;
        }
        else if(list[size] == ',')
            size++;
        else if(isdigit(list[size]))
        {
            if(mymap.count(depth))
                mymap.find(depth)->second += atoi(&list[size]);
            else
                mymap[depth] = atoi(&list[size]);
            size++;
        }
        else if(list[size] == '}')
        {
            depth--;
            if(depth<0)
                return -1;
            size++;
        }
    }
    
    map<int,int>::iterator it;
    for (it=mymap.begin(); it!=mymap.end(); ++it)
        total_sum +=it->first*it->second;
    
    return total_sum;
}



#endif













