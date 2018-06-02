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
		getline(in,a.ten);
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

int main()
{
	SinhVien* sv[100];
	int ds=0;
	int option,option1,option2,option3;
	do{
		cout<<"1. Quan ly sinh vien.\n";
		cout<<"2. Quan ly khoa.\n";
		cout<<"Nhap chuc nang ban muon chon: ";
		cin>>option;
		if (option==1)
		{
			cout<<"1. Sinh vien chuyen nganh.\n";
			cout<<"2. Sinh vien dai cuong.\n";
			cout<<"3. Xoa thong tin sinh vien.\n";
			cout<<"4. Hien thi thong tin sinh vien.\n";
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
						int markup;
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
								cout<<"Khong co ma sinh vien nay.\n";
							}
						}
						cout<<"Nhap ma sinh vien sau khi sua: ";
						cin>>fix;
						sv[markup]->SetMSV(fix);
					}
					else if (option3==2)
					{
						int markup1;
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
								cout<<"Khong co ma sinh vien nay.\n";
							}
						}
						cout<<"Nhap ten sinh vien sau khi sua: ";
						cin.ignore();
						getline(cin,fix1);
						sv[markup1]->SetTen(fix1);
					}
					else if (option3==3)
					{
						int markup2;
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
								cout<<"Khong co ma sinh vien nay.\n";
							}
						}
						cout<<"Nhap nganh hoc cua sinh vien sau khi sua: ";
						cin.ignore();
						getline(cin,fix2);
						sv[markup2]->SetNganh(fix2);
					}
					else if (option3==4)
					{
						int markup3,fix3;
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
								cout<<"Khong co ma sinh vien nay.\n";
							}
						}
						cout<<"Nhap tuoi sinh vien sau khi sua: ";
						cin>>fix3;
						sv[markup3]->SetTuoi(fix3);
					}
					else if (option3==5)
					{
						int markup4,fix4;
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
								cout<<"Khong co ma sinh vien nay.\n";
							}
						}
						cout<<"Nhap diem ly thuyet cua sinh vien sau khi sua: ";
						cin>>fix4;
						sv[markup4]->SetLyThuyet(fix4);
					}
					else if (option3==6)
					{
						int markup5,fix5;
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
								cout<<"Khong co ma sinh vien nay.\n";
							}
						}
						cout<<"Nhap diem thuc hanh cua sinh vien sau khi sua: ";
						cin>>fix5;
						sv[markup5]->SetLyThuyet(fix5);
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
						int markup6;
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
								cout<<"Khong co ma sinh vien nay.\n";
							}
						}
						cout<<"Nhap ma sinh vien sau khi sua: ";
						cin>>fix6;
						sv[markup6]->SetMSV(fix6);
					}
					else if (option3==2)
					{
						int markup7;
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
								cout<<"Khong co ma sinh vien nay.\n";
							}
						}
						cout<<"Nhap ten sinh vien sau khi sua: ";
						cin.ignore();
						getline(cin,fix7);
						sv[markup7]->SetTen(fix7);
					}
					else if (option3==3)
					{
						int markup8;
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
								cout<<"Khong co ma sinh vien nay.\n";
							}
						}
						cout<<"Nhap nganh hoc cua sinh vien sau khi sua: ";
						cin.ignore();
						getline(cin,fix8);
						sv[markup8]->SetNganh(fix8);
					}
					else if (option3==4)
					{
						int markup9,fix9;
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
								cout<<"Khong co ma sinh vien nay.\n";
							}
						}
						cout<<"Nhap tuoi sinh vien sau khi sua: ";
						cin>>fix9;
						sv[markup9]->SetTuoi(fix9);
					}
					else if (option3==5)
					{
						int markup10,fix10;
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
								cout<<"Khong co ma sinh vien nay.\n";
							}
						}
						cout<<"Nhap diem ly thuyet cua sinh vien sau khi sua: ";
						cin>>fix10;
						sv[markup10]->SetLyThuyet(fix10);
					}
					else if (option3==6)
					{
						int markup11,fix11;
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
								cout<<"Khong co ma sinh vien nay.\n";
							}
						}
						cout<<"Nhap diem thuc hanh cua sinh vien sau khi sua: ";
						cin>>fix11;
						sv[markup11]->SetLyThuyet(fix11);
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
		}
	}while(option!=0);
	return 0;
}
