#include <iostream>
#include"../seqlist.h"
using namespace std;
// 从顺序表中删除所有其值在给定值s与t之间(包含s和t，要求s<t)的所有元素，如果s或t不合理或者顺序表为空，则显示出错误信息并退出运行.
template<class T>
void del_s_t(SeqList<T> *seq, T s, T t) {
	if (seq->Length() <= 0) {
		cerr << "顺序表为空" << endl;
		return;
	}
	if (s > t) {
		cerr << "s或t不合理" << endl;
		return;
	}
	int index = 0;
	for (int i = 0; i < seq->Length(); i++) {
		if (seq->data[i] >= s && seq->data[i] <= t) {
			index++;
			continue;
		}
		seq->data[i - index] = seq->data[i];
	}
	seq->last = seq->last - index;
}
int main()
{
	SeqList<int> *seq = new SeqList<int>(10);
	seq->input();
	del_s_t(seq, 2, 5);
	seq->output();
}