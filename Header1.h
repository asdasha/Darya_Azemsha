//Criterij.h
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>

using namespace std;

class Criterij {
private:
	int kod;
	int kodS;
	int m;
	double sum;
	
public:
	Criterij(){}
	Criterij(int _kod, int _kodS, double _sum) {
		this->kod = _kod;
		this->kodS = _kodS;
		this->sum = _sum;
	}
	void cr() {
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
	}
		void getCR() {
		cout << "Код студента " << kodS << endl;
		cout << "Код преподавателя " << kod << endl;
		cout << "Средний балл преподавателя " << sum << endl;
	}
	friend ostream & operator <<(ostream & outc, const Criterij & obj) {
		outc << "Код студента " << obj.kodS << endl;
		outc << "Код преподавателя " << obj.kod << endl;
		outc << "Средний балл преподавателя " << obj.sum << endl;
		outc << endl;
		return outc;
	}

	friend istream & operator >>(istream &inc, Criterij &obj) {
		inc >> obj.kodS;
		inc >> obj.kod;
		inc >> obj.sum;
		return inc;
	}

};