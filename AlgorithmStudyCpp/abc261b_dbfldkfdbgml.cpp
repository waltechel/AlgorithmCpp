#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<set>

using namespace std;

/*
	1. 템플릿이어서 map이라는 이름의 변수를 사용할 수 있다.
	2. inline이 컴파일러에게 최적화하라고 힌트를 주는 것일 뿐이다.
	3. C++은 정적 타입 언어로 타입이 결정된 후 컴파일된다.
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	auto map = new string[N];
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}

	bool flag = true;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) {
				if (map[i][j] != '-') {
					flag = false;
				}
			} else {
				if (map[i][j] == 'D' && map[j][i] != 'D') {
					flag = false;
				}
				if (map[i][j] == 'W' && map[j][i] != 'L') {
					flag = false;
				}
				if (map[i][j] == 'L' && map[j][i] != 'W') {
					flag = false;
				}
			}

		}
	}

	if (flag) {
		cout << "correct";
	} else {
		cout << "incorrect";
	}

	return 0;
}

