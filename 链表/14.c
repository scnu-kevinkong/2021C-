#include <iostream>
#include"../singleLink.h"
using namespace std;
/*
	设AB两个递增单链表，公共元素产生C(不破坏A、B的结点).
*/
void  merge_mutual(SingleLink<int> *&link_a, SingleLink<int> *&link_b) {
	Node<int> *head_a = link_a->head->next;
	Node<int> *head_b = link_b->head->next;
	Node<int> *link = new Node<int>(NULL);
	Node<int> *link_next = link;
	Node<int> *temp;
	while (head_a != NULL && head_b != NULL) {
		if (head_a->data < head_b -> data) {
			head_a = head_a->next;
		}
		else if (head_a->data > head_b->data) {
			head_b = head_b->next;
		}
		else {
			temp = new Node<int>(head_a->data);
			temp->next = link_next->next;
			link_next->next = temp;
			link_next = link_next->next;
			head_a = head_a->next;
		}
	}
	link_next = link->next;
	while (link_next != NULL) {
		cout << link_next->data << "->";
		link_next = link_next->next;
	}
}
void main()
{
	SingleLink<int> *link_a = new SingleLink<int>();
	SingleLink<int> *link_b = new SingleLink<int>();
	link_a->h_insert_last(7);
	link_a->h_insert_last(8);
	link_a->h_insert_last(10);
	link_a->h_insert_last(13);
	link_a->h_insert_last(30);
	link_b->h_insert_last(1);
	link_b->h_insert_last(3);
	link_b->h_insert_last(8);
	link_b->h_insert_last(19);
	merge_mutual(link_a, link_b);
}