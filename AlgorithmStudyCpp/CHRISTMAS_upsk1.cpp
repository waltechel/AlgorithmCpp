#include <bits/stdc++.h>
using namespace std;
const long long MOD = 20091101;
//인형 상자 갯수, 어린이 수, 인형 상자안의 인형 갯수, presum, 1번답 dp
long long N, K, D[100001], psum[100001], cnt[100001];
//psum[i]%K == psum[j]%K 인 쌍을 찾는다.
long long waysToBuy() {
	long long ret = 0;
	for (int i = 0; i < K; i++) {
		if (cnt[i] > 1) {
			ret = (ret + (cnt[i] * (cnt[i] - 1)) / 2LL) % MOD;
		}
	}
	return ret;
}
//psum[i]%K == psum[j]%K 인 값을 찾고 그 값에 +1을 해준다.
long long maxBuys() {
	//ret[i] = i까지 왔을때 가진 최대 주문 수
	vector<long long> ret(N + 1, 0);
	//prev[i] = i가 psum[x]일때 가장 큰 x
	vector<long long> prev(K, -1);
	prev[0] = 0;
	for (int i = 1; i <= N; i++) {
		ret[i] = ret[i - 1];
		int loc = prev[psum[i]];
		if (loc != -1)ret[i] = max(ret[i], ret[loc] + 1);
		prev[psum[i]] = i;
	}
	return ret[N];
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		cin >> N >> K;
		long long tans = 0;
		//psum 처리를 위해 1부터 N까지 입력
		for (int i = 1; i <= N; i++) {
			cin >> D[i];
			psum[i] = (psum[i - 1] + D[i]) % K;
			//psum[i] % K 가 0이라면, 1개만으로 선물이 만족된다.
			if (psum[i] == 0)tans++;
			cnt[psum[i]]++;
		}

		cout << (waysToBuy() + tans) % MOD << ' ' << maxBuys() << '\n';
		for (int i = 0; i < K; i++)cnt[i] = 0;
	}
}