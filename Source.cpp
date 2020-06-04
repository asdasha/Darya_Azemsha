//source.cpp
	#include <iostream>
	#include <stdio.h>
	#include <string.h>
	#include <fstream>
	#include <Windows.h>
	#include "menu.h"

using namespace std;
int main() {
	system("chcp 1251");
	system("cls");
	teamWork obj;
	FileStudent obj3;
	menu obj1(&obj, &obj3);
	obj1.Menu();	
	system("pause");
	return(0);
}