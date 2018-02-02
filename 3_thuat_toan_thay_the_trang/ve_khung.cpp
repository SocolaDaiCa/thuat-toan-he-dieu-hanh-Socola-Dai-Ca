char tren_trai=201;
char duoi_trai=200;
char tren_phai=187;
char duoi_phai=188;

char ngang_top_bot=205;
char doc_left_right=186;

char ngang=196;
char doc=179;
char cong=197;
#include<windows.h>
void gotoxy(int x, int y)
{
    static HANDLE h = NULL;
    if(!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };
    SetConsoleCursorPosition(h,c);
}
void ve_khung(int h, int c, int line)
{
	for(int i=0; i<=2*h; i++)
	{
		for(int j=0; j<=4*c; j++)
		{
			if(i==0 && j==0) 			gotoxy(j, line+i),cout<<tren_trai; else
			if(i==0 && j==4*c) 			gotoxy(j, line+i),cout<<tren_phai; else
			if(i==2*h && j==0) 			gotoxy(j, line+i),cout<<duoi_trai; else
			if(i==2*h && j==4*c) 		gotoxy(j, line+i),cout<<duoi_phai; else
			if(j==0 || j==4*c)			gotoxy(j, line+i),cout<<doc_left_right; else
			if(i==0 || i==h*2 || i==2)	gotoxy(j, line+i),cout<<ngang_top_bot; else
			if(i%2==0 && j%4==0)		gotoxy(j, line+i),cout<<cong; else
			if(i%2==0)					gotoxy(j, line+i),cout<<ngang; else
			if(j%4==0)					gotoxy(j, line+i),cout<<doc;
			;
		}
	}
}
