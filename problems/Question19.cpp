/*Print all permutations of a given string*/
#include <iostream>

using namespace std;

int count=0;

void PrintPermutation(string word,int i)
{
    if(i==word.length()-1)
    {
        cout<<(++count)<<"\t\t"<<word<<endl;
        return;
    }
    for(int j=i;j<word.length();j++)
    {
        swap(word[j],word[i]);
        PrintPermutation(word,i+1);
        swap(word[j],word[i]);
    }
}

int main()
{
    string word;
    cout<<"Word:\t";
    cin>>word;
    cout<<"Index\t\t"<<"Permutation\n";
    PrintPermutation(word,0);
    return 0;
}