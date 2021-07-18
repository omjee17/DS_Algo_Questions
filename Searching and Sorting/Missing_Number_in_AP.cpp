#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int inSequence(int A, int B, int C){
        
        int ans=B-A;
        if(ans==0)
        return 1;
        else if(ans<0 && C<0 && ans%C==0)
        return 1;
        else if(ans>0 && C>0 && ans%C==0)
        return 1;
        else 
        return 0;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int A, B, C;
        cin>>A>>B>>C;
        
        Solution ob;
        cout<<ob.inSequence(A, B, C)<<endl;
    }
    return 0;
} 