#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    
    static bool cmp(int a,int b)
    {
        return __builtin_popcount(a)>__builtin_popcount(b); //inbuilt function to calculate the set bits in a number
        
    }
    
    void sortBySetBitCount(int *arr, int n)
    {
       stable_sort(arr,arr+n,cmp);
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}