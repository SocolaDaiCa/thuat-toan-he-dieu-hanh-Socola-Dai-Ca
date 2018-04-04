#include<iostream>
#include<fstream>
#include<conio.h>
#include<iomanip>
using namespace std;
#include"khung.cpp"
#include"4_bai_toan_lap_lich/fcfs.cpp"
#include"4_bai_toan_lap_lich/rr.cpp"
#include"4_bai_toan_lap_lich/sjf_k_chiem_doat.cpp"
#include"4_bai_toan_lap_lich/sjf_chiem_doat.cpp"
int main()
{
	int line=1;
//	fcfs(line), line++;
//	rr(line),line++;
//	sjf_k_chiem_doat(line), line++;
	sjf_chiem_doat(line), line++;
	gotoxy(0, line++),cout<<"Code by: Socola Dai Ca";
	gotoxy(0,0);
	while(true)	getch();
}

