#include <bits/stdc++.h>
using namespace std;
const double EPSILON = 1e-9;
const double INFTY = 1e200;
const double PI = 2.0 * acos(0.0);
//벡터는 방향과 거리의 쌍이다.
//시작점이 중요하지 않기떄문에 원점으로 부터 x,y 를 가르키는 방식으로 표현

struct vector2 {
    double x, y;
    explicit vector2(double x_ = 0, double y_ = 0) :x(x_), y(y_) {}
    bool operator==(const vector2& rhs)const {
        return x == rhs.x && y == rhs.y;
    }
    bool operator<(const vector2& rhs)const {
        return x != rhs.x ? x < rhs.x : y < rhs.y;
    }
    vector2 operator+(const vector2& rhs)const {
        return vector2(x + rhs.x, y + rhs.y);
    }
    vector2 operator-(const vector2& rhs)const {
        return vector2(x - rhs.x, y - rhs.y);
    }
    //벡터 곱은 rhs만큼 길이를 늘려준다.
    vector2 operator*(double rhs)const {
        return vector2(x * rhs, y * rhs);
    }
    // 벡터 길이 반환
    double norm()const {
        return hypot(x, y);
    }
    vector2 normalize() const {
        return vector2(x / norm(), y / norm());
    }
    //벡터의 각도
    double polar()const {
        return fmod(atan2(y, x) + 2 * PI, 2 * PI);
    }
    //벡터 내적 구현 (inner product)
    //1. 두 벡터의 사이각 구할 수 있다
    //2. 벡터 직각 여부 확인할 수 있다
    //3. 벡터의 사영 (b 벡터에 수직으로 햇빛을 쬘 떄 a가 b에 드리우는 그림자를 사영이라한다)

    double dot(const vector2& rhs)const {
        return x * rhs.x + y * rhs.y;
    }
    //벡터 외적 구현 (cross product)
    //1.면적 계산할 수 있다 (외적의 절대 값은 a,b를 두 변으로하는 평행 사변형의 넓이
    //2.두 벡터의 방향 판별 (외적 값이 양수면 반시계 , 음수면 시계방향 , 평행이면 0 반환)

    double cross(const vector2& rhs)const {
        return x * rhs.y - rhs.x * y;
    }
    vector2 project(const vector2& rhs)const {
        vector2 r = rhs.normalize();
        return r * r.dot(*this);
    }
};
double ccw(vector2 a, vector2 b) {
    return a.cross(b);
}
//이후 두 선분의 교차 여부내용이지만 아직은 어려워 보인다.

//공을 제외한 나머지 원들의 반지름을 1 증가시킨 후 
//공의 위치벡터와 방향벡터를 구한 후 모든 원들을 탐색하여 부딪히는 최소 시간을 찾는 과정을 반복한다 ? 

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;

    while (T--) {

    }
}