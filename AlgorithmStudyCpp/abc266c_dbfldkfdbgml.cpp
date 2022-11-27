#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<unordered_map>
#include<set>
#include<queue>
#include<stack>
#include<unordered_set>

using namespace std;

int ccw(int x1, int y1, int x2, int y2, int x3, int y3);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int Ax, Ay, Bx, By, Cx, Cy, Dx, Dy;

	cin >> Ax >> Ay;
	cin >> Bx >> By;
	cin >> Cx >> Cy;
	cin >> Dx >> Dy;

	//1 이 나오면 시계방향
	int ccw1 = ccw(Ax, Ay, Bx, By, Cx, Cy);
	int ccw2 = ccw(Bx, By, Cx, Cy, Dx, Dy);
	int ccw3 = ccw(Cx, Cy, Dx, Dy, Ax, Ay);
	int ccw4 = ccw(Dx, Dy, Ax, Ay, Bx, By);

	if (ccw1 == 1 && ccw2 == 1 && ccw3 == 1 && ccw4 == 1) {
		cout << "Yes";
	} else {
		cout << "No";
	}

	return 0;
}

int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
	int ret = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
	if (ret > 0) {
		return 1;
	} else if (ret < 0) {
		return -1;
	} else {
		return 0;
	}
}