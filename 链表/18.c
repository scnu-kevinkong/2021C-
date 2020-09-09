#include <iostream>
#include"../singleLink.h"
using namespace std;
/*
	y有两个循环单链表,链表头指针分别为h1和h2.
	编写一个函数将h2连接到h1之后，并保持循环链表形式
*/
void  merge_circle(SingleLink<int> *&link_a, SingleLink<int> *&link_b) {
	Node<int> *head_a = link_a->head;
	Node<int> *head_b = link_b->head;
	while(head_a->next != link_a->head) {
		head_a = head_a->next;
	}
	while (head_b->next != link_b->head) {
		head_b = head_b->next;
	}
	head_a->next = link_b->head;
	head_b->next = link_a->head;
}
void main()
{

}