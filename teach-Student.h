//Teach-Student.h
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include "Header.h"
#include "Teacher.h"
#include "Header1.h"

using namespace std;

class teamWork: public Student, public Teacher, public Criterij{
private:
	int curTeachmas;
	int maxTeachmas;
	Teacher *teachers;

	int curStudmas;
	int maxStudmas;
	Student *students;

	int curCrmas;
	int maxCrmas;
	Criterij *obj;
public:
	teamWork() {
		curTeachmas = 0;
		cout << "Введите необходимое вам количество преподавателей, которых вы будете вносить в базу" << endl;
		cin >> maxTeachmas;
		teachers = new Teacher[maxTeachmas];//выделение памяти для массива объектов класса с указанным размером

		curStudmas = 0;
		cout << "Введите необходимое вам количество студентов, которых вы будете вносить в базу" << endl;
		cin >> maxStudmas;
		students = new Student[maxStudmas];

		curCrmas = 0;
		maxCrmas = maxStudmas * maxTeachmas;
		obj = new Criterij[maxCrmas];

	};
	~teamWork() {
		delete[] teachers;
		delete[] students;
	}
	
	void setStudent() {
		for (int i = 0;i < maxStudmas;i++) {
			int kodS;
			string name;
			string firstname;
			string lastname;
			cout << "Введите код студента " << endl;
			cin >> kodS;
			cout << "Введите имя студента " << endl;
			cin >> name;
			cout << "Введите фамилию студента " << endl;
			cin >> firstname;
			cout << "Введите отчество студента " << endl;
			cin >> lastname;

			Student sup(kodS, name, firstname, lastname);
			addStud(sup);
		}
	}

	void setTeach() {
		for (int i = 0;i < maxTeachmas;i++) {
			int kod;
			string name;
			string firstname;
			string dol;
			cout << "Введите код преподавателя " << endl;
			cin >> kod;
			cout << "Введите имя преподавателя " << endl;
			cin >> name;
			cout << "Введите фамилию преподавателя " << endl;
			cin >> firstname;
			cout << "Введите должность преподавателя " << endl;
			cin >> dol;

			Teacher tw(kod, name, firstname, dol);
			addTeach(tw);
		}
	}

	void setCrit() {
		for (int i = 0;i < maxCrmas;i++) {
			int kod;
			int kodS;
			int m;
			double sum;
			cout << "Введите код студента" << endl;
			cin >> kodS;
			cout << "Введите код преподавателя" << endl;
			cin >> kod;
			sum = 0;
			cout << "Организованность и пунктуальность преподавателя" << endl;
			cin >> m;
			sum += m;
			cout << "Владение материалом и рациональное использование времени на занятиях" << endl;
			cin >> m;
			sum += m;
			cout << "Содержательная значимость и доступность излагаемого материала" << endl;
			cin >> m;
			sum += m;
			cout << "Связь с практической деятельностью" << endl;
			cin >> m;
			sum += m;
			cout << "Использование современных методов обучения" << endl;
			cin >> m;
			sum += m;
			cout << "Привлечение студентов к научной деятельности" << endl;
			cin >> m;
			sum += m;
			cout << "Умение общаться с аудиторией" << endl;
			cin >> m;
			sum += m;
			cout << "Преподаватель старается быть объективным в оценке учебных достижений" << endl;
			cin >> m;
			sum += m;
			cout << "Эрудиция и культура речи" << endl;
			cin >> m;
			sum += m;
			cout << "Объективность, уважение и тактичность в отношении к студентам" << endl;
			cin >> m;
			sum += m;
			cout << "Внешний вид преподавателя" << endl;
			cin >> m;
			sum += m;
			sum = sum / 11;
			cout << sum;
			cout << endl;
			Criterij cr(kod, kodS, sum);
			addCr(cr);
		}
	
	}

	void newStud() {
		int kodS;
		string name;
		string firstname;
		string lastname;
		cout << "Введите код студента " << endl;
		cin >> kodS;
		cout << "Введите имя студента " << endl;
		cin >> name;
		cout << "Введите фамилию студента " << endl;
		cin >> firstname;
		cout << "Введите отчество студента " << endl;
		cin >> lastname;

		Student sup(kodS, name, firstname, lastname);
		addStud(sup);
	}

	void newTeach(){
		int kod;
		string name;
		string firstname;
		string dol;
		cout << "Введите код преподавателя " << endl;
		cin >> kod;
		cout << "Введите имя преподавателя " << endl;
		cin >> name;
		cout << "Введите фамилию преподавателя " << endl;
		cin >> firstname;
		cout << "Введите должность преподавателя " << endl;
		cin >> dol;

		Teacher tw(kod, name, firstname, dol);
		addTeach(tw);
	}

	void newCrit() {
		int kod;
		int kodS;
		int m;
		double sum;
		cout << "Введите код студента" << endl;
		cin >> kodS;
		cout << "Введите код преподавателя" << endl;
		cin >> kod;
		sum = 0;
		cout << "Организованность и пунктуальность преподавателя" << endl;
		cin >> m;
		sum += m;
		cout << "Владение материалом и рациональное использование времени на занятиях" << endl;
		cin >> m;
		sum += m;
		cout << "Содержательная значимость и доступность излагаемого материала" << endl;
		cin >> m;
		sum += m;
		cout << "Связь с практической деятельностью" << endl;
		cin >> m;
		sum += m;
		cout << "Использование современных методов обучения" << endl;
		cin >> m;
		sum += m;
		cout << "Привлечение студентов к научной деятельности" << endl;
		cin >> m;
		sum += m;
		cout << "Умение общаться с аудиторией" << endl;
		cin >> m;
		sum += m;
		cout << "Преподаватель старается быть объективным в оценке учебных достижений" << endl;
		cin >> m;
		sum += m;
		cout << "Эрудиция и культура речи" << endl;
		cin >> m;
		sum += m;
		cout << "Объективность, уважение и тактичность в отношении к студентам" << endl;
		cin >> m;
		sum += m;
		cout << "Внешний вид преподавателя" << endl;
		cin >> m;
		sum += m;
		sum = sum / 11;
		cout << sum;

		Criterij cr(kod, kodS, sum);
		addCr(cr);
	}

	void getStud() {
		for (int i = 0;i < curStudmas;i++) {
			students[i].getStudent();
		}
	}

	void getTeach() {
		for (int i = 0;i < curTeachmas;i++) {
			teachers[i].getTeacher();
		}
	}

	void getCrit() {
		for (int i = 0;i < curCrmas;i++) {
			obj[i].getCR();
		}
	}

	void delS() {
		curStudmas = 0;
		cout << "Список студентов удален" << endl;
		}

	void delT() {
		curTeachmas = 0;
		cout << "Список преподавателей удален" << endl;
	}

	void delC() {
		curCrmas = 0;
		cout << "Список рейтинга удален" << endl;
	}

	void addStud(Student stud) {
		if (curStudmas == maxStudmas) {
			Student *temp = students;
			int nmax = 2 * maxStudmas + 1;
			students = new Student[nmax];
			for (int i = 0;i < maxStudmas;i++) {
				*(students + i) = *(temp + i);
			}
			delete[] temp;
			maxStudmas = nmax;
}
		students[curStudmas++] = stud;
	}

	void addTeach(Teacher teach) {
		if (curTeachmas == maxTeachmas) {
			Teacher *temp = teachers;
			int nmax = 2 * maxTeachmas + 1;
			teachers = new Teacher[nmax];
			for (int i = 0;i < maxTeachmas;i++) {
				*(teachers + i) = *(temp + i);
			}
			delete[] temp;
			maxTeachmas = nmax;
		}
		
		teachers[curTeachmas++] = teach;
	}

	void addCr(Criterij obj1) {
		if (curCrmas == maxCrmas) {
			Criterij *cr = obj;
			int nmax = 2 * maxCrmas + 1;
			obj = new Criterij[nmax];
			for (int i = 0;i < maxCrmas;i++) {
				*(obj + i) = *(cr + i);
			}
			delete[] cr;
			maxCrmas = nmax;
		}
		obj[curCrmas++] = obj1;
	}

	int getcurStudMas() {
		return curStudmas;
	}

	int getcurTeachMas() {
		return curTeachmas;
	}

	int getcurCr() {
		return curCrmas;
	}

	Student* getStudwithKod(int);
	Teacher* getTeachbyKod(int);
	Student* delStud(string);
	Teacher* delTeach(string);
	Student* getStudents() {
		return &students[0];
	}
	Teacher* getTeachers() {
		return &teachers[0];
	}
	Criterij * getCriterij() {
		return &obj[0];
	}
};
Student* teamWork::getStudwithKod(int kod) {
	for (int i = 0;i < curStudmas;i++) {
		if (students[i].getkod() == kod) {
			return &students[i];
		}
	}
	return nullptr;
}
Teacher* teamWork::getTeachbyKod(int kod) {
	for (int i = 0;i < curTeachmas;i++) {
		if (teachers[i].getkod() == kod) {
			return &teachers[i];
}
	}
	return nullptr;
}
Student* teamWork::delStud(string firstname) {
	for (int i = 0;i < curStudmas;i++) {
		if (students[i].getfirstname() == firstname) {
			for (int j = 0;j < curStudmas - 1;i++) {
				students[j] = students[j - 1];
			}
			curStudmas--;
		}
	}
	return nullptr;
}
Teacher* teamWork::delTeach(string firstname) {
	for (int i = 0;i < curTeachmas;i++) {
		if (teachers[i].getfirstname() == firstname) {
			for (int j = 0;j < curTeachmas - 1;i++) {
				teachers[j] = teachers[j - 1];
			}
			curTeachmas --;
		}
	}
	return nullptr;
}
