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
		cout << "������� ��� ��������" << endl;
		cin >> kodS;
		cout << "������� ��� �������������" << endl;
		cin >> kod;
		sum = 0;
		cout << "���������������� � �������������� �������������" << endl;
		cin >> m;
		sum += m;
		cout << "�������� ���������� � ������������ ������������� ������� �� ��������" << endl;
		cin >> m;
		sum += m;
		cout << "�������������� ���������� � ����������� ����������� ���������" << endl;
		cin >> m;
		sum += m;
		cout << "����� � ������������ �������������" << endl;
		cin >> m;
		sum += m;
		cout << "������������� ����������� ������� ��������" << endl;
		cin >> m;
		sum += m;
		cout << "����������� ��������� � ������� ������������" << endl;
		cin >> m;
		sum += m;
		cout << "������ �������� � ����������" << endl;
		cin >> m;
		sum += m;
		cout << "������������� ��������� ���� ����������� � ������ ������� ����������" << endl;
		cin >> m;
		sum += m;
		cout << "�������� � �������� ����" << endl;
		cin >> m;
		sum += m;
		cout << "�������������, �������� � ����������� � ��������� � ���������" << endl;
		cin >> m;
		sum += m;
		cout << "������� ��� �������������" << endl;
		cin >> m;
		sum += m;
		sum = sum / 11;
		cout << sum;
	}
		void getCR() {
		cout << "��� �������� " << kodS << endl;
		cout << "��� ������������� " << kod << endl;
		cout << "������� ���� ������������� " << sum << endl;
	}
	friend ostream & operator <<(ostream & outc, const Criterij & obj) {
		outc << "��� �������� " << obj.kodS << endl;
		outc << "��� ������������� " << obj.kod << endl;
		outc << "������� ���� ������������� " << obj.sum << endl;
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