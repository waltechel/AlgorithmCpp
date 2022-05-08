#include <bits/stdc++.h>
using namespace std;
const double EPSILON = 1e-9;
const double INFTY = 1e200;
const double PI = 2.0 * acos(0.0);
//���ʹ� ����� �Ÿ��� ���̴�.
//�������� �߿����� �ʱ⋚���� �������� ���� x,y �� ����Ű�� ������� ǥ��

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
    //���� ���� rhs��ŭ ���̸� �÷��ش�.
    vector2 operator*(double rhs)const {
        return vector2(x * rhs, y * rhs);
    }
    // ���� ���� ��ȯ
    double norm()const {
        return hypot(x, y);
    }
    vector2 normalize() const {
        return vector2(x / norm(), y / norm());
    }
    //������ ����
    double polar()const {
        return fmod(atan2(y, x) + 2 * PI, 2 * PI);
    }
    //���� ���� ���� (inner product)
    //1. �� ������ ���̰� ���� �� �ִ�
    //2. ���� ���� ���� Ȯ���� �� �ִ�
    //3. ������ �翵 (b ���Ϳ� �������� �޺��� �� �� a�� b�� �帮��� �׸��ڸ� �翵�̶��Ѵ�)

    double dot(const vector2& rhs)const {
        return x * rhs.x + y * rhs.y;
    }
    //���� ���� ���� (cross product)
    //1.���� ����� �� �ִ� (������ ���� ���� a,b�� �� �������ϴ� ���� �纯���� ����
    //2.�� ������ ���� �Ǻ� (���� ���� ����� �ݽð� , ������ �ð���� , �����̸� 0 ��ȯ)

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
//���� �� ������ ���� ���γ��������� ������ ����� ���δ�.

//���� ������ ������ ������ �������� 1 ������Ų �� 
//���� ��ġ���Ϳ� ���⺤�͸� ���� �� ��� ������ Ž���Ͽ� �ε����� �ּ� �ð��� ã�� ������ �ݺ��Ѵ� ? 

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;

    while (T--) {

    }
}