#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

int largestBst(Node *root);

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}



int main() {
  
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root1 = buildTree(s);

       //getline(cin, s);
      // int k = stoi(s);
       // getline(cin, s);

       cout << largestBst(root1);
        cout << endl;
       //cout<<"~"<<endl;
   }
   return 0;
}



class S{
    public:
    int maximum;
    int minimum;
    bool isBST;
    int size;
    
    S()
    {
        maximum=INT_MIN;
        minimum=INT_MAX;
        isBST=false;
        size=0;
    }
};

S helper(Node*root,int &res)
{
    if(root==NULL)
    {
        S ans;
        ans.isBST=true;
        return ans;
    }
    
    
    S left=helper(root->left,res);
    S right=helper(root->right,res);
    if(right.isBST && left.isBST && left.maximum<root->data && right.minimum>root->data)
    {
        S ans;
        ans.minimum=min(root->data,min(right.minimum,left.minimum));
        ans.maximum=max(root->data,max(right.maximum,left.maximum));
        ans.isBST=true;
        ans.size=left.size+right.size+1;
        res=max(res,ans.size);
        return ans;
    }
    else
    {
        S ans;
        ans.size=max(left.size,right.size);
        ans.isBST=false;
        res=max(left.size,right.size);
        return ans;
    }

}

int largestBst(Node *root)
{
    int res=0;
    S ans=helper(root,res);
    return res;
}