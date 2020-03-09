#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
	  if (persons.count(year) == 0) {
		  persons[year] = {"", ""};
	  }
	  persons[year][0] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
	  if (persons.count(year) == 0) {
		  persons[year] = {"", ""};
	  }
	  persons[year][1] = last_name;
  }
  string GetFullName(int year) {
	  string result_first_name = "";
	  string result_last_name = "";
	  for (auto person : persons) {
		  string first_name = person.second[0];
		  string second_name = person.second[1];
		  if (person.first > year) {
			  break;
		  }
		  if (first_name != "") {
			  result_first_name = first_name;
		  }
		  if (second_name != "") {
			  result_last_name = second_name;
		  }
	  }
	  if (result_first_name != "" && result_last_name != "") {
		  return result_first_name + " " + result_last_name;
	  } else if (result_first_name != "") {
		  return result_first_name + " with unknown last name";
	  } else if (result_last_name != "") {
		  return  result_last_name + " with unknown first name";
	  } else {
		  return "Incognito";
	  }

  }
private:
  map<int, vector<string>> persons;
};

int main() {

	Person person;

	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	for (int year : {1900, 1965, 1990}) {
	cout << person.GetFullName(year) << endl;
	}

	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1969, 1970}) {
	cout << person.GetFullName(year) << endl;
	}

	person.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970}) {
	cout << person.GetFullName(year) << endl;
	}

	return 0;
}
