#include <iostream>
#include <map>
using namespace std;

int main() {
	int n;
	cin >> n;
	map<string, string> countries;
	for (int i = 0; i < n; i++) {
		string command;
		cin >> command;
		if (command == "CHANGE_CAPITAL") {
			string country;
			string new_capital;
			cin >> country;
			cin >> new_capital;
			if (countries.count(country) > 0) {
				if (countries[country] == new_capital) {
					cout << "Country " << country << " hasn't changed its capital";
				} else {
					cout << "Country " << country << " has changed its capital from " << countries[country] << " to " << new_capital;
					countries[country] = new_capital;
				}
			} else {
				cout << "Introduce new country " << country << " with capital " << new_capital;
				countries[country] = new_capital;
			}
		} else if (command == "RENAME") {
			string old_country_name;
			string new_country_name;
			cin >> old_country_name;
			cin >> new_country_name;
			if (countries.count(old_country_name) == 0 || old_country_name == new_country_name || countries.count(new_country_name) > 0) {
				cout << "Incorrect rename, skip";
			} else {
				countries[new_country_name] = countries[old_country_name];
				countries.erase(old_country_name);
				cout << "Country " << old_country_name << " with capital " << countries[new_country_name];
				cout << " has been renamed to " << new_country_name;
			}
		} else if (command == "ABOUT") {
			string country;
			cin >> country;
			if (countries.count(country) > 0) {
				cout << "Country " << country << " has capital " << countries[country];
			} else {
				cout << "Country " << country << " doesn't exist";
			}
		} else if (command == "DUMP") {
			if (countries.size() > 0) {
				for (auto country : countries) {
					cout << country.first << "/" << country.second << " ";
				}
			} else {
				cout << "There are no countries in the world";
			}
		}
		cout << endl;
	}
	return 0;
}
