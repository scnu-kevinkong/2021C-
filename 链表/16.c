#include <iostream>
#include"../singleLink.h"
using namespace std;
/*
	两个证书序列A和B，判断序列B是否是序列A的连续子序列
*/
void  merge_mutual(SingleLink<int> *&link_a, SingleLink<int> *&link_b) {
	Node<int> *head_a = link_a->head->next;
	Node<int> *head_b = link_b->head->next;
	Node<int> *a_node = head_a;
	while (head_a != NULL && head_b != NULL) {
		if (head_a->data == head_b->data) {
			head_a = head_a->next;
			head_b = head_b->next;
		}
		else {
			a_node = a_node->next;
			head_a = a_node;
			head_b = link_b->head->next;
		}
	}
	if (head_b == NULL) {
		cout << "has";
	}
	else {
		cout << "no";
	}
}
void main()
{
	SingleLink<int> *link_a = new SingleLink<int>();
	SingleLink<int> *link_b = new SingleLink<int>();
	link_a->h_insert_last(7);
	link_a->h_insert_last(8);
	link_a->h_insert_last(1);
	link_a->h_insert_last(3);
	link_a->h_insert_last(8);
	link_a->h_insert_last(9);
	link_a->h_insert_last(10);
	link_b->h_insert_last(1);
	link_b->h_insert_last(3);
	link_b->h_insert_last(8);
	link_b->h_insert_last(9);
	merge_mutual(link_a, link_b);
}