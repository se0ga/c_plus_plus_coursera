#include <iostream>
#include <vector>
using namespace std;


int main() {
	int n;
	cin >> n;
	vector<int> temps(n);
	int temps_sum = 0;
	for (int& temp : temps) {
		cin >> temp;
		temps_sum += temp;
	}
	int middle_temp = temps_sum / n;
	vector<int> result;
	for (int i = 0; i < temps.size(); i++) {
		if (temps[i] > middle_temp) {
			result.push_back(i);
		}
	}
	cout << result.size() << endl;
	for (int temp : result) {
		cout << temp << " ";
	}

	return 0;
}
