#include<bits/stdc++.h>

using namespace std;

vector<vector<int> > adj;

vector<int> sccId;

vector<int> discovered;

stack<int> st;
int sccCnt, vertexCnt;

int scc(int here)
{
	int ret = discovered[here] = vertexCnt++;

	st.push(here);
	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i];

		if (discovered[there] == -1)
			ret = min(ret, scc(there));
		else if (sccId[there] == -1) // 무시해야하는 교차 간선이 아닐때
			ret = min(ret, discovered[there]);
	}

	if (ret == discovered[here])
	{
		while (true)
		{
			int t = st.top();
			st.pop();
			sccId[t] = sccCnt;
			if (t == here) break;
		}
		sccCnt++;
	}

	return ret;
}

vector<int> tarjanSCC()
{
	// init
	sccId = discovered = vector<int>(adj.size(), -1);
	// init
	sccCnt = vertexCnt = 0;

	// dfs (scc) about all vertex
	for (int i = 0; i < adj.size(); i++)
		if (discovered[i] == -1)
			scc(i);

	return sccId;
}

bool disjoint(const pair<int, int>& a, const pair<int, int>& b)
{
	return a.second <= b.first || b.second <= a.first;
}

void makeGraph(const vector<pair<int, int> >& meetings)
{
	int vars = meetings.size();

	adj.clear();
	adj.resize(vars * 2);
	for (int i = 0; i < vars; i += 2)
	{
		// i or j 둘중 하나는 해야한다.
		int j = i + 1;
		adj[i * 2 + 1].push_back(j * 2);
		adj[j * 2 + 1].push_back(i * 2);
	}

	for (int i = 0; i < vars; i++)
	{
		for (int j = 0; j < i; j++)
		{
			// i 와 j가 겹칠 경우 둘중 하나만 한다.
			if (!disjoint(meetings[i], meetings[j]))
			{
				adj[i * 2].push_back(j * 2 + 1);
				adj[j * 2].push_back(i * 2 + 1);
			}
		}
	}
}

vector<int> solve2SAT()
{
	int n = adj.size() / 2;

	vector<int> label = tarjanSCC();

	for (int i = 0; i < 2 * n; i += 2)
	{
		// i와 i+1 이 같은 scc 일 경우 답이 없다.
		if (label[i] == label[i + 1])
			return vector<int>();
	}

	vector<int> value(2 * n, -1);

	// scc의 역순 정렬 == 위성 정렬 순서
	vector<pair<int, int> > order;
	for (int i = 0; i < 2 * n; i++)
		order.push_back({ -label[i], i });

	sort(order.begin(), order.end());

	for (int i = 0; i < 2 * n; i++)
	{
		int vertex = order[i].second;
		int variable = vertex / 2, isTrue = (vertex % 2 == 0);
		if (value[variable] != -1)
			continue;

		// not A가 A보다 먼저 나왓으면 A는 참
		// A가 not A보다 먼저 나왔으면 A는 거짓
		value[variable] = !isTrue;
	}
	return value;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;

	for (; testCase > 0; testCase--)
	{
		int n;
		cin >> n;
		vector<pair<int, int> > meetings(2 * n);
		for (int i = 0; i < 2 * n; i += 2)
		{
			int s1, e1, s2, e2;
			cin >> s1 >> e1 >> s2 >> e2;

			meetings[i] = { s1, e1 };
			meetings[i + 1] = { s2, e2 };
		}

		makeGraph(meetings);

		vector<int> ans = solve2SAT();
		if (ans.size())
		{
			cout << "POSSIBLE\n";
			for (int i = 0; i < ans.size(); i += 2)
			{
				if (ans[i] == 1)
					cout << meetings[i].first << " " << meetings[i].second << "\n";
				else if (ans[i + 1] == 1)
					cout << meetings[i + 1].first << " " << meetings[i + 1].second << "\n";
			}
		}
		else
			cout << "IMPOSSIBLE\n";
	}
}