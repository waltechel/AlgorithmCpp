#include <iostream>

using namespace std;

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 커밋 연습(pull 받고 충돌 혹은 병합 요청 발생 시 해결하는 방법)
	// git add    : unstaged -> staged
	// git commit : staged   -> commited
	// git push   : remote/local 반영
	// git pull   : remote/local master에서 값 가져오기(fetch + merge = pull)
	cout << "hello world!";

	return 0;
}
