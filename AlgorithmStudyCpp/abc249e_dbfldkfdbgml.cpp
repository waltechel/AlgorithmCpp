#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
#include <string>

/*
	틀림
	문자열 압축했을 때 길이가 줄어드는 문자열이 나올 경우의 수를 P로 나누기
	문자열이 꼭 두 글자로 압축되는 것은 아니므로 안된다
	3 : 2C0 * 26
	4 : 3C0 * 26
	5 : 4C1 * 26 * 25  + 4C0 * 26
	6 : 5C1 * 26 * 25  + 5C0 * 26
	7 : 6C2 * 26 * 25 * 25 + 6C1 * 26 * 25 + 6C0 * 26
	8 : 7C2 * 26 * 25 * 25 + 7C1 * 26 * 25 + 7C0 * 26
*/
using namespace std;

int main() {
  
	long long N, P;
	cin >> N >> P;

	vector<vector<long long>> C(3001, vector<long long>(3001, 0));
	C[1][0] = 1;
	C[1][1] = 1;
	for (int i = 2; i <= 3000; i++) {
		for (int j = 0; j <= i; j++){
			if (j == 0 || i == j) {
				C[i][j] = 1;
				continue;
			}
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
			C[i][j] %= P;
		}
	}
	
	long long answer = 0;
	//3 : 2C0 * 26
	//4 : 3C0 * 26
	//5 : 4C1 * 26 * 25 + 4C0 * 26
	//6 : 5C1 * 26 * 25 + 5C0 * 26
	//7 : 6C2 * 26 * 25 * 25 + 6C1 * 26 * 25 + 6C0 * 26
	//8 : 7C2 * 26 * 25 * 25 + 7C1 * 26 * 25 + 7C0 * 26

	for (int i = (N - 1) / 2 - 1; i >= 0; i--) {
		long long value = C[N - 1][i];
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				value *= 26;
			} else {
				value *= 25;
			}
			value %= P;
		}
		answer += value;
		answer %= P;
	}

	cout << answer;

    return 0;
}