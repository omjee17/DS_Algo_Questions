#include <iostream>
using namespace std;


void helper(string s,int i,string output)
{
    if(i==s.size())
    {
        cout<<output<<endl;
        return;
    }
    
    helper(s,i+1,output+s[i]);
    helper(s,i+1,output);
}

int main() {
	string s;
	cin>>s;
	string s1="";
	helper(s,0,s1);
	return 0;
}
