#include <stdio.h>
//     9  8  7  6  5  4  3  2  1  0  (switch no)
// n = xx xx xx xx xx xx xx xx xx xx (base 2)
inline int val(int n, int no) { // switch number
    return (n >> (no << 1)) & 3;
}
inline int sum(int n) {
    int sum = 0;
    for(int i = 0; i < 10; i++) {
        sum += (n >> (i << 1)) & 3;
    }
    return sum;
}
int main() {
    int t; scanf("%d", &t);
    while(t--) {
        int a[16], x[16];
        int min = -1;
        // 12 -> 0, 3 -> 1, 6 -> 2, 9 -> 3
        for(auto &i : a) { scanf("%d", &i); i %= 12; i /= 3; }

        // Goal: Make all x[i] == 0.
        for(int i = 0; i < (1 << 20); i++) {
            x[0] = (a[0] + val(i, 0) + val(i, 3) + val(i, 5)) & 3;
            x[1] = (a[1] + val(i, 0) + val(i, 8)) % 4;
            x[2] = (a[2] + val(i, 0) + val(i, 5) + val(i, 8)) & 3;
            x[3] = (a[3] + val(i, 1) + val(i, 6) + val(i, 8) + val(i, 9)) & 3;
            x[4] = (a[4] + val(i, 2) + val(i, 3) + val(i, 7) + val(i, 8) + val(i, 9)) & 3;
            x[5] = (a[5] + val(i, 3) + val(i, 7) + val(i, 8) + val(i, 9)) & 3;
            x[6] = (a[6] + val(i, 3) + val(i, 4)) & 3;
            x[7] = (a[7] + val(i, 1) + val(i, 3) + val(i, 4) + val(i, 7)) & 3;
            x[8] = (a[8] + val(i, 4)) & 3;
            x[9] = (a[9] + val(i, 1) + val(i, 9)) & 3;
            x[10] = (a[10] + val(i, 2) + val(i, 4)) & 3;
            x[11] = (a[11] + val(i, 1)) & 3;
            x[12] = (a[12] + val(i, 4)) & 3;
            x[13] = (a[13] + val(i, 9)) & 3;
            x[14] = (a[14] + val(i, 2) + val(i, 5) + val(i, 6) + val(i, 7)) & 3;
            x[15] = (a[15] + val(i, 2) + val(i, 5) + val(i, 6) + val(i, 7)) & 3;

            bool flag = false;
            for(auto now : x) {
                if(now) { flag = true; break; }
            }
            if(flag) continue;
            int const val = sum(i);
            if(min == -1 || val < min) min = val;
        }
        printf("%d\n", min);
    }
}