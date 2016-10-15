//Whether a tree is BST or not

class Node
{
	int key;
	Node* left;
	Node* right;
	Node()
	{
		left=NULL;
		right=NULL;
	}
};

bool isBST(Node* T)
{
    static Node *prev = NULL;
    
    if(T!=NULL)
    {
        if (!isBST(T->left))
          return false;
 
        if (prev != NULL && T->key < prev->key)
          return false;
        prev = T;

        return isBST(T->right);
    }
 
    return true;
}