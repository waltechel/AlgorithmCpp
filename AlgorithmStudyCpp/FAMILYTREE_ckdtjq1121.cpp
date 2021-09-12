#include<bits/stdc++.h>

using namespace std;
const int MAX = 100001;
const int INF = 987654321;
int n, q;

vector<queue<int> > tree(MAX); // input data tree
vector<int> depth(MAX);	// depth of node
vector<int> preorder;	// preorder of tree
vector<int> lcaTree(MAX * 8);// [left, right] segment tree of lca(minValue)
vector<int> maxTree(MAX * 8);// [left, right] segment tree that max Num of node

void getDepth()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < tree[i].size(); j++)
		{
			int child = tree[i].front();
			depth[child] = depth[i] + 1;

			tree[i].pop();
			tree[i].push(child);
		}
	}
	return;
}

void getPreorder()
{
	stack<pair<int, int> > s;
	int parent = 0, child = 0;
	s.push(make_pair(parent, child));
	while (!s.empty())
	{
		while (tree[parent].size() > 0)
		{
			preorder.push_back(parent);

			child = tree[parent].front();


			s.push(make_pair(parent, child));
			tree[parent].pop();
			parent = child;
		}

		parent = s.top().first;
		child = s.top().second;

		preorder.push_back(child);
		s.pop();
	}
}
void init(int node, int start, int end)
{
	if (start == end)
	{
		lcaTree[node] = maxTree[node] = preorder[start];
		return;
	}

	int mid = (start + end) / 2;
	init(2 * node, start, mid);
	init(2 * node + 1, mid + 1, end);
	lcaTree[node] = min(lcaTree[2 * node], lcaTree[2 * node + 1]);
	maxTree[node] = max(maxTree[2 * node], maxTree[2 * node + 1]);
}
// return index that location of value
int findIndex(int node, int start, int end, int value)
{
	if (maxTree[node] < value || lcaTree[start] > value)
		return -1;

	if (preorder[start] == value)
		return start;

	int mid = (start + end) / 2;
	int left = findIndex(2 * node, start, mid, value);
	int right = findIndex(2 * node + 1, mid + 1, end, value);

	return max(left, right);
}
// lca(left, right)
int queryLCA(int node, int start, int end, int left, int right)
{
	// out of range
	if (end < left || right < start)
		return INF;

	// in of range
	if (left <= start && end <= right)
		return lcaTree[node];

	int mid = (start + end) / 2;
	int leftNode = queryLCA(2 * node, start, mid, left, right);
	int rightNode = queryLCA(2 * node + 1, mid + 1, end, left, right);
	return min(leftNode, rightNode);
}
int main() // RTE (stack overflow or incoreect memory access)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;
	for (; testCase > 0; testCase--)
	{
		cin >> n >> q;
		// 0은 부모가 없다 1 ~ (n-1) 만 부모가 있다
		for (int child = 1; child < n; child++)
		{
			int parent;
			cin >> parent;
			tree[parent].push(child);
		}

		depth[0] = 0;
		getDepth();
		//for (int i = 0; i < n; i++)
		//	cout << depth[i] << " ";
		//cout << '\n';
		preorder.clear();
		getPreorder();
		//for (int i = 0; i < preorder.size(); i++)
		//	cout << preorder[i] << " ";
		//cout << "\n";
		init(1, 0, preorder.size() - 1);

		int a, b, idxA, idxB, lca, swap;
		for (int i = 0; i < q; i++)
		{
			cin >> a >> b;
			// find left index, find right index
			// query(node, start, end , left, right)
			idxA = findIndex(1, 0, preorder.size() - 1, a);
			idxB = findIndex(1, 0, preorder.size() - 1, b);
			if (idxA > idxB)
			{
				swap = idxA;
				idxA = idxB;
				idxB = swap;
			}

			lca = queryLCA(1, 0, preorder.size() - 1, idxA, idxB);
			//cout << a << " " << b << "    " << idxA << " " << idxB << "   " << lca << "\n";
			cout << depth[a] + depth[b] - 2 * depth[lca] << "\n";
		}
	}
}