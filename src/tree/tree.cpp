#include <iostream>
using namespace std;
#include "tree.h"

int main()
{
	Tree<int> t;
	int a=12;
	for (;a!=0;)
	{
		cin>>a;
		t.Add(a);
	}
	t.PreOrder();
	cout<<endl<<t.Search(5)<<endl<<t.Search(0);
	return 0;
}
