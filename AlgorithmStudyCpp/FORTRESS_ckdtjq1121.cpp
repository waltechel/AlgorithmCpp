// 요새의 정보를 이용해서 트리를 만들 수 있다.
// 트리에서 N1 -> N2 의 최대 거리를 구한다.
#include<bits/stdc++.h>
int n;
int longest;
using namespace std;

struct node {
	int x;
	int y;
	int r;
	vector<node*> children;
};

vector<node> arr;

int sqr(int a)
{
	return a * a;
}
int sqrdist(int a, int b)
{
	return sqr(arr[a].x - arr[b].x) + sqr(arr[a].y - arr[b].y);
}
bool encloses(int a, int b)
{
	return arr[a].r > arr[b].r && sqrdist(a, b) < sqr(arr[a].r - arr[b].r);
}

bool isChild(int parent, int child)
{
	if (!encloses(parent, child))
		return false;

	for (int i = 0; i < n; i++)
	{
		if (i != parent && i != child && encloses(parent, i) && encloses(i, child))
			return false;
	}

	return true;
}


node* getTree(int root)
{
	node* ret = new node();
	for (int child = 0; child < n; child++)
	{
		if (isChild(root, child))		// 이부분에서 버그가 남..
		{
			cout << root << " " << child << "\n";
			ret->children.push_back(getTree(child));
		}
	}

	return ret;
}


int height(node* root)
{
	vector<int> heights;
	for (int i = 0; i < root->children.size(); i++)
		heights.push_back(height(root->children[i]));

	if (heights.empty()) return 0;

	sort(heights.begin(), heights.end());

	if (heights.size() >= 2)
		longest = max(longest, 2 + heights[heights.size() - 2] + heights[heights.size() - 1]);

	return heights.back() + 1;
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;

	for (; testCase > 0; testCase--)
	{

		cin >> n;

		int x, y, r;

		for (int i = 0; i < n; i++)
		{
			cin >> x >> y >> r;
			node newNode;
			newNode.x = x;
			newNode.y = y;
			newNode.r = r;

			arr.push_back(newNode);

		}

		node root = *getTree(0);

		longest = 0;
		int h = height(&root);
		cout << max(h, longest) << "\n";
	}
}