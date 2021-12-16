#include<bits/stdc++.h>

using namespace std;
const int INF = 987654321;

int seq[101];
int dp[101][11];
int psum[101];
int psqsum[101];
int n, s;

// A[begin] .. A[end]
int minSquaresOfError(int begin, int end)
{

	int sum = psum[end] - ((begin == 0) ? 0 : psum[begin - 1]);
	int squsum = psqsum[end] - ((begin == 0) ? 0 : psqsum[begin - 1]);
	int avg = (int)(0.5 + (double)sum / (end - begin + 1));

	int ret = squsum - 2 * avg * sum + avg * avg * (end - begin + 1);

	return ret;
}

int sector(int begin, int div)
{
	if (begin == n)
		return 0;

	if (div == 0)
		return INF;

	int& ret = dp[begin][div];
	if (ret != -1)
		return ret;

	ret = INF;
	for (int next = begin + 1; next <= n; next++)
	{
		// sector from i + sector i to div-1
		ret = min(ret, sector(next, div - 1) + minSquaresOfError(begin, next - 1));
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
		cin >> n >> s;

		for (int i = 0; i < n; i++)
		{
			cin >> seq[i];
		}
		sort(seq, seq + n);

		psum[0] = seq[0];
		psqsum[0] = seq[0] * seq[0];
		for (int i = 1; i < n; i++)
		{
			psum[i] = psum[i - 1] + seq[i];
			psqsum[i] = psqsum[i - 1] + seq[i] * seq[i];
		}

		memset(dp, -1, sizeof(dp));

		cout << sector(0, s) << '\n';
	}
}