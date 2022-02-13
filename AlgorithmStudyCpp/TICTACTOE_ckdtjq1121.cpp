#include <bits/stdc++.h>

using namespace std;

// ���� ƽ���� ���¸� ������ �ּ��� ���ϸ� ���� �̱� �� �ֳ�?
// [TIE, o, x]

// x�� ���̴�

// board �� state�� 3������ Ȱ���� �����ϱ�
// . -> 0, x -> 1, o -> 2
// 3^9 = 19683

// a state�� board����
// �ּ��� ���� x�� ���̶�� x�� �̱� �� �ִ� ����� 1���� ������ x�� �¸���
// �״��� TIE�� ���� �� �ִ� ����� 1���� �ִٸ� TIE
// else o�� �¸�

int board2int(vector<vector<char>> board)
{
    int ret = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            char c = board[i][j];

            int digit = (i * 3 + j) * 2;
            if (c == '.')
                ret += (0 << digit);
            else if (c == 'x')
                ret += (1 << digit);
            else
                ret += (2 << digit);
        }
    }

    return ret;
}
vector<vector<char>> int2board(int ret)
{
    vector<vector<char>> board(3, vector<char>(3));

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int digit = (i * 3 + j) * 2;
            int tmp = 0;
            if (ret & (1 << digit))
                tmp++;
            if (ret & (1 << digit + 1))
                tmp += 2;

            char c;
            if (tmp == 0)
                c = '.';
            else if (tmp == 1)
                c = 'x';
            else
                c = 'o';

            board[i][j] = c;
        }
    }

    return board;
}

// x�� ������ o���� 2, �ƴϸ� x���� 1
int whosTurn(int s)
{
    vector<vector<char>> b = int2board(s);

    int o = 0;
    int x = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (b[i][j] == 'o')
                o++;
            else if (b[i][j] == 'x')
                x++;
        }
    }

    return (x > o) ? 2 : 1;
}

int checkWin(vector<vector<char>> board)
{
    // ���� ��
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            if (board[i][0] == 'o')
                return 2;

            if (board[i][0] == 'x')
                return 1;
        }
    }

    // ���� ��
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            if (board[0][i] == 'o')
                return 2;

            if (board[0][i] == 'x')
                return 1;
        }
    }
    // �밢�� ��
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        if (board[0][0] == 'o')
            return 2;

        if (board[0][0] == 'x')
            return 1;
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        if (board[0][2] == 'o')
            return 2;

        if (board[0][2] == 'x')
            return 1;
    }

    return 0;
}

vector<int> dp;

int rec(int s)
{
    int check = checkWin(int2board(s));
    if (check)
        return check;

    int& ret = dp[s];
    if (ret != -1)
        return ret;

    vector<vector<char>> b = int2board(s);
    int turn = whosTurn(s);

    int tie = 0, x = 0, o = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (b[i][j] == '.')
            {
                // ���ʿ� �´� ���� ����
                if (turn == 1)
                    b[i][j] = 'x';
                else
                    b[i][j] = 'o';

                int tmp = rec(board2int(b)); // �̶��� ���
                if (tmp == 0)
                    tie++;
                else if (tmp == 1)
                    x++;
                else if (tmp == 2)
                    o++;

                b[i][j] = '.'; // ���󺹱�
            }
        }
    }

    if (x == 0 && o == 0)
        return ret = 0;

    if (turn == 1) // x
    {
        if (x)
            return ret = 1;
        else if (tie)
            return ret = 0;
        else
            return ret = 2;
    }
    else // o
    {
        if (o)
            return ret = 2;
        else if (tie)
            return ret = 0;
        else
            return ret = 1;
    }
}

int main()
{
    int testCase;
    cin >> testCase;

    // [0, 174762]
    dp = vector<int>(174762 + 1, -1); // 0 = TIE, 1 = x, 2 = o
    while (testCase--)
    {
        vector<vector<char>> a(3, vector<char>(3));
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                cin >> a[i][j];

        int ans = rec(board2int(a));
        if (ans == 0)
            cout << "TIE\n";
        else if (ans == 1)
            cout << "x\n";
        else if (ans == 2)
            cout << "o\n";
    }
}