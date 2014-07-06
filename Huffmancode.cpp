#include <queue>
#include <cstring>
#include <iostream>

using namespace std;

class Node
{

private:
    int key;
    int frequency;
    Node *left;
    Node *right;

    void Initialize()
    {
        this->key=-1;
        this->frequency=0;
        this->left=NULL;
        this->right=NULL;
    }

public:
    Node()
    {
        Initialize();
    }

    Node(int key, int frequency)
    {
        Initialize();
        this->key=key;
        this->frequency=frequency;
    }

    Node(int frequency, Node* left, Node* right)
    {
        Initialize();
        this->frequency=frequency;
        this->left=left;
        this->right=right;
    }

    bool operator <(const Node& that)const
    {
        return this->frequency>that.frequency;
    }

    bool IsLeaf()
    {
        if(this->key!=-1) return true;
        return false;
    }

    int GetKey()
    {
        return this->key;
    }

    int GetFrequency()
    {
        return this->frequency;
    }

    Node* GetLeftChild()
    {
        return this->left;
    }

    Node* GetRightChild()
    {
        return this->right;
    }
};

priority_queue<Node> Q;
Node* HuffmanTree=new Node();

//Creating a Huffman Code Tree

void GenerateTree(string s)
{
    int i;
    int alphabet[26];
    Node *ptr1,*ptr2,*ptr3;

    memset(alphabet,0,sizeof(alphabet));

    for(i=0;i<s.length();i++)
        alphabet[s[i]-'a']++;

    for(i=0;i<26;i++)
        if(alphabet[i])
        {
            ptr1=new Node((i+'a'), alphabet[i]);
            Q.push(*ptr1);
        }

    while( Q.size()>1 )
    {
        ptr1=new Node();
        ptr2=new Node();

        *ptr1=Q.top();
        Q.pop();
        *ptr2=Q.top();
        Q.pop();

        ptr3=new Node( (ptr1->GetFrequency()+ptr2->GetFrequency()), ptr1, ptr2);
        Q.push(*ptr3);
    }
    *HuffmanTree=Q.top();
    Q.pop();

}

void PrintTree(Node* T)
{
    if(T!=NULL)
    {
        PrintTree(T->GetLeftChild());
        if(T->IsLeaf())
            cout<<(char)T->GetKey()<<"\t";
        cout<<T->GetFrequency()<<endl;
        PrintTree(T->GetRightChild());
    }
}

bool HuffmanCode(Node* T,int key,string& Code)
{
    if(!T->IsLeaf())
    {
        if(HuffmanCode(T->GetLeftChild(),key,Code))
        {
            Code="0"+Code;
            return true;
        }
        else if(HuffmanCode(T->GetRightChild(),key,Code))
        {
            Code="1"+Code;
            return true;
        }
        return false;
    }
    if(T->GetKey()==key) return true;
    return false;
}

string GenerateCode(string s)
{
    int i;
    string Code="";
    string temp_code;
    for(i=0;i<s.length();i++)
    {
        temp_code="";
        HuffmanCode(HuffmanTree,s[i],temp_code);
        Code+=temp_code;
    }
    return Code;
}

string Decode(string s)
{
    string Decoded="";
    Node* T=HuffmanTree;
    int i;

    for(i=0;i<=s.length();)
    {
        if(T->IsLeaf())
        {
            Decoded+=(char)T->GetKey();
            T=HuffmanTree;
        }
        else if(s[i]=='0')
        {
            T=T->GetLeftChild();
            i++;
        }
        else
        {
            T=T->GetRightChild();
            i++;
        }
    }
    return Decoded;
}

int main()
{
    string s;
    cout<<"Input String:\t";
    cin>>s;

    GenerateTree(s);

    PrintTree(HuffmanTree);

    s=GenerateCode(s);

    cout<<"Huffman Code is:\n"<<s<<endl;

    cout<<"Decoded String is:\n"<<Decode(s)<<endl;

    return 0;
}
