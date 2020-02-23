#include <iostream>
#include <vector>
using namespace std;
void MoveStrings(vector<string>& a, vector<string>& b) {
	for (auto i : a) {
		b.push_back(i);
	}
	a.clear();
}


int main() {
	vector<string> a = {"a", "b", "c"};
	vector<string> b = {"d", "e"};
	MoveStrings(a, b);
	for (auto i : a) {
		cout << i << " " << endl;
	}

	for (auto i : b) {
		cout << i << " " << endl;
	}
	return 0;
}
