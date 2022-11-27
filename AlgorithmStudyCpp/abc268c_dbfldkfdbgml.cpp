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

using namespace std;

// 몇 칸 이동했을 때 얘가 재미를 보는지 계산한다.

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;
	int* A = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	int* answerA = new int[N];
	for (int i = 0; i < N; i++) {
		answerA[i] = 0;
	}

	for (int i = 0; i < N; i++) {
		// i번째 사람은 A[i] 음식을 가지고 있다. 
		// 이 사람이 행복하려면 A[i] 음식의 수가 가리키는 사람까지 이동을 시켜야 한다.
		// 그리고 move 전후로 -1, +1 까지는 재미를 볼 수 있다.
		int move = (A[i] - i + N) % N;
		answerA[move]++;
		answerA[(move + 1) % N]++;
		answerA[(move + N - 1) % N]++;
	}

	int answer = 0;
	for (int i = 0; i < N; i++) {
		answer = max(answer, answerA[i]);
	}

	cout << answer;

	return 0;
}