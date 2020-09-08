#include <iostream>
#include"../singleLink.h"
using namespace std;
/*
	设C={a1,b1,a2,b2,an,bn}为线性表,采用带头结点的hc单链表存放,设计一个就地算法.
	将其拆分为两个线性表,使得A={a1,a2,a3,an}，B={b1,b2,b3,bn}.
*/
void  split_link(SingleLink<int> *&link) {
	Node<int> *link_a = new Node<int>(NULL);
	Node<int> *link_b = new Node<int>(NULL);
	Node<int> *temp_a = link_a;
	Node<int> *head = link->head->next;
	while (head != NULL) {
		Node<int> *temp = new Node<int>(head->data);
		temp_a->next = temp;
		temp_a = temp_a->next;
		Node<int> *del = head;
		head = head->next;
		delete del;
		temp = new Node<int>(head->data);
		Node<int> *temp_b = link_b->next;
		link_b->next = temp;
		temp->next = temp_b;
		del = head;
		head = head->next;
		delete del;
	}
	temp_a = link_a;
	while (temp_a->next != NULL) {
		temp_a = temp_a->next;
		cout << temp_a->data << "->";
	}
	cout << endl;
	temp_a = link_b;
	while (temp_a->next != NULL) {
		temp_a = temp_a->next;
		cout << temp_a->data << "->";
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
	split_link(link);
}