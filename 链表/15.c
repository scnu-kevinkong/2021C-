#include <iostream>
#include"../singleLink.h"
using namespace std;
/*
	设AB两个递增单链表表示集合，求交集放在A.
*/
void  merge_mutual(SingleLink<int> *&link_a, SingleLink<int> *&link_b) {
	Node<int> *head_a = link_a->head->next;
	Node<int> *head_b = link_b->head->next;
	Node<int> *a_pre = link_a->head;
	Node<int> *b_pre = link_b->head;
	Node<int> *temp;
	while (head_a != NULL && head_b != NULL) {
		if (head_a->data < head_b -> data) {
			a_pre->next = a_pre->next->next;
			delete head_a;
			head_a = a_pre->next;
		}
		else if (head_a->data > head_b->data) {
			temp = head_b;
			head_b = head_b->next;
			b_pre->next = head_b;
			delete temp;
		}
		else {
			while (head_a != NULL && head_a->next != NULL && head_a->data == head_a->next->data) {
				temp = head_a;
				head_a = head_a->next;
				delete temp;
			}
			a_pre->next = head_a;
			a_pre = a_pre->next;
			head_a = head_a->next;
			head_b = head_b->next;
		}
	}
	while (head_a != NULL) {
		temp = head_a;
		head_a = head_a->next;
		a_pre->next = head_a;
		delete temp;
	}
}
void main()
{
	SingleLink<int> *link_a = new SingleLink<int>();
	SingleLink<int> *link_b = new SingleLink<int>();
	link_a->h_insert_last(7);
	link_a->h_insert_last(8);
	link_a->h_insert_last(8);
	link_a->h_insert_last(9);
	link_a->h_insert_last(10);
	link_b->h_insert_last(1);
	link_b->h_insert_last(3);
	link_b->h_insert_last(8);
	link_b->h_insert_last(9);
	merge_mutual(link_a, link_b);
	link_a->h_showout();
}