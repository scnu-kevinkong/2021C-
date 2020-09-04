#include <iostream>
#include"singleLink.h"
using namespace std;
/*
	设L为带头结点的单链表，试编写算法实现从尾到头反向输出每个结点的值
*/
void print_reverse(Node<int> * &node) {
	if (node == NULL) return;
	print_reverse(node->next);
	cout << node->data << "->";
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
	print_reverse(link->head->next);
}