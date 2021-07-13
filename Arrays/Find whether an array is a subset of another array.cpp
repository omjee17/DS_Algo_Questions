#include<bits/stdc++.h>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m) {
    sort(a1,a1+n);
    sort(a2,a2+m);
    
    int dp[n+1][m+1];
    
    
    
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if (i == 0 || j == 0) 
                dp[i][j] = 0;
            else if(a1[i-1]==a2[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    
   
    
    if(dp[n][m]==m)
        return "Yes";
    return "No";
    
}

int main()
{
    int n,m;
    cin>>n>>m;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int *arr1=new int[m];
    for(int i=0;i<m;i++)
    {
        cin>>arr1[i];
    }
    cout<<isSubset(arr,arr1,n,m)<<endl;

    delete[] arr;
    delete[] arr1;
} 