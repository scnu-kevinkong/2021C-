#ifndef DOUBLELINK_H_INCLUDED
#define DOUBLELINK_H_INCLUDED
#include<iostream>
#include<stdlib.h>
using namespace std;
// 为了数据结构解题方便，不做数据保护，都设为public
template<class T>
struct Node {
	T data;
	Node<T> *next;
	Node<T> *prev;
	int freq;
	Node(T value) :data(value), next(NULL), prev(NULL),freq(0) {}
	Node(T value, Node<T>* link) : data(value), next(link), prev(NULL), freq(0) {}
	Node(T value, Node<T>* nlink, Node<T>* plink) : data(value), next(nlink), prev(plink), freq(0) {}
};
template<class T>
class DoubleLink {
public:
	Node<T> *head;
	DoubleLink() {
		head = new Node<T>(NULL);
	}
	// 返回链表长度(带头结点).
	int get_length();
	// 返回链表长度(不带头结点).
	int get_length_nh();
	// 删除指定位置结点(不带头结点).
	T del_index_nh(int);
	// 删除指定位置结点(带头结点).
	T del_index(int);
	// 按序号查找结点值(带头结点).
	Node<T>* getElem(int);
	// 按序号查找结点值(不带头结点).
	Node<T>* getElem_nh(int);
	// 尾插法(带头结点).
	void h_insert_last(T);
	// 尾插法(不带头结点).
	void n_insert_last(T);
	// 头插法(带头结点).
	void h_insert_head(T);
	// 头插法(不带头结点).
	void n_insert_head(T);
	// 输出结果.带头结点
	void h_showout();
	// 输出结果.不带头结点
	void n_showout();
	// 设为循环链表
	void set_circle();
};
template<class T>
void DoubleLink<T>::set_circle() {
	Node<T> *temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = head;
	head->prev = temp;
}
template<class T>
int DoubleLink<T>::get_length_nh() {
	Node<T>* temp = head;
	int len;
	if (temp->data == NULL) {
		len = 0;
	}
	else {
		len = 1;
		while (temp->next != NULL)
		{
			temp = temp->next;
			len++;
		}
	}
	return len;
}
template<class T>
int DoubleLink<T>::get_length() {
	Node<T>* temp = head;
	int len = 0;
	while (temp->next != NULL)
	{
		temp = temp->next;
		len++;
	}
	return len;
}
template<class T>
T  DoubleLink<T>::del_index_nh(int index) {
	Node<T>* temp;
	if (index <= 0) return NULL;
	if (index == 1) {
		temp = head;
		if (head->data == NULL) return NULL;
		Node<T>* p = temp->next;
		T data = head->data;
		p->prev = temp->prev;
		head = p;
		delete temp;
		return data;
	}
	temp = getElem_nh(index - 1);
	if (temp == NULL) return NULL;
	Node<T>* p = temp->next;
	T data = p->data;
	temp->next = p->next;
	if (p->next != NULL) {
		p->next->prev = p->prev;
	}
	delete p;
	return data;
}
template<class T>
T  DoubleLink<T>::del_index(int index) {
	Node<T>* temp;
	if (index <= 0) return NULL;
	if (index == 1) {
		temp = head;
	}
	else {
		temp = getElem(index - 1);
	}
	if (temp == NULL || temp->next == NULL) return NULL;
	Node<T>* p = temp->next;
	T data = p->data;
	temp->next = p->next;
	if (p->next != NULL) {
		p->next->prev = temp;
	}
	delete p;
	return data;
}
template<class T>
Node<T>*  DoubleLink<T>::getElem_nh(int index) {
	int num = 0;
	Node<T> *temp = head;
	if (temp->data != NULL) {
		num = 1;
	}
	while (temp->next != NULL) {
		if (num == index) break;
		num++;
		temp = temp->next;
	}
	if (num == index) {
		return temp;
	}
	else {
		return NULL;
	}
}

template<class T>
Node<T>*  DoubleLink<T>::getElem(int index) {
	int num = 0;
	Node<T> *temp = head;
	while (temp->next != NULL) {
		num++;
		temp = temp->next;
		if (num == index) break;
	}
	if (num == index) {
		return temp;
	}
	else {
		return NULL;
	}
}

template<class T>
void DoubleLink<T>::n_insert_last(T value) {
	if (head->data == NULL) {
		head->data = value;
	}
	else {
		Node<T> *temp = head;
		Node<T> *node = new Node<T>(value);
		while (temp->next != NULL) {
			temp = temp->next;
		}
		node->prev = temp;
		temp->next = node;
	}
}
template<class T>
void DoubleLink<T>::h_insert_last(T value) {
	Node<T> *temp = head;
	Node<T> *node = new Node<T>(value);
	while (temp->next != NULL) {
		temp = temp->next;
	}
	node->prev = temp;
	temp->next = node;
}
template<class T>
void DoubleLink<T>::n_showout() {
	Node<T> *temp = head;
	if (temp->data != NULL) {
		cout << temp->data << "->";
	}
	while (temp->next != NULL) {
		temp = temp->next;
		cout << temp->data << "->";
	}
}
template<class T>
void DoubleLink<T>::h_showout() {
	Node<T> *temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
		cout << temp->data << "->";
	}
}
template<class T>
void DoubleLink<T>::n_insert_head(T value) {
	if (head->data == NULL) {
		head->data = value;
	}
	else {
		Node<T> *temp = new Node<T>(value);
		temp->next = head;
		temp->prev = NULL;
		head->prev = temp;
		head = temp;
	}
}

template<class T>
void DoubleLink<T>::h_insert_head(T value) {
	Node<T> *temp = new Node<T>(value);
	temp->next = head->next;
	if (temp->next != NULL) {
		temp->next->prev = temp;
	}
	temp->prev = head;
	head->next = temp;
}
#endif //DOUBLELINK_H_INCLUDED