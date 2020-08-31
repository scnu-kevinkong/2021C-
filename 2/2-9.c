#include <iostream>
#include"../seqlist.h"
using namespace std;
// 线性表(a1,a2,a3...an)中的元素递增有序且按照顺序存储于计算机内.要求设计一算法,完成用最少时间在表中查找数值为x的元素,若找到则将其与后继元素位置相交换,
// 若找不到则将其插入表中并使表中元素仍递增有序.
void insert(int *arr, int left,int length, int x) {
	for (int i = length; i > left; i--) {
		arr[i] = arr[i - 1];
	}
	arr[left] = x;
}
void binary_search(int *arr, int left, int right, int length, int x) {
	if (left > right) {
		insert(arr, right, length, x);
		for (int i = 0; i < 11; i++) {
			cout << arr[i] << endl;
		}
	}
	else {
		int mid = (left + right) / 2;
		if (arr[mid] == x) {
			if (mid != length - 1) {
				int temp = arr[mid];
				arr[mid] = arr[mid + 1];
				arr[mid + 1] = temp;
			}
			for (int i = 0; i < 10; i++) {
				cout << arr[i] << endl;
			}
		} else if (arr[mid] > x) {
			binary_search(arr, left + 1, mid, length, x);
		}
		else {
			binary_search(arr, mid + 1, right, length, x);
		}
	}
}
int main()
{
	int *arr = new int[10];
	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
	}
	binary_search(arr, 0, 9, 10, 3);
}