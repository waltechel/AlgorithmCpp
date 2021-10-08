#include<bits/stdc++.h>

using namespace std;

const int MAX_DISCS = 12;
int get(int state, int index)
{
	return (state >> (index * 2)) & 3;
}
int fetch(int state, int index, int value)
{
	return (state & ~(3 << (index * 2))) | (value << (index * 2)); // index의 loc -> value
}
int c[1 << (MAX_DISCS * 2)];

int bfs(int discs, int begin, int end)
{
	if (begin == end) // don't need to change
		return 0;

	queue<int> q;
	q.push(begin);

	memset(c, -1, sizeof(c));
	c[begin] = 0;

	while (!q.empty())
	{
		int here = q.front();
		q.pop();


		int top[4] = { -1, -1, -1, -1 };
		for (int i = discs - 1; i >= 0; i--) //	if(get(here,i) == get(here, i+1))     i+1 - > i
			top[get(here, i)] = i; // top discs state in here

		// i번째 기둥의 top disc를 j번째 기둥에 옮긴다
		for (int i = 0; i < 4; i++)
		{
			if (top[i] != -1) // i번째 기둥에 disc가 없으면 안된다.
			{
				for (int j = 0; j < 4; j++)
				{
					if (i != j && (top[j] == -1 || top[j] > top[i])) // i와 다른 j기둥 중 비어있거나 j기둥의 top이 더 큰경우 (옮길수 잇는경우)
					{
						int there = fetch(here, top[i], j);
						if (c[there] != -1)
							continue;

						c[there] = c[here] + 1;
						if (there == end)
							return c[there];

						q.push(there);
					}
				}
			}
		}

	}
	return -1;
}

int incr(int x) // x++ or x--
{
	if (x == 0)
		return 0;

	return x > 0 ? x + 1 : x - 1;
}
int sgn(int x) // x의 부호
{
	if (x == 0)
		return 0;

	return x > 0 ? 1 : -1;
}
int bidirect(int discs, int begin, int end)
{
	if (begin == end) // don't need to change
		return 0;

	queue<int> q;
	q.push(begin);
	q.push(end);

	memset(c, 0, sizeof(c));
	c[begin] = 1;
	c[end] = -1;

	while (!q.empty())
	{
		int here = q.front();
		q.pop();

		int top[4] = { -1, -1, -1, -1 };
		for (int i = discs - 1; i >= 0; i--) //	if(get(here,i) == get(here, i+1))     i+1 - > i
			top[get(here, i)] = i; // top discs state in here

		// i번째 기둥의 top disc를 j번째 기둥에 옮긴다
		for (int i = 0; i < 4; i++)
			if (top[i] != -1) // i번째 기둥에 disc가 없으면 안된다.
				for (int j = 0; j < 4; j++)
					if (i != j && (top[j] == -1 || top[j] > top[i])) // i와 다른 j기둥 중 비어있거나 j기둥의 top이 더 큰경우 (옮길수 잇는경우)
					{
						int there = fetch(here, top[i], j);
						if (c[there] == 0) // 방문한 적 없음
						{
							c[there] = incr(c[here]);
							q.push(there);
						}
						else if (sgn(c[there]) != sgn(c[here])) // 방문한 적이 있으나 서로 부호가 다르다면 양방향점이 만난것
						{
							return abs(c[there]) + abs(c[here]) - 1;
						}
					}
	}
	return -1;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;

	for (; testCase > 0; testCase--)
	{
		int n;
		cin >> n;

		// 0 ~ n-1 discs
		int perm = 0;
		for (int i = 0; i < 4; i++)
		{
			int m;
			cin >> m;
			for (int j = 0; j < m; j++)
			{
				int tmp;
				cin >> tmp;
				tmp--;
				perm |= (i << 2 * tmp); // tmp disc는 i번째 기둥에 있다
			}
		}

		int sorted = 0;
		for (int i = 0; i < n; i++)
		{
			sorted |= (3 << 2 * i);
		}
		// (perm -> sorted) bfs(Bi Direct searching) - shortest path
		cout << bidirect(n, perm, sorted) << "\n";
	}
}