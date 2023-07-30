#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
#include <string>

using namespace std;

double polygonArea(const vector<pair<long long, long long>>& list) {
	double area = 0;
	int n = list.size();
	for (int i = 0; i < n; i++) {
		int j = (i + 1) % n;
		area += list[i].first * list[j].second;
	}
	for (int i = 0; i < n; i++) {
		int j = (i + 1) % n;
		area -= list[j].first * list[i].second;
	}
	return abs(area) / 2.0;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	cout << fixed;
	cout.precision(1);

	int N;
	cin >> N;
	vector<pair<long long, long long>> list;
	for (int i = 0; i < N; i++) {
		long long x, y;
		cin >> x >> y;
		list.push_back({ x, y });
	}

	double idealArea = polygonArea(list);
	cout << idealArea;


    return 0;
}