void fcfs(int &line)
{
	float thoi_gian_da_qua=0;
	float tong_thoi_gian_phuc_vu=0;
	
	int n;
	fstream f;
	f.open("fcfs.txt", ios::in);
	f>>n;
	float thoi_diem_den[n+1];
	float thoi_gian_phuc_vu[n+1];
	
	gotoxy(0, line++), cout<<"Den truoc - Phuc vu truoc (FCFS)";
	gotoxy(0, line++), cout<<"Process"<<" \t"<<"Arrival Time"<<"\t"<<"Burst Time";
	for(int i=1; i<=n; i++)
	{
		f>>thoi_diem_den[i];
		f>>thoi_gian_phuc_vu[i];
		gotoxy(0, line++), cout<<"  P"<<i<<"\t\t   "<<thoi_diem_den[i]<<"\t\t   "<<thoi_gian_phuc_vu[i];
	}
	
	int line_khung=line;
	line+=4;
	mo_khung(line_khung);
	float *thoi_gian_cho=new float [n+1];
	gotoxy(0, line++), cout<<"thoi gian cho: "<<endl;
	for(int i=1; i<=n; i++)
	{
		tong_thoi_gian_phuc_vu+=thoi_gian_phuc_vu[i];
		if(thoi_diem_den[i]>thoi_gian_da_qua)
			thoi_gian_cho[i]=0;
		else
			thoi_gian_cho[i]=thoi_gian_da_qua-thoi_diem_den[i];
		thoi_gian_da_qua=thoi_diem_den[i]+thoi_gian_cho[i]+thoi_gian_phuc_vu[i];
		gotoxy(0, line++), cout<<"\tP"	<<i<<" = "<<tong_thoi_gian_phuc_vu
										<<" - "<<thoi_diem_den[i]
										<<" - "<<thoi_gian_phuc_vu[i]
										<<" = "<<thoi_gian_cho[i];
		ve_khung(line_khung, i, i, tong_thoi_gian_phuc_vu);
	}
	dong_khung(line_khung, n+1);
	gotoxy(0, line++), cout<<"thoi gian cho trung binh = (";
	float tong=0;
	for(int i=1; i<=n; i++)
	{
		cout<<thoi_gian_cho[i];
		tong+=thoi_gian_cho[i];
		if(i<n) cout<<" + ";
			else cout<<")/"<<n<<" = "<<tong/n;
	}
	gotoxy(0, line++), cout<<"thoi gian luu: ";
	for(int i=1; i<=n; i++)
	{
		gotoxy(0, line++), cout<<"\tP"<<i<<" = "<<thoi_gian_cho[i]<<" + "<<thoi_gian_phuc_vu[i]<<" = "<<( thoi_gian_cho[i]+thoi_gian_phuc_vu[i] );
	}
	gotoxy(0, line++), cout<<"Thoi gian luu trung binh = (";
	tong=0;
	for(int i=1; i<=n; i++)
	{
		cout<<( thoi_gian_cho[i]+thoi_gian_phuc_vu[i] );
		tong+=( thoi_gian_cho[i]+thoi_gian_phuc_vu[i] );
		if(i<n) cout<<" + ";
		else cout<<" )/"<<n<<" = "<<tong/n;
	}
}
