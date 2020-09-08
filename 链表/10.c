#include <iostream>
#include"../singleLink.h"
using namespace std;
/*
	将一个带头结点的单链表A分解为两个带头结点的单链表A和B.
	使得A表中含有原表中序号为奇数的元素,
	而B表中含有序号为偶数的元素,且其保持相对顺序不变.
*/
void  split_link(SingleLink<int> *&link) {
	Node<int> *link_a = new Node<int>(NULL);
	Node<int> *link_b = new Node<int>(NULL);
	Node<int> *temp_a = link_a;
	Node<int> *temp_b = link_b;
	int len = 0;
	Node<int> *head = link->head;
	while (head->next != NULL) {
		len++;
		if (len % 2 == 1) {
			temp_a->next = head->next;
			temp_a = temp_a->next;
		}
		else {
			temp_b->next = head->next;
			temp_b = temp_b->next;
		}
		head = head->next;
	}
	if (len % 2 == 1) {
		temp_b->next = NULL;
	}
	else {
		temp_a->next = NULL;
	}
	cout << "a link" << endl;
	temp_a = link_a;
	while (temp_a->next != NULL) {
		temp_a = temp_a->next;
		cout << temp_a->data << "->";
	}
	cout << endl;
	cout << "b link" << endl;
	temp_b = link_b;
	while (temp_b->next != NULL) {
		temp_b = temp_b->next;
		cout << temp_b->data << "->";
	}
}
void main()
{
	SingleLink<int> *link = new SingleLink<int>();
	link->h_insert_last(3);
	link->h_insert_last(12);
	link->h_insert_last(1);
	link->h_insert_last(11);
	link->h_insert_last(2);
	link->h_insert_last(-1);
	link->h_insert_last(9);
	split_link(link);
}