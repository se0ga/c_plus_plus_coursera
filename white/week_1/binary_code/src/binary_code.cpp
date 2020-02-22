#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	vector<int> result;
	cin >> n;
	while (n > 0) {
		result.push_back(n % 2);
		n /= 2;
	}
	reverse(result.begin(), result.end());
	for (auto s : result) {
		cout << s;
	}
	return 0;
}
