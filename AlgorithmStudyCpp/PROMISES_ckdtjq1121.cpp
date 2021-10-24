#include <bits/stdc++.h>

using namespace std;

int v, m, n;
vector<vector<int>> dist;
bool update(int a, int b, int c)
{
	if (dist[a][b] <= c)
		return false;

	for (int i = 0; i < v; i++)
		for (int j = 0; j < v; j++)
			dist[i][j] = min(dist[i][j],
				min(dist[i][a] + c + dist[b][j], dist[i][b] + c + dist[a][j]));

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;

	while (testCase--)
	{
		cin >> v >> m >> n;

		dist = vector<vector<int> >(v, vector<int>(v, INT_MAX / 4));
		for (int i = 0; i < v; i++)
			dist[i][i] = 0;

		for (int i = 0; i < m; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			// problem is bad
			dist[a][b] = min(dist[a][b], c);
			dist[b][a] = min(dist[b][a], c);
		}

		for (int k = 0; k < v; k++)
			for (int i = 0; i < v; i++)
				for (int j = 0; j < v; j++)
					if (dist[i][j] > dist[i][k] + dist[k][j])
						dist[i][j] = dist[i][k] + dist[k][j];

		int ans = 0;
		for (int l = 0; l < n; l++)
		{
			int a, b, c;
			cin >> a >> b >> c;

			if (!update(a, b, c))
				ans++;
		}
		cout << ans << "\n";
	}
}