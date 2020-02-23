#include <iostream>
#include <vector>
using namespace std;

vector<int> Reversed(const vector<int>& a) {
	vector<int> result;
	for (int i = a.size() - 1; i >= 0; i--) {
		result.push_back(a[i]);
	}
	return result;
}


int main() {
	vector<int> numbers = {1, 5, 3, 4, 2};
	vector<int> a = Reversed(numbers);
	for (auto i : a) {
		cout << i << " " << endl;
	}
	return 0;
}
