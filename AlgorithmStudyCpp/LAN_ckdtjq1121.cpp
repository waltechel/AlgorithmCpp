#include<bits/stdc++.h>

using namespace std;
vector<int> parent;
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

		vector<int> x(n);
		for (int i = 0; i < n; i++)
			cin >> x[i];

		vector<int> y(n);
		for (int i = 0; i < n; i++)
			cin >> y[i];


		parent = vector<int>(n);
		for (int i = 0; i < n; i++)
			parent[i] = i;
		for (int i = 0; i < m; i++)
		{
			int u, v;
			cin >> u >> v;

			int ru = find(u), rv = find(v);
			if (ru != rv)
				parent[ru] = rv;
		}

		priority_queue<pair<double, pair<int, int> >, vector<pair<double, pair<int, int> > >, greater< pair<double, pair<int, int> > > > pq;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				double dist = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));

				pq.push({ dist, { i, j } });
			}
		}

		double ans = 0;
		while (!pq.empty())
		{
			double dist = pq.top().first;
			int u = pq.top().second.first;
			int v = pq.top().second.second;
			pq.pop();

			int ru = find(u), rv = find(v);
			if (ru != rv)
			{
				parent[ru] = rv;
				ans += dist;
			}
		}

		cout.fixed;
		cout.precision(10);
		cout << ans << "\n";
	}
}