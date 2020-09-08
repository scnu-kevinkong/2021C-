#include <iostream>
#include"singleLink.h"
using namespace std;
/*
	给定一个带表头结点的单链表,设head为头指针,结点结构为(data,next).
	data为整型元素,next为指针.
	试写出算法:按递增次序输出单链表中的各点元素,并释放结点所占的存储空间.
*/
void sort_and_del(SingleLink<int> *&link) {
	while (link->head->next != NULL) {
		Node<int> *pre = link->head;
		int data = NULL;
		Node<int> *node = link->head;
		while (node->next != NULL) {
			if (data == NULL) {
				data = node->next->data;
			}
			else if (data > node->next->data){
				data = node->next->data;
				pre = node;
			}
			node = node->next;
		}
		cout << data << "->";
		Node<int> *temp = pre->next;
		pre->next = pre->next->next;
		delete temp;
	}
	cout << "end";
}
int main()
{
	SingleLink<int> *link = new SingleLink<int>();
	link->h_insert_last(3);
	link->h_insert_last(12);
	link->h_insert_last(1);
	link->h_insert_last(11);
	link->h_insert_last(2);
	link->h_insert_last(-1);
	link->h_insert_last(9);
	sort_and_del(link);
}