#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;

	for (; testCase > 0; testCase--)
	{
		int n, m;
		cin >> n >> m;

		vector<vector<pair<int, double> > > edge(n);
		for (int i = 0; i < m; i++)
		{
			int u, v;
			double w;
			cin >> u >> v >> w;

			edge[u].push_back({ v, w });
			edge[v].push_back({ u, w });
		}

		const double INF = DBL_MAX;
		vector<double> dist(n, INF);
		dist[0] = 1;

		priority_queue<pair<double, int>, vector<pair<double, int> >, greater<pair<double, int> > > pq;
		pq.push({ 1, 0 });

		while (!pq.empty())
		{
			int here = pq.top().second;

			pq.pop();

			for (int i = 0; i < edge[here].size(); i++)
			{
				int there = edge[here][i].first;
				double w = edge[here][i].second;

				if (dist[there] - dist[here] * w > 1e-10) // ¿ÀÂ÷
				{
					dist[there] = dist[here] * w;
					pq.push({ dist[there], there });
				}
			}
		}

		cout.fixed;
		cout.precision(12);
		cout << dist[n - 1] << "\n";
	}
}