#include<iostream>
#include<string>

using namespace std;

class vertex
{
    public:
    int words;
    int prefixes;
    vertex* child[26];
    vertex()
    {
        words=0;
        prefixes=0;
        for(int i=0;i<26;i++)
            child[i]=NULL;
    }
};

void addWord(vertex* T,string word,int i,int n)
{
    if(i==n)
    {
        T->words++;
        T->prefixes++;
    }
    else
    {
        int k=word[i]-'a';

        T->prefixes++;

        if(T->child[k]==NULL)
            T->child[k]=new vertex();

        addWord(T->child[k],word,i+1,n);
    }
}

int countWord(vertex *T,string word,int i,int n)
{
    if(i==n)
        return T->words;

    int k=word[i]-'a';

    if(T->child[k]==NULL)
        return 0;
    else
        return countWord(T->child[k],word,i+1,n);
}

int countPrefixes(vertex *T,string word,int i,int n)
{
    if(i==n)
        return T->prefixes;

    int k=word[i]-'a';

    if(T->child[k]==NULL)
        return 0;
    else
        return countPrefixes(T->child[k],word,i+1,n);
}

bool dltWord(vertex* &T,string word,int i,int n)
{
    bool flag;
    if(T==NULL)
        return false;

    if(i<n)
    {
        flag=dltWord(T->child[word[i]-'a'],word,i+1,n);
        if(flag)
        {
            T->prefixes--;
            if(T->words==0 && T->prefixes==0)
                T=NULL;
        }
        return flag;
    }

    else if(T->words>0)
    {
        T->words--;
        T->prefixes--;
        if(T->words==0 && T->prefixes==0)
            T=NULL;
        return true;
    }

    return false;
}

int main()
{
    string word,prefix;
    vertex *tree=new vertex();

    cin>>word;
    while(word!="0")
    {
        addWord(tree,word,0,word.length());
        cin>>word;
    }

    cin>>word;
    while(word!="0")
    {
        dltWord(tree,word,0,word.length());
        cin>>word;
    }

    cin>>prefix;
    while(prefix!="0")
    {
        cout<<countPrefixes(tree,prefix,0,prefix.length())<<endl;
        cin>>prefix;
    }
    return 0;
}
