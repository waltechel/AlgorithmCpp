#include <bits/stdc++.h>

using namespace std;
const int INF = 1000000;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, int> > > dist(n, vector<pair<int, int> >(n, { INF, 1 }));
	vector<int> check(n);
	for (int i = 0; i < n; i++)
		cin >> check[i];

	for (int i = 0; i < m; i++)
	{
		int u, v, t;
		cin >> u >> v >> t;
		u--, v--;
		dist[u][v].first = t;
		dist[v][u].first = t;
	}

	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int mcheck = max(dist[i][k].second, dist[k][j].second);
				mcheck = max(mcheck, check[k]);
				if (dist[i][j].first + dist[i][j].second >
					dist[i][k].first + dist[k][j].first + mcheck)
				{
					dist[i][j].first = dist[i][k].first + dist[k][j].first;
					dist[i][j].second = max(dist[i][j].second, mcheck);
				}
			}
		}
	}

	int q;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		int u, v;
		cin >> u >> v;
		u--, v--;
		cout << dist[u][v].first + dist[u][v].second << "\n";
	}
}