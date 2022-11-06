#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<queue>

using namespace std;

int main() {

	int N;
	cin >> N;
	int* P = new int[N + 1];
	for (int i = 1; i <= N; i++) {
		cin >> P[i];
	}
	// 버블 소트 잘 하면 A 연산으로 충분히 값이 갈 것 같다.
	// N^2이 되니까 400 * 400 하면 160000 이므로 안되겠다....

	queue<string> answers;
	for (int i = 1; i <= N; i++) {
		int minValue = 500;
		int minIndex = i;

		// 가장 앞에 있는 애를 찾기
		for (int k = i; k <= N; k++) {
			if (minValue > P[k]) {
				minValue = P[k];
				minIndex = k;
			}
		}

		while (minIndex != i) {
			if (minIndex - 2 >= i) {
				string line = "B " + to_string(minIndex - 2);
				answers.push(line);
				int temp = P[minIndex];
				P[minIndex] = P[minIndex - 2];
				P[minIndex - 2] = temp;
				minIndex -= 2;
			} else if (minIndex - 1 >= i) {
				string line = "A " + to_string(minIndex - 1);
				answers.push(line);
				int temp = P[minIndex];
				P[minIndex] = P[minIndex - 1];
				P[minIndex - 1] = temp;
				minIndex -= 1;
			}
		}

	}

	cout << answers.size() << "\n";
	while (!answers.empty()) {
		string line = answers.front();
		answers.pop();
		cout << line << "\n";
	}

	return 0;
}

