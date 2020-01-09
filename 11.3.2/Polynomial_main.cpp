//
//  Polynomial_main.cpp
//  Polynomial
//
//  Created by Noah on 2020/1/9.
//  Copyright © 2020 Noah. All rights reserved.
//

#include <iostream>
using namespace std;
#include "Polynomial.cpp"


int main( )
{
Polynomial A{ };
A.Print( );
Polynomial B{ }; //定义多项式A和B
B.Print( );
Polynomial C = A + B;
printf("结果是：");
C.Print( ); //输出相加结果
return 0;
}
