#include<bits/stdc++.h>

using namespace std;

int N, M;

struct BipartiteUnionFind {
	vector<int> parent, rank, enemy, size;
	BipartiteUnionFind(int n) : parent(n), rank(n, 0), enemy(n, -1), size(n, 1) {
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}

	int find(int u)
	{
		if (parent[u] == u)
			return u;
		return parent[u] = find(parent[u]);
	}
	int merge(int u, int v)
	{
		if (u == -1 || v == -1) return max(u, v);

		u = find(u), v = find(v);

		if (u == v) return u;

		if (rank[u] > rank[v]) swap(u, v);

		if (rank[u] == rank[v]) rank[v]++;

		parent[u] = v;
		size[v] += size[u];
		return v;
	}

	bool dis(int u, int v)
	{
		u = find(u), v = find(v);

		if (u == v) return false;

		int a = merge(u, enemy[v]), b = merge(v, enemy[u]);
		enemy[a] = b;
		enemy[b] = a;
		return true;
	}

	bool ack(int u, int v)
	{
		u = find(u), v = find(v);

		if (enemy[u] == v) return false;

		int a = merge(u, v), b = merge(enemy[u], enemy[v]);
		enemy[a] = b;

		if (b != -1)
			enemy[b] = a;

		return true;
	}
};

int maxParty(const BipartiteUnionFind& buf)
{
	int ret = 0;
	for (int node = 0; node < N; node++)
	{
		if (buf.parent[node] == node) // 루트 노드만
		{
			int enemy = buf.enemy[node];

			// node 와  enemy의 관계를 한번만 계산하기 위해서
			if (enemy > node) continue;

			int mySize = buf.size[node];
			int enemySize = (enemy == -1 ? 0 : buf.size[enemy]);

			ret += max(mySize, enemySize);
		}
	}

	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;

	for (; testCase > 0; testCase--)
	{
		cin >> N >> M;

		BipartiteUnionFind buf(N);

		bool contradict = false; //모순
		int num = -1;

		for (int i = 0; i < M; i++)
		{
			string s;
			int node1, node2;

			cin >> s >> node1 >> node2;

			if (contradict)
				continue;


			if (s == "ACK")
			{
				if (!buf.ack(node1, node2)) //모순 발생할 경우
				{
					contradict = true;
					num = i + 1;
				}
			}

			else
			{
				if (!buf.dis(node1, node2)) //모순 발생할 경우
				{
					contradict = true;
					num = i + 1;
				}
			}
		}

		if (contradict)
			cout << "CONTRADICTION AT " << num << "\n";
		else
			cout << "MAX PARTY SIZE IS " << maxParty(buf) << "\n";
	}
}