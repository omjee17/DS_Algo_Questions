#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
   string removeConsecutiveCharacter(string s)
    {
        if(s.size()==1)
        {
            return s;
        }
        string snew;
        snew.push_back(s[0]);
        int k=1;
        for(int i=1;i<s.size();i++)
        {
            if(snew[k-1]!=s[i])
            {
               snew.push_back(s[i]);
               k++;
            }
            else
                continue;
        }
        
        return snew;
    }
};

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.removeConsecutiveCharacter(s)<<endl;
    }
} 
