#include <iostream>
#include"../singleLink.h"
using namespace std;
/*
	给定两个单链表，编写算法找出两个链表的公共结点.
*/
void find_mutual(SingleLink<int> *&link1, SingleLink<int> *&link2) {
	Node<int> *head1 = link1->head;
	Node<int> *head2 = link2->head;
	int len1 = link1->get_length();
	int len2 = link2->get_length();
	int len_dis = 0;
	if (len1 > len2) {
		len_dis = len1 - len2;
		while (len_dis-- > 0) {
			head1 = head1->next;
		}
	}
	else {
		len_dis = len2 - len1;
		while (len_dis-- > 0) {
			head2 = head2->next;
		}
	}
	while (head1->next != NULL) {
		if (head1->next == head2->next) {
			cout << "start from here, node value: " << head1->next->data;
			break;
		}
		head1 = head1->next;
	}
}
int main()
{
	SingleLink<int> *link1 = new SingleLink<int>();
	SingleLink<int> *link2 = new SingleLink<int>();
	link1->h_insert_last(12);
	link1->h_insert_last(1);
	link1->h_insert_last(11);
	link1->h_insert_last(2);
	link2->head->next = link1->head->next->next->next;
	find_mutual(link1, link2);
}