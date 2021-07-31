#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

int countRev (string s)
{
   if(s.size()&1)
   {
       return -1;
   }
   
   stack<char>st;
   int n=s.size();
   for(int i=0;i<n;i++)
   {
       if(s[i]=='}' && st.empty())
       {
           st.push(s[i]);
       }
       else if(s[i]=='{')
       {
           st.push(s[i]);
       }
       else if(s[i]=='}' && !st.empty())
       {
           if(st.top()=='{')
           st.pop();
           else
           st.push(s[i]);
       }
   }
   int op=0,cl=0;
   while(!st.empty())
   {
       char a=st.top();
       if(a=='}')
       cl++;
       else
       op++;
       st.pop();
   }
   
   return ceil(ceil(op)/ceil(2))+ceil(ceil(cl)/ceil(2));
}