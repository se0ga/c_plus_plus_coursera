#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool IsPalindrom(string palindrom) {
	string original_palindrom = palindrom;
	reverse(palindrom.begin(), palindrom.end());
	return original_palindrom == palindrom;
}

vector<string> PalindromFilter(vector<string> words, int minLength) {
	vector<string> result;
	for (auto word: words) {
		if (word.size() >= minLength && IsPalindrom(word)) {
			result.push_back(word);
		}
	}
	return result;
}

int main() {
	return 0;
}
