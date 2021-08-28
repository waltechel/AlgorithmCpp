// 전위 순회 + 중위 순회 => 후위 순회 만들기
#include <iostream>
#include <vector>
using namespace std;

int rootIndex = 0;

void makePostorder(vector<int> preorder, vector<int> inorder, int leftBound, int rightBound)
{
	// 모든 노드 순회 끝
	if (rootIndex == preorder.size())
		return;

	int midBound = -1; // 범위 내에 root가 없을 경우

	// 범위 내 root 찾기
	for (int i = 0; i < inorder.size(); i++)
	{
		if (inorder[i] == preorder[rootIndex])
		{
			midBound = i;
			break;
		}
	}


	// 후위 순회 : 왼 -> 오 -> 루트 순서 순회
	rootIndex++;	// 다음 index 찾기
	// 왼쪽 노드가 있는 경우		왼쪽 노드 순회
	if (leftBound != midBound)
		makePostorder(preorder, inorder, leftBound, midBound - 1);

	// 오른쪽 노드가 있는 경우		오른쪽 노드 순회
	if (midBound != rightBound)
		makePostorder(preorder, inorder, midBound + 1, rightBound); // 오른쪽 트리 순회

	// 범위 내에 루트가 있었을 경우		루트 값 출력
	if (midBound != -1)
		cout << inorder[midBound] << " ";	// 본인 순회

	return;
}

int main()
{
	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; i++)
	{
		// init
		rootIndex = 0;

		// input
		int numOfNode;
		cin >> numOfNode;

		vector<int> preorder(numOfNode, 0);
		for (int i = 0; i < numOfNode; i++)
		{
			cin >> preorder[i];
		}

		vector<int> inorder(numOfNode, 0);
		for (int i = 0; i < numOfNode; i++)
		{
			cin >> inorder[i];
		}

		// output
		makePostorder(preorder, inorder, 0, numOfNode - 1);
		cout << "\n";
	}
}


// 전위 + 중위 순회 ==> 후위 순회를 만들어낼 수 있다.
// 
//  ex)
//  트리
//          27
//     16        54
//   9        36    72
//     12
//전위 순회 본인 왼쪽자식 오른쪽 자식 ( 전위 순회에서 알 수 있는 것 루트 노드)
// ==> 27 16 9 12 54 36 72
// 
//중위 순회 왼쪽자식 본인 오른쪽 자식 ( 중위 순회에서 알 수 있는 것은 왼쪽 노드)
// ==> 9 12 16 27 36 54 72
// 
//후위 순회 왼쪽 자식 오른쪽 자식 본인 
// ==> 12 9 16 36 72 54 27