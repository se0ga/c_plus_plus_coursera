#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> result;
	for (int i = 0; i < n; i++) {
		int number;
		cin >> number;
		result.push_back(number);
	}
	sort(begin(result), end(result), [](int a, int b) {return abs(b) > abs(a);});
	for (auto i : result) {
		cout << i << " ";
	}
	return 0;
}
