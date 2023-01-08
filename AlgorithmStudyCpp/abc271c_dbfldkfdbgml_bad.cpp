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

// 7 
// 1 2 3 3 3 4 5


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	deque<long long> deck;
	for (int i = 0; i < N; i++) {
		long long temp;
		cin >> temp;
		deck.push_back(temp);
	}
	sort(deck.begin(), deck.end());

	long long now = 0;
	while (!deck.empty()) {
		long long next = deck.front();
		if (now == next) {
			deck.pop_front();
			next = 1000000001;
			deck.push_back(next);
			continue;
		}

		if (now + 1 == next) {
			now = next;
			deck.pop_front();
			continue;
		}

		if (deck.size() >= 2) {
			deck.pop_back();
			deck.pop_back();
			now = now + 1;
		} else {
			break;
		}
	}

	cout << now;


	return 0;
}