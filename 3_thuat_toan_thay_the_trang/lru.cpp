void lru(int &line)
{
	fstream f_cin;
	int n, *a;
	f_cin.open("3_thuat_toan_thay_the_trang.txt", ios::in);
	// nhap
	f_cin>>n;
	a=new int [n+1];
	for(int i=1; i<=n; i++)
		f_cin>>a[i];
	// thuat toan toi uu, phia sau
	// thuat toan
	int f[4];
	f[1]=f[2]=f[3]=-1;
	
	int khoang_cach[4];
	khoang_cach[1]=khoang_cach[2]=khoang_cach[3]=0;
	
	gotoxy(0, line++), cout<<"Thuat toan LRU: ";
	ve_khung(5, n+1, line);
	hien_value(2, 1, " F1", line);
	hien_value(3, 1, " F2", line);
	hien_value(4, 1, " F3", line);
	hien_value(5, 1, " F", line);
	for(int i=1; i<=n; i++)
	{
		hien_value(1, i+1, a[i], line);
		if(a[i]!=f[1] && a[i]!=f[2] && a[i]!=f[3])
		{
			hien_value(5, i+1, " x ", line);
			//do tam qua trong, tim khoang cach
			for(int i_f=1; i_f<=3; i_f++)
			{
				khoang_cach[i_f]=n+1;
				for(int j=i-1; j>=1; j--)
				{
					if(f[i_f]==a[j])
					{
						khoang_cach[i_f]=abs(i-j);
						break;
					}
				}
			}
			// tim tam quan trong min, 2 quan trong hon 1
			int khoang_cach_xa_nhat=max(khoang_cach[1], max(khoang_cach[2], khoang_cach[3]));
			
			int vi_tri;
			// chi ra vi tri
			for(int i_f=1; i_f<=3; i_f++)
			{
				if(khoang_cach[i_f]==khoang_cach_xa_nhat)
				{
					vi_tri=i_f;
					for(int i_f_2=i_f+1; i_f_2<=3; i_f_2++)
					{
						if(khoang_cach[i_f_2]==khoang_cach_xa_nhat && f[vi_tri]>f[i_f_2])
							vi_tri=i_f_2;
					}
					break;
				}
			}
			// thay the cai it quan trong bang cai dang can
			f[vi_tri]=a[i];
		}
		hien_value(2, i+1, f[1], line);
		hien_value(3, i+1, f[2], line);
		hien_value(4, i+1, f[3], line);	
	}
	line+=10;
}
