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

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, Q;
	cin >> N >> Q;
	int* num_to_index = new int[N + 1];
	int* index_to_num = new int[N + 1];
	// 처음에는 각 자리에 각 공이 있다. 이 말이 문제에 있어야 하지 않나?
	for (int i = 1; i <= N; i++) {
		num_to_index[i] = i;
		index_to_num[i] = i;
	}

	for (int i = 0; i < Q; i++) {
		int	numOfX;
		cin >> numOfX;
		int indexOfX = num_to_index[numOfX];

		// 오른쪽의 애와 자리를 바꿔야 한다.
		int nextIndexOfX = indexOfX == N ? indexOfX - 1 : indexOfX + 1;
		int nextNumOfX = index_to_num[nextIndexOfX];

		num_to_index[nextNumOfX] = indexOfX;
		num_to_index[numOfX] = nextIndexOfX;
		index_to_num[nextIndexOfX] = numOfX;
		index_to_num[indexOfX] = nextNumOfX;

	}

	for (int i = 1; i <= N; i++) {
		cout << index_to_num[i] << " ";
	}


	return 0;
}