#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	map<string, vector<string>> routes;
	map<string, vector<string>> stops;
	for (int i = 0; i < n; i++) {
		string command;
		cin >> command;
		if (command == "NEW_BUS") {
			string bus_n;
			cin >> bus_n;
			int stops_number;
			cin >> stops_number;
			for (int i = 0; i < stops_number; i++) {
				string stop_name;
				cin >> stop_name;
				routes[bus_n].push_back(stop_name);
				stops[stop_name].push_back(bus_n);
			}

		} else if (command == "BUSES_FOR_STOP") {
			string stop_name;
			cin >> stop_name;
			if (stops.count(stop_name) > 0) {
				for (auto number : stops[stop_name]) {
					cout << number << " ";
				}
			} else {
				cout << "No stop";
			}
			cout << endl;
		} else if (command == "STOPS_FOR_BUS") {
			string bus_n;
			cin >> bus_n;
			if (routes.count(bus_n) > 0) {
				for (auto stop_name : routes[bus_n]) {
					cout << "Stop " << stop_name << ":";
					if (stops[stop_name].size() > 1) {
						for (auto number : stops[stop_name]) {
							if (number != bus_n) {
								cout << " " << number;
							}
						}
					} else {
						cout << " no interchange";
					}
					cout << endl;
				}
			} else {
				cout << "No bus" << endl;;
			}
		} else if (command == "ALL_BUSES") {
			if (routes.size() > 0) {
				for (auto route : routes) {
					cout << "Bus " << route.first << ":";
					for (string stop_name : route.second) {
						cout << " " << stop_name;
					}
					cout << endl;
				}
			} else {
				cout << "No buses" << endl;
			}
		}
	}
	return 0;
}
