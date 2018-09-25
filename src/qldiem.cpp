#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct MonHoc
{
	string ma;
	char ten[20];
	float dqt;
	float dkt;
};

void ThemMon (MonHoc &a)
{
	cin>>a.ma;
	cin.ignore();
	cin.getline(a.ten,20);
}

void ThemDiem (MonHoc &a)
{
	int option;
	cout<<"1. Them diem qua trinh.\n";
	cout<<"2. Them diem kiem tra.\n";
	cout<<"Chon chuc nang: ";
	cin>>option;
	if (option == 1)
	{
		float dqt1;
		cout<<"Moi ban nhap diem qua trinh: ";
		cin>>dqt1;
		a.dqt = dqt1;
	}
	else
	{
		float dkt1;
		cout<<"Moi ban nhap diem kiem tra: ";
		cin>>dkt1;
		a.dkt = dkt1;
	}
}

void HienThi(MonHoc a[], int n)
{
	for (int i=0;i<n;i++)
	{
		cout<<".=========================================================.\n";
		cout<<"Ma mon hoc    : "<<a[i].ma<<endl;
		cout<<"Ten mon hoc   : "<<a[i].ten<<endl;
		cout<<"Diem qua trinh: "<<a[i].dqt<<endl;
		cout<<"Diem kiem tra : "<<a[i].dkt<<endl;
	}
}

void Luu(MonHoc a[],int n)
{
	cout<<"1. Ghi moi file.\n";
	cout<<"2. Ghi tiep len file.\n";
	cout<<"Nhap chuc nang ban muon chon: ";
	int b;
	cin>>b;
	cout<<"Nhap ten file ban muon luu: ";
	char so[100];
	cin.ignore();
	cin.getline(so,100);
	if (b==2)
	{
		ofstream fout(so, ios::app);
		for (int i=0;i<n;i++)
		{
			fout<<"Ma mon hoc    : "<<a[i].ma<<endl;
			fout<<"Ten mon hoc   : "<<a[i].ten<<endl;
			fout<<"Diem qua trinh: "<<a[i].dqt<<endl;
			fout<<"Diem kiem tra : "<<a[i].dkt;
			if (i<n-1)
				fout<<endl;
		}
	}
	else
	{
		ofstream fout(so);
		for (int i=0;i<n;i++)
		{
			fout<<"Ma mon hoc    : "<<a[i].ma<<endl;
			fout<<"Ten mon hoc   : "<<a[i].ten<<endl;
			fout<<"Diem qua trinh: "<<a[i].dqt<<endl;
			fout<<"Diem kiem tra : "<<a[i].dkt<<endl;
			if (i<n-1)
				fout<<" ";
		}
	}
	cout<<"Luu vao file thanh cong!\n";
}

float TinhTrungBinh(MonHoc a)
{
	float c,b;
	cout<<"Nhap he so diem qua trinh: ";
	cin>>c;
	cout<<"Nhap he so diem qua trinh: ";
	cin>>b;
	float tong = a.dqt*c + a.dkt*b;
	return tong;
}

void Nap(MonHoc a[], int &n)
{
	int k;
	n=0;
	cout<<"Nhap ten file ban muon doc: ";
	char so[100];
	cin.ignore();
	cin.getline(so,100);
	ifstream fin(so);
	while(!fin.eof())
	{
		fin>>a[n++].ma;
		fin>>a[n++].ten;
		fin>>a[n++].dqt;
		fin>>a[n++].dkt;
	}
}

int main()
{
	int option=123;
	MonHoc a[100];
	int n=0;
	while (option!=0)
	{
		cout<<"1. Them mon.\n";
		cout<<"2. Them diem.\n";
		cout<<"3. In bang diem.\n";
		cout<<"4. Tinh trung binh.\n";
		cout<<"5. Luu.\n";
		cout<<"Chon chuc nang: ";
		cin>>option;
		if (option == 1)
		{
			ThemMon(a[n]);
			n++;
		}
		else if (option == 2)
		{
			string z;
			int mk,f=1;
			cout<<"Nhap ma mon ban muon them diem: ";
			cin>>z;
			cout<<z<<endl;
			for (int i=0;i<n;i++)
			{
				if (a[i].ma==z)
				{
					mk = i;
					f = 0;
				}
			}
			if (f==0)
			{
				ThemDiem(a[mk]);
			}
			else
				cout<<"Hien tai khong co mon hoc nay trong danh sach mon hoc cua ban.\n";
		}
		else if (option == 3)
		{
			HienThi(a,n);
		}
		else if (option == 4)
		{
			string z;
			int mk,f=1;
			cout<<"Nhap ma mon ban muon tinh diem: ";
			cin>>z;
			cout<<z<<endl;
			for (int i=0;i<n;i++)
			{
				if (a[i].ma==z)
				{
					mk = i;
					f = 0;
				}
			}
			if (f==0)
			{
				cout<<"Diem trung binh: "<<TinhTrungBinh(a[mk])<<endl;
			}
			else
				cout<<"Hien tai khong co mon hoc nay trong danh sach mon hoc cua ban.\n";
		}
		else if (option == 5)
		{
			Luu(a,n);
			n=0;
		}
		if (option == 3)
		{
			if (n > 0)
			{
				char ac;
				cout<<"Du lieu ban moi nhap vao chua duoc luu, ban co muon luu khong?(Y/N)\n";
				cin>>ac;
				if (ac=='Y' || ac=='y')
				{
					Luu(a,n);
					n=0;
				}
			}
			else
				Nap(a,n);
		}
	}
}
