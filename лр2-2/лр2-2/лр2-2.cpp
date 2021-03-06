//Задания 7-10
#include "stdafx.h"
#include <windows.h>
#define _USE_MATH_DEFINES
#include <math.h>


#define pi 3.14

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//Процедура рисования линии
BOOL Line(HDC hdc, int x1, int y1, int x2, int y2);


int i = -150, xView, yView, j = 5, k = 500, l = -5, m = -200, n = 0, o = 500;
double y;


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
{
	HWND hWnd;
	MSG lpMsg;
	WNDCLASS w;

	w.lpszClassName = L"Graphic";
	w.hInstance = hInstance;
	w.lpfnWndProc = WndProc;
	w.hCursor = LoadCursor(NULL, IDC_ARROW);
	w.hIcon = 0;
	w.lpszMenuName = 0;
	w.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	w.style = CS_HREDRAW | CS_VREDRAW;
	w.cbClsExtra = 0;
	w.cbWndExtra = 0;

	//Если не удалось зарегистрировать класс окна - выходим
	if (!RegisterClass(&w))
		return 0;

	//Создадим окно в памяти, заполнив аргументы CreateWindow
	hWnd = CreateWindow(w.lpszClassName,
		L"График функции",
		WS_OVERLAPPEDWINDOW,
		100,
		100,
		500,
		400,
		(HWND)NULL,
		(HMENU)NULL,
		(HINSTANCE)hInstance,
		(HINSTANCE)NULL);

	//Выводим окно из памяти на экран
	ShowWindow(hWnd, nCmdShow);
	//Обновим содержимое окна
	UpdateWindow(hWnd);

	//Цикл обработки сообщений

	while (GetMessage(&lpMsg, NULL, 0, 0)) { //Получаем сообщение из очереди
		TranslateMessage(&lpMsg); //Преобразует сообщения клавиш в символы
		DispatchMessage(&lpMsg); //Передаёт сообщение соответствующей функции окна
	}
	return(lpMsg.wParam);
}

//Функция окна
LRESULT CALLBACK WndProc(HWND hWnd, UINT messg,
	WPARAM wParam, LPARAM lParam)
{
	HDC hdc; //создаём контекст устройства
	PAINTSTRUCT ps; //создаём экземпляр структуры графического вывода
	static HPEN hPen; //создаём перо
	static HPEN hPen1, hPen2, hPen3, hPen4;	
	int a=1, b=0, x_scr, y_scr;
	double NUM = 0;
	int ampl = 150;
	double x, h = M_PI / 10;//Цикл обработки сообщений
	switch (messg)
	{
	case WM_SIZE:
		xView = LOWORD(lParam);
		yView = HIWORD(lParam);


			//сообщение рисования
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		SetMapMode(hdc, MM_ISOTROPIC); //логические единицы отображаем, как физические
		SetWindowExtEx(hdc, 500, 500, NULL); //Длина осей
		SetViewportExtEx(hdc, xView, -yView, NULL); //Определяем облась вывода
		SetViewportOrgEx(hdc, xView / 6, yView / 2, NULL); //Начало координат
		

		hPen3 = CreatePen(PS_SOLID, 1, RGB(111, 40, 130));
		SelectObject(hdc, hPen3);
		while (m<600) {
			Line(hdc, m, 500, m, -300);
			m = m + 10;
		}

		while (o > -300) {
			Line(hdc, -150, o, 600, o);
			o = o - 10;
		}
		MoveToEx(hdc, 0, 0, NULL);
		hPen1 = CreatePen(PS_DASHDOT, 3, RGB(0, 0, 0));
		SelectObject(hdc, hPen1);
		Line(hdc, 0, -300, 0, 500);
		Line(hdc, -150, 0, 600, 0);
		MoveToEx(hdc, 0, 0, NULL);
		hPen2 = CreatePen(PS_DASH, 3, RGB(0, 0, 0));
		SelectObject(hdc, hPen2);
		while (i<600) {
			Line(hdc, i, j, i, j - 10);
			i = i + 10;
		}
		
		TextOut(hdc, 520, -15, L"x", 1);
		while (k > -300) {
			Line(hdc, l, k, l + 10, k);
			k = k - 10;
		}
		TextOut(hdc, 10, 230, L"y", 1);
		
		for (i = -300; i<600; i++) {
			y = 50.0*(log(i * 0.01));
			LineTo(hdc, i, (int)y);
		}
		MoveToEx(hdc, 0, -150, NULL);
		hPen4 = CreatePen(PS_SOLID, 3, RGB(252, 3, 3));
		SelectObject(hdc, hPen4);
		MoveToEx(hdc, -150, -30, NULL);
		
		for (int i = -150; i < xView+150; i++)
		{
			NUM = 0;
			for (int k = 1; k < 50; k = k + 2)
			{
				NUM += cos(k * 0.02 * (3 + i)) * sin(k / 2.0) / k;
			}
			NUM = NUM * 4 / 3.14;
			LineTo(hdc, i, yView * ( 0.45 * NUM));
		}
		MoveToEx(hdc, 0, 0, NULL);
		hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 250));
		SelectObject(hdc, hPen);
		MoveToEx(hdc, -450, 0, NULL);
		for (x = -5*M_PI, x_scr = -450; x < 500; x += h)
		{
			if (sin(x) == -1) ampl -= 10; // уменьшение амплинуды каждый раз как синусоида достигает своего минимального значения
			x_scr = x *5* M_PI; // частота колебания
			y_scr = (ampl * sin(x)); // +300 это смещение сигнала вниз по ОY
			LineTo(hdc, x_scr, y_scr);
		}
		ValidateRect(hWnd, NULL);
		EndPaint(hWnd, &ps);
		break;

		//сообщение выхода - разрушение окна
	case WM_DESTROY:
		DeleteObject(hPen1);
		DeleteObject(hPen2);
		DeleteObject(hPen3);
		DeleteObject(hPen4);
		DeleteObject(hPen);
		//не забываем уничтожать перья
		PostQuitMessage(0); //Посылаем сообщение выхода с кодом 0 - нормальное завершение
		break;

	default:
		return(DefWindowProc(hWnd, messg, wParam, lParam)); //освобождаем очередь приложения от нераспознаных
	}
	return 0;
}

//Функция рисования линии
BOOL Line(HDC hdc, int x1, int y1, int x2, int y2)
{
	MoveToEx(hdc, x1, y1, NULL); //сделать текущими координаты x1, y1
	return LineTo(hdc, x2, y2); //нарисовать линию
}