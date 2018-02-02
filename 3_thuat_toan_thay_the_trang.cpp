#include<iostream>
#include<windows.h>
#include<iomanip>
#include<conio.h>
#include<fstream>
using namespace std;
#include"3_thuat_toan_thay_the_trang/ve_khung.cpp"
void hien_value(int h, int c, int value, int line) // so
{
	gotoxy(4*c-3, line+2*h-1);
	if(value<10)
	{
		if(value>-1) cout<<" "<<value;
	}
	else
	if(value<100) cout<<value; else
	cout<<value;
}
void hien_value(int h, int c, char*value, int line)
{
	gotoxy(4*c-3, line+2*h-1);
	cout<<value;
}
#include"3_thuat_toan_thay_the_trang/fifo.cpp"
#include"3_thuat_toan_thay_the_trang/thuat_toan_toi_uu.h"
#include"3_thuat_toan_thay_the_trang/lru.cpp"
int main()
{
	int line=0;
	fifo(line), line++;
	thuat_toan_toi_uu(line), line++;
	lru(line), line++;
	gotoxy(0, line++),cout<<"Code by: Socola Dai Ca";
	gotoxy(0,0),getch();
}
