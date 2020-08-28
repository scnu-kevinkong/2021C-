#include <iostream>
#include"../seqlist.h"
using namespace std;
// 从顺序表中删除最小值的元素（假设唯一），并由函数返回被删的值。空出的位置由最后一个元素填补，若顺序表为空则显示出错误信息并退出运行.
template<class T>
bool del_min(SeqList<T> *seq, T &value) {
	if (seq->IsEmpty()) return false;
	if (seq->Length() == 1) {
		seq->Remove(0, value);
	}
	else {
		T min = seq->data[0];
		int pos = 0;
		for (int i = 1; i < seq->Length(); i++) {
			if (min > seq->data[i]) {
				min = seq->data[i];
				pos = i;
			}
		}
		value = min;
		seq->data[pos] = seq->data[seq->last];
		seq->last--;
	}
	return true;
}
int main()
{
	SeqList<int> *seq = new SeqList<int>(10);
	seq->input();
	int value;
	if (del_min(seq, value)) {
		cout << value << endl;
	}
	else {
		cerr << "error response!" << endl;
	}
	seq->output();
}