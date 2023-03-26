#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<unordered_map>
#include<set>
#include<queue>
#include<stack>
#include<unordered_set>
#include<regex>

using namespace std;

/*
	답 보니까 해시 풀이가 있어서 해시를 사용함
	정석으로는 답이 무슨 소리를 하는지 모르겠음
*/

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	unordered_set<int> A;
	unordered_set<int> B;
	vector<long long> HA;
	vector<long long> HB;

	long long MOD = 8128812800000059;
	long long ha = 0;
	for (int i = 0; i < N; i++) {
		long long a;
		cin >> a;
		if (A.find(a) == A.end()) {
			A.insert(a);
			ha += a % MOD * (a + 1346) % MOD * (a + 9187) % MOD;
			ha %= MOD;
		}
		HA.push_back(ha);
	}
	long long hb = 0;
	for (int i = 0; i < N; i++) {
		long long b;
		cin >> b;
		if (B.find(b) == B.end()) {
			B.insert(b);
			hb += b % MOD * (b + 1346) % MOD * (b + 9187) % MOD;
			hb %= MOD;
		}
		HB.push_back(hb);
	}

	int Q;
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		if (HA[x] == HB[y]) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}

	return 0;
}