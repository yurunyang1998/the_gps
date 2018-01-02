//
// Created by yurunyang on 18-1-1.
//
#include <string>

#ifndef THE_GPS_THE_CLASSES_DECLARATION_H
#define THE_GPS_THE_CLASSES_DECLARATION_H

#include <vector>
//the link of the map
using namespace std;
class Arcnode
{
public:
    Arcnode(int adjvexx=0,int weightt=0,std::string namee= "");
    ~Arcnode();
    void add_linknode(int adjvex,int adjweight,std::string name); // num表示这个节点邻接了几个点
    void print_linknode();   //输出当前节点所邻接的节点


public:
    int adjvex;//下标
    int weight;//上一个节点到该点的路径长度
    std::string name; //实际的名字，如图书馆
    //Arcnode *next=0;
    std::vector<Arcnode> linknode;



};

class Allmap
{
public:
    Allmap();
    ~Allmap();
    void readline(string mapfile); //读取mapfile到vector  of line 里面
    void addArcnode(); //建立Arcnodes

public:
    std::vector<Arcnode> map;
    std::vector<std::string> vector_of_line;
    int vexnum; //节点数
    int arcnum; //弧的数目

};







#endif //THE_GPS_THE_CLASSES_DECLARATION_H
