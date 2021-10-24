#include<bits/stdc++.h>

using namespace std;
vector<int> parent;
vector<pair<int, pair<int, int> > > edge;
int find(int u)
{
	if (u == parent[u])
		return u;

	return parent[u] = find(parent[u]);
}

int main()
{
	int testCase;
	cin >> testCase;

	while (testCase--)
	{
		int n, m;
		cin >> n >> m;

		edge = vector<pair<int, pair<int, int> > >(m);
		for (int i = 0; i < m; i++)
		{
			int u, v, c;
			cin >> u >> v >> c;
			edge[i] = { c, {u, v} };
		}
		sort(edge.begin(), edge.end());

		// i번째 edge부터 사용해서 0과 n-1이 연결되는 index => j
		// [i,j] 안에서 max c - min c 들의 min => ans

		int ans = INT_MAX;
		for (int i = 0; i < m; i++)
		{
			parent = vector<int>(n);
			for (int j = 0; j < n; j++)
				parent[j] = j;

			int mx = 0, mi = INT_MAX;
			for (int j = i; j < m; j++)
			{
				int u = edge[j].second.first;
				int v = edge[j].second.second;
				int c = edge[j].first;

				int ru = find(u), rv = find(v);
				if (ru != rv)
					parent[ru] = rv;

				mx = max(mx, c);
				mi = min(mi, c);

				if (find(0) == find(n - 1))
				{
					ans = min(ans, mx - mi);
					break;
				}
			}
		}

		cout << ans << "\n";
	}
}