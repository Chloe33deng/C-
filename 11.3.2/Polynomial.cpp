//
//  Polynomial.cpp
//  Polynomial
//
//  Created by Noah on 2020/1/9.
//  Copyright © 2020 Noah. All rights reserved.
//

#include <iostream>
using namespace std;
#include "Polynomial.h"

Polynomial::~Polynomial( )
{
Node *q = nullptr;
while (first != nullptr) //释放单链表的每一个结点的存储空间
{
q = first; //暂存被释放结点
first = first->next; // first指向被释放结点的下一个结点
delete q;
}
}

Polynomial :: Polynomial(const Polynomial &B){
first = B.first;
}

Polynomial :: Polynomial( )
{
Node *r = nullptr, *s = nullptr;
int coef, exp;
first = new Node; //申请头结点
r = first; r->next = nullptr; //尾插法建立单链表
cout << "请输入系数和指数：";
cin >> coef >> exp; //输入第一项的系数和指数
while (coef != 0 || exp != 0) //循环结束的条件是输入系数为0
{
s = new Node; s->coef = coef; s->exp = exp;
r->next = s; r = s; //将结点s插入单链表的尾部
cout << "请输入系数和指数：";
cin >> coef >> exp;
}
r->next = nullptr;
}

Polynomial Polynomial :: operator + (Polynomial &B)
{
Node *pre = first, *p = pre->next; //工作指针pre和p初始化
Node *qre = B.first, *q = qre->next; //工作指针qre和q初始化
Node *qtemp = nullptr;
while (p != nullptr && q != nullptr)
{
if (p->exp < q->exp) { //第1种情况
pre = p; p = p->next;
}
else if (p->exp > q->exp) { //第2种情况
qtemp = q->next;
pre->next = q; //将结点q插入到结点p之前
q->next = p;
q = qtemp;
pre = q;
qre->next = q;
}
else { //第3种情况
p->coef = p->coef + q->coef;
if (p->coef == 0) { //系数相加为0，则删除结点p
pre->next = p->next;
delete p;
p = pre->next;
}
else { //系数不为0
pre = p; p = p->next;
}
qre->next = q->next; //第3种情况都要删除结点q
delete q;
q = qre->next;
}
}
if (p == nullptr) pre->next = q; //将结点q链接在第一个单链表的后面
B.first->next = nullptr;
return *this;
}

void Polynomial :: Print( )
{
Node *p = first->next;
if (p != nullptr) /*输出第一项*/
cout << p->coef << "x" << p->exp;
p = p->next;
while (p != nullptr)
{
if (p->coef > 0) /*输出系数的正号或负号*/
cout << " + " << p->coef << "x" << p->exp;
else
cout << p->coef << "x" << p->exp;
p = p->next;
}
cout << endl;
}
