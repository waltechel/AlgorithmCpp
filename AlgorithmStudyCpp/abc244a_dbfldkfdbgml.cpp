﻿#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);

	int N;
	string S;

	cin >> N;
	cin >> S;
	// string은 내부적으로는 char vector다.
	cout << S.back() << "";

	return 0;
}