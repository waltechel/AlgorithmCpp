#include <iostream>
using namespace std;
double dfs(double **arr, int *cycle, int n, int cur) {
    if(cur == n) {
        double res = 0;
        for(int i = 1; i < n; i++) {
            res += arr[cycle[i - 1]][cycle[i]];
        }
        return res;
    }

    // do not visit already visited points.
    int visited = 0;
    for(int i = 0; i < cur; i++) {
        visited |= (1 << cycle[i]);
    }

    // visit new points.
    double min = 1e10;
    for(int i = 0; i < n; i++) {
        if(visited & (1 << i)) continue;
        cycle[cur] = i;
        // iterate.
        double const val = dfs(arr, cycle, n, cur + 1);
        if(min > val) min = val;
    }

    return min;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cout << fixed;
    cout.precision(10);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;

        // input
        auto arr = new double*[n];
        for(int i = 0; i < n; i++) {
            arr[i] = new double[n];
            for(int j = 0; j < n; j++) cin >> arr[i][j];
        }

        auto cycle = new int[n + 1];
        cout << dfs(arr, cycle, n, 0) << '\n';
        for(int i = 0; i < n; i++) delete[] arr[i];
        delete[] arr;
        delete[] cycle;
    }
}