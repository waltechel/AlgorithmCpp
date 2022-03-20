#include <bits/stdc++.h>
using namespace std;
int ans;
int n, m;
vector<int> canEat[51], eater[51];
void search(vector<int> edible, int chosen) {
    if (ans <= chosen)return;
    int first = 0;
    while (first < n && edible[first] != 0)first++;
    if (first == n) {
        ans = chosen;
        return;
    }
    for (int i = 0; i < canEat[first].size(); i++) {
        int food = canEat[first][i];
        for (int j = 0; j < eater[food].size(); j++)edible[eater[food][j]]++;
        search(edible, chosen + 1);
        for (int j = 0; j < eater[food].size(); j++)edible[eater[food][j]]--;
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        //√ ±‚»≠
        for (int i = 0; i < n; i++)canEat[i].clear();
        for (int i = 0; i < m; i++)eater[i].clear();
        ans = m;

        map<string, int> index;
        for (int i = 0; i < n; i++) {
            string temp;
            cin >> temp;
            index[temp] = i;
        }
        for (int i = 0; i < m; i++) {
            int t;
            cin >> t;
            for (int j = 0; j < t; j++) {
                string temp;
                cin >> temp;
                eater[i].push_back(index[temp]);
                canEat[index[temp]].push_back(i);
            }
        }
        vector<int> edible(n, 0);
        search(edible, 0);
        cout << ans << '\n';
    }
}