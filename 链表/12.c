#include <iostream>
#include"../singleLink.h"
using namespace std;
/*
	在一个递增有序的线性表中,有数值相同的元素存在,若存储方式为单链表.
	去重.
*/
void  make_set(SingleLink<int> *&link) {
	Node<int> *head = link->head;
	int number = NULL;
	while (head->next != NULL) {
		if (number == head->next->data) {
			Node<int> *del = head->next;
			head->next = head->next->next;
			delete del;
			continue;
		}
		number = head->next->data;
		head = head->next;
	}
}
void main()
{
	SingleLink<int> *link = new SingleLink<int>();
	link->h_insert_last(7);
	link->h_insert_last(10);
	link->h_insert_last(10);
	link->h_insert_last(21);
	link->h_insert_last(30);
	link->h_insert_last(42);
	link->h_insert_last(42);
	link->h_insert_last(42);
	link->h_insert_last(42);
	link->h_insert_last(51);
	link->h_insert_last(70);
	link->h_insert_last(70);
	make_set(link);
	link->h_showout();
}