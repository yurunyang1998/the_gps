//
// Created by yurunyang on 18-1-1.
//
#include "iostream"
#include "the_classes_declaration.h"
#include <string>
#include <vector>
#include <fstream>

using  namespace std;

//下面这个是split函数
/////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
void SplitString(const string& s, vector<string>& v, const string& c)
{
    string::size_type pos1, pos2;
    pos2 = s.find(c);
    pos1 = 0;
    while(string::npos != pos2)
    {
        v.push_back(s.substr(pos1, pos2-pos1));

        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
    }
    if(pos1 != s.length())
        v.push_back(s.substr(pos1));
}

////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////



//下面这个是按行读取文件的函数
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
int  Readlines(string mapfile,vector<string> *vector_of_line)
{
    ifstream in(mapfile);
    string filename;
    string line;

    if(in) // 有该文件
    {
        vector_of_line->clear();
        while (getline(in, line)) // line中不包括每行的换行符
        {
            vector_of_line->push_back(line);
        }
        in.close();
    }
    else // 没有该文件
    {
        cout <<"no such file" << endl;
    }

    return 0;
}
///////////////////////////////////////////////////
///////////////////////////////////////////////////



Arcnode::Arcnode(int adjvexx, int weightt, std::string namee) {
    adjvex = adjvexx;
    weight = weightt;
    name   = namee;
};

Arcnode::~Arcnode(){}



//为当前节点建立邻接顶点
void Arcnode::add_linknode(int adjvex,int adjweight,std::string name) {

    int i =0;
    Arcnode new_node(adjvex,adjweight,name);
    linknode.push_back(new_node);

};

//////////这个是用来测试输出的
void Arcnode::print_linknode(){
    std::cout<<adjvex<<","<<weight<<","<<name<<","<< std::endl;
    std::vector<Arcnode>::size_type  size_type =0;

    while(size_type <linknode.size()){
        std::cout<<linknode[size_type].name<<std::endl;
        size_type++;
    }
}
////////////////////////////////////

//
Allmap::Allmap(){

};
Allmap::~Allmap() {};


///读取mapfile到vector  of line 里面
void Allmap::readline(string mapfile) {

    Readlines(mapfile,&vector_of_line);

}

void Allmap::addArcnode() {
    if (vector_of_line.size() ==0)
    {
        std::cout<<"还未将mapfile读取vector"<<endl;
        return;
    }

    int linesnum = vector_of_line.size();
    int num = 15;
    vector<string>::size_type iter;

    for (iter=0;iter<num;iter++)
    {
        vector<string> templine , templine2;
        SplitString(vector_of_line[iter],templine,"*");
        //cout<<vector_of_line[iter]<<endl;  //*
        SplitString(templine[0],templine2," ");

        int temp = std::stoi(templine2[0]); //将string 转化为 int

        //Arcnode * new_node = new Arcnode(temp,0,templine2[1]);   //*
        Arcnode new_node(temp,0,templine2[1]);     //这个是头结点
        vector<string>::size_type size ;

        for(size=1;size<templine.size();size++)
        {
            vector<string> templine3 ;
            SplitString(templine[size],templine3," ");
            int tempnode = std::stoi(templine3[0]);
            int tempweight = std::stoi(templine3[1]);
            new_node.add_linknode(tempnode,tempweight,templine3[2]);

        }

        map.push_back(new_node);
    }
    std::cout <<2<<endl;
    cout<<map[0].linknode[1].name<<endl;
    cout <<3<<endl;


}