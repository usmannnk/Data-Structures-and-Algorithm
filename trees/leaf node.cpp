#include<iostream>
using namespace std;

class node
{
public:
	int d;
	 node* left;
	 node* right;
};


void printLeafN(node* root)
{
	if (!root)
		return;

	if (!root->left && !root->right)
	{
		cout << root->d << "\t";
		return;
	}

	if (root->left)
		printLeafN(root->left);

	if (root->right)
		printLeafN(root->right);
}


node* newNode(int d)
{
	node* temp = new node;
	temp->d = d;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}


int main()
{
	node* root = newNode(1);
	root->left = newNode(1);
	root->right = newNode(2);
	root->left->left = newNode(2);
	root->right->left = newNode(4);
	root->right->right = newNode(4);
	root->right->left->left = newNode(4);
	root->right->left->right = newNode(7);
	root->right->right->left = newNode(7);
	root->right->right->right = newNode(9);
	printLeafN(root);	
}
