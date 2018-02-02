#include<windows.h>
void gotoxy(int x, int y)
{
    static HANDLE h = NULL;
    if(!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };
    SetConsoleCursorPosition(h,c);
}
char tren_trai=201;
char duoi_trai=200;
char tren_phai=187;
char duoi_phai=188;

char ngang_top_bot=205;
char doc_left_right=186;

char ngang=196;
char doc=179;
char cong=197;
char cong_to=206;
char re_trai=204;
char re_tren=203;
char re_phai=185;

void ve_khung(int hang, int cot, int i, int value)
{
	gotoxy(cot*4-3, hang);
	cout<<ngang_top_bot<<ngang_top_bot<<ngang_top_bot<<re_tren;
	gotoxy(cot*4-3, ++hang);	cout<<"P"<<i;
	gotoxy(cot*4, hang), cout<<doc_left_right;
	gotoxy(cot*4-3, ++hang);
	cout<<ngang_top_bot<<ngang_top_bot<<ngang_top_bot<<cong_to;
	gotoxy(cot*4, ++hang), cout<<value;
}
void mo_khung(int hang)
{
	gotoxy(0, hang), cout<<tren_trai;
	gotoxy(0, ++hang), cout<<doc_left_right;
	gotoxy(0, ++hang), cout<<re_trai;
	gotoxy(0, ++hang), cout<<"0";
}
void dong_khung(int hang, int cot)
{
	gotoxy(cot*4-4, hang), cout<<tren_phai;
	gotoxy(cot*4, ++hang);
	gotoxy(cot*4-4, ++hang), cout<<re_phai;
}
