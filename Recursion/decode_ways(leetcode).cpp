#include<bits/stdc++.h>
using namespace std;


int numDecodings(string s) {
    
    int n=s.size();
    int arr[n+1];
    arr[0]=1;
    arr[1]=1;
    
    if(s[0]=='0')
        return 0;
    for(int i=2;i<=n;i++)
    {
        arr[i]=0;
        if(s[i-1]>'0')
        {
            arr[i]=arr[i-1];
        }
        
        if(s[i-2]=='1' or (s[i-2]=='2' and s[i-1]<'7'))
        {
            arr[i]+=arr[i-2];
        }
        
    }
    return arr[n];
}


int main()
{
    string s;
    getline(cin,s);
    cout<<numDecodings(s)<<endl;
}