class sfj_chiem_doat
{
	public:
		int lich_thu;
		float thoi_diem_den;
		float thoi_diem_bat_dau_co_the_phuc_vu;
		float thoi_diem_phuc_vu_xong;
		float thoi_gian_phuc_vu;
		float thoi_gian_con_phai_phuc_vu;
		float thoi_gian_cho;
		int check;
};

class SX
{
	public:
		void theo_thoi_diem_bat_dau_co_the_phuc_vu(sfj_chiem_doat *a, int n) // theo thoi diem den, den truoc dung cuoi
		{
			for(int i=1; i<n; i++)
			{
				for(int j=i+1; j<=n; j++)
				{
					if(a[i].thoi_diem_bat_dau_co_the_phuc_vu<a[j].thoi_diem_bat_dau_co_the_phuc_vu)
						swap(a[i], a[j]);
				}
			}
		}
	void theo_thoi_gian_con_phai_phuc_vu(sfj_chiem_doat *a, int n)
	{
		for(int i=1; i<n; i++)
		{
			int vi_tri_cuoi=i;
			for(int j=i+1; j<=n; j++)
			{
				if(a[i].thoi_diem_bat_dau_co_the_phuc_vu==a[j].thoi_diem_bat_dau_co_the_phuc_vu)
					vi_tri_cuoi=j;
				else
					break;
			}
			for(int j=i; j<vi_tri_cuoi; j++) // theo thoi gian con phai phuc vu, cang nho thi o cuoi
			{
				for(int k=j+1; k<=vi_tri_cuoi; k++)
				{
					if(a[j].thoi_gian_con_phai_phuc_vu<a[k].thoi_gian_con_phai_phuc_vu)
						swap(a[j], a[k]);
				}
			}
			i=vi_tri_cuoi;
		}
	}
};

void sjf_chiem_doat(int &line)
{
	SX sx;
	float thoi_gian_da_qua=0;
//	float tong_thoi_gian_phuc_vu=0;
	int n;
	fstream f;
	f.open("sfj.txt", ios::in);
	f>>n;
	sfj_chiem_doat a[n+1];
	// hien de bai
	gotoxy(0, line++), cout<<"Cong viec ngan nhat truoc (SJF):";
	gotoxy(0, line++), cout<<"SJF chiem doat:";
	gotoxy(0, line++), cout<<"Process"<<" \t"<<"Arrival Time"<<"\t"<<"Burst Time";
	for(int i=1; i<=n; i++)
	{
		a[i].lich_thu=i;
		f>>a[i].thoi_diem_den;
		a[i].thoi_diem_bat_dau_co_the_phuc_vu=a[i].thoi_diem_den;
		
		f>>a[i].thoi_gian_phuc_vu;
		a[i].thoi_gian_con_phai_phuc_vu=a[i].thoi_gian_phuc_vu;
		gotoxy(0, line++), cout<<"  P"<<i<<"\t\t   "<<a[i].thoi_diem_den<<"\t\t   "<<a[i].thoi_gian_phuc_vu;
	}
	// ve khung
	int line_khung=line;
	line+=4;
	mo_khung(line_khung);
	gotoxy(0, line++), cout<<"thoi gian cho: "<<endl;
	int cot=0, n_tg=n;
	int dong=15;
	while(n!=1)
	{
		sx.theo_thoi_diem_bat_dau_co_the_phuc_vu(a, n);
		sx.theo_thoi_gian_con_phai_phuc_vu(a, n);
//		for(int i=1; i<=n; i++)
//			gotoxy(0, dong++), cout<<"p"<<a[i].lich_thu<<": "<<a[i].thoi_diem_bat_dau_co_the_phuc_vu<<";"<<a[i].thoi_gian_con_phai_phuc_vu;
//		gotoxy(0, dong++),cout<<"xong";
		float thoi_diem_den_lien_sau=a[n].thoi_diem_bat_dau_co_the_phuc_vu;
		for(int i=n-1; i>=1; i--)
		{
			if(thoi_diem_den_lien_sau!=a[i].thoi_diem_bat_dau_co_the_phuc_vu)
			{
				thoi_diem_den_lien_sau=a[i].thoi_diem_bat_dau_co_the_phuc_vu;
				break;
			}
		}
		if(a[n].thoi_diem_bat_dau_co_the_phuc_vu<thoi_diem_den_lien_sau)
		{
			thoi_gian_da_qua+=thoi_diem_den_lien_sau-a[n].thoi_diem_bat_dau_co_the_phuc_vu;
			a[n].thoi_gian_con_phai_phuc_vu-=(thoi_diem_den_lien_sau-a[n].thoi_diem_bat_dau_co_the_phuc_vu);
		}
		else
		{
			thoi_gian_da_qua+=a[n].thoi_gian_con_phai_phuc_vu;
			a[n].thoi_gian_con_phai_phuc_vu=0;
		}
		for(int i=1; i<=n; i++)
		{
			if(a[i].thoi_diem_bat_dau_co_the_phuc_vu<thoi_gian_da_qua)
				a[i].thoi_diem_bat_dau_co_the_phuc_vu=thoi_gian_da_qua;
		}
		ve_khung(line_khung, ++cot, a[n].lich_thu, thoi_gian_da_qua);
		if(a[n].thoi_gian_con_phai_phuc_vu==0) // neu phu vu xong thi
		{
			a[n].thoi_diem_phuc_vu_xong=thoi_gian_da_qua;
			n--;
		}
	}
	thoi_gian_da_qua+=a[n].thoi_gian_con_phai_phuc_vu;
	a[n].thoi_gian_con_phai_phuc_vu=0;
	if(a[n].thoi_gian_con_phai_phuc_vu==0) // neu phu vu xong thi
	{
		a[n].thoi_diem_phuc_vu_xong=thoi_gian_da_qua;
//		n--;
	}
	ve_khung(line_khung, ++cot, a[n].lich_thu, thoi_gian_da_qua);
	
	dong_khung(line_khung, cot+1);	
	for(int i=1; i<=n_tg; i++)
	{
		gotoxy(0, line++);
		cout<<"P"<<a[i].lich_thu<<" = "
			<<a[i].thoi_diem_phuc_vu_xong<<" - "
			<<a[i].thoi_diem_den<<" - "
			<<a[i].thoi_gian_phuc_vu<<" = "
			<<a[i].thoi_diem_phuc_vu_xong-a[i].thoi_diem_den-a[i].thoi_gian_phuc_vu;
	}
	
	gotoxy(0, line++), cout<<"thoi gian cho trung binh = (";
	float tong=0;
	for(int i=1; i<=n_tg; i++)
	{
		cout<<a[i].thoi_diem_phuc_vu_xong-a[i].thoi_diem_den-a[i].thoi_gian_phuc_vu;
		tong+=a[i].thoi_diem_phuc_vu_xong-a[i].thoi_diem_den-a[i].thoi_gian_phuc_vu;
		if(i!=n_tg)
			cout<<" + ";
		else
			cout<<" )/"<<n_tg<<" = "<<tong/n_tg;
	}
//	for(int i=1; i<=n; i++)
//	{
//		cout<<thoi_gian_cho[i];
//		tong+=thoi_gian_cho[i];
//		if(i<n) cout<<" + ";
//			else cout<<")/"<<n<<" = "<<tong/n;
//	}
//	gotoxy(0, line++), cout<<"thoi gian luu: ";
//	for(int i=1; i<=n; i++)
//	{
//		gotoxy(0, line++), cout<<"\tP"<<i<<" = "<<thoi_gian_cho[i]<<" + "<<thoi_gian_phuc_vu[i]<<" = "<<( thoi_gian_cho[i]+thoi_gian_phuc_vu[i] );
//	}
//	gotoxy(0, line++), cout<<"Thoi gian luu trung binh = (";
//	tong=0;
//	for(int i=1; i<=n; i++)
//	{
//		cout<<( thoi_gian_cho[i]+thoi_gian_phuc_vu[i] );
//		tong+=( thoi_gian_cho[i]+thoi_gian_phuc_vu[i] );
//		if(i<n) cout<<" + ";
//		else cout<<" )/"<<n<<" = "<<tong/n;
//	}
	
}
