void fifo(int &line)
{
	int n;
	fstream f_in;
	f_in.open("3_thuat_toan_thay_the_trang.txt", ios::in);
	f_in>>n;
	int a[n+1];
	for(int i=1; i<=n; i++)
		f_in>>a[i];
	gotoxy(0, line++), cout<<"Thuat toan vao truoc ra truoc (FIFO):";
	int f[4], vt=1;
	f[1]=f[2]=f[3]=-1;
	ve_khung(5, n+1, line);
	hien_value(2, 1, " F1", line);
	hien_value(3, 1, " F2", line);
	hien_value(4, 1, " F3", line);
	hien_value(5, 1, " F ", line);
	for(int i=1; i<=n; i++)
	{
		hien_value(1, i+1, a[i], line);
		if(a[i]!=f[1] && a[i]!=f[2] && a[i]!=f[3])
		{
			f[vt]=a[i];
			vt++;
			if(vt>3)
				vt=1;
			hien_value(5, i+1, " x ", line);
		}
		hien_value(2, i+1, f[1], line);
		hien_value(3, i+1, f[2], line);
		hien_value(4, i+1, f[3], line);
	}
	line+=10;
}
