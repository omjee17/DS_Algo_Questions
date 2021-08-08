#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool isPowerofTwo(long long n){
        
        if(n==0)
        return 0;
        return (n&(n-1))==0;
        
    }
};

int main()
{

    int t;
    cin>>t;

    for(int i=0;i<t;i++)
    {
        long long n; 
        cin>>n;

        Solution ob;
         if(ob.isPowerofTwo(n))//Now, if log2 produces an integer not decimal then we are sure raising 2 to this value
             cout<<"YES"<<endl;
         else
            cout<<"NO"<<endl;

    }

    return 0;
}