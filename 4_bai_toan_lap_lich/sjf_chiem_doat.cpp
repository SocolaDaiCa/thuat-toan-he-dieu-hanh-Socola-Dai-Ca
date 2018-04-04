class sfj_chiem_doat
{
	public:
		int index;
		int come;
		int start;
		int end;
		int time;
		int timeLeft;
//		int lich_thu;
//		float thoi_diem_den;
//		float thoi_diem_bat_dau_co_the_phuc_vu;
//		float thoi_diem_phuc_vu_xong;
//		float thoi_gian_phuc_vu;
//		float thoi_gian_con_phai_phuc_vu;
//		float thoi_gian_cho;
//		int check;
};
void SjfChiemDoatSort(sfj_chiem_doat *a, int n, int now){
	// sap xep thep thoi diem co the phuc vu giam dan
	for(int i=1; i<n; i++)
	{
		for(int j=i+1; j<=n; j++)
		{
			if(a[i].start < a[j].start)
				swap(a[i], a[j]);
		}
	}
	// sap xep theo thu tu gian dan cua thoi gian con phai phuc vu
	int i = n;
	while(a[i].start > now) i--;
	for(; i < n; i++){
		for(int j = i + 1; j <= n; j++){
			if(a[i].timeLeft < a[i].timeLeft){
				swap(a[i], a[j]);
			}
		}
	}
}
void sjf_chiem_doat(int &line){
	float now = 0, totalTime = 0;
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
		a[i].index=i;
		f>>a[i].come;
		a[i].start = a[i].come;
		f>>a[i].time;
		a[i].timeLeft=a[i].time;
		gotoxy(0, line++), cout<<"  P"<<i<<"\t\t   "<<a[i].come<<"\t\t   "<<a[i].time;
	}
	// ve khung
	int line_khung=line;
	line+=4;
	mo_khung(line_khung);
	gotoxy(0, line++), cout<<"thoi gian cho: "<<endl;
	int cot=0, n_tg=n;
	int dong=15;
	while(n > 0){
		SjfChiemDoatSort(a, n, now);
		// phuc vu
		now += a[i]
		ve_khung(line_khung, ++cot, a[n].index, now);
		if(a[n].timeLeft == 0) n--;
	}
}
