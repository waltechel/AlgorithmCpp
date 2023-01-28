#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/*
	string은 어떻게 되어 있길래 문자열 정렬이 가능한가요?
	이게 실제로는 char [] 배열일까?
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);

	string S;

	cin >> S;
	sort(S.begin(), S.end());
	cout << S;

	return 0;
}