#include <iostream>
using namespace std;
#include "dathuc.h"
int main()
{
	DaThuc a(4);
	a.Print();
	cout<<endl;
	a.SetHeSo(3,4);
	a.Print();
	cout<<endl<<a.Cal(2);
	return 0;
}
