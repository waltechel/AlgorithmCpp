#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
//과목 , 선수 과목, 학기, 한학기 최대과목
int N, K, M, L;
//선수 과목
int prerequisite[12];
//학기
int classes[10];
//메모리제이션 cache[i][j] = i학기에 j과목까지 수강했을때 졸업할 수 있는 최소 학기
int cache[10][1 << 12];
//n에 포함된 비트의 1의 갯수
int bitCount(int n) {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		if (n & (1 << i))ret++;
	}
	return ret;
}
int graduate(int semester, int taken) {
	//이미 K개 이상의 과목을 수강했을 때
	if (bitCount(taken) >= K)return 0;
	//마지막 학기를 넘었을때
	if (semester == M)return INF;
	int& ret = cache[semester][taken];
	if (ret != -1)return ret;
	ret = INF;
	//해당 학기에, 수강할 수 있는 과목
	int canTake = (classes[semester] & ~taken);
	for (int i = 0; i < N; i++) {
		// 선수 과목이 안된 것 제외
		if ((canTake & (1 << i)) && (taken & prerequisite[i]) != prerequisite[i])canTake &= ~(1 << i);
	}

	for (int take = canTake; take > 0; take = ((take - 1) & canTake)) {
		if (bitCount(take) > L)continue;
		ret = min(ret, graduate(semester + 1, taken | take) + 1);
	}
	ret = min(ret, graduate(semester + 1, taken));
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		cin >> N >> K >> M >> L;
		int j2 = (1 << N);
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < j2; j++) {
				cache[i][j] = -1;
			}
		}
		// 선수 과목에 비트로 입력값 추가
		for (int i = 0; i < N; i++) {
			int num;
			cin >> num;
			while (num--) {
				int t;
				cin >> t;
				prerequisite[i] |= (1 << t);
			}
		}
		// 해당 학기에 비트로 입력값 추가
		for (int i = 0; i < M; i++) {
			int num;
			cin >> num;
			while (num--) {
				int t;
				cin >> t;
				classes[i] |= (1 << t);
			}
		}
		if (graduate(0, 0) >= INF)cout << "IMPOSSIBLE\n";
		else cout << graduate(0, 0) << '\n';
		for (int i = 0; i < N; i++)prerequisite[i] = 0;
		for (int i = 0; i < M; i++)classes[i] = 0;
	}
}