#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<unordered_map>
#include<set>
#include<queue>
#include<stack>
#include<unordered_set>
#include<regex>
#include <iomanip>

using namespace std;

/*
	답이 6가지 종류 안에 나오지 않을까 고민함
*/

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<double> positiveList;
	vector<double> negativeList;
	vector<double> list;
	for (int i = 0; i < N; i++) {
		double temp;
		cin >> temp;
		if (temp > 0) {
			positiveList.push_back(temp);
		} else {
			negativeList.push_back(temp);
		}
		list.push_back(temp);
	}
	sort(list.begin(), list.end());
	sort(positiveList.begin(), positiveList.end());
	sort(negativeList.begin(), negativeList.end());

	double minValue = 10000000000;
	double maxValue = -10000000000;
	double a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;

	a = list[0];
	b = list[1];
	c = list[2];
	d = list[0];
	e = list[1];
	f = list[2];
	minValue = min(minValue, (a + b + c) / (a * b * c));
	maxValue = max(maxValue, (d + e + f) / (d * e * f));

	a = list[list.size() - 1];
	b = list[list.size() - 2];
	c = list[list.size() - 3];
	d = list[list.size() - 1];
	e = list[list.size() - 2];
	f = list[list.size() - 3];
	minValue = min(minValue, (a + b + c) / (a * b * c));
	maxValue = max(maxValue, (d + e + f) / (d * e * f));

	if (positiveList.size() >= 3) {
		a = positiveList[0];
		b = positiveList[1];
		c = positiveList[2];
		d = positiveList[0];
		e = positiveList[1];
		f = positiveList[2];
		minValue = min(minValue, (a + b + c) / (a * b * c));
		maxValue = max(maxValue, (d + e + f) / (d * e * f));

		a = positiveList[positiveList.size() - 1];
		b = positiveList[positiveList.size() - 2];
		c = positiveList[positiveList.size() - 3];
		d = positiveList[positiveList.size() - 1];
		e = positiveList[positiveList.size() - 2];
		f = positiveList[positiveList.size() - 3];
		minValue = min(minValue, (a + b + c) / (a * b * c));
		maxValue = max(maxValue, (d + e + f) / (d * e * f));
	}

	if (negativeList.size() >= 3) {
		a = negativeList[0];
		b = negativeList[1];
		c = negativeList[2];
		d = negativeList[0];
		e = negativeList[1];
		f = negativeList[2];
		minValue = min(minValue, (a + b + c) / (a * b * c));
		maxValue = max(maxValue, (d + e + f) / (d * e * f));

		a = negativeList[negativeList.size() - 1];
		b = negativeList[negativeList.size() - 2];
		c = negativeList[negativeList.size() - 3];
		d = negativeList[negativeList.size() - 1];
		e = negativeList[negativeList.size() - 2];
		f = negativeList[negativeList.size() - 3];
		minValue = min(minValue, (a + b + c) / (a * b * c));
		maxValue = max(maxValue, (d + e + f) / (d * e * f));
	}

	if (positiveList.size() >= 1 && negativeList.size() >= 2) {
		a = positiveList[0];
		b = negativeList[0];
		c = negativeList[1];
		d = positiveList[0];
		e = negativeList[0];
		f = negativeList[1];
		minValue = min(minValue, (a + b + c) / (a * b * c));
		maxValue = max(maxValue, (d + e + f) / (d * e * f));

		a = positiveList[0];
		b = negativeList[negativeList.size() - 1];
		c = negativeList[negativeList.size() - 2];
		d = positiveList[0];
		e = negativeList[negativeList.size() - 1];
		f = negativeList[negativeList.size() - 2];
		minValue = min(minValue, (a + b + c) / (a * b * c));
		maxValue = max(maxValue, (d + e + f) / (d * e * f));

		a = positiveList[0];
		b = negativeList[0];
		c = negativeList[negativeList.size() - 1];
		d = positiveList[0];
		e = negativeList[0];
		f = negativeList[negativeList.size() - 1];
		minValue = min(minValue, (a + b + c) / (a * b * c));
		maxValue = max(maxValue, (d + e + f) / (d * e * f));

		a = positiveList[positiveList.size() - 1];
		b = negativeList[0];
		c = negativeList[1];
		d = positiveList[positiveList.size() - 1];
		e = negativeList[0];
		f = negativeList[1];
		minValue = min(minValue, (a + b + c) / (a * b * c));
		maxValue = max(maxValue, (d + e + f) / (d * e * f));

		a = positiveList[positiveList.size() - 1];
		b = negativeList[negativeList.size() - 1];
		c = negativeList[negativeList.size() - 2];
		d = positiveList[positiveList.size() - 1];
		e = negativeList[negativeList.size() - 1];
		f = negativeList[negativeList.size() - 2];
		minValue = min(minValue, (a + b + c) / (a * b * c));
		maxValue = max(maxValue, (d + e + f) / (d * e * f));

		a = positiveList[positiveList.size() - 1];
		b = negativeList[0];
		c = negativeList[negativeList.size() - 1];
		d = positiveList[positiveList.size() - 1];
		e = negativeList[0];
		f = negativeList[negativeList.size() - 1];
		minValue = min(minValue, (a + b + c) / (a * b * c));
		maxValue = max(maxValue, (d + e + f) / (d * e * f));
	}

	if (positiveList.size() >= 2 && negativeList.size() >= 1) {
		a = positiveList[0];
		b = positiveList[1];
		c = negativeList[0];
		d = positiveList[0];
		e = positiveList[1];
		f = negativeList[0];
		minValue = min(minValue, (a + b + c) / (a * b * c));
		maxValue = max(maxValue, (d + e + f) / (d * e * f));

		a = positiveList[0];
		b = positiveList[positiveList.size() - 1];
		c = negativeList[0];
		d = positiveList[0];
		e = positiveList[positiveList.size() - 1];
		f = negativeList[0];
		minValue = min(minValue, (a + b + c) / (a * b * c));
		maxValue = max(maxValue, (d + e + f) / (d * e * f));

		a = positiveList[0];
		b = positiveList[1];
		c = negativeList[negativeList.size() - 1];
		d = positiveList[0];
		e = positiveList[1];
		f = negativeList[negativeList.size() - 1];
		minValue = min(minValue, (a + b + c) / (a * b * c));
		maxValue = max(maxValue, (d + e + f) / (d * e * f));

		a = positiveList[0];
		b = positiveList[positiveList.size() - 1];
		c = negativeList[negativeList.size() - 1];
		d = positiveList[0];
		e = positiveList[positiveList.size() - 1];
		f = negativeList[negativeList.size() - 1];
		minValue = min(minValue, (a + b + c) / (a * b * c));
		maxValue = max(maxValue, (d + e + f) / (d * e * f));

		a = positiveList[positiveList.size() - 1];
		b = positiveList[positiveList.size() - 2];
		c = negativeList[0];
		d = positiveList[positiveList.size() - 1];
		e = positiveList[positiveList.size() - 2];
		f = negativeList[0];
		minValue = min(minValue, (a + b + c) / (a * b * c));
		maxValue = max(maxValue, (d + e + f) / (d * e * f));

		a = positiveList[positiveList.size() - 1];
		b = positiveList[positiveList.size() - 2];
		c = negativeList[negativeList.size() - 1];
		d = positiveList[positiveList.size() - 1];
		e = positiveList[positiveList.size() - 2];
		f = negativeList[negativeList.size() - 1];
		minValue = min(minValue, (a + b + c) / (a * b * c));
		maxValue = max(maxValue, (d + e + f) / (d * e * f));
	}

	cout << fixed << setprecision(12) << minValue << "\n" << maxValue;

	return 0;
}