#include <iostream>
#include"../doubleLink.h"
using namespace std;
/*
	头指针L除了pred,data和next,还有一个freq.
	在链表被启用前,其值初始化为0.
	每当在链表中进行一次Locate(L,x)运算时,
	freq+1,并按照递减顺序排列，相同频度的最近访问结点在前面.
*/
template<class T>
Node<T>*  Locate(DoubleLink<T> *& L, T x) {
	Node<T> *p = L->head->next;
	Node<T> *q;
	while (p->next != NULL && p->data != x) {
		p = p->next;
	}
	if (p == NULL) {
		cout << "not found" << endl;
		return;
	}
	else {
		p->freq++;
		if (p->next != NULL) p->next->prev = p->prev;
		p->prev->next = p->next;
		q = p->prev;
		while (q != L->head && q->freq <= p->freq) {
			q = q->prev;
		}
		p->next = q->next;
		q->next->prev = p;
		p->prev = q;
		q->next = p
	}
	return p;
}
void main()
{
}