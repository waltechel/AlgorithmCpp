#include <bits/stdc++.h>
using namespace std;
struct A {
    int num, a, b;
};

vector<A> route1, route2;
bool compare(const A a, const A b) {
    if (a.a == b.a)return a.b > b.b;
    return a.a < b.a;
}
bool check[500001];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    long long minA = INT64_MAX, maxB = INT64_MIN;
    for (int i = 0; i < m; i++) {
        long long a, b;
        cin >> a >> b;
        A bus;
        bus.num = i; bus.a = a; bus.b = b;
        if (a < b) {
            route1.push_back(bus);
        }
        else {
            minA = min(minA, a);
            maxB = max(maxB, b);
            bus.b = b + n;
            route2.push_back(bus);
        }
        check[i] = true;
    }
    //case 1: 일반적인 a<b 노선
    sort(route1.begin(), route1.end(), compare);
    sort(route2.begin(), route2.end(), compare);
    int r = 0;
    for (int i = 0; i < route1.size(); i++) {
        if (minA <= route1[i].a)check[route1[i].num] = false;
        if (maxB >= route1[i].b)check[route1[i].num] = false;

        if (route1[i].b <= r)check[route1[i].num] = false;
        r = max(r, route1[i].b);
    }
    r = 0;
    for (int i = 0; i < route2.size(); i++) {
        if (route2[i].b <= r)check[route2[i].num] = false;
        r = max(r, route2[i].b);
    }
    for (int i = 0; i < m; i++) {
        if (check[i])cout << i + 1 << ' ';
    }

}