#include <iostream>
#include"../seqlist.h"
using namespace std;
//对长度为n的顺序表L，编写一个时间复杂度为O(n)、空间复杂度为O(1)的算法，该算法删除线性表中所有值为x的数据元素.
template<class T>
void del_x_1(SeqList<T> *seq, T x) {
	int index = 0;
	for (int i = 0; i < seq->Length(); i++) {
		if (seq->data[i] == x) {
			index++;
			continue;
		}
		seq->data[i - index] = seq->data[i];
	}
	seq->last = seq->last - index;
}
template<class T>
void del_x_2(SeqList<T> *seq, T x) {
	int index = 0;
	for (int i = 0; i < seq->Length(); i++) {
		if (seq->data[i] != x) {
			seq->data[i - index] = seq->data[i];
			continue;
		}
		index++;
	}
	seq->last = seq->last - index;
}
int main()
{
	SeqList<int> *seq = new SeqList<int>(10);
	seq->input();
	del_x_2(seq, 2);
	seq->output();
}