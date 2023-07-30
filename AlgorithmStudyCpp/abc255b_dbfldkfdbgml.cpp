#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
#include <string>
#include <unordered_set>
#include <set>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int N, K;
	cin >> N >> K;
	
	set<int> listLight;
	for (int i = 0; i < K; i++) {
		int temp;
		cin >> temp;
		listLight.insert(temp);
	}

	vector<pair<int, int>> A;
	vector<pair<int, int>> B;
	for (int i = 1; i <= N; i++) {
		int x, y;
		cin >> x >> y;
		if (listLight.find(i) == listLight.end()) {
			A.push_back({ x, y });
		} else {
			B.push_back({ x, y });
		}
	}

	double answer = 0;
	for (pair<int, int> pointA : A) {
		double candi = (double) 100000000000000000l;
		for (pair<int, int> pointB : B) {
			candi = min(candi, sqrt( 
			(long long)	(pointA.first  - pointB.first ) * (pointA.first - pointB.first) +
			(long long) (pointA.second - pointB.second) * (pointA.second - pointB.second)
			));
		}
		answer = max(answer, candi);
	}
	cout << fixed << setprecision(10) << answer << endl;

	return 0;
}