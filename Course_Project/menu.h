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
			cout << "Выберите пункт меню" << endl;
			cout << "1 - Добавить студента" << endl;
			cout << "2 - Добавить преподавателя" << endl;
			cout << "3 - Удалить всех студентов" << endl;
			cout << "4 - Удалить всех преподавателей" << endl;
			cout << "5 - Удалить студента по фамилии" << endl;
			cout << "6 - Удалить преподавателя по фамилии" << endl;
			cout << "7 - Показать информацию о студентах" << endl;
			cout << "8 - Показать информацию о преподавателях" << endl;
			cout << "9 - Найти информацию о студенте по коду" << endl;
			cout << "10 - Найти информацию о преподавателе по коду" << endl;
			cout << "11 - Записать информацию о студентах в файл" << endl;
			cout << "12 - Записать информацию о преподавателях в файл" << endl;
			cout << "13 - Выйти" << endl;
			cout << "14 - Выставление критериев" << endl;
			cout << "15 - Запись рейтинга в файл" << endl;
			cout << "16 - Вывод информации о студентах из файла" << endl;
			cout << "17 - Вывод информации о препоавателях из файла" << endl;
			cout << "18 - Вывод информации о рейтинге из файла" << endl;
			cout << "19 - Добавить информацию о всех студентах" << endl;
			cout << "20 - Добавить информацию о всех преподавателях" << endl;
			cout << "21 - Вывод информации о рейтинге" << endl;
			cout << "22 - Ввод полной инофрмации о рейтинге" << endl;
			cout << "23 - Удалить весь рейтинг" << endl;
			cout << "***" << endl;
			cin >> ch;
			cout << "***" << endl;

			switch (ch) {
			case 1: {
				cout << "Добавить студента" << endl;
				obj->newStud();
				cout << endl;
				break;
			}
			case 2: {
				cout << "Добавить преподавателя" << endl;
				obj->newTeach();
				cout << endl;
				break;
			}
			case 3: {
				cout << "Удалить всех студентов" << endl;
				obj->delS();
				cout << endl;
				break;
			}
			case 4: {
				cout << "Удалить всех преподавателей" << endl;
				obj->delT();
				cout << endl;
				break;
			}
			case 5: {
				cout << "Удалить студента по фамилии" << endl;
				cout << "Введите, пожалуйста, фамилию: ";
				string firstname;
				cin >> firstname;
				 stud = obj->delStud(firstname);
				cout << "Студент " << firstname << " удален" << endl;
				break;
			}
			case 6: {
				cout << "Удалить студента по фамилии" << endl;
				cout << "Введите, пожалуйста, фамилию: ";
				string firstname;
				cin >> firstname;
				
				teach = obj->delTeach(firstname);
				cout << "Преподаватель " << firstname << " удален" << endl;
				break;
			}
			case 7: {
				cout << "Информация о студентах " << endl;
				obj->getStud();
				cout << endl;
				break;
			}
			case 8: {
					cout << "Информация о преподавателях " << endl;
					obj->getTeach();
					cout << endl;
					break;
			}
			case 9: {
				cout << "Найти информацию о студенте по коду" << endl;
				int cod;
				cout << "Введите, пожалуйста, код студента" << endl;
				cin >> cod;
				cout << endl;
				Student* stud = obj->getStudwithKod(cod);
				if (stud != nullptr) {
					stud->getStudent();
				}
				else {
					cout << "Студент с кодом " << cod << " не найден" << endl;
				}
				cout << endl;
				break;
			}
			case 10:
				cout << "Найти информацию о преподавателе по коду" << endl;
				int cod;
				cout << "Введите, пожалуйста, код преподавателя" << endl;
				cin >> cod;
				cout << endl;
				teach = obj->getTeachbyKod(cod);
				if (teach != nullptr) {
					teach->getTeacher();
				}
				else {
					cout << "Преподаватель с кодом " << cod << " не найден" << endl;
				}
				cout << endl;
				break;
			case 11:
				cout << "Сохранение данных о студентах в файл" << endl;
				file->toFile(obj);
				cout << endl;
				break;
			case 12:
				cout << "Сохранение данных о преподавателях в файл" << endl;
				file->TeacherToFile(obj);
				cout << endl;
				break;
			case 13: {
				exit(0);
				break;
			}
			case 14:
				cout << "Выставление рейтинга" << endl;
				obj->newCrit();
				cout << endl;
				break;
			case 15:
				cout << "Рейтинг преподавателя сохранен" << endl;
				file->crToFile(obj);
				cout << endl;
				break;
			case 16:
				cout << "Считать данные о студентах из файла" << endl;
				
				obj->getStud();
				cout << endl;
				break;
			case 17:
				cout << "Считать данные о преподавателях из файла" << endl;
				file->TeacherOutFile(obj);
				obj->getTeach();
				cout << endl;
				break;
			case 18:
				cout << "Считать данные о рейтинге из файла" << endl;
				obj->getCrit();
				cout << endl;
				break;
			case 19:
				cout << "Ввод информации о всех студентах" << endl;
				obj->setStudent();
				cout << endl;
				break;
			case 20:
				cout << "Ввод информации о всех преподавателях" << endl;
				obj->setTeach();
				cout << endl;
				break;
			case 21:
				cout << "Вывод рейтинга" << endl;
				obj->getCrit();
				cout << endl;
				break;
			case 22:
				cout << "Ввод полной информации о рейтинге" << endl;
				obj->setCrit();
				cout << endl;
				break;
			case 23: {
				cout << "Удалить весь рейтинг" << endl;
				obj->delC();
				cout << endl;
				break;
			}

			default: {
				cout << "Вы ввели неправильный номер" << endl;
				break;
			}
			}
		}
	}
};
