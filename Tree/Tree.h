//
//  File: Tree.h
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
//  Tree.h - This is the header file for templatised class Tree      //
//                                                                   //
//  Created by Juned Ansari on 1/25/14.                              //
//  Site: www.junedansari.com                                        //
//  Phone: 315-396-4987                                              //
//                                                                   //
//  Version: v1.0                                                    //
//  Copyright (c) 2014 Juned. All rights reserved.                   //
///////////////////////////////////////////////////////////////////////

#ifndef Cppdatastructures_Tree_h
#define Cppdatastructures_Tree_h

#include<iostream>
#include<stack>
#include "TreeNode.h"
using namespace std;

template <typename NODETYPE>
class Tree {
    
public:
    Tree();                                     // Constructor
    void insertNode(const NODETYPE &);          // Insert a node in the tree
    void preOrderTraversal() const;             // Pre-Order traversal of the tree
    void preOrderMy();                          // Custom pre-order traversal of the Tree to print in the form:(5 (3(1)(4)) (7))
    void inOrderTraversal() const;              // In-order traversal of the tree
    void postOrderTraversal() const;            // Post-order traversal of the tree
    bool isBalanced();                          // To find if the tree is balanced or not
    bool findNode(const NODETYPE &) const;      // To search for a particular node in the tree
    bool bfs(const NODETYPE&) const;            // Bread-first-search pseudo implementation
    // bfs
    
private:
    TreeNode<NODETYPE> *root;
    
    void insertNodeHelper( TreeNode< NODETYPE > **, const NODETYPE &);          //Insert a node utility helper function
    void preOrderHelper( TreeNode< NODETYPE > *) const;                         //Pre-Order traversal utility helper function
    void iterativePreOrderHelper( TreeNode<NODETYPE> *) const;                  //Pre-Order iterative traversal utility helper function
    void preOrderMyHelper(TreeNode<NODETYPE> *ptr);                             //Pre-OrderMy utility helper function for preOrderMy()
    void inOrderHelper( TreeNode< NODETYPE > *) const;                          //In-order traversal utility helper function
    void iterativeInOrderHelper( TreeNode<NODETYPE> *) const;                   //In-order iterative traversal utility helper function
    void postOrderHelper( TreeNode< NODETYPE > *) const;                        //Post-order traversal utility helper function
    void iterativePostOrderHelper( TreeNode<NODETYPE> *) const;                 //Post-order iterative traversal utility helper function
    int checkHeight(TreeNode<NODETYPE> *);                                      //Check for height of the node
    NODETYPE findNodeHelper(TreeNode<NODETYPE> *, const NODETYPE &) const;      //Find a node using the helper function
    bool bfs(TreeNode<NODETYPE> *, const NODETYPE &) const;                     //Bread-first-search helper function
};

// Constructor
template <typename NODETYPE>
Tree< NODETYPE > :: Tree()
{
    root = 0;
}

// Insert a node in the tree
template <typename NODETYPE>
void Tree< NODETYPE >::insertNode(const NODETYPE &value) {
    insertNodeHelper(&root, value);
}

//Insert a node utility helper function
template <typename NODETYPE>
void Tree< NODETYPE >::insertNodeHelper(TreeNode< NODETYPE > **ptr, const NODETYPE &value)
{
    if(*ptr == 0)
        *ptr = new TreeNode<NODETYPE>(value);
    else
    {
        if (value < (*ptr)->data)
            insertNodeHelper( &((*ptr)->leftPtr), value);
        else
        {
            if (value > (*ptr)->data)
                insertNodeHelper(&((*ptr)->rightPtr), value);
            else
                cout << value << " Duplicate\n" << endl;
        }
    }
}

// Pre-Order traversal of the tree
template <typename NODETYPE>
void Tree< NODETYPE > ::preOrderTraversal() const {
    //preOrderHelper(root);
    iterativePreOrderHelper(root);
}

//Pre-Order traversal utility helper function
template <typename NODETYPE>
void Tree< NODETYPE >:: preOrderHelper( TreeNode< NODETYPE > *ptr) const
{
    if (ptr != 0)
    {
        cout << ptr->data << ' ';
        preOrderHelper( ptr->leftPtr);
        preOrderHelper( ptr->rightPtr);
    }
}

//Pre-Order iterative traversal utility helper function
template <typename NODETYPE>
void Tree<NODETYPE>::iterativePreOrderHelper( TreeNode<NODETYPE> *ptr) const
{
    if (ptr==0)
        return;
    stack<TreeNode<NODETYPE>* > tempStack;
    tempStack.push(ptr);
    while (!tempStack.empty())
    {
        TreeNode<NODETYPE> * curr = tempStack.top();
        cout << curr->data << ' ';
        tempStack.pop();
        
        if(curr->rightPtr !=0)
            tempStack.push(curr->rightPtr);
        if(curr->leftPtr !=0)
            tempStack.push(curr->leftPtr);
    }
    return;
}

// In-order traversal of the tree
template <typename NODETYPE>
void Tree< NODETYPE > :: inOrderTraversal() const {
    //inOrderHelper(root);
    iterativeInOrderHelper(root);
}

//In-order traversal utility helper function
template <typename NODETYPE>
void Tree< NODETYPE >::inOrderHelper(TreeNode< NODETYPE > *ptr) const
{
    if (ptr != 0 )
    {
        inOrderHelper(ptr->leftPtr);
        cout << ptr->data << ' ';
        inOrderHelper(ptr->rightPtr);
    }
}

//In-order iterative traversal utility helper function
template <typename NODETYPE>
void Tree<NODETYPE>::iterativeInOrderHelper( TreeNode<NODETYPE> *ptr) const
{
    stack< TreeNode<NODETYPE>* > tempStack;
    while (!tempStack.empty() || ptr)
    {
        if(ptr ==0 )
        {
            ptr = tempStack.top();
            cout    << ptr->data << ' ';
            ptr = ptr->rightPtr;
            tempStack.pop();
        }
        if(ptr != 0)
        {
            tempStack.push(ptr);
            ptr = ptr->leftPtr;
        }
    }
    return;
}

// Post-order traversal of the tree
template <typename NODETYPE>
void Tree< NODETYPE >::postOrderTraversal() const{
    //postOrderHelper(root);
    iterativePostOrderHelper(root);
}

//Post-order traversal utility helper function
template <typename NODETYPE>
void Tree< NODETYPE > ::postOrderHelper(TreeNode< NODETYPE > *ptr) const
{
    if (ptr != 0)
    {
        postOrderHelper(ptr->leftPtr);
        postOrderHelper(ptr->rightPtr);
        cout << ptr->data << ' ';
    }
}

//Post-order iterative traversal utility helper function
template <typename NODETYPE>
void Tree<NODETYPE>::iterativePostOrderHelper( TreeNode<NODETYPE> *ptr) const{
    if(ptr == 0)
        return;
    stack<TreeNode<NODETYPE>* > s1;
    stack<TreeNode<NODETYPE>* > s2;
    s1.push(ptr);
    while (!s1.empty()) {
        TreeNode<NODETYPE>* curr = s1.top();
        s2.push(curr);
        s1.pop();
        
        if(curr->leftPtr != 0)
            s1.push(curr->leftPtr);
        if(curr->rightPtr != 0)
            s1.push(curr->rightPtr);
    }
    
    while (!s2.empty()) {
        TreeNode<NODETYPE> *temp = s2.top();
        s2.pop();
        cout << temp->data <<' ';
    }
    return;
}

//Check for height of the node
template <typename NODETYPE>
int Tree<NODETYPE>::checkHeight(TreeNode<NODETYPE> *ptr) {
    if (ptr == 0)
        return 0;
    
    int leftHeight = checkHeight(ptr->leftPtr);
    if(leftHeight == -1)
        return -1;
    
    int rightHeight = checkHeight(ptr->rightPtr);
    if(rightHeight == -1)
        return -1;
    
    int heightDiff = leftHeight - rightHeight;
    if(abs(heightDiff) > 1)
        return -1;
    else
        return (max(leftHeight, rightHeight) + 1);
}

// To find if the tree is balanced or not
template <typename NODETYPE>
bool Tree< NODETYPE >::isBalanced() {
    if(checkHeight(root) == -1)
    {
        return false;
    }
    else
        return true;
}

//Find a node using the helper function
template <typename NODETYPE>
bool Tree<NODETYPE>::findNode(const NODETYPE &value) const
{
    if(findNodeHelper(root, value) == value)
        return true;
    else
        return false;
}

//Find a node using the helper function
template <typename NODETYPE>
NODETYPE Tree<NODETYPE>::findNodeHelper(TreeNode<NODETYPE> *ptr, const NODETYPE & value) const{
    if(ptr == 0)
        return 0;
    NODETYPE currval = ptr->data;
    if(currval == value)
        return currval;
    if (value > currval)
        return findNodeHelper(ptr->rightPtr, value);
    else
        return findNodeHelper(ptr->leftPtr, value);
}

//Bread-first-search helper function
template <typename NODETYPE>
bool Tree<NODETYPE>::bfs(const NODETYPE & searchValue) const{
    bfs(root, searchValue);
}

/*template <typename NODETYPE>
 bool Tree<NODETYPE>::bfs(TreeNode<NODETYPE> *ptr, const NODETYPE & searchValue) const {
 if (node == NULL) return false;
 
 queue<BST<T>*> q;
 q.push(node);
 
 while (!q.empty())
 {
 BST<T>* tmp = q.front();
 q.pop();
 
 if (tmp->mData == searchKey)
 return true;
 else
 {
 if(tmp->mLeft != NULL)
 q.push(tmp->mLeft);
 if(tmp->mRight != NULL)
 q.push(tmp->mRight);
 }
 }
 return false;
 }*/

// Custom pre-order traversal of the Tree to print in the form:(5 (3(1)(4)) (7))
template <typename NODETYPE>
void Tree<NODETYPE>::preOrderMy()
{
    preOrderMyHelper(root);
}

//Pre-Order traversal utility helper function
template <typename NODETYPE>
void Tree<NODETYPE>::preOrderMyHelper(TreeNode<NODETYPE> *ptr)
{
	if(ptr!=0)
	{
		cout << '(' << ptr->data;
		//string.append(“(”);
        //string.append((string)ptr->data);
        preOrderMyHelper(ptr->leftPtr);
        preOrderMyHelper(ptr->rightPtr);
        cout << ')';
        //string.append(“ )”);
    }
}


#endif









