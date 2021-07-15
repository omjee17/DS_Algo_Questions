#include<bits/stdc++.h>
using namespace std;

vector<string>ans;
void permute(string s,int l,int r)
{
    if(l==r)
    {
        ans.push_back(s);
        return;
    }

    for(int i=l;i<=r;i++)
    {
        swap(s[l],s[i]);
        permute(s,l+1,r);
        swap(s[l],s[i]);
    }

}

int main(){
    string s;
    cin>>s;

    permute(s,0,s.size()-1);

    for(auto i:ans)
    {
        cout<<i<<" ";
    }

    return 0;
}