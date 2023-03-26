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
	return abs(area);
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	cout << fixed;
	cout.precision(0);

	int N;
	cin >> N;
	vector<pair<long long, long long>> list;
	for (int i = 0; i < N; i++) {
		long long x, y;
		cin >> x >> y;
		list.push_back({ x, y });
	}

	double idealArea = polygonArea(list);

	int from = 0;
	int to = 2;
	vector<pair<long long, long long>> subList(list.begin() + from, list.begin() + to + 1);
	double base = polygonArea(subList) * 4;
	double candi = base;
	while (from < N + 2) {
		if (idealArea >= base) {
			vector<pair<long long, long long>> newTriangleList;
			newTriangleList.push_back(list[from % N]);
			newTriangleList.push_back(list[to++ % N]);
			newTriangleList.push_back(list[to % N]);
			double newTriangleArea = polygonArea(newTriangleList) * 4;
			base += newTriangleArea;
		} else {
			vector<pair<long long, long long>> oldTriangleList;
			oldTriangleList.push_back(list[from++ % N]);
			oldTriangleList.push_back(list[from % N]);
			oldTriangleList.push_back(list[to % N]);
			double oldTriangleArea = polygonArea(oldTriangleList) * 4;
			base -= oldTriangleArea;
		}
		if (abs(idealArea - candi) > abs(idealArea - base)) {
			candi = base;
		}
	}

	cout << abs(idealArea - candi);

    return 0;
}