//
//  ALGraph.h
//  邻接表的实现
//
//  Created by Noah on 2019/12/12.
//  Copyright © 2019 Noah. All rights reserved.
//

#ifndef ALGraph_H
#define ALGraph_H
const int MaxSize=10;


struct ArcNode
{
    int adjvex;
    ArcNode *next;
};
template<class DataType>
struct VertexNode
{
    DataType vertex;
    ArcNode *firstedge;
};


template<class DataType>
class ALGraph
{
public:
    ALGraph(DataType a[],int n,int e);
    ~ALGraph();
    void DFSTraverse(int v);
    void BFSTraverse(int v);
private:
    VertexNode<DataType>adjlist[MaxSize];
    int vertexNum,arcNum;
};
#endif
