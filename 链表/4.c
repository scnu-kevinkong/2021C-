#include <iostream>
#include"../singleLink.h"
using namespace std;
/*
	试编写在带头结点的单链表L中删除一个最小值结点的高效算法(假设最小值是唯一的)
*/
void del_minimize(Node<int> * link) {
	if (link->next == NULL) return;
	Node<int> *min = link;
	min->data = link->next->data;
	while (link->next != NULL) {
		if (min->data > link->next->data) {
			min = link;
			min->data = link->next->data;
		}
		link = link->next;
	}
	cout << min->data;
	Node<int> *temp = min;
	temp = temp->next;
	delete min;
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
	del_minimize(link->head);
}