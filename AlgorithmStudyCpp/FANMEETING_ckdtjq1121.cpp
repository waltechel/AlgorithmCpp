#include <bits/stdc++.h>

using namespace std;

//void normalize(vector<int>& c)
//{
//	c.push_back(0);
//
//	int cn = c.size();
//	for (int i = 0; i < cn; i++)
//	{
//
//		if (c[i] < 0)
//		{
//			int borrow = abs(c[i] + 9) / 10;
//			c[i + 1] -= borrow;
//			c[i] += borrow * 10;
//		}
//		else
//		{
//			c[i + 1] += c[i] / 10;
//			c[i] = c[i] % 10;
//		}
//	}
//
//	while (c.size() > 1 && c.back() == 0) c.pop_back();
//
//}

vector<int> multiply(vector<int>& a, vector<int>& b)
{
    int an = a.size(), bn = b.size();
    vector<int> c(an + bn, 0);

    for (int i = 0; i < an; i++)
        for (int j = 0; j < bn; j++)
            c[i + j] += a[i] * b[j];

    //normalize(c);

    return c;
}

void addFun(vector<int>& a, vector<int>& b, int start)
{
    int an = a.size();
    int bn = b.size();
    int length = bn;
    a.resize(max(an, bn + start));

    for (int i = 0; i < length; i++)
        a[i + start] += b[i];

    //normalize(a);
}

void subFun(vector<int>& a, vector<int>& b)
{
    int an = a.size();
    int bn = b.size();
    int length = bn;
    a.resize(max(an, bn + 1));

    for (int i = 0; i < length; i++)
        a[i] -= b[i];

    //normalize(a);
}

vector<int> karatsuba(vector<int>& a, vector<int>& b)
{
    int an = a.size(), bn = b.size();

    if (an < bn)
        return karatsuba(b, a);
    if (an == 0 || bn == 0)
        return vector<int>();
    if (an <= 100)
        return multiply(a, b);

    int half = an / 2;
    vector<int> a0(a.begin(), a.begin() + half);
    vector<int> a1(a.begin() + half, a.end());
    vector<int> b0(b.begin(), b.begin() + min(bn, half));
    vector<int> b1(b.begin() + min(bn, half), b.end());

    vector<int> z2 = karatsuba(a1, b1);
    vector<int> z0 = karatsuba(a0, b0);

    addFun(a0, a1, 0), addFun(b0, b1, 0);
    vector<int> z1 = karatsuba(a0, b0);
    subFun(z1, z0), subFun(z1, z2);

    vector<int> ret;
    addFun(ret, z0, 0);
    addFun(ret, z1, half);
    addFun(ret, z2, half + half);

    return ret;
}

int solve(const string& members, const string& fans)
{
    int n = members.size(), m = fans.size();
    vector<int> a(n), b(m);

    for (int i = 0; i < n; i++)
        a[i] = (members[i] == 'M');
    for (int i = 0; i < m; i++)
        b[m - 1 - i] = (fans[i] == 'M');

    vector<int> c = karatsuba(a, b);

    int ret = 0;
    // 모든 멤버가 같이 허그를 하고 있어야 함
    for (int i = n - 1; i < m; i++)
    {
        if (c[i] == 0)
            ret++;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCase;
    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        string members, fans;
        cin >> members >> fans;

        cout << solve(members, fans) << "\n";
    }
}