#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;

	for (; testCase > 0; testCase--)
	{
		int v, e, n, m;
		cin >> v >> e >> n >> m;
		vector<vector<pair<int, int> > > edge(v);
		for (int i = 0; i < e; i++)
		{
			int u, v, w;
			cin >> u >> v >> w;
			u--, v--;

			edge[u].push_back({ v, w });
			edge[v].push_back({ u, w });
		}

		vector<int> target(n);
		for (int i = 0; i < n; i++)
		{
			cin >> target[i];
			target[i]--;
		}

		vector<int> station(m);
		for (int i = 0; i < m; i++)
		{
			cin >> station[i];
			station[i]--;
		}

		vector<int> dist(v, INT_MAX);
		for (int i = 0; i < m; i++)
		{
			dist[station[i]] = 0;
		}

		priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
		for (int i = 0; i < m; i++)
		{
			pq.push({ 0, station[i] });
		}

		while (!pq.empty())
		{
			int here = pq.top().second;
			pq.pop();

			for (int j = 0; j < edge[here].size(); j++)
			{
				int there = edge[here][j].first;
				int w = edge[here][j].second;

				if (dist[there] > dist[here] + w)
				{
					dist[there] = dist[here] + w;
					pq.push({ dist[there], there });
				}
			}
		}

		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			ans += dist[target[i]];
		}

		cout << ans << "\n";
	}
}