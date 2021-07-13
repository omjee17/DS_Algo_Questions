#include<bits/stdc++.h>
using namespace std;

bool hasAlternatingBits(int n) {
        if(n==0)
            return true;
        
        int prev=n&1;
        n=n>>1;
        while(n>0)
        {
            int x=n&1;
            if(prev==x)
            {
                return false;
            }
            
            prev=x;
            n=n>>1;
        }
        return true;
    }

int main()
{
    int n;
    cin>>n;
    cout<<hasAlternatingBits(n)<<endl;
}