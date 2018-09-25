#ifndef queue_h
#define queue_h

#include "node.h"
template <class T>
class Queue
{
private:
	Node<T> *head;
public:
	Queue()
	{
		head = 0;
	};
	
	void QueueIn(T newValue)
	{
		Node<T> *p = new Node<T>;
		p->data = newValue;
		p->next = 0;
		if (head==0)
		{
			head = p;
		}
		else
		{
			Node<T> *n = head;
			while (n->next != 0)
				n = n->next;
			n->next = p;
		}
	};

	T DeQueue()
	{
		T t = head->data;
		Node<T> *q = head;
		head = head->next;
		delete q;
		return t;
	};
};

#endif