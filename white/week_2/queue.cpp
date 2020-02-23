#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int amount;
	cin >> amount;
	string command;
	int num;
	vector<bool> queue;
	for (int i = 0; i < amount; i++) {
		cin >> command;
		if (command == "WORRY") {
			cin >> num;
			queue[num] = true;
		} else if (command == "QUIET") {
			cin >> num;
			queue[num] = false;
		} else if (command == "COME") {
			cin >> num;
			for (int i = 0; i < abs(num); i++) {
				if (num > 0) {
					queue.push_back(false);
				} else {
					queue.pop_back();
				}
			}
		} else if (command == "WORRY_COUNT") {
			int counter = 0;
			for (bool p : queue) {
				if (p == true)
				counter++;
			}
			cout << counter << endl;
		}
	}
}
