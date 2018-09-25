#include <iostream>
#include <string.h>
#include <string>
using namespace std;
#include "list.h"
#include "stack.h"
#include "queue.h"
int main(int argc, char const *argv[])
{
	/* List 
	List<int> ds1;
	ds1.Add(1);
	ds1.Add(3);
	ds1.Add(2);
	ds1.Add(6);
	ds1.Add(4);
	ds1.AddAnItemInPos(5,2);
	ds1.PrintAll();
	cout<<endl<<ds1.GetAnItemInPos(2);
	cout<<endl<<ds1.Lenght()<<endl;
	ds1.Sort();
	cout<<endl;
	ds1.PrintAll();*/

	/* Stack
	Stack<int> s;
	s.Push(10);
	s.Push(15);
	s.Push(30);
	cout<<s.Pop()<<endl;
	cout<<s.Pop()<<endl;*/

	/* Queue
	Queue<int> q;
	q.QueueIn(10);
	q.QueueIn(15);
	q.QueueIn(30);
	cout<<q.DeQueue()<<endl;
	cout<<q.DeQueue()<<endl;
	cout<<q.DeQueue()<<endl;*/

	/* Tinh toan hau to
	char a[100]="1000|5*8+";
	int tong = 0;
	Stack<int> s;
	for (int i = 0; i < strlen(a); i++)
	{
		if (a[i]>='0' && a[i]<='9')
			tong = tong*10 + (a[i]-'0');
		else
		{
			s.Push(tong);
			tong = 0;
			if (s.Get())
			{
				int s1 = s.Pop();
				int s2 = s.Pop();
				if (a[i]=='+')
					s.Push(s1+s2);
				if (a[i]=='-')
					s.Push(s1-s2);
				if (a[i]=='*')
					s.Push(s1*s2);
				if (a[i]=='/')
					s.Push(s1/s2);
			}
		}
	}
	int kq = s.Pop();
	cout<<"Ket qua la: "<<kq<<endl;*/

	/* Tinh toan trung to
	char a[100]="10/100 + 1";
	float tong = 0;
	char b;
	Stack<float> s;
	for (int i = 0; i < strlen(a)+1; i++)
	{
		if (a[i]>='0' && a[i]<='9')
			tong = tong*10 + (a[i]-'0');
		else
		{
			if (a[i]==' ')
				continue;
			s.Push(tong);
			tong = 0;
			if (s.Get())
			{
				float s1 = s.Pop();
				float s2 = s.Pop();
				if (b=='+')
					s.Push(s1+s2);
				if (b=='-')
					s.Push(s2-s1);
				if (b=='*')
					s.Push(s1*s2);
				if (b=='/')
					s.Push(s2/s1);
			}
			if (a[i]=='+' || a[i]=='/' || a[i]=='*' || a[i]=='-')
			{
				b = a[i];
			}
		}
	}
	float kq = s.Pop();
	cout<<"Ket qua la: "<<kq<<endl;*/
}
