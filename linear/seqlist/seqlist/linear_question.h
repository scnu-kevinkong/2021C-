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

// 已知一维数组A[m+n]中依次存放两个线性表a1,a2,a3.....am和b1,b2,b3.....bn,试编写一个函数,将数组中两个顺序表的位置互换,即将(b1,b2,b3...bn)放在(a1,a2...am)前面.
template<class T>
void Reverse(SeqList<T> *seq1, SeqList<T> *seq2, SeqList<T> *&seq) {
  seq1->reverse();
  seq2->reverse();
  combine(seq1, seq2, seq);
  seq->reverse();
}

//线性表(a1,a2,a3...an)中的元素递增有序且按照顺序存储于计算机内.要求设计一算法,完成用最少时间在表中查找数值为x的元素,若找到则将其与后继元素位置相交换,找不到则将其插入表中并使表中元素依旧有序.
template<class T>
void SearchExchangeInsert(SeqList<T> *seq, T x) {
  int low = 0;
  int high = seq->Length() - 1;
  int mid = 0;
  T temp;
  while (low <= high) {
    mid = (low + high) / 2;
    seq->getData(mid, temp);
    if (temp == x) break;
    else if (temp > x) {
      high = mid - 1;
    }
    else {
      low = mid + 1;
    }
  }
  if (temp == x && mid != seq->Length() - 1) {
    T exchange = temp;
    T last_value;
    seq->getData(mid + 1, last_value);
    seq->setData(mid, last_value);
    seq->setData(mid +1, temp);
  }
  if (low > high) {
    seq->extend_len(1);
    for (int i = seq->Length() - 1; i > high; i--) {
      seq->getData(i, temp);
      seq->setData(i + 1, temp);
    }
    seq->setData(high + 1, x);
  }
}
/*
 一个长度为L(L>=1)的升序序列S,处在第[L/2]个位置的数称为S的中位数,例如序列S1=(11,13,15,17,19),则S1的中位数是15,两个序列的中位数是含他们所有元素的升序序列的中位数.
 例如,若S2=（2,4,6,8,20),则S1和S2的中位数是11.
 现在有两个等长的升序序列A和B,试设计一个在时间和空间两方面都高效的算法.
*/
template<class T>
void get_two_mid(SeqList<T> *seq1, SeqList<T> *seq2, T &x) {
  T temp1, temp2;
  int l1, l2, r1, r2, m1, m2;
  l1 = 0; l2 = 0; r1 = seq1->Length() - 1; r2 = seq2->Length() - 1;
  while (l1 != r1 || l2 != r2) {
    m1 = (l1 + r1) / 2; m2 = (l2 + r2) / 2;
    seq1->getData(m1, temp1);
    seq2->getData(m2, temp2);
    if (temp1 == temp2) {
      cout << temp1 << endl;
      return;
    }
    if (temp1 < temp2) {
      if ((l1 + r1) % 2 == 0) {
        l1 = m1;
        r2 = m2;
      }
      else {
        l1 = m1 + 1;
        r2 = m2;
      }
    }
    else {
      if ((l2 + r2) % 2 == 0) {
        r1 = m1;
        l2 = m2;
      }
      else {
        r1 = m1;
        l2 = m2 + 1;
      }
    }
  }
  seq1->getData(l1, temp1);
  seq2->getData(l2, temp2);
  x = temp1 < temp2 ? temp1 : temp2;
  return;
}

/*
  已知一个整数序列A=(a0,a1,...an-1),其中0<=ai<n(0<=i<n),若存在ap1=ap2=....=apm=x且m>n/2(0<=pk<n,1<=k<=m),则称x为A的主元素.
  例如A=（0,5,5,3,5,7,5,5),则5为主元素;又如A=(0,5,5,3,5,1,3,5,7),则A中没有主元素.
  假设A中的n个元素保存在一个一维数组中,请设计一个尽可能高效的算法,找出A的主元素.
  若存在主元素,则输出该元素：否则输出-1.
*/
template<class T>
void majority(SeqList<T> *seq, T &x) {
  T temp,major;
  int count, i;
  count = 1;
  seq->getData(0, major);
  for (i = 1; i < seq->Length(); i++) {
    seq->getData(i, temp);
    if (temp == major) {
      count++;
    }
    else {
      if (count > 0) {
        count--;
      }
      else {
        seq->getData(i, major);
        count = 1;
      }
    }
  }
  if (count > 0) {
    for (i = count = 0; i < seq->Length(); i++) {
      seq->getData(i, temp);
      if (temp == major) {
        count++;
      }
    }
  }
  if (count > (seq->Length()-1) / 2) {
    x = major;
  }
  else {
    x = -1;
  }
  return;
}

/*
  给定一个含n(n>=1)个整数的数组,请设计一个在时间上可能高效的算法.
  找出数组中未出现的最小整数,例如数组{-5,3,2,3}中未出现的最小整数是1;
  数组1,2,3中未出现的最小整数是4.
*/
int findMissMin(SeqList<int> *seq) {
  int temp;
  int i;
  int *a = new int[seq->Length() + 1];
  for (i = 0; i < seq->Length(); i++) {
    seq->getData(i, temp);
    a[i] = 0;
    if (temp > 0 && temp <= seq->Length()) {
      a[temp - 1] = 1;
    }
  }
  for (i = 0; i < seq->Length(); i++) {
    if (a[i] == 0) {
      break;
    }
  }
  return i + 1;
}
#endif //SEQLIST_H_QUESTION
