#include <bits/stdc++.h>
using namespace std;
int a[200001];
int ch[200001];
struct A {
    int pri, num;
    bool operator<(const A& p)const {
        if (pri == p.pri)return num < p.num;
        return pri < p.pri;
    }
};
priority_queue<A> pq1, pq2, pq3;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        while (!pq1.empty())pq1.pop();
        while (!pq2.empty())pq2.pop();
        while (!pq3.empty())pq3.pop();
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            ch[i] = 0;
        }
        for (int i = 2; i <= n; i++) {
            cin >> a[i];
            ch[a[i]]++;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (ch[i]) {
                pq1.push({ 1,ch[i] });
            }
        }
        pq1.push({ 1,1 });
        while (true) {
            //감염 안된게 있으면
            if (!pq1.empty()) {
                ans++;
                while (!pq2.empty()) {
                    int x = pq2.top().num;
                    pq2.pop();
                    //cout << "감염된거 뺴주기1 "<<x<<' '<<ans<<'\n';
                    x--;
                    if (x > 0)pq3.push({ 0,x });
                }
                int x = pq1.top().num;
                pq1.pop();
                //cout << "감염안된거 뺴기1 " << x << ' '<<ans<<'\n';
                x--;
                if (x > 0)pq3.push({ 0,x });
            }
            else {
                if (pq2.empty())break;
                ans++;
                int x = pq2.top().num;
                pq2.pop();
                x -= 2;
                if (x > 0)pq3.push({ 0,x });
                while (!pq2.empty()) {
                    int xx = pq2.top().num;
                    pq2.pop();
                    xx--;
                    if (xx > 0)pq3.push({ 0,xx });
                }
            }
            while (!pq3.empty()) {
                pq2.push(pq3.top());
                pq3.pop();
            }
        }
        cout << ans << '\n';
    }

}