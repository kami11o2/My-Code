#include <iostream>
#include <string>
using namespace std;

class SinhVien
{
protected:
	string msv;
	string ten;
	string nganh;
	int tuoi;
public:
	void SetMSV(string a)
	{
		this->msv = a;
	}
	void SetTen(string a)
	{
		this->ten = a;
	}
	void SetNganh(string a)
	{
		this->nganh = a;
	}
	void SetTuoi(int a)
	{
		this->tuoi = a;
	}
	string GetMSV()
	{
		return msv;
	}
	virtual void SetLyThuyet(float a)=0;
	virtual void SetThucHanh(float a)=0;
	SinhVien(){}
	~SinhVien(){}
	virtual void Print()=0;
};

class ChuyenNganh: public SinhVien
{
protected:
	float dlt;
	float dth;
public:
	void SetMSV(string a)
	{
		this->msv = a;
	}
	void SetTen(string a)
	{
		this->ten = a;
	}
	void SetNganh(string a)
	{
		this->nganh = a;
	}
	void SetTuoi(int a)
	{
		this->tuoi = a;
	}
	void SetLyThuyet(float a)
	{
		this->dlt = a;
	}
	void SetThucHanh(float a)
	{
		this->dth = a;
	}
	string GetMSV()
	{
		return msv;
	}
	friend istream& operator >> (istream& in, ChuyenNganh &a)
	{
		in.ignore();
		cout<<"Nhap ma sinh vien  : ";
		getline(in,a.msv);
		cout<<"Nhap ten sinh vien : ";
		getline(in,a.ten);
		cout<<"Nhap nganh         : ";
		getline(in,a.nganh);
		cout<<"Nhap tuoi          : ";
		in>>a.tuoi;
		cout<<"Nhap diem ly thuyet: ";
		in>>a.dlt;
		cout<<"Nhap diem thuc hanh: ";
		in>>a.dth;
		return in;
	}
	ChuyenNganh(){}
	~ChuyenNganh(){}
	void Print()
	{
		cout<<"Ma sinh vien  : "<<msv<<endl;
		cout<<"Ho va ten     : "<<ten<<endl;
		cout<<"Nganh hoc     : "<<nganh<<endl;
		cout<<"Tuoi          : "<<tuoi<<endl;
		cout<<"Diem ly thuyet: "<<dlt<<endl;
		cout<<"Diem thuc hanh: "<<dth<<endl;
	}
};

class DaiCuong: public SinhVien
{
protected:
	float dlt;
	float dth;
public:
	void SetMSV(string a)
	{
		this->msv = a;
	}
	void SetTen(string a)
	{
		this->ten = a;
	}
	void SetNganh(string a)
	{
		this->nganh = a;
	}
	void SetTuoi(int a)
	{
		this->tuoi = a;
	}
	void SetLyThuyet(float a)
	{
		this->dlt = a;
	}
	void SetThucHanh(float a)
	{
		this->dth = a;
	}
	string GetMSV()
	{
		return msv;
	}
	friend istream& operator >> (istream& in, DaiCuong &a)
	{
		in.ignore();
		cout<<"Nhap ma sinh vien  : ";
		getline(in,a.msv);
		cout<<"Nhap ten sinh vien : ";
		getline(in,a.ten);
		cout<<"Nhap nganh         : ";
		getline(in,a.nganh);
		cout<<"Nhap tuoi          : ";
		in>>a.tuoi;
		cout<<"Nhap diem ly thuyet: ";
		in>>a.dlt;
		cout<<"Nhap diem thuc hanh: ";
		in>>a.dth;
		return in;
	}
	DaiCuong(){}
	~DaiCuong(){}
	void Print()
	{
		cout<<"Ma sinh vien  : "<<msv<<endl;
		cout<<"Ho va ten     : "<<ten<<endl;
		cout<<"Nganh hoc     : "<<nganh<<endl;
		cout<<"Tuoi          : "<<tuoi<<endl;
		cout<<"Diem ly thuyet: "<<dlt<<endl;
		cout<<"Diem thuc hanh: "<<dth<<endl;
	}
};

class Khoa
{
protected:
	string ten;
public:
	void SetTen(string a)
	{
		this->ten = a;
	}
	string GetTen()
	{
		return ten;
	}
	Khoa(){}
	~Khoa(){}
	friend istream& operator >> (istream& in, Khoa &a)
	{
		cout<<"Nhap ten khoa: ";
		in.ignore();
		getline(in,a.ten);
		return in;
	}
	friend ostream& operator << (ostream& out, Khoa &a)
	{
		out<<"Khoa: "<<a.ten<<endl;
		return out;
	}
};

class ChuyenNganhHoc
{
protected:
	string ten;
	string mn;
public:
	ChuyenNganhHoc(){}
	~ChuyenNganhHoc(){}
	void SetTen(string a)
	{
		this->ten = a;
	}
	string GetTen()
	{
		return ten;
	}
	void SetMa(string a)
	{
		this->mn = a;
	}
	string GetMa()
	{
		return mn;
	}
	friend istream& operator >> (istream& in, ChuyenNganhHoc &a)
	{
		cout<<"Nhap ten chuyen nganh: ";
		in.ignore();
		getline(in,a.ten);
		cout<<"Nhap ma chuyen nganh : ";
		in>>a.mn;
		return in;
	}
	friend ostream& operator << (ostream& out, ChuyenNganhHoc &a)
	{
		out<<"Chuyen nganh   : "<<a.ten<<endl;
		out<<"Ma chuyen nganh: "<<a.mn<<endl;
		return out;
	}
};

//===========================================================================

int SoSanhChuoi(string a, string b)
{
	int m = a.size(), h = b.size();
	if (m>h)
		return 1;
	if (h>m)
		return -1;
	for (int i=0; i<m; i++)
	{
		if (a[i]<b[i])
			return -1;
		if (b[i]<a[i])
			return 1;
	}
	return 0;
}

//============================================================================

int main()
{
	SinhVien* sv[100];
	Khoa k[100];
	ChuyenNganhHoc cnh[100];
	int markupdd[100];
	int ds=0,dsk=0,dscn=0,dsdd=0;
	int option,option1,option2,option3;
	do{
		cout<<"1. Quan ly sinh vien.\n";
		cout<<"2. Quan ly khoa.\n";
		cout<<"0. Thoat.\n";
		cout<<"Nhap chuc nang ban muon chon: ";
		cin>>option;
		if (option==1)
		{
			cout<<"1. Sinh vien chuyen nganh.\n";
			cout<<"2. Sinh vien dai cuong.\n";
			cout<<"3. Xoa thong tin sinh vien.\n";
			cout<<"4. Hien thi thong tin sinh vien.\n";
			cout<<"5. Sap xep thu tu sinh vien theo ma sinh vien.\n";
			cout<<"6. Hien thi thu tu cac sinh vien hien co.\n";
			cout<<"Nhap chuc nang ban muon chon: ";
			cin>>option1;
			if (option1==1)
			{
				cout<<"1. Them sinh vien.\n";
				cout<<"2. Sua thong tin sinh vien.\n";
				cout<<"Nhap chuc nang ban muon chon: ";
				cin>>option2;
				if (option2==1)
				{
					ChuyenNganh* svcn = new ChuyenNganh();
					cin>>*svcn;
					sv[ds]=svcn;
					ds++;
				}
				else if (option2==2)
				{
					cout<<"1. Sua ma sinh vien.\n";
					cout<<"2. Sua ten sinh vien.\n";
					cout<<"3. Sua nganh hoc.\n";
					cout<<"4. Sua tuoi sinh vien.\n";
					cout<<"5. Sua diem ly thuyet.\n";
					cout<<"6. Sua diem thuc hanh.\n";
					cout<<"Nhap chuc nang ban muon chon: ";
					cin>>option3;
					if (option3==1)
					{
						int markup,q=1;
						string fix,pick;
						cout<<"Nhap ma sinh vien cua sinh vien ban muon sua: ";
						cin>>pick;
						for (int i=0;i<=ds;i++)
						{
							if (sv[i]->GetMSV()==pick)
							{
								markup=i;
								break;
							}
							if (i==ds)
							{
								q=0;
							}
						}
						if (q==1)
						{
							cout<<"Nhap ma sinh vien sau khi sua: ";
							cin>>fix;
							sv[markup]->SetMSV(fix);
						}
						else
							cout<<"Khong co ma sinh vien nay.\n";
					}
					else if (option3==2)
					{
						int markup1,q1=1;
						string fix1,pick1;
						cout<<"Nhap ma sinh vien cua sinh vien ban muon sua: ";
						cin>>pick1;
						for (int i=0;i<=ds;i++)
						{
							if (sv[i]->GetMSV()==pick1)
							{
								markup1=i;
								break;
							}
							if (i==ds)
							{
								q1=0;
							}
						}
						if (q1==1)
						{
							cout<<"Nhap ten sinh vien sau khi sua: ";
							cin.ignore();
							getline(cin,fix1);
							sv[markup1]->SetTen(fix1);
						}
						else
							cout<<"Khong co ma sinh vien nay.\n";

					}
					else if (option3==3)
					{
						int markup2,q2=1;
						string fix2,pick2;
						cout<<"Nhap ma sinh vien cua sinh vien ban muon sua: ";
						cin>>pick2;
						for (int i=0;i<=ds;i++)
						{
							if (sv[i]->GetMSV()==pick2)
							{
								markup2=i;
								break;
							}
							if (i==ds)
							{
								q2=0;
							}
						}
						if (q2==1)
						{
							cout<<"Nhap nganh hoc cua sinh vien sau khi sua: ";
							cin.ignore();
							getline(cin,fix2);
							sv[markup2]->SetNganh(fix2);
						}
						else
							cout<<"Khong co ma sinh vien nay.\n";

					}
					else if (option3==4)
					{
						int markup3,fix3,q3=1;
						string pick3;
						cout<<"Nhap ma sinh vien cua sinh vien ban muon sua: ";
						cin>>pick3;
						for (int i=0;i<=ds;i++)
						{
							if (sv[i]->GetMSV()==pick3)
							{
								markup3=i;
								break;
							}
							if (i==ds)
							{
								q3=0;
							}
						}
						if (q3==1)
						{
							cout<<"Nhap tuoi sinh vien sau khi sua: ";
							cin>>fix3;
							sv[markup3]->SetTuoi(fix3);
						}
						else
							cout<<"Khong co ma sinh vien nay.\n";
					}
					else if (option3==5)
					{
						int markup4,fix4,q4=1;
						string pick4;
						cout<<"Nhap ma sinh vien cua sinh vien ban muon sua: ";
						cin>>pick4;
						for (int i=0;i<=ds;i++)
						{
							if (sv[i]->GetMSV()==pick4)
							{
								markup4=i;
								break;
							}
							if (i==ds)
							{
								q4=0;
							}
						}
						if (q4==1)
						{
							cout<<"Nhap diem ly thuyet cua sinh vien sau khi sua: ";
							cin>>fix4;
							sv[markup4]->SetLyThuyet(fix4);
						}
						else
							cout<<"Khong co ma sinh vien nay.\n";
					}
					else if (option3==6)
					{
						int markup5,fix5,q5=1;
						string pick5;
						cout<<"Nhap ma sinh vien cua sinh vien ban muon sua: ";
						cin>>pick5;
						for (int i=0;i<=ds;i++)
						{
							if (sv[i]->GetMSV()==pick5)
							{
								markup5=i;
								break;
							}
							if (i==ds)
							{
								q5=0;
							}
						}
						if (q5==1)
						{
							cout<<"Nhap diem thuc hanh cua sinh vien sau khi sua: ";
							cin>>fix5;
							sv[markup5]->SetLyThuyet(fix5);
						}
						else
							cout<<"Khong co ma sinh vien nay.\n";
					}
				}
			}
			else if (option1==2)
			{
				cout<<"1. Them sinh vien.\n";
				cout<<"2. Sua thong tin sinh vien.\n";
				cout<<"Nhap chuc nang ban muon chon: ";
				cin>>option2;
				if (option2==1)
				{
					DaiCuong* svdc = new DaiCuong();
					cin>>*svdc;
					sv[ds]=svdc;
					ds++;
				}
				else if (option2==2)
				{
					cout<<"1. Sua ma sinh vien.\n";
					cout<<"2. Sua ten sinh vien.\n";
					cout<<"3. Sua nganh hoc.\n";
					cout<<"4. Sua tuoi sinh vien.\n";
					cout<<"5. Sua diem ly thuyet.\n";
					cout<<"6. Sua diem thuc hanh.\n";
					cout<<"Nhap chuc nang ban muon chon: ";
					cin>>option3;
					if (option3==1)
					{
						int markup6,q6=1;
						string fix6,pick6;
						cout<<"Nhap ma sinh vien cua sinh vien ban muon sua: ";
						cin>>pick6;
						for (int i=0;i<=ds;i++)
						{
							if (sv[i]->GetMSV()==pick6)
							{
								markup6=i;
								break;
							}
							if (i==ds)
							{
								q6=0;
							}
						}
						if (q6==1)
						{
							cout<<"Nhap ma sinh vien sau khi sua: ";
							cin>>fix6;
							sv[markup6]->SetMSV(fix6);
						}
						else
							cout<<"Khong co ma sinh vien nay.\n";
					}
					else if (option3==2)
					{
						int markup7,q7=1;
						string fix7,pick7;
						cout<<"Nhap ma sinh vien cua sinh vien ban muon sua: ";
						cin>>pick7;
						for (int i=0;i<=ds;i++)
						{
							if (sv[i]->GetMSV()==pick7)
							{
								markup7=i;
								break;
							}
							if (i==ds)
							{
								q7=0;
							}
						}
						if (q7==1)
						{
							cout<<"Nhap ten sinh vien sau khi sua: ";
							cin.ignore();
							getline(cin,fix7);
							sv[markup7]->SetTen(fix7);
						}
						else
							cout<<"Khong co ma sinh vien nay.\n";
					}
					else if (option3==3)
					{
						int markup8,q8=1;
						string fix8,pick8;
						cout<<"Nhap ma sinh vien cua sinh vien ban muon sua: ";
						cin>>pick8;
						for (int i=0;i<=ds;i++)
						{
							if (sv[i]->GetMSV()==pick8)
							{
								markup8=i;
								break;
							}
							if (i==ds)
							{
								q8=0;
							}
						}
						if (q8==1)
						{
							cout<<"Nhap nganh hoc cua sinh vien sau khi sua: ";
							cin.ignore();
							getline(cin,fix8);
							sv[markup8]->SetNganh(fix8);
						}
						else
							cout<<"Khong co ma sinh vien nay.\n";
					}
					else if (option3==4)
					{
						int markup9,fix9,q9=1;
						string pick9;
						cout<<"Nhap ma sinh vien cua sinh vien ban muon sua: ";
						cin>>pick9;
						for (int i=0;i<=ds;i++)
						{
							if (sv[i]->GetMSV()==pick9)
							{
								markup9=i;
								break;
							}
							if (i==ds)
							{
								q9=0;
							}
						}
						if (q9==1)
						{
							cout<<"Nhap tuoi sinh vien sau khi sua: ";
							cin>>fix9;
							sv[markup9]->SetTuoi(fix9);
						}
						else
							cout<<"Khong co ma sinh vien nay.\n";
					}
					else if (option3==5)
					{
						int markup10,fix10,q10=1;
						string pick10;
						cout<<"Nhap ma sinh vien cua sinh vien ban muon sua: ";
						cin>>pick10;
						for (int i=0;i<=ds;i++)
						{
							if (sv[i]->GetMSV()==pick10)
							{
								markup10=i;
								break;
							}
							if (i==ds)
							{
								q10=0;
							}
						}
						if (q10==1)
						{
							cout<<"Nhap diem ly thuyet cua sinh vien sau khi sua: ";
							cin>>fix10;
							sv[markup10]->SetLyThuyet(fix10);
						}
						else
							cout<<"Khong co ma sinh vien nay.\n";
					}
					else if (option3==6)
					{
						int markup11,fix11,q11=1;
						string pick11;
						cout<<"Nhap ma sinh vien cua sinh vien ban muon sua: ";
						cin>>pick11;
						for (int i=0;i<=ds;i++)
						{
							if (sv[i]->GetMSV()==pick11)
							{
								markup11=i;
								break;
							}
							if (i==ds)
							{
								q11=0;
							}
						}
						if (q11==1)
						{
							cout<<"Nhap diem thuc hanh cua sinh vien sau khi sua: ";
							cin>>fix11;
							sv[markup11]->SetLyThuyet(fix11);
						}
						else
							cout<<"Khong co ma sinh vien nay.\n";
					}
				}
			}
			else if (option1==3)
			{
				int markupc,l1=1;
				string pickc;
				cout<<"Nhap ma sinh vien cua sinh vien ban muon xoa: ";
				cin>>pickc;
				for (int i=0;i<=ds;i++)
				{
					if (sv[i]->GetMSV()==pickc)
					{
						markupc=i;
						break;
					}
					if (i==ds)
					{
						l1=0;
					}
				}
				if (l1==1)
				{
					ds--;
					for (int i=markupc;i<ds;i++)
					{
						SinhVien* sv1;
						sv1 = sv[i+1];
						sv[i+1] = sv[i];
						sv[i] = sv1;
					}
					sv[ds]->SetMSV("Nope");
					cout<<"Xoa thong tin sinh vien thanh cong.\n";
				}
				else if (l1==0)
				{
					cout<<"Khong co ma sinh vien nay.\n";
				}
			}
			else if (option1==4)
			{
				int l=1;
				int markupc1;
				string pickc1;
				cout<<"Nhap ma sinh vien ban muon xem thong tin: ";
				cin>>pickc1;
				for (int i=0;i<=ds;i++)
				{
					if (sv[i]->GetMSV()==pickc1)
					{
						markupc1=i;
						break;
					}
					if (i==ds)
						l=0;
				}
				if (l==1)
					sv[markupc1]->Print();
				else if (l==0)
					cout<<"Khong co ma sinh vien nay.\n";
			}
			else if (option1==5)
			{
				SinhVien* svc;
				for (int i=0;i<ds;i++)
				{
					for (int j=i;j<ds;j++)
					{
						string ma1=sv[i]->GetMSV(),ma2=sv[j]->GetMSV();
						if (SoSanhChuoi(ma1,ma2)==1)
						{
							svc = sv[i];
							sv[i] = sv[j];
							sv[j] = svc;
						}
					}
				}
				cout<<"Da sap xep xong thu tu cac sinh vien!\n";
			}
			else if (option1==6)
			{
				for (int i=0;i<ds;i++)
				{
					cout<<"Thong tin sinh vien so "<<i<<": \n";
					sv[i]->Print();
				}
			}
		}
		else if (option==2)
		{
			cout<<"1. Quan ly khoa.\n";
			cout<<"2. Quan ly chuyen nganh hoc.\n";
			cout<<"Nhap chuc nang ban muon chon: ";
			cin>>option1;
			if (option1==1)
			{
				cout<<"1. Them khoa.\n";
				cout<<"2. Sua thong tin khoa.\n";
				cout<<"3. Xoa thong tin khoa.\n";
				cout<<"4. Hien thi thong tin khoa.\n";
				cout<<"Nhap chuc nang ban muon chon: ";
				cin>>option2;
				if (option2==1)
				{
					cin>>k[dsk];
					dsk++;
				}
				else if (option2==2)
				{
					int markupk,p1=1;
					cout<<"Nhap ten khoa ban muon sua: ";
					string checkk;
					cin>>checkk;
					for (int i=0;i<=dsk;i++)
					{
						if (k[i].GetTen()==checkk)
						{
							markupk=i;
							break;
						}
						if (i==dsk)
						{
							p1=0;
						}
					}
					if (p1==1)
					{
						cout<<"Nhap ten khoa sau khi sua: ";
						cin>>checkk;
						k[markupk].SetTen(checkk);
					}
					else
						cout<<"Khong co khoa nay trong danh sach!\n";
				}
				else if (option2==3)
				{
					int markupk1,k1=1;
					string pickk1;
					cout<<"Nhap khoa ban muon xoa: ";
					cin>>pickk1;
					for (int i=0;i<=dsk;i++)
					{
						if (k[i].GetTen()==pickk1)
						{
							markupk1=i;
							break;
						}
						if (i==dsk)
						{
							k1=0;
						}
					}
					if (k1==1)
					{
						dsk--;
						for (int i=markupk1;i<dsk;i++)
						{
							Khoa k1;
							k1 = k[i+1];
							k[i+1] = k[i];
							k[i] = k1;
						}
						k[dsk].SetTen("Nope");
						cout<<"Xoa thong tin khoa thanh cong.\n";
					}
					else
						cout<<"Khong co khoa nay trong danh sach!\n";
				}
				else if (option2==4)
				{
					cout<<"Cac khoa co trong danh sach: \n";
					for (int i=0;i<dsk;i++)
					{
						cout<<"- "<<k[i]<<endl;
					}
				}
			}
			else if (option1==2)
			{
				cout<<"1. Them chuyen nganh.\n";
				cout<<"2. Sua thong tin chuyen nganh.\n";
				cout<<"3. Xoa thong tin chuyen nganh.\n";
				cout<<"4. Hien thi thong tin chuyen nganh.\n";
				cout<<"Nhap chuc nang ban muon chon: ";
				cin>>option2;
				if (option2==1)
				{
					int m1=1;
					string tenk;
					cout<<"Nhap ten khoa ban muon them chuyen nganh hoc: ";
					cin>>tenk;
					for (int i=0;i<=dsk;i++)
					{
						if (k[i].GetTen()==tenk)
						{
							markupdd[dsdd]=i;
							dsdd++;
							break;
						}
						if (i==dsk)
						{
							m1=0;
						}
					}
					if (m1==1)
					{
						cin>>cnh[dscn];
						dscn++;
					}
					else
						cout<<"Khong co khoa nay!\n";
				}
				else if (option2==2)
				{
					cout<<"1. Sua ten chuyen nganh.\n";
					cout<<"2. Sua ma chuyen nganh.\n";
					cout<<"Nhap chuc nang ban muon chon: ";
					cin>>option3;
					if (option3==1)
					{
						int m2=1,markupcn;
						string tencn;
						cout<<"Nhap ten chuyen nganh hoc ban muon sua: ";
						cin>>tencn;
						for (int i=0;i<=dscn;i++)
						{
							if (cnh[i].GetTen()==tencn)
							{
								markupcn=i;
								break;
							}
							if (i==dscn)
							{
								m2=0;
							}
						}
						if (m2==1)
						{
							cout<<"Nhap ten chuyen nganh sau khi sua: ";
							cin>>tencn;
							cnh[markupcn].SetTen(tencn);
						}
						else
							cout<<"Khong co chuyen nganh nay!\n";
					}
					else if (option3==2)
					{
						int m3=1,markupcn1;
						string tencn1,macn;
						cout<<"Nhap ten chuyen nganh hoc ban muon sua: ";
						cin>>tencn1;
						for (int i=0;i<=dscn;i++)
						{
							if (cnh[i].GetTen()==tencn1)
							{
								markupcn1=i;
								break;
							}
							if (i==dscn)
							{
								m3=0;
							}
						}
						if (m3==1)
						{
							cout<<"Nhap ma chuyen nganh sau khi sua: ";
							cin>>macn;
							cnh[markupcn1].SetMa(macn);
						}
						else
							cout<<"Khong co chuyen nganh nay!\n";
					}

				}
				else if (option2==3)
				{
					int markupcn2,m4=1;
					string pickcn;
					cout<<"Nhap ten chuyen nganh ban muon xoa: ";
					cin>>pickcn;
					for (int i=0;i<=dscn;i++)
					{
						if (cnh[i].GetTen()==pickcn)
						{
							markupcn2=i;
							break;
						}
						if (i==dscn)
						{
							m4=0;
						}
					}
					if (m4==1)
					{
						dscn--;
						dsdd--;
						for (int i=markupcn2;i<dscn;i++)
						{
							int z = markupdd[i+1];
							markupdd[i+1] = markupdd[i];
							markupdd[i] = z;
							ChuyenNganhHoc cnh1;
							cnh1 = cnh[i+1];
							cnh[i+1] = cnh[i];
							cnh[i] = cnh1;
						}
						cnh[dscn].SetTen("Nope");
						cout<<"Xoa thong tin khoa thanh cong.\n";
					}
					else
						cout<<"Khong co chuyen nganh nay!\n";
				}
				else if (option2==4)
				{
					int m5=1,markupcn3;
					string pickcn1;
					cout<<"Nhap ten chuyen nganh ban muon xem thong tin: ";
					cin>>pickcn1;
					for (int i=0;i<=dscn;i++)
					{
						if (cnh[i].GetTen()==pickcn1)
						{
							markupcn3=i;
							break;
						}
						if (i==dscn)
						{
							m5=0;
						}
					}
					if (m5==1)
					{
						cout<<cnh[markupcn3];
						cout<<"Thuoc khoa: "<<k[markupdd[markupcn3]]<<endl;
					}
					else
						cout<<"Khong co chuyen nganh nay!\n";
				}
			}
		}
	}while(option!=0);
	for(int i = 0; i<ds; i++)
    {
    	delete sv[i];
    }
	return 0;
}
