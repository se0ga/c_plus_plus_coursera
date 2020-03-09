#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class ReversibleString {
public:
	ReversibleString() {
		string = "";
	}
	ReversibleString(const string& s) {
		string = s;
	}
	void Reverse() {
		reverse(string.begin(), string.end());
	}
	string ToString() const {
		return string;
	}
private:
	string string;
};


int main() {
	ReversibleString s("live");
	s.Reverse();
	cout << s.ToString() << endl;

	s.Reverse();
	const ReversibleString& s_ref = s;
	string tmp = s_ref.ToString();
	cout << tmp << endl;

	ReversibleString empty;
	cout << '"' << empty.ToString() << '"' << endl;
	return 0;
}
