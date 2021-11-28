#include <bits/stdc++.h>

using namespace std;
int h, w;
int dy[4][3] = {
    {0, 0, 1},
    {0, 1, 1},
    {0, 1, 1},
    {0, 0, 1} };
int dx[4][3] = {
    {0, 1, 1},
    {0, 0, 1},
    {0, -1, 0},
    {0, 1, 0} };

pair<int, int> findempty(vector<vector<char>> grid)
{
    int y = -1, x = -1;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (grid[i][j] == '.')
            {
                y = i;
                x = j;

                return { y, x };
            }
        }
    }

    return { y, x };
}
int ways2cover(vector<vector<char>> grid)
{
    pair<int, int> empty = findempty(grid);
    // ��� ĭ�� ������� ä����
    if (empty.first == -1 && empty.second == -1)
        return 1;

    int y = empty.first, x = empty.second;
    int ret = 0;
    // 4���� ������ ��� ���
    for (int i = 0; i < 4; i++)
    {
        bool can = 1;
        for (int j = 0; j < 3; j++)
        {
            int ny = y + dy[i][j];
            int nx = x + dx[i][j];

            // ���� ������ ������ ��
            if (ny < 0 || ny >= h || nx < 0 || nx >= w)
            {
                can = 0;
                break;
            }

            // ���� ���� �� ����
            if (grid[ny][nx] == '#')
            {
                can = 0;
                break;
            }
        }

        if (can)
        {
            // �ش� ����� ����� ���� ����� ���� ��
            for (int j = 0; j < 3; j++)
            {
                int ny = y + dy[i][j];
                int nx = x + dx[i][j];

                grid[ny][nx] = '#';
            }
            ret += ways2cover(grid);
            // ���Ҵ� ����� ��
            for (int j = 0; j < 3; j++)
            {
                int ny = y + dy[i][j];
                int nx = x + dx[i][j];

                grid[ny][nx] = '.';
            }
        }
    }

    return ret;
}
int main()
{
    int testCase;
    cin >> testCase;

    while (testCase--)
    {
        cin >> h >> w;

        vector<vector<char>> grid(h, vector<char>(w));
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> grid[i][j];
            }
        }

        int ans = ways2cover(grid);

        cout << ans << "\n";
    }
}
