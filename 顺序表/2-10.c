#include <iostream>
#include"../seqlist.h"
using namespace std;
/*
 将n个整数存放到一维数组R中,设计一个时间和空间两方面都尽可能高效的算法。
 将R中保存的序列循环左移p个位置,即将R中的数据由(X0,X1,X2,Xn-1)变为(Xp,Xp+1,Xn-1,X0,X1,Xp-1).
*/

/*
	设计思想: 把数组ab转为ba(a代表前p个元素,b代表剩下n-p个元素)
	先将a逆置a-,再将b逆置变成b-,最后a-b-逆置得到ba

*/
void reverse(int *data, int left,int right) {
	for (int i = left; i < (right-left + 1) / 2; i++) {
		int temp = data[i];
		data[i] = data[right - i];
		data[right - i] = temp;
	}
}
int main()
{
	int *arr = new int[10];
	int p;
	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
	}
	cin >> p;
	reverse(arr, 0, p-1);
	reverse(arr, p, 9);
	reverse(arr, 0, 9);
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << "->" << endl;
	}
}