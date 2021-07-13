#include<bits/stdc++.h>
using namespace std;

// first approach
// make two string i.e 01010101... and 10101010... and compare with the given string 
// and return the minimum number of mismatch
int minFlips(string arr)
{
    int first=0,second=0;
    int n=arr.size();
    
    string s1,s2;
    s1[0]='1';
    s2[0]='0';
    for(int i=0;i<n;i++)
    {
        i%2==0?s1+='1':s1+='0';
        i%2==0?s2+='0':s2+='1';
    }
    for(int i=0;i<n;i++)
    {
        if(s1[i]!=arr[i])
        first++;
        if(s2[i]!=arr[i])
        second++;
    }
    return min(first,second);
}




// second approach
// without creating two new string
int minFlipssecond(string arr)
{
    int first=0,second=0;
    int n=arr.size();
    
    for(int i=0;i<n;i++)
    {
        if((i%2==0 && arr[i]=='0') || (i%2!=0 && arr[i]=='1'))
        {
            first++;
        }
        if((i%2==0 && arr[i]=='1')||(i%2!=0 && arr[i]=='0'))
        {
            second++;
        }
    }
    
    return min(first,second);
}



// main
int main(){
    string s;
    cin>>s;
    cout<<minFlips(s)<<endl;

    return 0;
}