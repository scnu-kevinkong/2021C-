#include <iostream>
#include"../singleLink.h"
using namespace std;
/*
	有一个带头结点的单链表L，设计一个算法使其元素递增有序.
*/
void sort(SingleLink<int> *&link) {
	Node<int> *head = link->head;
	Node<int> *result = new Node<int>(NULL);
	if (head->next != NULL) {
		result->next = new Node<int>(head->next->data);
	}
	head = head->next->next;
	while (head != NULL) {
		Node<int> *temp = result;
		while (temp->next != NULL && temp->next->data < head->data) temp = temp->next;
		Node<int> *del = head;
		Node<int> *data = new Node<int>(del->data);
		data->next = temp->next;
		temp->next = data;
		head = head->next;
		delete del;
	}
	head = link->head;
	link->head = result;
	delete head;
}
int main()
{
	SingleLink<int> *link = new SingleLink<int>();
	link->h_insert_last(12);
	link->h_insert_last(1);
	link->h_insert_last(11);
	link->h_insert_last(2);
	link->h_insert_last(3);
	link->h_insert_last(9);
	link->h_insert_last(4);
	link->h_insert_last(-1);
	link->h_insert_last(30);
	sort(link);
	link->h_showout();
}