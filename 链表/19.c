#include <iostream>
#include"../singleLink.h"
using namespace std;
/*
	设有一个带头结点的循环单链表,其结点值均为正整数.
	设计一个算法,反复找出单链表中结点值最小的结点并输出,然后将该结点从中删除,直到单链表为空为止,
	再删除表头结点.
*/
void  del_min(SingleLink<int> *&link) {
	Node<int> *head = link->head;
	Node<int> *node = new Node<int>(NULL);
	while (1) {
		if (link->head->next == link->head) {
			delete link->head;
			break;
		}
		if (node->data == NULL) {
			node->next = head;
			node->data = head->next->data;
			head = head->next;
			continue;
		}
		if (head->next == link->head) {
			cout << node->data << "->";
			Node<int> *temp = node->next->next;
			node->next->next = node->next->next->next;
			node->next = node->next->next->next;
			head = link->head;
			delete temp;
			node->data = NULL;
			
		}
		else if (head->next->data < node->data) {
			node->next = head;
			node->data = head->next->data;
			head = head->next;
		}
		else {
			head = head->next;
		}
	}
}
void main()
{
	SingleLink<int> *link = new SingleLink<int>();
	link->h_insert_last(2);
	link->h_insert_last(1);
	link->h_insert_last(10);
	link->h_insert_last(8);
	link->h_insert_last(4);
	link->h_insert_last(20);
	link->h_insert_last(-1);
	link->set_circule();
	del_min(link);
}