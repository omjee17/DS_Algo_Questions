#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;
 
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

vector <int> zigZagTraversal(Node* root)
{
    vector<int>ans;
    
    stack<Node*>s1;
    stack<Node*>s2;
    
    s1.push(root);
    
    while(!s1.empty())
    {
        Node*a=s1.top();
        while(!s1.empty())
        {
            ans.push_back(a->data);
            if(a->left)
            s2.push(a->left);
            if(a->right)
            s2.push(a->right);
            
            s1.pop();
            if(!s1.empty())
            a=s1.top();
        }
        
        
        if(!s2.empty())
        {
            Node*a1=s2.top();
            while(!s2.empty())
            {
                ans.push_back(a1->data);
                if(a1->right)
                s1.push(a1->right);
                if(a1->left)
                s1.push(a1->left);
                
                s2.pop();
                if(!s2.empty())
                {
                    a1=s2.top();
                }
                
            }
            
        }
        
    }
    return ans;
   
}


int main()
{
    // Build tree and then call zigZagTraversal function
    return 0;
}