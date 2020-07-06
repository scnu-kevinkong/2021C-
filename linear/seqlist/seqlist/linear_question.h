#pragma once
#ifndef SEQLIST_H_QUESTION
#define SEQLIST_H_QUESTION
#include"linear_seqlist.h"
#include<iostream>
using namespace std;
// 从顺序表中删除最小值的元素（假设唯一），并由函数返回被删的值。空出的位置由最后一个元素填补，若顺序表为空则显示出错误信息并退出运行.
template<class T>
bool del_min_data(SeqList<T> *seq, T &value) {
  T remove_temp;
  if (seq->IsEmpty()) return false;
  if (seq->Length() == 1) {
    seq->getData(0,value);
    seq->Remove(0, remove_temp);
  }
  else {
    T min;
    seq->getData(0, min);
    int m_pos = 0;
    T seq_temp_value;
    for (int i = 0; i < seq->Length(); i++) {
      seq->getData(i, seq_temp_value);
      if (seq_temp_value < min) {
        min = seq_temp_value;
        m_pos = i;
      } 
    }
    seq->getData(seq->Length() - 1, seq_temp_value);
    seq->setData(m_pos, seq_temp_value);
    value = min;
  }
  seq->Remove(seq->Length() - 1, remove_temp);
  return true;
}

//设计一个高效的算法将顺序表L的所有元素逆置,要求算法的空间复杂度为O(1).
template<class T>
void reverse(SeqList<T> *seq) {
  int len = seq->Length();
  for (int i = 0; i < len / 2; i++) {
    cout << "rank switch" << i + 1 << endl;
    T temp1,temp2;
    seq->getData(i, temp1);
    seq->getData(len - i - 1, temp2);
    seq->setData(i, temp2);
    seq->setData(len - i - 1, temp1);
  }
}
//对长度为n的顺序表L，编写一个时间复杂度为O(n)、空间复杂度为O(1)的算法，该算法删除线性表中所有值为x的数据元素.
template<class T>
void del_x_1(SeqList<T> *seq, T x) {
  T temp;
  int index = 0;
  for (int i = 0; i < seq->Length(); i++) {
    seq->getData(i, temp);
    if (temp == x) {
      index++;
      continue;
    }
    seq->setData(i - index, temp);
  }
  seq->cut_length(index);
}

template<class T>
void del_x_2(SeqList<T> *seq, T x) {
  T temp;
  int index = 0;
  for (int i = 0; i < seq->Length(); i++) {
    seq->getData(i, temp);
    if (temp != x) {
      seq->setData(i - index, temp);
      continue;
    }
    index++;
  }
  seq->cut_length(index);
}

// 从顺序表中删除所有其值在给定值s与t之间(包含s和t，要求s<t)的所有元素，如果s或t不合理或者顺序表为空，则显示出错误信息并退出运行.
template <class T>
bool del_s_t(SeqList<T> *seq, T s, T t) {
  T temp;
  int index = 0;
  T cur;
  if (seq->IsEmpty()) {
    cout << "table empty"<<endl;
    return false;
  }
  if (s > t) {
    cout << "type error"<<endl;
    return false;
  }
  for (int i = 0; i < seq->Length(); i++) {
    seq->getData(i, temp);
    if (temp >= s && temp <= t) {
      index++;
      continue;
    }
    seq->setData(i - index, temp);
  }
  seq->cut_length(index);
  return true;
}
// 从有序表中删除所有其值重复的元素,使表中所有元素的值均不同.
template <class T>
void become_set(SeqList<T> *seq) {
  T temp;
  int index = 0;
  T cur;
  for (int i = 0; i < seq->Length(); i++) {
    if (i == 0) {
      seq->getData(0, cur);
      continue;
    }
    seq->getData(i, temp);
    if (cur == temp) {
      index++;
    }
    else {
      seq->setData(i - index, temp);
      cur = temp;
    }
  }
  seq->cut_length(index);
}

// 将两个有序顺序表合并为一个新顺序表，并由函数返回结果顺序表.
template<class T>
void combine(SeqList<T> *seq1,SeqList<T> *seq2, SeqList<T> * &seq) {
  T temp1, temp2;
  int i = 0;
  for (int k = 0; k < seq1->Length(); k++) {
    if (k < seq2->Length()) {
      seq2->getData(i, temp2);
      seq1->getData(k, temp1);
      if (temp2 > temp1) {
        seq->Push(temp1);
      }
      else {
        seq->Push(temp2);
        i++;
      }
    }
  }
  for (int k = i; k < seq2->Length(); k++) {
    seq2->getData(k, temp2);
    seq->Push(temp2);
  }
  return;
}
#endif //SEQLIST_H_QUESTION
