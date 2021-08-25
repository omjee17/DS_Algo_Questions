#include<bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    Node *left, *right;
};
 

void diagonalView(Node*root,map<int,vector<int>>&m,int d)
{
    if(root==NULL)
    {
        return;
    }

    m[d].push_back(root->data);

    diagonalView(root->right,m,d);
    diagonalView(root->left,m,d+1);
}


void diagonalPrint(Node* root)
{
     
    // create a map of vectors
    // to store Diagonal elements
    map<int,vector<int>> diagonalPrint;
    diagonalView(root,diagonalPrint,0);
 
    cout << "Diagonal Traversal of binary tree : \n";
    for (auto it :diagonalPrint)
    {
        vector<int> v=it.second;
        for(auto it:v)
          cout<<it<<" ";
        cout<<endl;
    }
}
 
// Utility method to create a new node
Node* newNode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
 
// Driver program
int main()
{
    Node* root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);
 
    /*  Node* root = newNode(1);
        root->left = newNode(2);
        root->right = newNode(3);
        root->left->left = newNode(9);
        root->left->right = newNode(6);
        root->right->left = newNode(4);
        root->right->right = newNode(5);
        root->right->left->right = newNode(7);
        root->right->left->left = newNode(12);
        root->left->right->left = newNode(11);
        root->left->left->right = newNode(10);*/
 
    diagonalPrint(root);
 
    return 0;
}