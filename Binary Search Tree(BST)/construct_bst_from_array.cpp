#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

TreeNode* helper(vector<int>nums,int s,int e)
{
        if(s>e)
            return NULL;

        int mid=(s+e)/2;
        TreeNode*root=new TreeNode(nums[mid]);
        root->left=helper(nums,s,mid-1);
        root->right=helper(nums,mid+1,e);
        
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int s=0,e=nums.size()-1;
        
        TreeNode*root=helper(nums,s,e);
        return root;
}

int main()
{
    int n;
    cin>>n;
    vector<int>nums;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        nums.push_back(a);
    }

    TreeNode*root=sortedArrayToBST(nums);

    return 0;
}