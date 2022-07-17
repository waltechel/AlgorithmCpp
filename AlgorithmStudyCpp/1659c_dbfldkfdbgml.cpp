#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
long long A[200001];
long long B[200001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for (int test = 0; test < T; test++) {
        int n, a, b;
        cin >> n >> a >> b;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
            B[i] = A[i];
        }

        for (int i = 1; i <= n; i++) {
            B[i] += B[i - 1];
        }

        // 각 점까지 수도를 이동했다고 했을 때의 최솟값을 구하기
        long long answer = (long long) 1 << 61;

        for (int i = 0; i <= n; i++) {
            long long candi = (A[i] - 0) * a;
            candi += (B[n] - B[i]) * b - A[0] * b - (n - i - 1) * A[i] * b;

            answer = min(answer, candi);
        }

        cout << answer << "\n";

    }

    return 0;
}