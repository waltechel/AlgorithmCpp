#include<bits/stdc++.h>

using namespace std;

const int MAX_V = 1000;
int V, E;
vector<int> adj[MAX_V];
vector<bool> visited;
const int UNWATCHED = 0;
const int WATCHED = 1;
const int INSTALLED = 2;

int installed;

int dfs(int here)
{
	visited[here] = true;
	int children[3] = { 0, 0, 0 };
	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i];
		if (!visited[there])
			children[dfs(there)]++;
	}

	if (children[UNWATCHED])
	{
		installed++;
		return INSTALLED;
	}

	if (children[INSTALLED])
		return WATCHED;

	return UNWATCHED;
}

int installCamera()
{
	installed = 0;
	visited = vector<bool>(V, false);
	for (int u = 0; u < V; u++)
		if (!visited[u] && dfs(u) == UNWATCHED)
			installed++;

	return installed;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;

	for (; testCase > 0; testCase--)
	{
		cin >> V >> E;

		for (int i = 0; i < E; i++)
		{
			int u, v;
			cin >> u >> v;

			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		int ans = installCamera();

		cout << ans << "\n";

		for (int i = 0; i < MAX_V; i++)
			adj[i].clear();
	}
}