#include <iostream>
#include"../doubleLink.h"
using namespace std;
/*
	设计一个算法判断带头结点的循环双链表是否对称
*/
void  is_symmetry(DoubleLink<int> *&link) {
	Node<int> *pre = link->head->prev;
	Node<int> *next = link->head->next;
	while (pre != next && pre->next != next) {
		if (pre->data == next->data) {
			pre = pre->prev;
			next = next->next;
		}
		else {
			cout << "no" << endl;
			return;
		}
	}
	cout << "yes" << endl;
}
void main()
{
	DoubleLink<int> *link = new DoubleLink<int>();
	link->h_insert_last(7);
	link->h_insert_last(8);
	link->h_insert_last(1);
	link->h_insert_last(1);
	link->h_insert_last(8);
	link->h_insert_last(7);
	link->set_circle();
	is_symmetry(link);
}