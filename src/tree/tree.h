template <class T>
struct NodeTree
{
	T data;
	NodeTree<T> *right;
	NodeTree<T> *left;
};

template <class T>

class Tree
{
private:
	NodeTree<T> *root;
	void PrePrint(NodeTree<T> *root) const
	{
		if (root != 0)
		{
			PrePrint(root->left);
			cout<<root->data<<" ";
			PrePrint(root->right);
		}
	}
public:
	Tree ()
	{
		root = 0;
	}
	
	void Add(T value)
	{
		NodeTree<T> *temp = new NodeTree<T>;
		temp->data = value;
		temp->right = 0;
		temp->left = 0;
		if (root == 0)
			root = temp;
		else
		{
			NodeTree<T> *n = root;
			NodeTree<T> *t = n;
			while (n!=0)
			{
				t = n;
				if (n->data < value)
					n = n->right;
				else
					n = n->left;
			}
			if (t->data < value)
				t->right = temp;
			else
				t->left = temp;
		}
	};
	
	void PreOrder() const
	{
		PrePrint(root);
	};

	bool Search(T value)
	{
		NodeTree<T> *t = root;
		if (root -> data == value)
			return true;
		while (t != NULL)
		{
			if (t->data == value)
				return true;
			if (t->data < value)
				t = t->right;
			else
				t = t->left;
		}
		return false;
	}

};
