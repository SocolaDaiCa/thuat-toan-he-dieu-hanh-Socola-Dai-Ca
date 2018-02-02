void rr(int &line)
{
	int n;
	float time_slice;
	int cot=1, hang=10;
	float tong_thoi_gian=0;
	int so_lich_phuc_vu_xong=0;
	//-------------------------------
	fstream f;
	f.open("rr.txt", ios::in);
	f>>n>>time_slice;
	float thoi_diem_den[n+1];
	float thoi_gian_phuc_vu[n+1];
	
	gotoxy(0, line++), cout<<"Lap lich Round-Robin(RR): "<<endl;
	gotoxy(0, line++), cout<<"Process"<<"\t "<<"Arrival Time"<<"\t"<<"Burst Time";
	for(int i=1; i<=n; i++)
	{
		f>>thoi_diem_den[i];
		f>>thoi_gian_phuc_vu[i];
		gotoxy(0, line++), cout<<"   P"<<i<<"\t\t"<<thoi_diem_den[i]<<"\t   "<<thoi_gian_phuc_vu[i];
	}
	
	mo_khung(line);
	
	for(int i=1;;i++)
	{
		if(thoi_diem_den[i]<=tong_thoi_gian && thoi_gian_phuc_vu[i]!=0) // phuc vu
		{
			if(thoi_gian_phuc_vu[i]>time_slice)
			{
				thoi_gian_phuc_vu[i]-=time_slice;
				tong_thoi_gian+=time_slice;
			}
			else
			{
				tong_thoi_gian+=thoi_gian_phuc_vu[i];
				thoi_gian_phuc_vu[i]=0;
			}
			ve_khung(line, cot++, i, tong_thoi_gian);
		}
		if(thoi_gian_phuc_vu[i]==0) so_lich_phuc_vu_xong++;
		if(so_lich_phuc_vu_xong==n)
			break;
		if(i==n) i=0,so_lich_phuc_vu_xong=0;
	}
	dong_khung(line, cot), line+=4;
}








