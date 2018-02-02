void sjf_k_chiem_doat(int &line)
{
	float thoi_gian_da_qua=0;
	float tong_thoi_gian_phuc_vu=0;
	int n;
	fstream f;
	f.open("sfj.txt", ios::in);
	f>>n;
	float thoi_diem_den[n+1];
	float thoi_gian_phuc_vu[n+1];
	int check[n+1];
	// hien de bai
	gotoxy(0, line++), cout<<"Cong viec ngan nhat truoc (SJF):";
	gotoxy(0, line++), cout<<"SJF khong chiem doat:";
	gotoxy(0, line++), cout<<"Process"<<" \t"<<"Arrival Time"<<"\t"<<"Burst Time";
	for(int i=1; i<=n; i++)
	{
		check[i]=0;
		f>>thoi_diem_den[i];
		f>>thoi_gian_phuc_vu[i];
		gotoxy(0, line++), cout<<"  P"<<i<<"\t\t   "<<thoi_diem_den[i]<<"\t\t   "<<thoi_gian_phuc_vu[i];
	}
	// ve khung
	int line_khung=line;
	line+=4;
	mo_khung(line_khung);
	float thoi_gian_cho[n+1];
	gotoxy(0, line++), cout<<"thoi gian cho: "<<endl;
	for(int i=1; i<=n; i++)
	{
		// tim thoi diem den dau tien thoa man
		for(int j=1; j<=n; j++)
		{
			if(thoi_diem_den[j]<=thoi_gian_da_qua && check[j]==0)
			{
				// tim tien trinh ngan nhat thoa man
				float thoi_gian_phuc_vu_min=thoi_gian_phuc_vu[j];
				int vi_tri=j;
				for(int k=j+1; k<=n; k++)
				{
					if(thoi_diem_den[k]<=thoi_gian_da_qua && thoi_gian_phuc_vu_min>thoi_gian_phuc_vu[k] && check[k]==0)
						thoi_gian_phuc_vu_min=thoi_gian_phuc_vu[k], vi_tri=k;
				}
				// tim duoc roi thi phuc vu
				check[vi_tri]=1;
				thoi_gian_cho[vi_tri]=thoi_gian_da_qua-thoi_diem_den[vi_tri];
				thoi_gian_da_qua+=thoi_gian_phuc_vu[vi_tri];
				ve_khung(line_khung, i, vi_tri, thoi_gian_da_qua);
				
				gotoxy(0, line++), cout<<"\tP"	<<vi_tri<<" = "<<thoi_gian_da_qua
										<<" - "<<thoi_diem_den[vi_tri]
										<<" - "<<thoi_gian_phuc_vu[vi_tri]
										<<" = "<<thoi_gian_cho[vi_tri];
				break;
			}
		}
	}
	dong_khung(line_khung, n+1);	
//	for(int i=1; i<=n; i++)
//	{
//		tong_thoi_gian_phuc_vu+=thoi_gian_phuc_vu[vi_tri[i]];
//		if(thoi_diem_den[vi_tri[i]]>thoi_gian_da_qua)
//			thoi_gian_cho[vi_tri[i]]=0;
//		else
//			thoi_gian_cho[vi_tri[i]]=thoi_gian_da_qua-thoi_diem_den[vi_tri[i]];
//		thoi_gian_da_qua=thoi_diem_den[vi_tri[i]]+thoi_gian_cho[vi_tri[i]]+thoi_gian_phuc_vu[vi_tri[i]];
//		
//		ve_khung(line_khung, i, vi_tri[i], tong_thoi_gian_phuc_vu);
//	}
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

