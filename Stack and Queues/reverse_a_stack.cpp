#include<bits/stdc++.h>
using namespace std;


void reverseStack(stack<int>&s)
{
    if(s.size()==0 || s.size()==1)
    {
        return;
    }
    int top=s.top();
    s.pop();
    reverseStack(s);
    s.push(top);
}

int main()
{
    int n;
    cin>>n;
    stack<int> st;
    while (n--){
        int x;
        cin>>x;
        st.push(x);
    }
    reverseStack(st);

    while(!st.empty()){
        int top = st.top();
        st.pop();
        cout<<top<<endl;
    }
    return 0;
}