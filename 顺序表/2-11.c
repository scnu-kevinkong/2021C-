#include <iostream>
#include"../seqlist.h"
using namespace std;
/*
 一个长度为L(L>=1)的升序序列S,处在第[L/2]个位置的数称为S的中位数,例如序列S1=(11,13,15,17,19),则S1的中位数是15,两个序列的中位数是含他们所有元素的升序序列的中位数.
 例如,若S2=（2,4,6,8,20),则S1和S2的中位数是11.
 现在有两个等长的升序序列A和B,试设计一个在时间和空间两方面都高效的算法.
*/
int main()
{
	int n;
	cin >> n;
	int *a = new int[5];
	int *b = new int[5];
	int s1 =0, s2=0, z1=0, z2 = 0;
	int m1 = n-1, m2 = n - 1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	while (s1 != m1 || s2 != m2) {
		z1 = (s1 + m1) / 2;
		z2 = (s2 + m2) / 2;
		if (a[z1] == b[z2]) cout << a[m1] << endl;
		if (a[z1] < b[z2]) {
			// 元素个数为奇数.
			if ((s1 + m1) % 2 == 0) {
				s1 = z1;
				m2 = z2;
			}
			else {
				s1 = z1 + 1;
				m2 = z2;
			}
		}
		else {
			// 元素个数为奇数.
			if ((s2 + m2) % 2 == 0) {
				s2 = z2;
				m1 = z1;
			}
			else {
				s2 = z2 + 1;
				m1 = z1;
			}
		}
	}
	int temp = a[s1] < b[s2] ? a[s1] : b[s2];
	cout << temp;
}