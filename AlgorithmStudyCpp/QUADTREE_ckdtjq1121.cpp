#include <bits/stdc++.h>

using namespace std;

string s;
int i = 0;
string flip()
{

    vector<string> ret;

    for (; i < s.size(); i++)
    {
        string tmp;
        if (s[i] == 'x')
        {
            i++;
            tmp = 'x';
            tmp += flip();
            ret.push_back(tmp);
        }
        else
        {
            tmp = s[i];
            ret.push_back(tmp);
        }

        if (ret.size() == 4)
            break;
    }
    // for(int j = 0; j < ret.size(); j++)
    // {
    //     cout << j << " " << ret[j] << "\n";
    // }
    // cout << "\n"; 

    // 1 2 3 4 -> 3 4 1 2
    if (ret.size() == 1)
        return ret[0];
    else
        return ret[2] + ret[3] + ret[0] + ret[1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCase;
    cin >> testCase;

    while (testCase--)
    {
        i = 0;

        cin >> s;

        cout << flip() << "\n";
    }
}