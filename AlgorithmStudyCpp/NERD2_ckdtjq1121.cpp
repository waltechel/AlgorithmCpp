#include<bits/stdc++.h>
const int MAX = 50000;
using namespace std;

int p[MAX];
int q[MAX];
int n;
struct node {
	int p, q;
	node* left = NULL;
	node* right = NULL;
};

node* pushNode(node* root, int i)
{
	node* ret = new node();

	node* inode = new node();
	if (root->p < p[i] && root->q < q[i])
	{
		root->p = p[i];
		root->q = q[i];

		return root;
	}


	// root 72 50

	// 73 51
	if (root->p < p[i] && root->q < q[i])
	{

	}
	// 73 49
	else if (root->p < p[i] && root->q >= q[i])
	{
		if (root->right != NULL)
			ret->right = pushNode(root->right, i);
		else
		{
			inode->p = p[i];
			inode->q = q[i];

			root->right = inode;
			ret = root;
		}
	}
	// 71 51
	else if (root->p >= p[i] && root->q < q[i])
	{
		if (root->left != NULL)
			ret->left = pushNode(root->left, i);
		else
		{
			inode->p = p[i];
			inode->q = q[i];

			root->left = inode;
			ret = root;
		}
	}
	// 71 49
	else if (root->p > p[i] && root->q > q[i])
	{
		return root;
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;

	for (; testCase > 0; testCase--)
	{
		cin >> n;


		for (int i = 0; i < n; i++)
		{
			cin >> p[i] >> q[i];
		}

		node root; // 0
		for (int i = 1; i < n; i++)
			pushNode(&root, i);


		cout << root.right->p << "\n";



	}
}