#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {
	int n;
	cin >> n;
	map<set<string>, int> stops;
	for (int i = 0; i < n; i++) {
		int amount;
		cin >> amount;
		set<string> current_stops;
		for (int j = 0; j < amount; j++) {
			string stop;
			cin >> stop;
			current_stops.insert(stop);
		}
		if (stops.count(current_stops) > 0) {
			cout << "Already exists for " << stops[current_stops];
		} else {
			stops[current_stops] = stops.size() + 1;
			cout << "New bus " << stops[current_stops];
		}
		cout << endl;
	}
}
