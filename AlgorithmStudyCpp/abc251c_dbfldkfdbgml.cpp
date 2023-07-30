#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed;
	cout.precision(0);

	int N;
	cin >> N;

	unordered_map<string, pair<int, int>> map;

	for (int i = 1; i <= N; i++) {
		string submission;
		int score;
		cin >> submission >> score;
		if (map.find(submission) == map.end()) {
			map.insert({ submission, {score , i} });
		}
	}

	int bestScore = -1;
	int bestSubmissionIndex = 100000000;
	for (auto entry : map) {
		string submission = entry.first;
		pair<int, int> scorePair = entry.second;

		if (scorePair.first == bestScore && bestSubmissionIndex > scorePair.second) {
			bestScore = scorePair.first;
			bestSubmissionIndex = scorePair.second;
		}

		if (scorePair.first > bestScore) {
			bestScore = scorePair.first;
			bestSubmissionIndex = scorePair.second;
		}
	}

	cout << bestSubmissionIndex;

	return 0;
}