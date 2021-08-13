#include <iostream>
#include <memory.h>
using namespace std;

const int MAX = 12;
const int INF = 987654321;
int n, k, m, l;
int cashe[10][(1 << MAX)];
int classes[10];
int prerequisite[MAX];

int bitCount(int bits)
{
	if (bits == 0)
		return 0;
	return bits % 2 + bitCount(bits / 2);
}

int graduate(int semester, int taken)
{
	if (bitCount(taken) >= k) return 0;

	if (semester == m) return INF;

	int& ret = cashe[semester][taken];
	if (ret != -1) return ret;
	ret = INF;

	int canTake = (classes[semester] & ~taken);	// taken에 없고 classes에 있는 것들
	for (int i = 0; i < n; i++)
	{
		if ((canTake & (1 << i)) &&
			(taken & prerequisite[i]) != prerequisite[i])
			canTake &= ~(1 << i);


	}

	for (int take = canTake; take > 0; take = (take - 1) & canTake)
	{
		if (bitCount(take) > l) continue;
		ret = min(ret, graduate(semester + 1, taken | take) + 1);
	}

	ret = min(ret, graduate(semester + 1, taken));
	return ret;
}

int main()
{
	int c;	// case
	cin >> c;

	for (int i = 0; i < c; i++)
	{
		memset(prerequisite, 0, sizeof(prerequisite));
		memset(classes, 0, sizeof(classes));
		memset(cashe, -1, sizeof(cashe));

		cin >> n >> k >> m >> l;

		int preNum;
		int subject;
		for (int j = 0; j < n; j++)		// 선수과목 정보 입력
		{
			cin >> preNum;
			for (int a = 0; a < preNum; a++)
			{
				cin >> subject;

				prerequisite[j] |= (1 << subject);
			}

		}

		int classNum;
		for (int j = 0; j < m; j++)		// 학기 정보 입력
		{
			cin >> classNum;
			for (int a = 0; a < classNum; a++)
			{
				cin >> subject;
				classes[j] |= (1 << subject);
			}
		}

		int ret = graduate(0, 0);

		if (ret == INF)
			cout << "IMPOSSIBLE" << "\n";
		else
			cout << ret << "\n";

	}
	return 0;
}


