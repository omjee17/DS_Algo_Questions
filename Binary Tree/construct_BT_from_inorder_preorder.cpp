#include<bits/stdc++.h>
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


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 
class Solution{
    public:
    int preIndex=0;
    Node* helper(int in[],int pre[],int start,int end)
    {
        if(start>end)
        {
            return NULL;
        }
        
        int a=pre[preIndex++];
        
        Node*root=new Node(a);
        if(start==end)
        return root;
        
        int mid;
        for(int i=start;i<=end;i++)
        {
            if(in[i]==a)
            {
                mid=i;
                break;
            }
        }
        root->left=helper(in,pre,start,mid-1);
        root->right=helper(in,pre,mid+1,end);
        return root;
        
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        return helper(in,pre,0,n-1);
    }
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
