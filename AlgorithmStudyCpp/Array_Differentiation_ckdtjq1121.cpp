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
		priority_queue<int> pq;	// �����Ϸ���..
		bool cycle = false;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			arr[i] = abs(arr[i]);

			// 0�� �ִٸ� ��
			if (arr[i] == 0)
				cycle = true;
		}

		// ��� ���� ������ pq�� �ִ´�
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

		// �Ȱ��� ���� �ִٸ� cycle�� �����Ѵ�..
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