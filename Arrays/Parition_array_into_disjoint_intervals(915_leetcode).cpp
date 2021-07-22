#include<bits/stdc++.h>
using namespace std;

// return minimum size of left array such that 
// left and right are two non-empty subarray
// in which every element in left is less than or equal to element in right

int partitionDisjoint(vector<int>& nums) 
{
        int maxInLeft=nums[0],maxOverall=nums[0];
        int paritionIndex=0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<maxInLeft)
            {
                paritionIndex=i;
                maxInLeft=maxOverall;
            }
            
            maxOverall=max(nums[i],maxOverall);
        }
    return paritionIndex+1;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    cout<<partitionDisjoint(v)<<endl;
    return 0;
}