//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

vector<long long int> productExceptSelf(vector<long long int>&, int );

// your code will be pasted here

int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        
        vec = productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}// } Driver Code Ends


//User function template for C++

// nums: given vector
// return the Product vector P that hold product except self at each index
vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
   
    vector<long long int>ans;
    
    long long int sum=1;
    
    if(nums.size()==2)
    {
        ans.push_back(nums[1]);
        ans.push_back(nums[0]);
        return ans;
    }
    bool flag=false;
    int count=0;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]==0)
        {
            count++;
            flag=1;
        }
        sum*=nums[i];
    }
    if(count>1)
    {
        for(int i=0;i<nums.size();i++)
        ans.push_back(0);
    }
    if(flag==true)
    {
        sum=1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
            sum*=nums[i];
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            ans.push_back(sum);
            else
            ans.push_back(0);
        }
    }
    else
    {
        for(int i=0;i<nums.size();i++)
        {
                long long int a=(sum/nums[i]);
                ans.push_back(a);

        }
    }
    return ans;
}
