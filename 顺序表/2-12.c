#include <iostream>
#include"../seqlist.h"
using namespace std;
/*
  已知一个整数序列A=(a0,a1,...an-1),其中0<=ai<n(0<=i<n),若存在ap1=ap2=....=apm=x且m>n/2(0<=pk<n,1<=k<=m),则称x为A的主元素.
  例如A=（0,5,5,3,5,7,5,5),则5为主元素;又如A=(0,5,5,3,5,1,3,5,7),则A中没有主元素.
  假设A中的n个元素保存在一个一维数组中,请设计一个尽可能高效的算法,找出A的主元素.
  若存在主元素,则输出该元素：否则输出-1.
*/
int main()
{
	int n;
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int temp = a[0];
	if (n == 1) {
		cout << temp;
	}
	else {
		int num = 1;
		for (int i = 1; i < n; i++) {
			if (a[i] == temp) {
				num++;
			}
			else {
				num--;
			}
			if (num < 0) {
				temp = a[i];
				num = 1;
			}
		}
		num = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] == temp) num++;
		}
		if (num > n / 2) {
			cout << temp;
		}
		else {
			cout << -1;
		}
	}
}