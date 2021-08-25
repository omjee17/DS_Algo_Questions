#include<bits/stdc++.h>
using namespace std;


int maxSubArray(vector<int>& nums){
        
        int ans=INT_MIN;
        int sum=0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(sum<0)
            {
                sum=0;
            }
             sum+=nums[i];
            ans=max(ans,sum);
        }
    return ans;
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
    cout<<maxSubArray(nums)<<endl;

    return 0;
}
