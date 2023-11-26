#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> countTree;

void update(int i, int n) {
    countTree[i] = n;
    i /= 2;
    while (i > 0) {
        countTree[i] = countTree[i * 2] + countTree[i * 2 + 1];
        i /= 2;
    }
}

long long sum(int from, int to) {
    long long ret = 0;
    while (from <= to) {
        if (from % 2 == 1) {
            ret += countTree[from++];
        }
        if (to % 2 == 0) {
            ret += countTree[to--];
        }
        from /= 2;
        to /= 2;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int test = 0; test < T; test++) {
        int N;
        cin >> N;

        vector<pair<int, int>> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i].first >> A[i].second;
        }

        sort(A.begin(), A.end(), [](const auto& a, const auto& b) {
            if (a.first != b.first) {
                return (a.first - b.first) > 0;
            } else {
                return a.second < b.second;
            }
            });

        vector<int> B;
        for (const auto& a : A) {
            B.push_back(a.second);
        }

        sort(B.begin(), B.end());
        B.erase(unique(B.begin(), B.end()), B.end());

        map<int, int> C;
        for (int i = 0; i < B.size(); i++) {
            C[B[i]] = i + 1;
        }

        int size = 1;
        while (size < N) {
            size *= 2;
        }
        int start = size;
        size *= 2;

        // Initialize countTree with zeros
        countTree = vector<int>(size, 0);

        for (const auto& a : A) {
            int index = C[a.second];
            update(start + index, countTree[start + index] + 1);
        }

        long long answer = 0;
        for (const auto& a : A) {
            int index = C[a.second];
            update(start + index, countTree[start + index] - 1);
            answer += sum(start + index, size - 1);
        }

        cout << answer << "\n";
    }

    return 0;
}
