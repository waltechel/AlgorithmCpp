#include<iostream>
using namespace std;
typedef long long ll;

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n, k;
		cin >> n >> k;
		ll* presentBox = (ll*)malloc(n * sizeof(ll));
		ll* partSum = (ll*)malloc(n * sizeof(ll));	// 인형의 상자까지의 부분합
		ll* theRestCount = (ll*)malloc(k * sizeof(ll));	// 나머지의 개수
		for (int j = 0; j < n; j++)
		{
			theRestCount[j] = 0;
		}

		for (int j = 0; j < n; j++)
		{
			cin >> presentBox[j];
			if (j == 0)
			{
				partSum[j] = presentBox[j];
			}
			else
			{
				partSum[j] = partSum[j - 1] + presentBox[j];
			}

			partSum[j] = partSum[j] % k;

			theRestCount[partSum[j]]++;
		}

		ll result_first = 0;
		ll result_second = -1; // 구현 X
		for (int j = 0; j < k; j++)
		{
			result_first += theRestCount[j] * (theRestCount[j] - 1) / 2;
			result_first %= 20091101;
		}

		cout << result_first << " " << result_second;

	}
}