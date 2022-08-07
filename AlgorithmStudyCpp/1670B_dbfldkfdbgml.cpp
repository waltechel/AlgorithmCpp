#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for (int test = 0; test < T; test++) {
        int N;
        cin >> N;

        string s;
        cin >> s;

        int K;
        cin >> K;

        bool names[26];
        for (int i = 0; i < 26; i++) {
            names[i] = false;
        }

        for (int i = 0; i < K; i++) {
            char t;
            cin >> t;
            names[(int)(t - 'a')] = true;
        }

        for (int i = 0; i < N; i++) {
            char t = s[i];
            if (names[(int)(t - 'a')] == true) {
                s[i] = '1';
            } else {
                s[i] = '0';
            }
        }

        int answer = 0;
        for (int i = N - 1; i >= 1; i--) {
            if (s[i] == '1') {
                int l = i;
                for (int j = i - 1; j >= 1; j--) {
                    if (s[j] == '0') {
                        l = j;
                    } else {
                        break;
                    }
                }
                int length = i - l + 1;
                answer = max(answer, length);
            }
        }

        cout << answer << "\n";
    }

    return 0;
}