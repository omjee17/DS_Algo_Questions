#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
   
    vector<vector<int>>ans;
    
    void helper(vector<int>&arr,int i,int sum,vector<int>&v)
    {
        if(sum<0)
        return;
        if(arr.size()==i)
        {
            if(sum==0)
            {
                
                ans.push_back(v);
            }
            return;
        }
        if(sum==0)
        {
            ans.push_back(v);
            return;
        }
        
        v.push_back(arr[i]);
        helper(arr,i,sum-arr[i],v);
        v.pop_back();
        helper(arr,i+1,sum,v);
    }
    
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        
        vector<int>v;
        set<int>s;
        
        for(int i=0;i<A.size();i++)
        s.insert(A[i]);
        
        vector<int>a;
        for(auto i:s)
        {
            a.push_back(i);
        }
        sort(a.begin(),a.end());
        helper(a,0,B,v);
        return ans;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	