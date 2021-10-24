#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

const int MAX_VALUE = 2000000000;

int* parent;
int find(int now);
void merge(int a, int b);
double dist(pair<int, int> a, pair<int, int> b);

struct Edge {
	int a;
	int b;
	double cost;
};

bool comparator(const Edge a, const Edge b) {
	return a.cost < b.cost;
}

int main() {

	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int test_case = 0; test_case < T; test_case++) {
		int N, M;

		cin >> N >> M;
		
		vector<pair<int, int>> A;
		for (int i = 0; i < N; i++) {
			int x;
			cin >> x;
			A.push_back(make_pair(x, 0));
		}
		for (int i = 0; i < N; i++) {
			int y;
			cin >> y;
			A[i].second = y;
		}

		// 기존에 매설된 간선은 그냥 넣는다.
		parent = new int[N];
		for (int i = 0; i < N; i++) {
			parent[i] = i;
		}
		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;
			if (find(a) != find(b)) {
				merge(a, b);
			}
		}

		//크루스칼로 소스 돌린다. 그러면 맞는다 ㅠㅠ
		vector<Edge> edgeList;
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				if (find(i) != find(j)) {
					Edge e;
					e.a = i;
					e.b = j;
					e.cost = dist(A[i], A[j]);
					edgeList.push_back(e);
				}
			}
		}
		sort(edgeList.begin(), edgeList.end(), comparator);

		double answer = 0.0;
		for (int i = 0; i < edgeList.size(); i++) {
			Edge e = edgeList[i];
			int a = e.a;
			int b = e.b;
			double cost = sqrt(e.cost);
			if (find(a) != find(b)) {
				merge(a, b);
				answer += cost;
			}
		}

		// 소수 10자리까지 fixed
		cout.setf(ios::fixed);
		cout.precision(10);
		cout << answer << "\n";

	}

	return 0;
}


void merge(int a, int b) {
	int rootA = find(a);
	int rootB = find(b);
	if (rootA < rootB) {
		parent[rootB] = rootA;
	} else {
		parent[rootA] = rootB;
	}
}

int find(int now) {
	if (parent[now] == now) {
		return now;
	} else {
		return parent[now] = find(parent[now]);
	}
}

double dist(pair<int, int> a, pair<int, int> b) {
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}
