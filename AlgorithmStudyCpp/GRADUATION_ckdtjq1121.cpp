#include <iostream>

using namespace std;

int main()
{
	int c;	// case
	cin >> c;

	for (int i = 0; i < c; i++)
	{
		int resultCount = 0;
		int n, k, m, l;
		cin >> n >> k >> m >> l;

		int endSubjectBit = 0;
		//bool* endSubject = (bool*)malloc(n * sizeof(bool)); // 이수가 끝난 과목 체크 표
		//for (int j = 0; j < n; j++)			// false 이수하지 않음으로 초기화
		//{
		//	endSubject[j] = false;
		//}
		int* preSubjectBit = (int*)malloc(n * sizeof(int));
		//bool** preSubject = (bool**)malloc(n * sizeof(bool*)); // 선수과목 체크 표
		for (int j = 0; j < n; j++)			//  false 선수과목이 아님으로 초기화
		{
			preSubjectBit[j] = 0;
			/*for (int a = 0; a < n; a++)
			{
				preSubject[j][a] = false;
			}*/

		}

		int nCount;
		int temp;
		for (int j = 0; j < n; j++)		// 선수과목 정보 입력
		{
			cin >> nCount;
			for (int a = 0; a < nCount; a++)
			{
				cin >> temp;

				preSubjectBit[j] |= (1 << temp);
				/*preSubject[j][temp] = true;*/

			}

		}

		int* semesterBit = (int*)malloc(m * sizeof(int));
		//bool** semester = (bool**)malloc(m * sizeof(bool*));
		for (int j = 0; j < m; j++)			//  false 학기에 있는 과목이 아님으로 초기화
		{
			semesterBit[j] = 0;
			/*semester[j] = (bool*)malloc(n * sizeof(bool));
			for (int a = 0; a < n; a++)
			{
				semester[j][a] = false;
			}*/
		}

		int mCount;

		for (int j = 0; j < m; j++)		// 학기 정보 입력
		{
			cin >> mCount;
			for (int a = 0; a < mCount; a++)
			{
				cin >> temp;

				semesterBit[j] |= (1 << temp);
				//semester[j][temp] = true;	

			}

		}

		int tempEndSubjectBit = 0;
		//bool* tempEndSubject = (bool*)malloc(n * sizeof(bool)); // 임시 이수 완료 표
		//for (int j = 0; j < n; j++)		// false 이수하지 않음으로 초기화
		//{
		//	tempEndSubject[j] = false;
		//}

		// 학기 시작
		int result = 0;
		bool failFlag;
		for (int j = 0; j < m; j++)	// 학기
		{
			for (int a = 0; a < n; a++)		//학기의 과목
			{
				//if (!semester[j][a]) // [j]학기에 [a] 과목이 없을 경우 패스
				if ((semesterBit[j] & (1 << a)) == 0)
				{

					continue;
				}

				//if (endSubject[a]) // endSubject[a]를 이미 수강 하였을 경우 패스
				if (endSubjectBit & (1 << a))
				{
					continue;
				}

				failFlag = false;
				for (int b = 0; b < n; b++)
				{
					//if (preSubject[a][b] && !endSubject[b]) // a의 선수 과목으로 b가 있고 b를 수강 하지 못 했을 때	a를 수강하지 못함
					if ((preSubjectBit[a] & (1 << b)))
					{
						if ((endSubjectBit & (1 << b)) == 0)
						{
							failFlag = true;
							break;
						}
					}
				}

				if (!failFlag)	// 실패하지 않았다면 -> 선수 과목들을 수강완료 했을 경우 수강할 수 있음
				{
					//tempEndSubject[a] = true; // 수강 완료
					tempEndSubjectBit |= (1 << a);
				}
			}


			// 한 학기 끝

			//for (int a = 0; a < n; a++)	// 전 학기와 다른 점이 있는지?
			//{
				//if (endSubject[a] != tempEndSubject[a])	
			// 
			if (endSubjectBit != tempEndSubjectBit)
			{
				result++;
				//for (int a = 0; a < n; a++)	// 이번 학기에서 수강 완료한 과목  수강 완료 표에 추가
				//{
				//	if (endSubject[a] != tempEndSubject[a])
				//	{
				//		endSubject[a] = endSubject[a] || tempEndSubject[a];
				//	}
				//}				
				endSubjectBit |= tempEndSubjectBit;
			}
			// 수강완료 과목 개수 카운트
			resultCount = 0;
			for (int a = 0; a < n; a++)
			{
				//if (endSubject[a])
				if (endSubjectBit & (1 << a))
				{
					resultCount++;
				}
			}
			// 목표 과목 수 이상  수강 완료 ->
			if (resultCount >= k)
				break;
		}

		// 결과 출력
		if (resultCount < k)
			cout << "IMPOSSIBLE" << "\n";
		else
			cout << result << "\n";
	}
	// 새로 수강할 수 있는 과목이 있을때 마다 그 학기에서 과목을 수강을 한다. => 최소 학기를 수강하진 않음
	// 학기 들의 조합 중에 최소 학기가 존재 함  => recursive + dp
	// 한 학기에 들을 수 있는 과목 수 l(L)로 제한적임
}


