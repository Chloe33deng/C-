//
//  Joseph_main.cpp
//  约瑟夫环的问题
//
//  Created by Noah on 2020/1/9.
//  Copyright © 2020 Noah. All rights reserved.
//

#include <iostream>
using namespace std;
#include "Joseph.h"



int main( )
{
int n, m;
cout << "请输入约瑟夫环的长度：";
cin >> n;
cout << "请输入密码：";
cin >> m;
JosephRing R(n);
R.Joseph(m);
return 0;
}
