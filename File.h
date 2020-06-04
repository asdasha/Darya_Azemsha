//file.h
#include <fstream>
#include <Windows.h>
#include <string>

#include "teach-Student.h"

using namespace std;

class FileStudent {
public:
	void toFile(teamWork * obj) {
		ofstream output("Student.txt", ofstream::app);
		if (output.is_open()) {
			SetConsoleCP(1251);
			int size = obj->getcurStudMas();
			for (int i = 0;i < size;i++) {
				output << (obj->getStudents()[i]);
			}
			SetConsoleCP(866);
			output.close();
		}
		else {
			cout << "Error!!!" << endl;
		}
	}
	void STuFile(teamWork * obj) {
		ofstream output("student.txt", ofstream::app);
		if (output.is_open()) {
			SetConsoleCP(1251);
			int size = obj->getcurStudMas();
			for (int i = 0;i < size;i++) {
				output << (obj->getStudents()[i]);
			}
			SetConsoleCP(866);
			output.close();
		}
		else {
			cout << "Error!!!" << endl;
		}
	}
	void TeacherToFile(teamWork * obj){
		ofstream outt;
		outt.open("teacher.txt");
		if (outt.is_open()) {
			int size = obj->getcurTeachMas();
			for (int i = 0;i < size;i++) {
				outt << obj->getTeachers()[i];
			}
			outt.close();
		}
		else {
			cout << "Error!!!" << endl;
		}
	}
	void crToFile(teamWork * obj) {
		ofstream outc;
		outc.open("rating.txt");
		if (outc.is_open()) {
			int size = obj->getcurCr();
			for (int i = 0;i < size;i++) {
				outc << obj->getCriterij()[i];
			}
			outc.close();
		}
		else {
			cout << "Error!!!" << endl;
		}
	}

	void outFile(teamWork * obj){
		ifstream in("Student.txt", ifstream::app);
		if (in.is_open()) {
			while (!in.eof()) {
				Student stud;
				in >> stud;
				cout << stud << endl;
		}
			in.close();
		}
		else {
			cout << "Error!!!" << endl;
		}
	}
	void TeacherOutFile(teamWork * obj){
		ifstream inteach("teacher.txt", ifstream::app);
		if (inteach.is_open()) {
			int size;
			inteach >> size;
			for (int i = 0;i < size;i++) {
				Teacher teach;
				inteach >> teach;
				obj->addTeach(teach);
				while (inteach.read((char*)&teach, sizeof(Teacher))) {
					teach.getTeacher();
				}
			}
			inteach.close();
		}
		else {
			cout << "Error!!!" << endl;
		}
	}
	void crOutFile(teamWork * obj){
		ifstream incr("rating.txt", ifstream::app);
		if (incr.is_open()) {
			int size;
			incr >> size;
			for (int i = 0;i < size;i++) {
				Criterij cr;
				incr >> cr;
				obj->addCr(cr);
				while (incr.read((char*)&cr, sizeof(Criterij))) {
					cr.getCR();
				}
			}
			incr.close();
		}
		else {
			cout << "Error!!!" << endl;
		}
	}
};