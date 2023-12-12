#pragma once

namespace ASD {
	class Window
	{
		int x, y, width, height;
		int color, bgColor;
		int MaxLen;
		int startPosY, startPosX;

	public:
		Window();
		~Window();
		void Move(int _x, int _y);
		int GetColor() { return color; }
		int GetBgColor() { return bgColor; }
		int GetX() { return x; }
		int GetY() { return y; }
		int GetWidth() { return width; }
		int GetHeight() { return height; }
		int GetMaxLen();
		void SetColor(int c);
		void SetBgColor(int c);
		void SetWidth(int w);
		void SetHeight(int h);
		void SetPos(int _x, int _y);
		void Show();
		void DrawMenu();
		void Clear();
		void Paint(int col, int bgCol);
		char* FillGap(const char *s);
		size_t my_strlen(const char* s);
		const char*  StartPos(const char *s);
		void SetStartPos(int posX, int posY);
		void DrawTriangle(int x1, int y1, int x2, int y2, int x3, int y3);
	};
}


