//
//  Polynomial.h
//  Polynomial
//
//  Created by Noah on 2020/1/9.
//  Copyright © 2020 Noah. All rights reserved.
//

#ifndef Polynomial_h
#define Polynomial_h

struct Node //定义多项式链表的结点
{
int coef, exp; // coef表示系数，exp表示指数
Node *next;
};

class Polynomial
{
public:
Polynomial( ); //构造函数
~Polynomial( ); //析构函数，同单链表析构函数
Polynomial(const Polynomial &B); //拷贝构造函数
Polynomial operator + (Polynomial &B); //重载运算法，多项式相加
void Print( ); //打印一元多项式
private:
Node *first;
};
#endif /* Polynomial_h */
