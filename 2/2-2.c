#include <iostream>
#include"../seqlist.h"
using namespace std;
// 设计一个高效的算法将顺序表L的所有元素逆置,要求算法的空间复杂度为O(1).
template<class T>
void reverse(SeqList<T> *seq) {
	for (int i = 0; i < seq->Length() / 2; i++) {
		T temp = seq->data[i];
		seq->data[i] = seq->data[seq->last - i];
		seq->data[seq->last - i] = temp;
	}
}
int main()
{
	SeqList<int> *seq = new SeqList<int>(10);
	seq->input();
	reverse(seq);
	seq->output();
}