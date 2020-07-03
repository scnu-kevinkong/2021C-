#pragma once
#ifndef SEQLIST_H_INCLUDED
#define SEQLIST_H_INCLUDED
#include<iostream>
#include<stdlib.h>
using namespace std;

template<class T>
class SeqList {

protected:
  T *data; //存放数据的数组.
  int maxSize; //最大容纳.
  int last; //当前已保存的最后位置（从0开始）.
  void reSize(int); //改变data数组空间大小.
public:
  SeqList(int); //构造函数.
  SeqList(SeqList<T> *L); //复制构造函数.
  ~SeqList() { delete[] data; } //析构函数.
  int Size() { return maxSize; } //返回计算表最大容纳个数.
  int Length() { return last + 1; } //返回当前长度.
  int Search(T x); //搜索x在表中位置，函数返回索引（从0开始）.
  bool Locate(int, T &); //返回第i个值（从0开始）.
  // 返回值TRUE，x的表项为i的值，返回值False则不存在.
  bool getData(int i, T &x) const {
    if (i >= 0 && i <= last) {
      x = data[i];
      return true;
    }
    else {
      return false;
    }
  }
  // 设置第i个表项的值，返回值True则为成功
  bool setData(int i, T x) {
    if (i >= 0 && i <= last) {
      data[i] = x;
      return true;
    }
    else {
      return false;
    }
  }
  bool Insert(int, T); //插入x在第i个表项之后，0为开始.
  bool Push(T); //插在最后面.
  bool Remove(int, T&); //删除第i个，并返回给x.
  bool IsEmpty() { return last == -1 ? true : false; } //判断是否为空.
  bool IsFull() { return last == maxSize - 1 ? true : false; } //判断表是否满.
  void clearAll() { delete[] data; }
  void input(); //输入.
  void output(); //输出.
  void union_seq(SeqList<T>*, SeqList<T>* &); //合并.
  void Intersection(SeqList<T>*, SeqList<T>* &); //交集
};

// 构造函数，通过指定参数sz定义表的长度.
template <class T>
SeqList<T>::SeqList(int sz) {
  if (sz > 0) {
    maxSize = sz;
    last = -1;
    data = new T[maxSize];
    if (data == NULL) {
      cerr << "存储分配错误!" << endl;
      exit(1);
    }
  }
};

// 复制构造函数，用参数表给出的顺序表初始化新建的顺序表.
template<class T>
SeqList<T>::SeqList(SeqList<T> *L) {
  maxSize = L->Size();
  last = L->Length() - 1;
  T value;
  data = new T[maxSize];
  if (data == NULL) {
    cerr << "存储分配错误" << endl;
    exit(1);
  }
  for (int i = 0; i <= last; i++) {
    if (L->getData(i, value)) {
      data[i] = value;
    }
    else {
      cerr << "获取值出错." << endl;
    }
  }
};

// 保护函数，扩充顺序表的存储数组空间大小，新数组的元素个数为newSize.
template <class T>
void SeqList<T>::reSize(int newSize) {
  if (newSize <= 0) {
    cerr << "无效的数组大小." << endl;
  }
  if (newSize != maxSize) {
    T *new_arr = new T[newSize]; //建立新数组.
    if (new_arr == NULL) {
      cerr << "存储分配错误" << endl;
      exit(1);
    }
    int n = last + 1;
    T *ori_ptr = data;//原数组首地址.
    T *des_ptr = new_arr;//目的数组首地址.
    while (n--) {
      *des_ptr++ = *ori_ptr++;//复制.
    }
    delete[] data;//删除旧数组.
    data = new_arr;//复制新数组.
    maxSize = newSize;
  }
};

template<class T>
// 将新元素x插入到表中第i个表项之后，函数返回插入成功信息.
bool SeqList<T>::Insert(int i, T x) {
  if (last == maxSize - 1) return false;
  if (i < 0 || i > last + 1) return false;
  for (int j = last; j >= i; j--) {
    data[j + 1] = data[j];
  }
  data[i] = x;
  last++;
  return true;
}
// 查找值的位置
template<class T>
int SeqList<T>::Search(T x) {
  int index = -1;
  for (int i = 0; i <= last; i++) {
    if (data[i] == x) {
      index = i;
      break;
    }
  }
  return index;
}
// 把数据推到最后面.
template<class T>
bool SeqList<T>::Push(T x) {
  if (last == maxSize - 1) return false;
  last++;
  data[last] = x;
  return true;
}
// 返回第index个位置的值.
template<class T>
bool SeqList<T>::Locate(int index, T &x) {
  if (index < 0 || index > last + 1) return false;
  x = data[index];
  return true;
}
// 删除第index个值，成功返回true，X为删除的第i项值.
template<class T>
bool SeqList<T>::Remove(int index, T&x) {
  if (last == -1) return false;
  if (index < 0 || index > maxSize - 1) return false;
  x = data[index];
  for (int i = index; i <= last - 1; i++) {
    data[i] = data[i + 1];
  }
  last--;
  return true;
}
// 键盘输入建立顺序表.
template<class T>
void SeqList<T>::input() {
  cout << "开始建立顺序表,请输入表中元素个数：" << endl;
  while (1) {
    cin >> last;
    last--;
    if (last < maxSize - 1) break;
    cout << "表中元素个数输入有误,范围不能超过" << maxSize << ";";
  }
  for (int i = 0; i <= last; i++) {
    cout << "请输入第" << i << "个元素的值:" << endl;
    cin >> data[i];
  }
}
// 输出顺序表中的值.
template<class T>
void SeqList<T>::output() {
  for (int i = 0; i <= last; i++) {
    cout <<data[i]<<endl;
  }
}
// 合并两个顺序表.
template<class T>
void SeqList<T>::union_seq(SeqList<T> *LA,SeqList<T> * &LB) {
  int n = LA->Length();
  LB->clearAll();
  LB = new SeqList<T>(LA);
  if (last == -1) return;
  LB->reSize(n + last + 1);
  for (int i = 0; i <= last; i++) {
    if (LB->Search(data[i]) == -1) {
      LB->Push(data[i]);
    }
  }
}
// 两个顺序表交集.
template<class T>
void SeqList<T>::Intersection(SeqList<T>* LA, SeqList<T>* &LB) {
  int n = LA->Length();
  LB->clearAll();
  LB = new SeqList<T>(n + last + 1);
  if (last == -1) return;
  for (int i = 0; i <= last; i++) {
    if (LA->Search(data[i]) != -1) {
      LB->Push(data[i]);
    }
  }
}
#endif //SEQLIST_H_INCLUDED
