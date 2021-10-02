#include<bits/stdc++.h>

using namespace std;

map<vector<int>, int> dist;

void precalc(int n)
{
	vector<int> perm(n);
	for (int i = 0; i < n; i++)
		perm[i] = i;

	queue<vector<int> > q;
	dist[perm] = 0;
	q.push(perm);
	int cnt = 0;
	while (!q.empty())
	{
		vector<int> here = q.front();
		q.pop();

		int cost = dist[here];

		for (int i = 0; i < n; i++)
		{
			for (int j = i + 2; j <= n; j++)
			{
				reverse(here.begin() + i, here.begin() + j);
				if (dist.count(here) == 0) // 첫 등장하는 조합
				{
					dist[here] = cost + 1;
					q.push(here);
				}
				reverse(here.begin() + i, here.begin() + j);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;

	for (int i = 1; i <= 8; i++)
	{
		precalc(i);
	}

	for (; testCase > 0; testCase--)
	{
		int n;
		cin >> n;

		// 좌표압축
		vector<pair<int, int> > arr(n);
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i].first;
			arr[i].second = i;
		}
		sort(arr.begin(), arr.end()); // value로 정렬
		for (int i = 0; i < n; i++)
		{
			arr[i].first = arr[i].second;
			arr[i].second = i; // arr[i] value -> i
		}
		sort(arr.begin(), arr.end()); // index로 정렬
		vector<int> perm(n);
		for (int i = 0; i < n; i++)
		{
			perm[i] = arr[i].second;
		}

		cout << dist[perm] << "\n";
	}
}