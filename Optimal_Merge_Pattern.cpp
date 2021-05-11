#include<bits/stdc++.h>
using namespace std;

class Tree
{
public:
	int val;
	Tree *left;
	Tree *right;
}*root,*temp1;

class Node
{
public:
	Tree *tree;
	Node *next;
}*head,*temp;

Tree *createTree(int val)
{
	Tree *newnode = new Tree();
	newnode->val=val;
	newnode->left=newnode->right=NULL;
	return newnode;
}

Node* createNode(int val)
{
	Node *newnode = new Node();
	newnode->tree=createTree(val);
	newnode->next=NULL;
	return newnode;
}
void insert(Node *newnode)
{
	if(head==NULL)head=newnode;
	else
	{
		if(head->tree->val>=newnode->tree->val)
		{
			newnode->next=head;
			head=newnode;
		}
		else
		{
			temp=head;
			while(temp->next and temp->next->tree->val<newnode->tree->val)
				temp=temp->next;

			newnode->next=temp->next;
			temp->next=newnode;
		}
	}
}
void inOrder(Tree *root)
{
	if(root)
	{
		inOrder(root->left);
		cout<<root->val<<" ";
		inOrder(root->right);
	}
}
void display()
{
	temp=head;
	while(temp!=NULL)
	{
		cout<<temp->tree->val<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
void doMerge()
{
	int work=0;

	while(head->next)
	{
		// display();
		int first = head->tree->val;
		int second = head->next->tree->val;
		
		work+=first+second;

		Node *newnode = createNode(first+second);
		newnode->tree->left=head->tree;
		newnode->tree->right=head->next->tree;
		head=head->next->next;

		insert(newnode);
	}
	// display();
	cout<<"WorkDone : "<<work<<endl;
}

int main()
{
	vector<int> v = {2,1,5,10,11,3};
	for(int x:v)
	{
		Node *newnode = createNode(x);
		insert(newnode);
	}
	display();
	doMerge();
	temp=head;
	inOrder(temp->tree);
	cout<<endl;
	return 0;
}