#include <iostream>
#include"singleLink.h"
using namespace std;
/*
	试编写算法将带头结点的单链表就地逆置,所谓就地就是空间复杂度为O(1).
*/
void reverse(SingleLink<int> *&link) {
	Node<int> *temp = new Node<int>(NULL);
	while (link->head->next != NULL) {
		link->head = link->head->next;
		Node<int> *node = new Node<int>(link->head->data);
		node->next = temp->next;
		temp->next = node;
	}
	link->head = temp;
}
int main()
{
	SingleLink<int> *link = new SingleLink<int>();
	link->h_insert_last(1);
	link->h_insert_last(2);
	link->h_insert_last(3);
	link->h_insert_last(9);
	link->h_insert_last(4);
	link->h_insert_last(-1);
	reverse(link);
	link->h_showout();
}