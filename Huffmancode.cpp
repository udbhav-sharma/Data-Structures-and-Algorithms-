#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

class Node
{
    public:

    int key;
    int frequency;
    Node *left,*right;
    Node()
    {
        key=-1;
        frequency=0;
        left=NULL;
        right=NULL;
    }
    bool operator <(const Node& that)const
    {
        return this->frequency>that.frequency;
    }
};

priority_queue<Node> Q;
Node* HuffmanTree=new Node();

//Creating a Huffman Code Tree

void Huffman_Code_Tree(string s)
{
    int i,n=s.length();
    int alphabet[26];
    Node *temp1,*temp2,*temp3;

    memset(alphabet,0,sizeof(alphabet));

    for(i=0;i<n;i++)
        alphabet[s[i]-'a']++;

    for(i=0;i<26;i++)
    {
        if(alphabet[i]>0)
        {
            temp1=new Node();
            temp1->frequency=alphabet[i];
            temp1->key=i+'a';
            Q.push(*temp1);
        }
    }

    n=Q.size();
    for(i=1;i<n;i++)
    {
        temp1=new Node();
        temp2=new Node();

        *temp1=Q.top();
        Q.pop();
        *temp2=Q.top();
        Q.pop();

        temp3=new Node();
        temp3->frequency=temp1->frequency+temp2->frequency;
        temp3->left=temp1;
        temp3->right=temp2;
        Q.push(*temp3);
    }
    *HuffmanTree=Q.top();
    Q.pop();

}

void Print_Tree(Node* T)
{
    if(T!=NULL)
    {
        Print_Tree(T->left);
        if(T->key!=-1)
            cout<<(char)T->key<<" ";
        cout<<T->frequency<<endl;
        Print_Tree(T->right);
    }
}

//Generate HuffmanCode for a given string

bool HuffmanCode(Node* T,int key,string& Code)
{
    if(T->left!=NULL)
    {
        if(HuffmanCode(T->left,key,Code))
        {
            Code="0"+Code;
            return true;
        }
        else if(HuffmanCode(T->right,key,Code))
        {
            Code="1"+Code;
            return true;
        }
        return false;
    }
    else
    {
        if(T->key==key)
            return true;
        else
            return false;
    }
}

string GenerateCode(string s)
{
    int i,n=s.length();
    string Code="";
    string temp_code;
    for(i=0;i<n;i++)
    {
        temp_code="";
        HuffmanCode(HuffmanTree,s[i],temp_code);
        Code+=temp_code;
    }
    return Code;
}

//Decode Huffman Code

string Decode(string s)
{
    string Decoded="";
    Node* T=HuffmanTree;
    int i,n=s.length();

    for(i=0;i<=n;)
    {
        if(T->key!=-1)
        {
            Decoded+=(char)T->key;
            T=HuffmanTree;
        }
        else if(s[i]=='0')
        {
            T=T->left;
            i++;
        }
        else
        {
            T=T->right;
            i++;
        }
    }
    return Decoded;
}

int main()
{
    string s;
    cin>>s;

    Huffman_Code_Tree(s);

    Print_Tree(HuffmanTree);

    s=GenerateCode(s);

    cout<<"Huffman Code is:\n"<<s<<endl;

    cout<<"Decoded String is:\n"<<Decode(s)<<endl;

    return 0;
}
