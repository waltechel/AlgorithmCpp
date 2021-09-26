#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;

	for (; testCase > 0; testCase--)
	{
		int n;
		cin >> n;

		int sum = 0;
		vector<int> arr(n);
		priority_queue<int> pq;	// 정렬하려고..
		bool cycle = false;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			arr[i] = abs(arr[i]);

			// 0이 있다면 끝
			if (arr[i] == 0)
				cycle = true;
		}

		// 모든 합의 조합을 pq에 넣는다
		for (int i = 1; i < (1 << n); i++)
		{
			int a = 0;
			for (int j = 0; j < n; j++)
			{
				if (i & (1 << j))
					a += arr[j];
			}

			pq.push(a);
		}

		// 똑같은 값이 있다면 cycle이 존재한다..
		int prev = pq.top();
		pq.pop();
		while (!pq.empty())
		{
			int next = pq.top();
			pq.pop();

			if (prev == next)
			{
				cycle = true;
				break;
			}

			prev = next;
		}

		if (cycle)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}