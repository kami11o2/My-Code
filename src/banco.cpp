#include <iostream>
using namespace std;
#include "banco.h"
int main()
{
	char bc[100][100];
	int N;
	cout<<"Nhap kich co ban co: ";
	cin>>N;
	TaoBanCo(bc,N);
	XepHau(1,bc,N);
	return 0;
}
