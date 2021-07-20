#include <bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    long long minCost(long long arr[], long long n) {
        priority_queue<long long,vector<long long>,greater<long long>>q;
        for(int i=0;i<n;i++)
        {
            q.push(arr[i]);
        }
        long long ans=0;
        while(q.size()>=2)
        {
            long long first=q.top();
            q.pop();
            long long second=q.top();
            q.pop();
            
            q.push(first+second);
            ans+=(first+second);
        }
        return ans;
    }
};

long long minCost(long long arr[], long long n);
int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}
