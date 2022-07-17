    #include <bits/stdc++.h>
    using namespace std;
     
    int main() {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        int T;
        cin >> T;
        while (T--) {
            int n, a, b;
            cin >> n >> a >> b;
            while (b) {
                if (a == b) {
                    for (int i = 0; i < a; i++)cout << "RB";
                    a = 0; b = 0;
                    break;
                }
                else {
                    int div = a / (b + 1);
                    if (a % (b + 1))div++;
                    for (int i = 0; i < div; i++)cout << "R";
                    cout << "B";
                    a -= div;
                    b--;
                }
            }
            if (a) {
                for (int i = 0; i < a; i++)cout << "R";
            }
            cout << '\n';
        }
     
    }