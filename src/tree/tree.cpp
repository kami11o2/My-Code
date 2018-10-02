#include <iostream>
using namespace std;
#include "tree.h"

int main()
{
	Tree t;
	t.Add(5);
	t.Add(6);
	t.Add(4);
	t.Add(8);
	t.Add(10);
	t.Add(7);
	t.Add(15);
	t.Add(1);
	t.Add(4);
	t.Add(19);
	t.Print();
	return 0;
}
