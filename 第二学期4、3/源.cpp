#include<iostream>
using namespace std;

template<class T>
struct Node
{
	T data;
	Node<T> * next;
};

template<class T>
class LinkList
{
private:
	Node<T> * front;
public:
	LinkList(int N, int K);
	~LinkList();
	Node<T> * Getfront();
};

template<class T>
LinkList<T>::LinkList(int N, int K)
{
	front = new Node<T>;
	front->data = N + K;
	Node<T> * r = front;
	for (int i = 0; i < N; i++)
	{
		r->next = new Node<T>;
		r = r->next;
		r->data = 1;
	}
	for (int i = 0; i < K; i++)
	{
		r->next = new Node<T>;
		r = r->next;
		r->data = 2;
	}
	r->next = NULL;
	r = NULL;
}

template<class T>
LinkList<T>::~LinkList()
{
	Node<T> *r = front;
	while (r)
	{
		r = front->next;
		delete front;
		front = r;
	}


}

template<class T>
Node<T> * LinkList<T>::Getfront()
{
	return front;
}

template<class T>
bool judgement(LinkList<T> &L)
{
	bool isIt = true;
	int insistant = 0;
	Node<T> * p = L.Getfront();
	p = p->next;
	while (p)
	{
		if (p->data == 1)
		{
			insistant++;
		}
		else
		{
			insistant--;

			if (insistant < 0)
			{
				isIt = false;

			}


		}
		p = p->next;
	}
	return isIt;
}

template<class T>
void F(LinkList<T> &L, int n, int & count)
{
	if (n == 1)
	{
		if (judgement(L))
		{
			count++;
		}
	}
	else
	{

		for (int i = 0; i < n; i++)
		{

			Node<T> * front = L.Getfront();
			Node<T> * p = L.Getfront();
			Node<T> * r = L.Getfront();
			for (int i = 0; i < n; i++)
			{
				p = p->next;
			}
			for (int i = 0; i < n - 1; i++)
			{
				r = r->next;
			}
			Node<T> * tempFN = front->next;
			front->next = new Node<T>;
			front->next->data = p->data;
			front->next->next = tempFN;
			r->next = p->next;
			delete p;
			F(L, n - 1, count);



		}

	}
}

int main()
{
	int Count = 0, M = 0, N = 0, K = 0;
	cin >> M >> N >> K;
	LinkList<int> L(N, K);
	F(L, M, Count);
	cout << Count;
	return 0;
}