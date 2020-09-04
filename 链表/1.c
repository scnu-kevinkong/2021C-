#include <iostream>
#include"../singleLink.h"
using namespace std;
/*
	设计一个递归算法,删除不带头结点的单链表L中所有值为X的结点.
*/
void delete_value(Node<int> * &node, int x) {
	if (node == NULL) return;
	Node<int> *p;	
	if (node->data == x) {
		p = node;
		node = node->next;
		delete p;
		delete_value(node, x);
	}
	else {
		delete_value(node->next, x);
	}
}
int main()
{
	SingleLink<int> *link = new SingleLink<int>();
	link->n_insert_last(1);
	link->n_insert_last(2);
	link->n_insert_last(3);
	link->n_insert_last(2);
	link->n_insert_last(4);
	link->n_insert_last(2);
	delete_value(link->head, 2);
	link->n_showout();
}