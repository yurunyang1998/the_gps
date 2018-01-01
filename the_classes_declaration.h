//
// Created by yurunyang on 18-1-1.
//
#include "string"

#ifndef THE_GPS_THE_CLASSES_DECLARATION_H
#define THE_GPS_THE_CLASSES_DECLARATION_H

#include <vector>
//the link of the map

class Arcnode
{
public:
    Arcnode(int adjvexx=0,int weightt=0,std::string namee= "");
    ~Arcnode();
    void add_linknode(int num); // num表示这个节点邻接了几个点
    void print_linknode();   //输出当前节点所邻接的节点


private:
    int adjvex;//下标
    int weight;//上一个节点到该点的路径长度
    std::string name; //实际的名字，如图书馆
    //Arcnode *next=0;
    std::vector<Arcnode> linknode;



};

class Allmap
{
public:
    Allmap(int num);
    ~Allmap();

private:
    std::vector<Arcnode> map;
    int vexnum; //节点数
    int arcnum; //弧的数目

};







#endif //THE_GPS_THE_CLASSES_DECLARATION_H
