//
//  Graph.h
//  Cppdatastructures
//
//  Created by Juned Ansari on 4/6/14.
//  Copyright (c) 2014 Juned. All rights reserved.
//

#ifdef Cppdatastructures_Graph_h
#define Cppdatastructures_Graph_h
/*
void Graph::BFS(int s)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
    
    // Create a queue for BFS
    list<int> queue;
    
    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);
    
    // 'i' will be used to get all adjacent vertices of a vertex
    list<int>::iterator i;
    
    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop_front();
        
        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it
        for(i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}
 
// use level for traversing shorted distance or anything
// use parent to go back to s->starting node

void Graph::BFS(s, Adj)
{
    level = {s, 0};
    parent = {s, null};
    int i=1;
    queue<node> frontier.push(s);
    
    while(!frontier.isEmpty())
    {
        for(u in frontier)
        {
            for(v:Adj[u]) or for(u:v.neighbors())
            {
                if( !level.isPresent(v))
                {
                    level[v] = i;
                    parent[v]= u;
                    frontier.push(v);
                }
            }
            i++;
        }
    }
}
 

 // Recursive function to print all the nodes at distance k in the
 // tree (or subtree) rooted with given root. See
void printkdistanceNodeDown(node *root, int k)
{
    // Base Case
    if (root == NULL || k < 0)  return;
    
    // If we reach a k distant node, print it
    if (k==0)
    {
        cout << root->data << endl;
        return;
    }
    
    // Recur for left and right subtrees
    printkdistanceNodeDown(root->left, k-1);
    printkdistanceNodeDown(root->right, k-1);
}

 
 
 
// Prints all nodes at distance k from a given target node.
// The k distant nodes may be upward or downward.  This function
// Returns distance of root from target node, it returns -1 if target
// node is not present in tree rooted with root.
int printkdistanceNode(node* root, node* target , int k)
{
    // Base Case 1: If tree is empty, return -1
    if (root == NULL) return -1;
    
    // If target is same as root.  Use the downward function
    // to print all nodes at distance k in subtree rooted with
    // target or root
    if (root == target)
    {
        printkdistanceNodeDown(root, k);
        return 0;
    }
    
    // Recur for left subtree
    int dl = printkdistanceNode(root->left, target, k);
    
    // Check if target node was found in left subtree
    if (dl != -1)
    {
        // If root is at distance k from target, print root
        // Note that dl is Distance of root's left child from target
        if (dl + 1 == k)
            cout << root->data << endl;
        
        // Else go to right subtree and print all k-dl-2 distant nodes
        // Note that the right child is 2 edges away from left child
        else
            printkdistanceNodeDown(root->right, k-dl-2);
        
        // Add 1 to the distance and return value for parent calls
        return 1 + dl;
    }
    
    // MIRROR OF ABOVE CODE FOR RIGHT SUBTREE
    // Note that we reach here only when node was not found in left subtree
    int dr = printkdistanceNode(root->right, target, k);
    if (dr != -1)
    {
        if (dr + 1 == k)
            cout << root->data << endl;
        else
            printkdistanceNodeDown(root->left, k-dr-2);
        return 1 + dr;
    }
    
    // If target was neither present in left nor in right subtree
    return -1;
}
 
 
*/
#endif
