#include <iostream>
#include"../singleLink.h"
using namespace std;
/*
	假设两个递增线性表,编写算法将两个单链表归并为降序单链表.
*/
void  merge_desc(SingleLink<int> *&link_a, SingleLink<int> *&link_b) {
	Node<int> *head_a = link_a->head->next;
	Node<int> *head_b = link_b->head->next;
	Node<int> *link = new Node<int>(NULL);
	Node<int> *head_temp, *temp;
	while (head_a != NULL && head_b != NULL) {
		if (head_a->data < head_b->data) {
			temp = head_a->next;
			head_a->next = link->next;
			link->next = head_a;
			head_a = temp;
		}
		else {
			temp = head_b->next;
			head_b->next = link->next;
			link->next = head_b;
			head_b = temp;
		}
	}
	while (head_a != NULL) {
		temp = head_a->next;
		head_a->next = link->next;
		link->next = head_a;
		head_a = temp;
	}
	while (head_b != NULL) {
		temp = head_b->next;
		head_b->next = link->next;
		link->next = head_b;
		head_b = temp;
	}
	temp = link->next;
	while (temp != NULL) {
		cout << temp->data << "->";
		temp = temp->next;
	}
}
void main()
{
	SingleLink<int> *link_a = new SingleLink<int>();
	SingleLink<int> *link_b = new SingleLink<int>();
	link_a->h_insert_last(7);
	link_a->h_insert_last(10);
	link_a->h_insert_last(10);
	link_a->h_insert_last(21);
	link_a->h_insert_last(30);
	link_b->h_insert_last(1);
	link_b->h_insert_last(3);
	link_b->h_insert_last(8);
	link_b->h_insert_last(13);
	merge_desc(link_a, link_b);
}