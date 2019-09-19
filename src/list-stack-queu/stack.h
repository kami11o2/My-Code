#ifndef stack_h
#define stack_h

#include "node.h"
template <class T>
class Stack
{
private:
	Node<T> *top;
public:
	Stack()
	{
		top = 0;
	};

	void Push(T newValue)
	{
		Node<T> *p = new Node<T>;
		p->data = newValue;
		p->next = top;
		top = p;
	};

	T Pop()
	{
		T t = top->data;
		Node<T> *q = top;
		top = top->next;
		delete q;
		return t;
	};

	bool Get()
	{
		return top->next!=0;
	}

	bool IsEmpty() const
	{
		return top==0;
	};
};

#endif
