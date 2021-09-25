#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;
	for (; testCase > 0; testCase--)
	{
		// input
		int n;
		cin >> n;
		vector<string> arr(n);
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}

		vector<bool> vertex(26, false);
		set<pair<int, int> > dict; // edge info
		for (int i = 0; i + 1 < n; i++)
		{
			int j = 0;
			int size = min(arr[i].size(), arr[i + 1].size());
			while (j < size)
			{
				int u = arr[i][j] - 'a';
				int v = arr[i + 1][j] - 'a';

				if (u != v)
				{
					dict.insert({ u, v });

					vertex[u] = true;
					vertex[v] = true;

					break;
				}

				j++;
			}
		}

		vector<int> indegree(26, 0);
		set<pair<int, int> >::iterator iter;
		for (iter = dict.begin(); iter != dict.end(); iter++)
		{
			int v = iter->second;

			indegree[v]++;
		}

		queue<int> q;
		vector<int> order;
		for (int i = 0; i < 26; i++)
		{
			if (indegree[i] == 0 && vertex[i])
				q.push(i);
		}
		while (!q.empty())
		{
			int u = q.front();
			q.pop();

			order.push_back(u);

			for (iter = dict.begin(); iter != dict.end(); iter++)
			{
				if (iter->first == u)
				{
					int v = iter->second;

					indegree[v]--;
					if (indegree[v] == 0 && vertex[v])
						q.push(v);
				}
			}
		}

		// rest order
		for (int i = 0; i < 26; i++)
		{
			if (vertex[i] == false)
			{
				order.push_back(i);
			}
		}

		// can't be order character in cycle
		if (order.size() != 26)
		{
			cout << "INVALID HYPOTHESIS\n";
			continue;
		}

		// print
		for (int i = 0; i < order.size(); i++)
		{
			char c = order[i] + 'a';
			cout << c;
		}
		cout << "\n";
	}

	//int a = 'z';
	//cout << a - 97<< " ";
}


// cycle 이 생기면 
// INVALID HYPOTHESIS