#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<string> result(n);
	for (string& i : result) {
		cin >> i;
	}
	sort(begin(result), end(result), [](string a, string b) {
		transform(a.begin(), a.end(),a.begin(), ::toupper);
		transform(b.begin(), b.end(),b.begin(), ::toupper);
		return a < b;
	});
	for (auto i : result) {
		cout << i << " ";
	}
	return 0;
}
