//teacher.h
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>

using namespace std;
class Teacher {
private:
	int kod;
	string name;
	string firstname;
	string dol;

public:
	Teacher() {

	}
	Teacher(int k, string n, string f, string d) {
		kod = k;
		name = n;
		firstname = f;
		dol = d;
	}
	int getkod() {
		return kod;
	}
	string getname() {
		return name;
	}
	string getfirstname() {
		return firstname;
	}
	string getdol() {
		return dol;
	}

	void getTeacher() {
		cout << "��� ������������� - " << kod << endl;
		cout << "��� ������������� - " << name << endl;
		cout << "������� ������������� - " << firstname << endl;
		cout << "��������� ������������� - " << dol << endl;
	}

	friend ostream & operator <<(ostream & outt, const Teacher & obj){
		outt << "��� ������������� - " << obj.kod << endl;
		outt << "��� ������������� - " << obj.name << endl;
		outt << "������� ������������� - " << obj.firstname << endl;
		outt << "��������� ������������� - " << obj.dol << endl;
		outt << endl;
		return (outt);
	}

	friend istream & operator >>(istream & inteach, Teacher & ob){
		inteach >> ob.kod;
		inteach >> ob.name;
		inteach >> ob.firstname;
		inteach >> ob.dol;
		return(inteach);
	}
};