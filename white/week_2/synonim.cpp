#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {
	int n;
	cin >> n;
	map<string, set<string>> synonims;
	for (int i = 0; i < n; i++) {
		string command;
		cin >> command;
		string word;
		cin >> word;
		if (command == "ADD" || command == "CHECK") {
			string word_2;
			cin >> word_2;
			if (command == "ADD") {
				synonims[word].insert(word_2);
				synonims[word_2].insert(word);
			} else {
				if (synonims[word].count(word_2) > 0) {
					cout << "YES";
				} else {
					cout << "NO";
				}
				cout << endl;
			}
		} else {
			cout << synonims[word].size() << endl;
		}
	}
	return 0;
}
