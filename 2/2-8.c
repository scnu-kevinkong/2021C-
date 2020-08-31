#include <iostream>
#include"../seqlist.h"
using namespace std;
// 已知一维数组A[m+n]中依次存放两个线性表a1,a2,a3.....am和b1,b2,b3.....bn,试编写一个函数,将数组中两个顺序表的位置互换,即将(b1,b2,b3...
void reverse(int *arr, int left, int right) {
	int index = 0;
	for (int i = left; i <= (left + right) / 2; i++) {
		int temp = arr[i];
		arr[i] = arr[right - index];
		arr[right - index] = temp;
		index++;
	}
}
int main()
{
	int *arr = new int[10];
	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
	}
	reverse(arr,0,6);
	reverse(arr,7, 9);
	reverse(arr, 0, 9);
	for (int i = 0; i < 10; i++) {
		cout<<arr[i]<<endl;
	}
}