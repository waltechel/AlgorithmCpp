#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
int A[100000];
int B[100000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for (int test = 0; test < T; test++) {
        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        int negativeCount = 0;
        for (int i = 0; i < N; i++) {
            if (A[i] < 0) {
                negativeCount++;
            } 
        }

        for (int i = 0; i < N; i++) {
            if (negativeCount > 0) {
                if (A[i] > 0) {
                    A[i] *= -1;
                }
                negativeCount--;
            } else {
                if (A[i] < 0) {
                    A[i] *= -1;
                }
            }
        }

        /*for(int i = 0 ; i < N ; i++){
            cout << A[i] << " ";
        }
        cout << "\n";*/

        bool answer = true;
        for (int i = 0; i < N - 1; i++) {
            if (A[i] > A[i + 1]) {
                answer = false;
                break;
            }
        }

        if (answer) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }

    }

    return 0;
}