#include<bits/stdc++.h>
using namespace std;

class Node
{
	public:
	
	Node *left;
	int val;
	Node *right;

	Node(int val)
	{
		left=right=NULL;
		this->val=val;
	}
}*root;


class TreeNode
{
	public:
	Node* insertTree(Node *root,int val);
	Node *deleteTree(Node *root,int val);
	void inOrder(Node *root);
};

Node* TreeNode::insertTree(Node *root,int val)
{
	if(root==NULL)
	{
		root = new Node(val);
	}
	else if(root->val > val)
	{
		root->left = insertTree(root->left,val);
	}
	else
	{
		root->right = insertTree(root->right,val);
	}

	return root;
}


void TreeNode::inOrder(Node *root)
{
	if(root)
	{
		inOrder(root->left);
		cout << root->val << " ";
		inOrder(root->right);
	}
}

int findMin(Node *root)
{
	int temp = root->val;
	while(root)
	{
		temp = min(root->val,temp);
		root=root->left;
	}
	return temp;
}
Node* TreeNode::deleteTree(Node *root,int val)
{
	if(root)
	{
		if(root->val > val)root->left = deleteTree(root->left,val);
		else if(root->val<val)root->right = deleteTree(root->right,val);
		else
		{
			if(root->left==NULL && root->right == NULL)
			{
				root = NULL;
			}
			else if(root->left == NULL)
			{
				root = root->right;
			}
			else if(root->right == NULL)
			{
				root = root->left;
			}
			else
			{
				root->val = findMin(root->right);
				root->right = deleteTree(root->right,root->val);
			}
		}
	}
	return root;
}
int main()
{
	int ch;
	int val;
	root=NULL;
	TreeNode bt;
	
	vector<int> temp = {31,9,99,10,17,35,92,24,32,27};
	
	for(int x:temp)
	{
		root = bt.insertTree(root,x);
	}
	bt.inOrder(root);
	cout<<endl;

	root = bt.deleteTree(root,100);

	bt.inOrder(root);
	cout<<endl;
	return 0;
}