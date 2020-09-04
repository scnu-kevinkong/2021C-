#include <iostream>
#include"../seqlist.h"
using namespace std;
// 将两个有序顺序表合并为一个新顺序表，并由函数返回结果顺序表.
template<class T>
void combine(SeqList<T> *seq1, SeqList<T> *seq2, SeqList<T> * &seq) {
	if (seq1->Length() + seq2->Length() > seq->maxSize) return;
	int seq1_pos = 0;
	int seq2_pos = 0;
	while (seq1_pos < seq1->Length() && seq2_pos<seq2->Length()) {
		if (seq1->data[seq1_pos] < seq2->data[seq2_pos]) {
			seq->Push(seq1->data[seq1_pos++]);
		}
		else if (seq2_pos < seq2->Length()){
			seq->Push(seq2->data[seq2_pos++]);
		}
	}
	for (;seq1_pos < seq1->Length(); seq1_pos++) {
		seq->Push(seq1->data[seq1_pos]);
	}
	for (;seq2_pos < seq2->Length(); seq2_pos++) {
		seq->Push(seq2->data[seq2_pos]);
	}
}
int main()
{
	SeqList<int> *seq1 = new SeqList<int>(10);
	seq1->input();
	SeqList<int> *seq2 = new SeqList<int>(10);
	seq2->input();
	SeqList<int> *seq = new SeqList<int>(30);
	combine(seq1,seq2, seq);
	seq->output();
}