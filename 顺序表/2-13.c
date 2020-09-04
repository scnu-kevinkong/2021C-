#include <iostream>
#include"../seqlist.h"
using namespace std;
/*
  给定一个含n(n>=1)个整数的数组,请设计一个在时间上可能高效的算法.
  找出数组中未出现的最小整数,例如数组{-5,3,2,3}中未出现的最小整数是1;
  数组1,2,3中未出现的最小整数是4.
*/
int main()
{
	int n;
	cin >> n;
	int *a = new int[n];
	int *r = new int[1000];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] > 0) {
			r[a[i] - 1] = 1;
		}
	}
	for (int i = 0; i < 1000; i++) {
		if (r[i] != 1) {
			cout << i + 1;
			break;
		}
	}
}