#include<bits/stdc++.h>
using namespace std;

int sum(int n)
    {
        int ans=0;
        while(n>0)
        {
            int temp=n%10;
            ans+=temp;
            n=n/10;
        }
        return ans;
    }
    string smallestNumber(int S, int D){
       
       if(D==1 && S<=9)
       {
           return to_string(S);
       }
       for(int i=pow(10,D-1);i<pow(10,D);i++)
       {
           int s=sum(i);
           if(s==S)
           {
               string ans=to_string(i);
               return ans;
           }
       }
       
       return "-1";
}


int main()
{
    int s,d;
    cin>>s>>d;

    cout<<smallestNumber(s,d)<<endl;

    return 0;
}