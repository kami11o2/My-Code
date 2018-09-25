#ifndef list_h
#define list_h

#include "node.h"
template <class T>

class List
{
private:
	Node<T> *head;
public:
	
	List()
	{
		head = 0;
	};
	
	List(T value, int count)
	{
		head = 0;
		for (int i=0;i<count;i++)
		{
			Add(value);
		}
	};
	
	List(List<T> l, int loop)
	{
		head = 0;
		for (int i=0;i<loop;i++)
		{
			Node<T> *p = l.head;
			while(p->next!=0)
			{
					Add(p->data);
					p=p->next;
			}
		}
	};
	
	List(List<T> l, int from, int to)
	{
		head = 0;
		Node<T> *p = l.head;
		for (int i=1; i<from; i++)
		{
			p = p->next;
		}
		for (int i=from;i<to+1;i++)
		{
			Add(p->data);
			p=p->next;
		}
	};
	
	List(List<T> first, List<T> last)
	{
		head = 0;
		Node<T> *f = first.head;
		Node<T> *l = last.head;
		while (f != 0)
		{
			Add(f->data);
			f = f->next;
		}
		while (l != 0)
		{
			Add(l->data);
			l = l->next;
		}
	};
	
	void Add(T v)
	{
		Node<T> *n = new Node<T>;
		n->data = v;
		n->next =0;

		if (head == 0)
		{
			head = n;
		}
		else
		{
			Node<T> *p = head;
			while (p->next != 0)
				p = p->next;
			p->next = n;
		}
	};
	
	void PrintAll() const
	{
		Node<T> *p = head;
		while (p!=0)
		{
			cout<<p->data<<" ";
			p = p->next;
		}
	};
	
	void Swap(int pos1, int pos2)
	{
		Node<T> *p = head;
		Node<T> *q = head;
		for (int i=0;i<pos1-1;i++)
			p=p->next;
		for (int i=0;i<pos2-1;i++)
			q=q->next;
		int t=q->data;
		q->data = p->data;
		p->data = t;
	}

	void Delete(int pos)
	{
		if (pos == 1)
		{
			Node<T> *q = head;
			head = head->next;
			delete q;
		}
		else
		{
			Node<T> *p = head;
			for (int i = 1; i < pos-1; i++)
			{
				p = p->next;
			}
			Node<T> *q = p->next;
			p->next = p->next->next;
			delete q;
		}
	};
	
	int Count(T value) const
	{
		Node<T> *p = head;
		int count=0;
		while (p!=0)
		{
			if (p->data==value)
				count++;
			p = p->next;
		}
		return count;
	};
	
	void Change(T value, int pos)
	{
		Node<T> *p = head;
		for (int i=0;i<pos-1;i++)
		{
			p=p->next;
		}
		p->data=value;
	}
	
	void AddAnItemInPos(T value, int pos)
	{
		Add(value);
		for (int i=Lenght();i>pos;i--)
		{
			Swap(i,i-1);
		}
	};
	
	int Lenght() const
	{
		int count = 0;
		Node<T> *p = head;
		while (p!=0)
		{
			count++;
			p = p->next;
		}
		return count;
	};
	
	T GetAnItemInPos(int pos) const
	{
		Node<T> *n = head;
		for (int i=1;i<pos;i++)
			n = n->next;
		return n->data;
	};
	
	int Max() const
	{
		Node<T> *p = head;
		int Max = 0;
		while (p != 0)
		{
			if (p->data > Max)
				Max = p->data;
			p = p ->next;
		}	
		return Max;
	}
	
	int Min() const
	{
		Node<T> *p = head;
		int Min = p->data;
		while (p != 0)
		{
			if (p->data < Min)
				Min = p->data;
			p = p ->next;
		}	
		return Min;
	};
	
	void Sort()
	{
		Node<T> *p = head;
		Node<T> *q = head->next;
		for (int i=1; i<Lenght();i++)
		{
			for (int j=1;j<i;j++)
				q = q->next;
			for (int z=i;z<Lenght();z++)
			{
				if (q->data<p->data)
				{
					int t = q->data;
					q->data = p->data;
					p->data = t;
				}
				q = q->next;
			}
			p = p->next;
			q = head->next;
		}
	};
	
};

#endif
