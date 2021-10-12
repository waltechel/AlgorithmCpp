#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;

	while (testCase--)
	{
		int n;
		cin >> n;

		vector<pair<int, int> > arr(n);
		vector<int> diff(n);
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i].first >> arr[i].second;
			diff[i] = arr[i].first - arr[i].second;
		}

		vector<int> dist(2 * 200, INT_MAX); // -199 ~ 199
		priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
		for (int i = 0; i < n; i++)
		{
			if (dist[diff[i] + 200] > arr[i].first)
			{
				dist[diff[i] + 200] = arr[i].first;
				pq.push({ arr[i].first, diff[i] + 200 });
			}
		}
		while (!pq.empty())
		{
			int cost = pq.top().first;
			int u = pq.top().second;
			pq.pop();

			for (int i = 0; i < n; i++)
			{
				int v = u + diff[i];

				if (v < 0 || v >= 400)
					continue;

				if (dist[v] > dist[u] + arr[i].first)
				{
					dist[v] = dist[u] + arr[i].first;
					pq.push({ dist[v], v });
				}
			}
		}

		if (dist[200] == INT_MAX)
			cout << "IMPOSSIBLE\n";
		else
			cout << dist[200] << "\n";
	}
}