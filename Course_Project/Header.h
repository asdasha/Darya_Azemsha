//Student.h
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>

using namespace std;

class Student {

private:
	int kodS;
	string name;
	string firstname;
	string lastname;
	int n;

public:
	Student() {};

	~Student() {};

	Student(int k, string n, string f, string l) {
		kodS = k;
		name = n;
		firstname = f;
		lastname = l;
	}

	int getkod() {
		return kodS;
	}

	string getname() {
		return name;
	}

	string getfirstname() {
		return firstname;
	}

	string getlastname() {
		return lastname;
	}

	void getStudent() {
		cout << "Код студента - " << kodS << endl;
		cout << "Имя студента - " << name << endl;
		cout << "Фамилия студента - " << firstname << endl;
		cout << "Отчество студента - " << lastname << endl;
	}
	

	friend ostream & operator <<(ostream & output, const Student & obj) {
		output << "Код студента - " << obj.kodS << endl;
		output << "Имя студента - " << obj.name << endl;
		output << "Фамилия студента - " << obj.firstname << endl;
		output << "Отчество студента - " << obj.lastname << endl;
		output << endl;
		return output;
	}
	

		friend istream & operator >>(istream & in, Student & obj) {
			in >> obj.kodS;
			in >> obj.name;
			in >> obj.firstname;
			in >> obj.lastname;
			return in;
		}
};