#include <iostream>
#include "Window.h"
#include "fun_console.h"

ASD::Window::Window() {
	x = y = 0;
	width = GetCols();
	height = GetRows();
	int color;
	int bgCOlor;
	MaxLen = 70;
	startPosY;


}

void ASD::Window::SetColor(int c) {
	color = c;
}
ASD::Window::~Window() {

}
void ASD::Window::SetStartPos(int posX, int posY) {
	this->startPosX = posX;
	this->startPosY = posY;
}
const char* ASD::Window::StartPos(const char *s) {
	this->SetPos(this->startPosX, this->startPosY++);
	this->Paint(this->color, this->bgColor);
	std::cout << this->FillGap(s);
	return 0;
}
void ASD::Window::SetBgColor(int c) {
	bgColor = c;
}

void ASD::Window::Move(int _x, int _y) {
	if (_x + width <= GetCols()) {
		x = _x;
	}
	else {
		width -= (_x - x);
		x = _x;
	}

	if (_y + height <= GetRows()) {
		y = _y;
	}
	else {
		height -= (_y - y);
		y = _y;
	}
}

void ASD::Window::SetWidth(int w) {
	if (w >= 3 && x + w <= GetCols()) {
		width = w;
	}
}

void ASD::Window::SetHeight(int h) {
	if (h >= 3 && y + h <= GetRows()) {
		height = h;
	}
}
void ASD::Window::Clear() {
	this->Paint(White, Black);
	cls();


}
int ASD::Window::GetMaxLen() {
	return MaxLen;
}
void ASD::Window::Paint(int col, int bgCol) {
	this->color = col;
	this->bgColor = bgCol;
	::SetColor(this->color, this->bgColor);
}
size_t ASD::Window::my_strlen(const char *s) {
	const char* cur = s;
	for (; *cur; ++cur);
	return (cur - s);
}
char* ASD::Window::FillGap(const char *s) {
	int strLen = this->my_strlen(s);
	int rest = (this->GetMaxLen() - strLen) - 2;
	char *Space = new char[rest + 1];

	for (int i = 0; i < strLen; i++) {
		std::cout << s[i];
	}
	for (int i = 0; i < rest; i++) {
		Space[i] = ' ';
	}
	Space[rest] = '\0';
	return Space;
}
void ASD::Window::Show() {


	for (int i = 0; i < height; i++) {
		GotoXY(x, y + i);
		for (int j = 0; j < width; j++) {
			std::cout << " ";
		}
	}
	GotoXY(x, y);
}
void ASD::Window::SetPos(int _x, int _y) {
	GotoXY(_x, _y);
}
void ASD::Window::DrawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
	SetPos(15, 2);
	this->SetBgColor(Black);
	this->SetColor(White);
	std::cout << "		  (" << x1 << ", " << y1 << ")\n";
	this->SetStartPos(15, 3);
	StartPos("		    /\\");
	this->SetStartPos(15, 4);
	StartPos("		   /  \\");
	this->SetStartPos(15, 5);
	StartPos("		  /    \\");
	this->SetStartPos(15, 6);
	StartPos("		 /      \\");
	this->SetStartPos(15, 7);
	StartPos("		/        \\");
	this->SetStartPos(15, 8);
	StartPos("	       ------------");
	std::cout << "\n	          (" << x2 << ", " << y2 << ")	" << "(" << x3 << ", " << y3 << ")";







}
void ASD::Window::DrawMenu() {

	this->SetStartPos(15, 8);
	//this->Clear();
	this->SetBgColor(Red);
	this->SetColor(White);
	StartPos("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
	StartPos("                 Виберіть Пункт меню:");
	StartPos("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
	this->SetStartPos(15, 11);
	this->SetBgColor(White);
	this->SetColor(Black);

	StartPos("[1]- Задати текст для сортування");
	this->SetBgColor(Green);
	this->SetColor(Black);
	StartPos("[2]- Відсортувати, та отримати результат");
	this->SetBgColor(LightMagenta);
	this->SetColor(Black);
	StartPos("[0]- Вийти");
	this->SetStartPos(15, 21);
	StartPos("Введіть пункт меню: ");
	SetPos(35, 21);



}