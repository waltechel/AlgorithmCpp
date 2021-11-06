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
    // 모든 칸이 블록으로 채워짐
    if (empty.first == -1 && empty.second == -1)
        return 1;

    int y = empty.first, x = empty.second;
    int ret = 0;
    // 4가지 종류의 블록 모양
    for (int i = 0; i < 4; i++)
    {
        bool can = 1;
        for (int j = 0; j < 3; j++)
        {
            int ny = y + dy[i][j];
            int nx = x + dx[i][j];

            // 범위 밖으로 나가게 됨
            if (ny < 0 || ny >= h || nx < 0 || nx >= w)
            {
                can = 0;
                break;
            }

            // 블럭을 놓을 수 없음
            if (grid[ny][nx] == '#')
            {
                can = 0;
                break;
            }
        }

        if (can)
        {
            // 해당 모양의 블록을 놓고 경우의 수를 셈
            for (int j = 0; j < 3; j++)
            {
                int ny = y + dy[i][j];
                int nx = x + dx[i][j];

                grid[ny][nx] = '#';
            }
            ret += ways2cover(grid);
            // 놓았던 블록을 뺌
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
