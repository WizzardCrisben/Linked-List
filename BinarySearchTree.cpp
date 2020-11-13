
//Name: TB Mokhitli		Student No: 211233680
// C++ implementation to construct a Binary Search Tree

#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

// node of a BST 
struct Node
{
	int data;
	Node *left, *right;
};


// function to get a new node 
Node* getNode(int data)
{
	// Allocate memory 
	Node *newNode = (Node*)malloc(sizeof(Node));

	// put in the data	 
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}


// function to construct a BST from 
/*Node *LevelOrder(Node *root, int data)
{
	if (root == NULL){
		root = getNode(data);
		return root;
	}
	if (data <= root->data)
		root->left = LevelOrder(root->left, data);
	else
		root->right = LevelOrder(root->right, data);
	return root;
}*/

Node* constructBst(int arr[], int n)
{
	if (n == 0)return NULL;
	Node *root = NULL;

	for (int i = 0; i<n; i++)
		root = LevelOrder(root, arr[i]);

	return root;
}

// function to print the inorder traversal 
void preorderTraversal(Node* root)
{
	if (root != NULL)
	{
		cout << root->data << " ";
		preorderTraversal(root->left);
		preorderTraversal(root->right);
	}
}

void inorderTraversal(Node* root)
{
	if (!root)
		return;

	inorderTraversal(root->left);
	cout << root->data << " ";
	inorderTraversal(root->right);
}

void postorderTraversal(Node* root)
{
	if (!root)
		return;

	postorderTraversal(root->left);
	postorderTraversal(root->right);
	cout << root->data << " ";
}


// Driver program to test above 
int main()
{
	int NumTree[] = {5, 10, 7, 3, 8, 13, 6, 4, 16 }; //initialization of BST 
	int n = sizeof(NumTree) / sizeof(NumTree[0]);

	Node *root = constructBst(NumTree, n);

	cout << "Preorder Traversal: ";
	preorderTraversal(root);
	cout << "\nInorder Traversal: ";
	inorderTraversal(root);
	cout << "\nPostorder Traversal: ";
	postorderTraversal(root);

	_getch();
	return 0;
}
