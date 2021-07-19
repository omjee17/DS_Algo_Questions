#include <bits/stdc++.h>
using namespace std;

bool ifPossible(string s)
{
    map<char,int>m;
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        m[s[i]]++;
    }
    
    for(auto i:m)
    {
        if(i.second>n/2)
        {
            return false;
        }
    }
    return true;
}


int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    
	    cout<<ifPossible(s)<<endl;
	}
	return 0;
}