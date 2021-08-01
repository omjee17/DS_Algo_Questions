#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string longestPalin (string S) {
        
        int n=S.size();
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        
        string ans = "";
        ans += S[0];
        
        for (int i = 0; i < n; i++)
            dp[i][i] = true;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                if(S[i]==S[j])
                {
                    if(j-i==1 || dp[i+1][j-1])
                    {
                        dp[i][j]=true;
                        
                        if (ans.size() < j - i + 1)
                            ans = S.substr(i, j - i + 1);
                    }
                }
            }
        }
       
        return ans;
        
    }
};


int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
