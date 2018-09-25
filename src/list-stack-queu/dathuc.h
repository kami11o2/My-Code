#include "list.h"
#include <math.h>
class DaThuc
{
private:
	List<int> hs;
	List<int> bac;
public:
	DaThuc()
	{
		hs.Add(0);
		bac.Add(0);
	};
	
	DaThuc(int count)
	{
		for (int i=0;i<=count;i++)
		{
			hs.Add(1);
			bac.Add(i);
		}
	};
	
	void Print() const
	{
		for (int i=bac.Lenght()-1;i>=0;i--)
		{
			if (bac.Lenght()==1)
			{
				cout<<hs.GetAnItemInPos(0);
			}
			if (hs.GetAnItemInPos(i)==0)
				continue;
			if (i==0)
			{
				if (hs.GetAnItemInPos(i)<0)
					cout<<" - "<<-hs.GetAnItemInPos(i);
				else if (hs.GetAnItemInPos(i)>0)
					cout<<" + "<<hs.GetAnItemInPos(i);
				continue;
			}
			if (hs.GetAnItemInPos(i)==1 && i==bac.Lenght()-1)
				cout<<"X";
			else if (i==bac.Lenght()-1)
				cout<<hs.GetAnItemInPos(i)<<"X";
			else if (hs.GetAnItemInPos(i)>0 && hs.GetAnItemInPos(i)!=1)
				cout<<" + "<<hs.GetAnItemInPos(i)<<"X";
			else if (hs.GetAnItemInPos(i)>0 && hs.GetAnItemInPos(i)==1)
				cout<<" + "<<"X";
			else if (hs.GetAnItemInPos(i)<0 && hs.GetAnItemInPos(i)!=-1)
				cout<<" - "<<-hs.GetAnItemInPos(i)<<"X";
			else if (hs.GetAnItemInPos(i)<0 && hs.GetAnItemInPos(i)==-1)
				cout<<" - "<<"X";
			if (i!=1)
				cout<<"^"<<i;
		}
	};
	
	void SetHeSo(int bac, int value)
	{
		hs.Change(value,bac);
	};
	
	int Cal(int value)
	{
		int sum=0;
		for (int i=0;i<=bac.Lenght()-1;i++)
		{
			sum = sum + hs.GetAnItemInPos(i) * pow(value,i);
		}
		return sum;
	};
};
