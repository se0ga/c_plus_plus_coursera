#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	int amount;
	vector<int> months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int month = 0;
	cin >> amount;
	vector<vector<string>> calendar(31);
	for (int i = 0; i < amount; i++) {
		string command;
		int num;
		cin >> command;
		if (command == "ADD") {
			cin >> num;
			string name;
			cin >> name;
			calendar[num - 1].push_back(name);
		} else if (command == "DUMP") {
			cin >> num;
			cout << calendar[num - 1].size();
			for (auto name : calendar[num - 1]) {
				cout << " " << name ;
			}
			cout << endl;
		} else if (command == "NEXT") {
			int next_month = (month + 1) % 12;
			int days_amount = months[next_month];
			for (int i = months[month]; i > days_amount; i--) {
				for (auto name : calendar[i - 1]) {
					calendar[days_amount - 1].push_back(name);
				}
			}
			calendar.resize(days_amount);
			month = next_month;
		}
	}
}
