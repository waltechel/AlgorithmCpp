#include<bits/stdc++.h>

using namespace std;
const int MAX = 100001;
const int INF = 987654321;
int sign[MAX];
vector<pair<int, int> > tree(MAX * 4);

pair<int, int> init(int left, int right, int node)
{
	if (left == right)
		return tree[node] = make_pair(sign[left], sign[right]);

	int mid = (left + right) / 2;
	pair<int, int> leftNode = init(left, mid, 2 * node);
	pair<int, int> rightNode = init(mid + 1, right, 2 * node + 1);

	return tree[node] = make_pair(min(leftNode.first, rightNode.first), max(leftNode.second, rightNode.second));
}

pair<int, int> query(int a, int b, int left, int right, int node)
{
	if (right < a || b < left)
		return make_pair(INF, 0);

	if (a <= left && right <= b)
		return tree[node];

	int mid = (left + right) / 2;
	pair<int, int> leftNode = query(a, b, left, mid, 2 * node);
	pair<int, int> rightNode = query(a, b, mid + 1, right, 2 * node + 1);

	return make_pair(min(leftNode.first, rightNode.first), max(leftNode.second, rightNode.second));
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;

	for (; testCase > 0; testCase--)
	{
		int n, q;
		cin >> n >> q;

		for (int i = 1; i <= n; i++)
			cin >> sign[i];

		init(1, n, 1);	// make segment tree

		for (int i = 0; i < q; i++)
		{
			int a, b;
			cin >> a >> b;

			pair<int, int> ans = query(a + 1, b + 1, 1, n, 1); // query [a+1, b+1]

			cout << ans.second - ans.first << endl;
		}
	}
}