#include <iostream>
#include <map>
using namespace std;

void PrintAnswer(bool answer) {
	if (answer) {
		cout << "YES";
	} else {
		cout << "NO";
	}
	cout << endl;
}

map<char, int> CreateMap(string word) {
	map<char, int> result;
	for (auto ch : word) {
		result[ch]++;
	}
	return result;
}

bool IsAnagram(string word_1, string word_2) {
	return CreateMap(word_1) == CreateMap(word_2);
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string word_1;
		string word_2;
		cin >> word_1 >> word_2;
		PrintAnswer(IsAnagram(word_1, word_2));
	}
	return 0;
}
