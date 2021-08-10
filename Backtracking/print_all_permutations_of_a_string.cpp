#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	    vector<string>ans;
	    
	    void helper(string s,int l,int r)
	    {
	        if(l==r)
	        {
	            ans.push_back(s);
	            return;
	        }
	        
	        for(int i=l;i<=r;i++)
	        {
	            swap(s[l],s[i]);
	            helper(s,l+1,r);
	            swap(s[l],s[i]);
	        }
	    }
	    
		vector<string>find_permutation(string S)
		{
		    helper(S,0,S.size()-1);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};

int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}