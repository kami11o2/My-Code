struct NodeTree
{
	int data;
	NodeTree *right;
	NodeTree *left;
};

class Tree
{
private:
	NodeTree *root;
public:
	Tree ()
	{
		root = 0;
	}
	
	void Add(int value)
	{
		NodeTree *temp = new NodeTree;
		temp->data = value;
		if (root == 0)
			root = temp;
		else
		{
			NodeTree *n = root;
			while (n!=0)
			{
				if (temp->data > n->data)
					n = n->right;
				else
					n = n->left;
			}
			n = temp;
		}
	};
	
	int Temp(NodeTree *root)
	{
		if(root->left == 0)
			return root->left->data;
		if(root->right == 0)
			return root->right->data;
		if(root->left != 0)
    		return Temp(root->left);
    	cout<<root->data<<" ";
    	return Temp(root->right);
	}
	
	void Print()
	{
		NodeTree *t = root;
		Temp(t);
	};

};
