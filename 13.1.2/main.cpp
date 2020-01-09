//
//  main.cpp
//  13.1.2对称矩阵的压缩存储
//
//  Created by Noah on 2019/11/21.
//  Copyright © 2019 Noah. All rights reserved.
//

#include <iostream>
using namespace std;
template<class T>
class SymmetricMatrix
{
public:
    SymmetricMatrix(T* array, size_t n)
    {
        _arraySize = n*(n + 1) / 2;
        _size = n;
        _array = new T[_arraySize];
        assert(array);
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                _array[i*(i + 1) / 2 + j] = array[i*n + j];
            }
        }
    }
    T& GetPos(size_t row, size_t col)    // 获取节点
    {
          //如果该位置为上三角的，利用对称原理，交换该位置的行和列即可
        if (row < col)
        {
            swap(row, col);
        }
        return _array[row*(row + 1) / 2 + col];
    }
    void Display()     //打印
    {
        for (int i = 0; i < _size; i++)
        {
            for (int j = 0; j < _size; j++)
            {
                if (i >= j)
                {
                    cout << _array[i*(i + 1) / 2 + j] << " ";
                }
                else if (i<j)
                {
                    cout << _array[j*(j + 1) / 2 + i] << " ";
                }
            }
            cout << endl;
        }
        cout << endl;
    }
private:
    T *_array;      //压缩矩阵
    size_t _size;   //方阵大小_size*_size
    size_t _arraySize;   //压缩矩阵的总大小
};
const int N=5;
int main()
{
    int A[N][N],SA[N * (N+1)/2]={0};
    int i,j;
    for(i=0;i <= N; i++)
        for(j=0;j <= i; j++)
            A[i][j] = A[j][i] = i+j;
    for(i = 0;i < N; i++)
    {
        for( j = 0;j < N;j++)
            cout<<A[i][j]<<" ";
        cout<<endl;
    }
    for(i = 0;i < N; j++)
        for(j = 0;j <= i;j++)
            SA[i * (i-1)/2+j] = A[i][j];
    SA[i* (i -1)/2 + j] = A[i][j];
    cout<<"请输入行号和列号:";
    cin>>i>>j;
    cout<<i<<"行"<<j<<"列的元素值是：";
    if(i>=j)
        cout<<SA[i * (i - 1)/2 + j]<<endl;
    else
        cout<<SA[j*(j-1)/2 + i]<<endl;
    return 0;
}
