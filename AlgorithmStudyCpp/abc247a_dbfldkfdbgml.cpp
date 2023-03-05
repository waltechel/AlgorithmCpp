#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    string S;
    cin >> S;

    cout << "0";
    for (int i = 0; i < 3; i++) {
        cout << S[i];
    }

    return 0;
}