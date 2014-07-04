/*
Write a longest palindrome substring in a given string using recursion..
*/
#include <iostream>
#include <string>
using namespace std;

string maxsubstr="";

void compare(string s)
{
    s.length()>maxsubstr.length() ? maxsubstr=s:maxsubstr=maxsubstr;
}

bool LPS (string s)
{
    if(s.length()<=1)
        return true;
    if(s[0]==s[s.length()-1] )
    {
        if(LPS(s.substr(1,s.length()-2)))
        {
            compare(s);
            return true;
        }
    }
    if(LPS(s.substr(0,s.length()-1)))
        compare(s.substr(0,s.length()-1));
    if(LPS(s.substr(1)))
        compare(s.substr(1));
    return false;
}

int main()
{
    string s;
    cin>>s;
    while(s!="-1")
    {
        maxsubstr="";
        LPS(s);
        cout<<maxsubstr<<endl;
        cin>>s;
    }
    return 0;
}
