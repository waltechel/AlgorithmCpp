#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
#include <string>
#include <unordered_set>
#include <set>

using namespace std;

/*
	합 중의 A의 배수 합 빼고, B의 배수 합 빼고, A, B의 공배수 합 더하면 된다.
*/
long long gcd(int a, int b) {
	if (a % b == 0) {
		return b;
	} else {
		return gcd(b, a % b);
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long N, A, B;
	cin >> N >> A >> B;

	long long sum = N * (N + 1) / 2;
	long long Asum = (N / A) * ((N / A) + 1) / 2 * A;
	long long Bsum = (N / B) * ((N / B) + 1) / 2 * B;
	long long ABsum = (N / (A * B / gcd(A, B))) * ((N / (A * B / gcd(A, B))) + 1) / 2 * (A * B / gcd(A, B));
	cout << sum - Asum - Bsum + ABsum;
	
	return 0;
}