#include <iostream>
#include"../seqlist.h"
using namespace std;
// 从有序表中删除所有其值重复的元素,使表中所有元素的值均不同.
template<class T>
void become_set(SeqList<T> *seq) {
	if (seq->Length() <= 1) {
		return;
	}
	int index = 0;
	T temp = seq->data[0];
	for (int i = 1; i < seq->Length(); i++) {
		if (seq->data[i] == temp) {
			index++;
			continue;
		}
		temp = seq->data[i];
		seq->data[i - index] = seq->data[i];
	}
	seq->last = seq->last - index;
}
int main()
{
	SeqList<int> *seq = new SeqList<int>(10);
	seq->input();
	become_set(seq);
	seq->output();
}