//
//  Joseph.h
//  约瑟夫环的问题
//
//  Created by Noah on 2020/1/9.
//  Copyright © 2020 Noah. All rights reserved.
//

#ifndef Joseph_h
#define Joseph_h


struct Node //定义约瑟夫环的结点Node
{
int data;
struct Node *next;
};

class JosephRing
{
public:
JosephRing( ); //构造函数，初始化空循环链表
JosephRing(int n); //构造函数，初始化n个结点的环
~JosephRing( ); //析构函数，同单链表析构函数
void Joseph(int m); //密码为m，打印出环的顺序
private:
Node *rear;
};

#endif /* Joseph_h */
