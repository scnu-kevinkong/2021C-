#include <iostream>
#include"../singleLink.h"
using namespace std;
/*
	在带头结点的单链表L中，删除所有值为x的结点,并释放其空间.
	假设值为x的结点不唯一，试编写算法实现上述操作.
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
	link->h_insert_last(1);
	link->h_insert_last(2);
	link->h_insert_last(3);
	link->h_insert_last(2);
	link->h_insert_last(4);
	link->h_insert_last(2);
	delete_value(link->head->next, 3);
	link->h_showout();
}