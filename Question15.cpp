#include<iostream>
using namespace std;

void AppendZeros(string &num,int length)
{
    for(int i=0;i<length-num.length();i++)
        num=num[0]+num;
}

string AddStrings(string num1,string num2)
{
    num1.length() > num2.length()? AppendZeros(num2,num1.length()):AppendZeros(num1,num2.length());
    int a,b,carry=0;
    int temp_sum;
    string sum="";
    for(int i=num1.length()-1;i>=0;i--)
    {
        a=(num1[i]-'0');
        b=(num2[i]-'0');
        temp_sum=(((!a)&b&(!carry))|(a&(!b)&(!carry))|((!a)&(!b)&carry)|(a&b&carry));
        sum=(char)(temp_sum+'0')+sum;
        carry=((a&b)|(a&carry)|(b&carry));
    }
    if(carry)sum='1'+sum;
    return sum;
}

int main()
{
    string num1,num2;
    cout<<"First Number:\t";
    cin>>num1;
    cout<<"Second Number:\t";
    cin>>num2;
    cout<<"Sum is\t"<<AddStrings(num1,num2)<<endl;
    return 0;
}
