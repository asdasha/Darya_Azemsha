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
		cout << "��� �������� - " << kodS << endl;
		cout << "��� �������� - " << name << endl;
		cout << "������� �������� - " << firstname << endl;
		cout << "�������� �������� - " << lastname << endl;
	}
	

	friend ostream & operator <<(ostream & output, const Student & obj) {
		output << "��� �������� - " << obj.kodS << endl;
		output << "��� �������� - " << obj.name << endl;
		output << "������� �������� - " << obj.firstname << endl;
		output << "�������� �������� - " << obj.lastname << endl;
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