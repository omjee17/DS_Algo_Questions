#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}

int countPairs(Node* root1, Node* root2, int x);


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node* root1 = NULL;
        Node* root2 = NULL;
        int n1, n2, k;
        cin>>n1;
        for(int i=0; i<n1; i++)
        {
            cin>>k;
            insert(&root1, k);
        }
        cin>>n2;
        for(int i=0; i<n2; i++)
        {
            cin>>k;
            insert(&root2, k);
        }
        int s;
        cin>>s;
        cout<<countPairs(root1, root2, s)<<"\n";
    }
    return 0;
}


void traverse(Node*root,map<int,bool>&m)
{
    if(root==NULL)
    return;
    
    m[root->data]=true;
    traverse(root->left,m);
    traverse(root->right,m);
    
}

// Method:1 O(n) Time O(n) Space
int countPairs(Node* root1, Node* root2, int x)
{
    map<int,bool>m1;
    map<int,bool>m2;
    
    traverse(root1,m1);
    traverse(root2,m2);
    
    int cnt=0;
    for(auto i:m1)
    {
        if(m2[x-i.first]==true && x-i.first>0 && i.first>0 && x>0)
        {
            cnt++;
        }
    }
    for(auto i:m2)
    {
        if(m1[x-i.first]==true && x-i.first>0 && i.first>0 && x>0)
        {
            cnt++;
        }
    }
    return cnt;
}
