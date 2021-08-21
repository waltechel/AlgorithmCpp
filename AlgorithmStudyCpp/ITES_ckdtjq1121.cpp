#include <iostream>
#include <queue>
using namespace std;

typedef long long ll;

int main()
{
	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; i++)
	{
		int k, n;
		cin >> k >> n;

		queue<ll> arr; // arrSum의 원소들
		// A[0] = 1983, A[i] = (A[i-1] * 214013 + 2531011) % 2 ^ 32  ( i != 0 )
		ll prev = 1983;
		ll next = (prev * 214013 + 2531011) % 4294967296;

		int ret = 0;
		ll arrSum = 0; // Sum(head, tail)
		int tail = 0;
		for (int head = 0; head < n; head++)
		{
			while (arrSum < k && ++tail < n)
			{
				ll input = prev % 10000 + 1; // A[i-1] % 10000 + 1
				arrSum += input; 
				arr.push(input);

				prev = next;
				next = (prev * 214013 + 2531011) % 4294967296;
			}

			if (arrSum == k)
				ret++;

			if (!arr.empty())
			{
				arrSum -= arr.front();
				arr.pop();
			}
		}

		cout << ret << "\n";
	}
}