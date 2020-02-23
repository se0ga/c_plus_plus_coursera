#include <iostream>
#include <algorithm>
using namespace std;

bool IsPalindrom(string palindrom) {
	string original_palindrom = palindrom;
	reverse(palindrom.begin(), palindrom.end());
	return original_palindrom == palindrom;
}

int main() {
	cout << IsPalindrom("madar");
	return 0;
}
