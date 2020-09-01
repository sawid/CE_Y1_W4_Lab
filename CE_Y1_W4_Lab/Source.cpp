#include <stdio.h>
#include <conio.h>
#include <windows.h>
void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void draw_ship(int x,int y)
{
	gotoxy(x, y);
	printf(" <-0-> ");
}
void erase_ship(int x, int y) {
	gotoxy(x, y);
	printf("       ");
}
int main()
{
	char ch = ' ';
	int x = 38, y = 20;
	draw_ship(x, y);
	do {
		if (_kbhit()) {
			ch = _getch();
			if (ch == 'a') { 
				--x;
				if (x <= 0) {
					x = 0;
				}
				draw_ship(x, y); 
			}
			if (ch == 'd') {
				++x;
				if (x >= 75) {
					x = 75;
				}
				draw_ship(x, y); 
			}
			if (ch == 'w') {
				--y;
				if (y <= 0) {
					y = 0;
				}
				erase_ship(x,++y);
				draw_ship(x, --y);
			}
			if (ch == 's') {
				++y;
				if (y >= 23) {
					y = 23;
				}
				erase_ship(x, --y);
				draw_ship(x, ++y);
			}
			fflush(stdin);
		}
		Sleep(100);
	} while (ch != 'x');
	return 0;
}