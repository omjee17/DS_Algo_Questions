#include<bits/stdc++.h>
using namespace std;

vector<int> nextPermutation(int n, vector<int> arr)
{   
        int i=n-2,j=n-1;
        
        while(i>=0)
        {
            if(arr[i]<arr[i+1])
            {
                break;
            }
            i--;
        }
        while(j>i)
        {
            if(arr[j]>arr[i])
            {
                break;
            }
            j--;
        }
        if(i==-1)
        {
            sort(arr.begin(),arr.end());
            return arr;
        }
        swap(arr[i],arr[j]);
        reverse(arr.begin()+i+1,arr.end());
        return arr;
}

int main()
{
    int n;
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        arr.push_back(a);
    }

    vector<int>ans=nextPermutation(n,arr);

    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
}