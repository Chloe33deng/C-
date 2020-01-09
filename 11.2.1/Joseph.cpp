//
//  Joseph.cpp
//  约瑟夫环的问题
//
//  Created by Noah on 2020/1/9.
//  Copyright © 2020 Noah. All rights reserved.
//

#include <iostream>
using namespace std;
#include "Joseph.h"



JosephRing :: JosephRing( )
{
rear = nullptr;
}

JosephRing :: JosephRing(int n)
{
Node *s = nullptr;
rear = new Node;
rear->data = 1; rear->next = rear; //建立长度为1的循环单链表
for (int i = 2; i <= n; i++) //依次插入数据域为2、3、…、n的结点
{
s = new Node; s->data = i;
s->next = rear->next; //将结点s插入尾结点rear的后面
rear->next = s;
rear = s; //指针rear指向当前的尾结点
}
}

JosephRing :: ~JosephRing()
{
if (rear != nullptr){
Node *p = rear->next;
while(rear->next != rear)
{
rear->next = p->next;
delete p;
p = rear->next;
}
delete rear;
}
}

void JosephRing :: Joseph(int m)
{
Node *pre = rear, *p = rear->next; //初始化工作指针p和pre
int count = 1;
cout << "出环的顺序是：";
while (p->next != p) //循环直到循环链表中只剩一个结点
{
if (count < m) { //计数器未累加到密码值
pre = p; p = p->next; //将工作指针pre和p分别后移
count++;
}
else { //计数器已经累加到密码值
cout << p->data<< "    "; //输出出环的编号
pre->next = p->next; //将结点p摘链
delete p;
p = pre->next; //工作指针p后移，但pre不动
count = 1; //计数器从1开始重新计数
}
}
cout << p->data << "    "; //输出最后一个结点的编号
delete p; //释放最后一个结点
rear = nullptr;
}
