#include<bits/stdc++.h>
using namespace std;


string nearestPalindromic(string n) {
        long long val=stoll(n);
        if(val<=10)
        {
            string s=to_string(val-1);
            return s;
                
        }
        else
        {
            int s=n.size();
            vector<long long>v;
            v.push_back(pow(10,s-1)-1); //case:where palindrome has one less digit
            v.push_back(pow(10,s)+1);   //case:where palindrome hsa one more digit
            
            //case where same number number of digits are there
            //ex :123
            // we will create 3 palindrome left half(121),lefthalf+1(131),lefthalf-1(111)
            //same goes with odd number length digit 12345(12321),lefthalf+1(12421),lefthalf-1(12221)
            
            if(s%2==0)
            {
                string str=n.substr(0,n.size()/2);
                int firstpre=stoll(str),secondpre=stoll(str)-1,thirdpre=stoll(str)+1;
                string fp=to_string(firstpre),sp=to_string(secondpre),tp=to_string(thirdpre);
                string fs(fp.rbegin(),fp.rend()),ss(sp.rbegin(),sp.rend()),ts(tp.rbegin(),tp.rend());
            
                v.push_back(stoll(fp+fs));
                v.push_back(stoll(sp+ss));
                v.push_back(stoll(tp+ts));
            }
            else
            {
                string str=n.substr(0,(n.size()+1)/2);
                int firstpre=stoll(str),secondpre=stoll(str)-1,thirdpre=stoll(str)+1;
                string fp=to_string(firstpre),sp=to_string(secondpre),tp=to_string(thirdpre);
                string fs(fp.rbegin()+1,fp.rend()),ss(sp.rbegin()+1,sp.rend()),ts(tp.rbegin()+1,tp.rend());
                v.push_back(stoll(fp+fs));
                v.push_back(stoll(sp+ss));
                v.push_back(stoll(tp+ts));
            }
            
            if(find(v.begin(),v.end(),val)==v.end())
            v.push_back(val);
            sort(v.begin(),v.end());
            
            string ans,str1,str2;

            for(int i=0;i<v.size();i++)
            {
                if(v[i]==val)
                {
                    if(v[i+1]-val==val-v[i-1])
                    {
                        return to_string(v[i-1]);
                    }
                    else if(v[i+1]-val<val-v[i-1])
                    {
                        return to_string(v[i+1]);
                    }
                    else
                    {
                        return to_string(v[i-1]);
                    }
                }
            }
        }
        return n;
    }

    int main()
    {
        // input the number as digit and call the function function will 
        // return the closest palindrome
    }