#include<bits/stdc++.h>
using namespace std;



int countSubstring(string s)
{
    int ans=0;
    int n=s.size();
    int zero=0,one=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='0')
        zero++;
        else 
        one++;
        if(zero==one)
        ans++;
    }

    return ans;
}


int main()
{
    string s;
    cin>>s;
    cout<<countSubstring(s)<<endl;

    return 0;
}