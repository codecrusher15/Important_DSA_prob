//Lab 10 
#include<bits/stdc++.h>
using namespace std;
struct node
{
	struct node* left;
	struct node* right;
	int height;
	int count;
	int key;
};
int BST_rank(struct node* root,int x);
int find_el_rank(struct node* root,int rank);
struct node* insert(struct node* node,int key);
struct node* newnode(int key);
struct node* rotate(struct node* Z);
int height(struct node* node);
int AVL(struct node* node);
int count(struct node* node);
int main()
{
	int n;
	cin >> n;
	int a[n],b[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
	}
	struct node* root = NULL;
	for (int i = 0; i < n; i++)
	{
		// rank is definded as (number of elements less n) +1
		root = insert(root,a[i]); //inserting elements in BST one by one
		if(b[i] == 0) cout << a[i] << " "; //b[i] = 0 so print same element  a[i]
		else
		{
			int rank = BST_rank(root,a[i]);
			if(b[i]>= rank) cout << -1 << " "; //invalid rank
			else cout << find_el_rank(root,rank-b[i]) << " "; //finding element with rank b[i] less than current rank
		}
	}
	
	
}
int BST_rank(struct node* root,int x) 	//function to find rank when element is given
{
	int rank = 1;
	while(root)
	{
		if(x == root->key)
		{
			if(root->left) rank+=root->left->count;
			return rank;
		}
		else if(x > root->key)
		{
			rank++;
			if(root->left) rank+=root->left->count;
			root = root->right;
		}
		else root = root->left;
	}
	return rank;
}
int find_el_rank(struct node* root,int rank) //func to find element when rank is given
{
	int r;
	if(root && rank>0 && rank< root->count+1)
	{
		while(root)
		{
			if(root->left) r = root->left->count+1;
			else r = 1;
			if(r == rank) return root->key;
			else if(r<rank)
			{
				root = root->right;
				rank = rank -r;
			}
			else root = root->left;
		}
	}
	return -1;
}
struct node* insert(struct node* node,int key) //inserting node in BST
{
	if(!node) return newnode(key);
	if(key< node->key) node->left = insert(node->left,key);
	else if(key>node->key) node->right = insert(node->right,key);
	node->height = height(node);
	node->count = count(node);
	if(!AVL(node)) node = rotate(node);
	return node;
}
struct node* newnode(int key) //func to create node and return its pointer
{
	struct node * new_node = (struct node*)(malloc(sizeof(struct node)));
	new_node->key = key;
	new_node->left = new_node->right = NULL;
	new_node->height = 0;
	new_node->count = 1;
	return new_node;
}
int height(struct node* node) //compute curr height using left and right children
{
	if(node)
	{
		if(node->left && node->right) return 1+max(node->left->height,node->right->height);
		else if(node->left) return 1 + node->left->height;
		else if(node->right) return 1 + node->right->height;
		else return 0;
	}
	else return -1;
}
int count(struct node* node) //compute current count using left and right child
{
	if(node)
	{
		if(node->left && node->right) return 1+node->left->count+node->right->count;
		else if(node->left) return 1 + node->left->count;
		else if(node->right) return 1 + node->right->count;
		else return 1;
	}
	else return 0;
}
int AVL(struct node* node) //return 1 if AVL property is satisfied at particular node else return 0
{
	if(abs(height(node->left)-height(node->right)) < 2) return 1;
	else return 0;
}
struct node* rotate(struct node* Z)
{
	struct node *X,*Y,*T1,*T2,*T3,*T4,*ret_val;
	int c = 0;
	if(height(Z->left)+1==Z->height) Y = Z->left;
	else {Y = Z->right;c++;}
	c = c*2;
	if(height(Y->left)+1==Y->height) X = Y->left;
	else{X=Y->right;c++;}
	switch (c)
	{
	case 0:
		T3 = Y->right;
		Y->right = Z;
		Z->left = T3;
		ret_val = Y;
		break;
	case 1:
		T2=X->left;
		T3=X->right;
		Y->right = T2;
		Z->left = T3;
		X->left = Y;
		X->right = Z;
		ret_val = X;
		break;
	case 2:
		T2 = X->left;
		T3 = X->right;
		Y->left = T3;
		Z->right = T2;
		X->left = Z;
		X->right = Y;
		ret_val = X;
		break;
	case 3:
		T2 = Y->left;
		Y->left = Z;
		Z->right = T2;
		ret_val = Y;
		break;
	}
	if(ret_val == Y)
	{
		Z->height = height(Z);
		X->height = height(X);
		Y->height = height(Y);
		Z->count = count(Z);
		X->count = count(X);
		Y->count = count(Y);
		return ret_val;
	}
	else if(ret_val == X)
	{
		Z->height = height(Z);
		Y->height = height(Y);
		X->height = height(X);
		Z->count = count(Z);
		Y->count = count(Y);
		X->count = count(X);
		return ret_val;
	}
	return NULL;
}
