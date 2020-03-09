#include <map>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

// если имя неизвестно, возвращает пустую строку
string FindNameByYear(const map<int, string>& names, int year) {
  string name;  // изначально имя неизвестно

  // перебираем всю историю по возрастанию ключа словаря, то есть в хронологическом порядке
  for (const auto& item : names) {
    // если очередной год не больше данного, обновляем имя
    if (item.first <= year) {
      name = item.second;
    } else {
      // иначе пора остановиться, так как эта запись и все последующие относятся к будущему
      break;
    }
  }

  return name;
}

// если имя неизвестно, возвращает пустую строку
string FindHistoryNameByYear(const map<int, string>& names, int year) {
  string current_name;  // изначально имя неизвестно
  vector <string> history;

  // перебираем всю историю по возрастанию ключа словаря, то есть в хронологическом порядке
  for (const auto& item : names) {
    // если очередной год не больше данного, обновляем имя
    if (item.first <= year) {
    	if (current_name != item.second) {
    		history.push_back(current_name);
        	current_name = item.second;
    	}
    } else {
      // иначе пора остановиться, так как эта запись и все последующие относятся к будущему
      break;
    }
  }
  string stringified_history;
  for (string name : history) {
	  if (stringified_history.empty()) {
		  stringified_history = name;
	  } else {
		  stringified_history = name + ", " + stringified_history;
	  }
  }
  if (!stringified_history.empty()) {
	  current_name += " (" + stringified_history + ")";
  }
  return current_name ;
}

class Person {
public:
	Person(const string& first_name, const string& last_name, const int& year) {
		first_names[year] = first_name;
		last_names[year] = last_name;
		year_of_birth = year;
	}
	  void ChangeFirstName(const int& year, const string& first_name) {
		  if (year >= year_of_birth) {
			  first_names[year] = first_name;
		  }
	  }
	  void ChangeLastName(const int& year, const string& last_name) {
		  if (year >= year_of_birth) {
			  last_names[year] = last_name;
		  }
	  }
	  string GetFullName(const int& year) const {
		  if (year < year_of_birth) {
			  return "No person";
		  }
		// получаем имя и фамилию по состоянию на год year
		const string first_name = FindNameByYear(first_names, year);
		const string last_name = FindNameByYear(last_names, year);
		return ReturnName(first_name, last_name);
	  }

	  string GetFullNameWithHistory(const int& year) const {
		  if (year < year_of_birth) {
			  return "No person";
		  }
		// получить все имена и фамилии по состоянию на конец года year
			const string first_name = FindHistoryNameByYear(first_names, year);
			const string last_name = FindHistoryNameByYear(last_names, year);
			return ReturnName(first_name, last_name);
	  }

	private:
	  map<int, string> first_names;
	  map<int, string> last_names;
	  int year_of_birth;

	  string ReturnName(string first_name, string last_name) const {
		  // если и имя, и фамилия неизвестны
		  if (first_name.empty() && last_name.empty()) {
			return "Incognito";

		  // если неизвестно только имя
		  } else if (first_name.empty()) {
			return last_name + " with unknown first name";

		  // если неизвестна только фамилия
		  } else if (last_name.empty()) {
			return first_name + " with unknown last name";

		  // если известны и имя, и фамилия
		  } else {
			return first_name + " " + last_name;
		  }
	  }
};

int main() {
  Person person("Polina", "Sergeeva", 1960);
  for (int year : {1959, 1960}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1965, "Appolinaria");
  person.ChangeLastName(1967, "Ivanova");
  for (int year : {1965, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  return 0;
}

