#include <iostream>
#include"singleLink.h"
using namespace std;
/*
	设在一个带表头结点的单链表中所有元素结点的数据值无序.
	试编写一个函数,删除表中所有介于给定两个值(作为函数参数给出)之间的元素(若存在).
*/
void del_val_x_y(SingleLink<int> *&link,int x,int y) {
	Node<int> *head = link->head;
	while (head->next != NULL) {
		if (head->next->data > x && head->next->data < y) {
			Node<int> *del = head->next;
			head->next = head->next->next;
			delete del;
		}
		head = head->next;
	}
}
int main()
{
	SingleLink<int> *link = new SingleLink<int>();
	int a = 0, b = -1;
	link->h_insert_last(12);
	link->h_insert_last(1);
	link->h_insert_last(11);
	link->h_insert_last(2);
	link->h_insert_last(3);
	link->h_insert_last(9);
	link->h_insert_last(4);
	link->h_insert_last(-1);
	link->h_insert_last(30);
	while (a > b) {
		cout << "请输入给定的两个范围值a和b" << endl;
		cin >> a >> b;
	}
	del_val_x_y(link,a,b);
	link->h_showout();
}