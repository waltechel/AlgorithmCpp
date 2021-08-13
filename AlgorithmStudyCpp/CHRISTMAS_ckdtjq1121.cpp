#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
typedef long long ll;
const int MAX = 100000;
const int MOD = 20091101;

ll waysToBuy(const vector<ll>& psum, int K)
{

	ll ret = 0;
	vector<ll> count(K, 0);
	for (int i = 0; i < psum.size(); i++)
	{
		count[psum[i]]++;
	}

	for (int i = 0; i < K; i++)
	{
		if (count[i] >= 2)
			ret = (ret + count[i] * (count[i] - 1) / 2LL) % MOD;
	}

	return ret;
}

ll maxBuys(const vector<ll>& psum, int K)
{
	vector<ll> ret(psum.size(), 0);
	vector<ll> prev(K, -1);

	for (int i = 1; i < psum.size(); i++)
	{
		ret[i] = ret[i - 1];

		int loc = prev[psum[i]];
		if (loc != -1)
			ret[i] = max(ret[i], ret[loc] + 1);

		prev[psum[i]] = i;
	}
	return ret.back();
}
int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int N, K;
		cin >> N >> K;
		if (N < 1 || K < 1 || N > MAX || K > MAX)
			exit(1);

		vector<ll> v(N + 1);
		vector<ll> psum(N + 1);
		psum[0] = 0;
		ll extra = 0;
		for (int j = 1; j <= N; j++)
		{
			cin >> v[j];
			psum[j] = (psum[j - 1] + v[j]) % K;

			if (psum[i] == 0)
				extra++;
		}

		cout << (waysToBuy(psum, K) + extra) % MOD << " " << maxBuys(psum, K);
	}
}