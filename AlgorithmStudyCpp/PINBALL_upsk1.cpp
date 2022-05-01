#include <bits/stdc++.h>
using namespace std;
int cnt[130];
bool check(string s) {
    for (int i = 'A'; i <= 'Z'; i++)cnt[i] = 0;
    for (int i = 0; i < s.size(); i++) {
        if (cnt[s[i]])return false;
        cnt[s[i]]++;
        int i2 = i + 1;
        while (i2 < s.size()) {
            if (s[i] == s[i2])i2++;
            else break;
        }
        i2--;
        i = i2;
    }
    return true;
}
string s[101];
bool c[101];
vector<string> v;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    int tc = 1;
    while (T--) {
        v.clear();
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)c[i] = false;
        for (int i = 'A'; i <= 'Z'; i++)cnt[i] = 0;
        bool flag = true;
        string ans = "";

        for (int i = 0; i < n; i++) {
            cin >> s[i];
            if (check(s[i]) == false) {
                flag = false;
            }
            v.push_back(s[i]);
        }
        if (flag == false) {
            cout << "Case #" << tc++ << ": IMPOSSIBLE\n";
            continue;
        }
        int tnum = 0;
        while (tnum < 110) {
            int idx1 = -1, idx2 = -1;
            string temp = "";
            for (int i = 0; i < v.size(); i++) {
                for (int j = 0; j < v.size(); j++) {
                    if (i == j)continue;
                    if (v[i][0] == v[j].back()) {
                        idx1 = i;
                        idx2 = j;
                        temp = v[j] + v[i];
                        break;
                    }
                    if (v[i].back() == v[j][0]) {
                        idx1 = i;
                        idx2 = j;
                        temp = v[i] + v[j];
                        break;
                    }
                }
                if (idx1 != -1)break;
            }
            if (idx1 == -1)break;
            vector<string> v2;
            for (int i = 0; i < v.size(); i++) {
                if (i == idx1 || i == idx2)continue;
                v2.push_back(v[i]);
            }
            v.clear();
            v.push_back(temp);
            for (int i = 0; i < v2.size(); i++) {
                v.push_back(v2[i]);
            }
            tnum++;
        }
        for (int i = 0; i < v.size(); i++)ans += v[i];
        //cout << ans << '\n';
        if (check(ans) == false)flag = false;
        if (flag == false) {
            cout << "Case #" << tc++ << ": IMPOSSIBLE\n";
            continue;
        }
        cout << "Case #" << tc++ << ": " << ans << '\n';
    }
}