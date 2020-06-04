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
		cout << "Код преподавателя - " << kod << endl;
		cout << "Имя преподавателя - " << name << endl;
		cout << "Фамилия преподавателя - " << firstname << endl;
		cout << "Должность преподавателя - " << dol << endl;
	}

	friend ostream & operator <<(ostream & outt, const Teacher & obj){
		outt << "Код преподавателя - " << obj.kod << endl;
		outt << "Имя преподавателя - " << obj.name << endl;
		outt << "Фамилия преподавателя - " << obj.firstname << endl;
		outt << "Должность преподавателя - " << obj.dol << endl;
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