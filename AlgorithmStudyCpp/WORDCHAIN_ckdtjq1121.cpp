#include<bits/stdc++.h>

using namespace std;

int n;

vector<vector<int> > adj;
vector<string> graph[26][26];
vector<int> indegree;
vector<int> outdegree;
vector<string> arr;

void makeGraph(const vector<string>& words)
{
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			graph[i][j].clear();
		}
	}

	adj = vector<vector<int> >(26, vector<int>(26, 0));
	indegree = outdegree = vector<int>(26, 0);

	for (int i = 0; i < words.size(); i++)
	{
		int u = arr[i][0] - 'a';
		int v = arr[i][arr[i].size() - 1] - 'a';

		graph[u][v].push_back(arr[i]);

		adj[u][v]++;

		outdegree[u]++;
		indegree[v]++;
	}
}

void getEulerCircuit(int here, vector<int>& circuit)
{
	for (int there = 0; there < adj.size(); there++)
	{
		while (adj[here][there] > 0)
		{
			adj[here][there]--;
			getEulerCircuit(there, circuit);
		}
	}

	circuit.push_back(here);
}

vector<int> getEulerTrailOrCircuit()
{
	vector<int> circuit;

	// �������� ������ �ٸ���� ������������ outdegree�� indegree ���� 1ũ��
	for (int i = 0; i < 26; i++)
	{
		if (outdegree[i] == indegree[i] + 1)
		{
			getEulerCircuit(i, circuit);
			return circuit;
		}
	}
	// outdegree�� 0�� �ƴ� ��� ������ ������ �ص� �ȴ�?
	for (int i = 0; i < 26; i++)
	{
		if (outdegree[i])
		{
			getEulerCircuit(i, circuit);
			return circuit;
		}
	}

	return circuit;
}

bool checkEuler()
{
	int plus = 0, minus = 0;

	for (int i = 0; i < 26; i++)
	{
		int delta = outdegree[i] - indegree[i];

		if (delta < -1 || 1 < delta)
			return false;
		if (delta == 1)
			plus++;
		if (delta == -1)
			minus++;
	}

	return (plus == 1 && minus == 1) || (plus == 0 && minus == 0);
}

string solve(const vector<string>& words)
{
	// init and input data
	makeGraph(words);

	// check condition of Euler circuit
	if (!checkEuler())
		return "IMPOSSIBLE";

	vector<int> circuit = getEulerTrailOrCircuit();

	// circuit.size()�� ��ȸ�� ����� ����, words.size()�� ��ȸ�� ������ ����
	// ��� ������ ��ȸ���� ���Ͽ�����
	if (circuit.size() != words.size() + 1)
		return "IMPOSSIBLE";
	// �Ųٷ� ����Ǿ� �ִ� ���� ����
	reverse(circuit.begin(), circuit.end());
	// ret�� words �ٿ��� return
	string ret;
	for (int i = 1; i < circuit.size(); i++)
	{
		// string [a~b]
		int a = circuit[i - 1], b = circuit[i];
		if (ret.size())
			ret += " ";
		ret += graph[a][b].back();
		graph[a][b].pop_back();
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
		cin >> n;

		arr = vector<string>(n);
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		cout << solve(arr) << "\n";
	}
}