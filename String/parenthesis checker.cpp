#include<bits/stdc++.h>
using namespace std;


bool isbalanced(string s)
    {
        if(s.size()&1)
        {
            return false;
        }
        else
        {
            stack<char>st;
            int n=s.size();
            for(int i=0;i<n;i++)
            {
                if(s[i]=='{' || s[i]=='[' || s[i]=='(')
                {
                    st.push(s[i]);
                }
                else
                {
                    if(st.empty())
                    {
                        return false;
                    }
                    
                    else if(s[i]=='}' && st.top()!='{')
                    {
                        return false;
                    }
                    else if(s[i]==']' && st.top()!='[')
                    {
                        return false;
                    }
                    else if(s[i]==')' && st.top()!='(')
                    {
                        return false;
                    }
                    else
                    {
                        st.pop();
                    }
                }
            }
            return true;
        }
        
        
        return true;
    }

int main()
{
    string s;
    cin>>s;
    isbalanced(s)==1?cout<<"balanced":cout<<"Not balanced";
    return 0;
}