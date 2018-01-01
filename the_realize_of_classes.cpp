//
// Created by yurunyang on 18-1-1.
//
#include "iostream"
#include "the_classes_declaration.h"
Arcnode::Arcnode(int adjvexx, int weightt, std::string namee) {
    adjvex = adjvexx;
    weight = weightt;
    name   = namee;
};

Arcnode::~Arcnode(){}



//为当前节点建立邻接顶点
void Arcnode::add_linknode(int num) {

    int i =0;
    for(i=0;i<num;i++) {

        int temp_adjvex=0;
        int temp_adjweight = 0;
        std::string  temp_name = "";

        std::cout<<"请输入节点序号" <<std::endl;
        std::cin>> temp_adjvex;

        std::cout<< "请输入上一个节点到这个节点的长度"<<std::endl;
        std::cin>> temp_adjweight;

        std::cout<< "请输入这个节点的名字" <<std::endl;
        std::cin>> temp_name;

        Arcnode new_node(temp_adjvex,temp_adjweight,temp_name);
        linknode.push_back(new_node);
    }

};


void Arcnode::print_linknode(){
    std::cout<<adjvex<<","<<weight<<","<<name<<","<< std::endl;
    std::vector<Arcnode>::size_type  size_type =0;

    while(size_type <linknode.size()){
        std::cout<<linknode[size_type].name<<std::endl;
        size_type++;
    }






}

//
Allmap::Allmap(int num){};
Allmap::~Allmap() {};