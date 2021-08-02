#include <iostream>

using namespace std;

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// git add    : unstaged -> staged
	// git commit : staged   -> commited
	// git push   : remote/local 반영
	// git pull   : remote/local master에서 변경된 커밋들을 fetch + merge = pull
	cout << "hello world!";

	return 0;
}