#include<bits/stdc++.h>

using namespace std;
const int MAX = 1000000;
vector<int> tree;

void init(int node, int start, int end)
{
	tree[node] = 0;
	if (start == end)
		return;

	int mid = (start + end) / 2;
	init(2 * node, start, mid);
	init(2 * node + 1, mid + 1, end);
	return;
}

int findNumOfBigger(int node, int start, int end, int val)
{
	if (val < start)
		return tree[node];

	if (end <= val)
		return 0;
	int mid = (start + end) / 2;
	return findNumOfBigger(2 * node, start, mid, val) + findNumOfBigger(2 * node + 1, mid + 1, end, val);
}

int querySum(int node, int start, int end, int idx)
{
	if (idx < start)
		return 0;

	if (end <= idx)
		return tree[node];

	int mid = (start + end) / 2;
	return querySum(2 * node, start, mid, idx) + querySum(2 * node + 1, mid + 1, end, idx);
}

void update(int node, int start, int end, int val)
{
	if (val < start || end < val)
		return;

	tree[node]++;

	if (start == end)
		return;


	int mid = (start + end) / 2;
	update(2 * node, start, mid, val);
	update(2 * node + 1, mid + 1, end, val);
}
int main()	// 1132ms , 904ms
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;
	for (; testCase > 0; testCase--)
	{
		int n;
		cin >> n;
		// input array
		vector<int> arr(n);
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		// makeTree
		int height = ceil(log2(MAX));
		tree.resize(1 << (height + 1));
		// initTree
		init(1, 0, MAX - 1);
		// get ans
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			// 앞에 있는 수 중 arr[i]보다 큰 수의 개수를 ret에 추가
			//ans += findNumOfBigger(1, 0, MAX - 1, arr[i]);							// 1148ms
			// MAX-1까지 수의 개수 - arr[i]까지 수의 개수 =  arr[i]보다 큰 숫자의 개수
			ans += querySum(1, 0, MAX - 1, MAX - 1) - querySum(1, 0, MAX - 1, arr[i]);	// 904ms
			// segtree에 arr[i]를 추가
			update(1, 0, MAX - 1, arr[i]);
		}
		cout << ans << "\n";
	}
}