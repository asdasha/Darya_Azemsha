//menu.h
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include "File.h"
using namespace std;

class menu {
private:
		teamWork * obj;
		FileStudent * file;
public:
	menu() {}
	menu(teamWork *_obj,FileStudent * _file) {
		this->obj = _obj;
		this->file = _file;
	}
	void Menu() {
		while (1) {
			string firstname;
			Student *stud;
			Teacher *teach;
			Criterij *cr;
			int ch;
			cout << "�������� ����� ����" << endl;
			cout << "1 - �������� ��������" << endl;
			cout << "2 - �������� �������������" << endl;
			cout << "3 - ������� ���� ���������" << endl;
			cout << "4 - ������� ���� ��������������" << endl;
			cout << "5 - ������� �������� �� �������" << endl;
			cout << "6 - ������� ������������� �� �������" << endl;
			cout << "7 - �������� ���������� � ���������" << endl;
			cout << "8 - �������� ���������� � ��������������" << endl;
			cout << "9 - ����� ���������� � �������� �� ����" << endl;
			cout << "10 - ����� ���������� � ������������� �� ����" << endl;
			cout << "11 - �������� ���������� � ��������� � ����" << endl;
			cout << "12 - �������� ���������� � �������������� � ����" << endl;
			cout << "13 - �����" << endl;
			cout << "14 - ����������� ���������" << endl;
			cout << "15 - ������ �������� � ����" << endl;
			cout << "16 - ����� ���������� � ��������� �� �����" << endl;
			cout << "17 - ����� ���������� � ������������� �� �����" << endl;
			cout << "18 - ����� ���������� � �������� �� �����" << endl;
			cout << "19 - �������� ���������� � ���� ���������" << endl;
			cout << "20 - �������� ���������� � ���� ��������������" << endl;
			cout << "21 - ����� ���������� � ��������" << endl;
			cout << "22 - ���� ������ ���������� � ��������" << endl;
			cout << "23 - ������� ���� �������" << endl;
			cout << "***" << endl;
			cin >> ch;
			cout << "***" << endl;

			switch (ch) {
			case 1: {
				cout << "�������� ��������" << endl;
				obj->newStud();
				cout << endl;
				break;
			}
			case 2: {
				cout << "�������� �������������" << endl;
				obj->newTeach();
				cout << endl;
				break;
			}
			case 3: {
				cout << "������� ���� ���������" << endl;
				obj->delS();
				cout << endl;
				break;
			}
			case 4: {
				cout << "������� ���� ��������������" << endl;
				obj->delT();
				cout << endl;
				break;
			}
			case 5: {
				cout << "������� �������� �� �������" << endl;
				cout << "�������, ����������, �������: ";
				string firstname;
				cin >> firstname;
				 stud = obj->delStud(firstname);
				cout << "������� " << firstname << " ������" << endl;
				break;
			}
			case 6: {
				cout << "������� �������� �� �������" << endl;
				cout << "�������, ����������, �������: ";
				string firstname;
				cin >> firstname;
				
				teach = obj->delTeach(firstname);
				cout << "������������� " << firstname << " ������" << endl;
				break;
			}
			case 7: {
				cout << "���������� � ��������� " << endl;
				obj->getStud();
				cout << endl;
				break;
			}
			case 8: {
					cout << "���������� � �������������� " << endl;
					obj->getTeach();
					cout << endl;
					break;
			}
			case 9: {
				cout << "����� ���������� � �������� �� ����" << endl;
				int cod;
				cout << "�������, ����������, ��� ��������" << endl;
				cin >> cod;
				cout << endl;
				Student* stud = obj->getStudwithKod(cod);
				if (stud != nullptr) {
					stud->getStudent();
				}
				else {
					cout << "������� � ����� " << cod << " �� ������" << endl;
				}
				cout << endl;
				break;
			}
			case 10:
				cout << "����� ���������� � ������������� �� ����" << endl;
				int cod;
				cout << "�������, ����������, ��� �������������" << endl;
				cin >> cod;
				cout << endl;
				teach = obj->getTeachbyKod(cod);
				if (teach != nullptr) {
					teach->getTeacher();
				}
				else {
					cout << "������������� � ����� " << cod << " �� ������" << endl;
				}
				cout << endl;
				break;
			case 11:
				cout << "���������� ������ � ��������� � ����" << endl;
				file->toFile(obj);
				cout << endl;
				break;
			case 12:
				cout << "���������� ������ � �������������� � ����" << endl;
				file->TeacherToFile(obj);
				cout << endl;
				break;
			case 13: {
				exit(0);
				break;
			}
			case 14:
				cout << "����������� ��������" << endl;
				obj->newCrit();
				cout << endl;
				break;
			case 15:
				cout << "������� ������������� ��������" << endl;
				file->crToFile(obj);
				cout << endl;
				break;
			case 16:
				cout << "������� ������ � ��������� �� �����" << endl;
				
				obj->getStud();
				cout << endl;
				break;
			case 17:
				cout << "������� ������ � �������������� �� �����" << endl;
				file->TeacherOutFile(obj);
				obj->getTeach();
				cout << endl;
				break;
			case 18:
				cout << "������� ������ � �������� �� �����" << endl;
				obj->getCrit();
				cout << endl;
				break;
			case 19:
				cout << "���� ���������� � ���� ���������" << endl;
				obj->setStudent();
				cout << endl;
				break;
			case 20:
				cout << "���� ���������� � ���� ��������������" << endl;
				obj->setTeach();
				cout << endl;
				break;
			case 21:
				cout << "����� ��������" << endl;
				obj->getCrit();
				cout << endl;
				break;
			case 22:
				cout << "���� ������ ���������� � ��������" << endl;
				obj->setCrit();
				cout << endl;
				break;
			case 23: {
				cout << "������� ���� �������" << endl;
				obj->delC();
				cout << endl;
				break;
			}

			default: {
				cout << "�� ����� ������������ �����" << endl;
				break;
			}
			}
		}
	}
};
