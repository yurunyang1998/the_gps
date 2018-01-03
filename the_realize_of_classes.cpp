//
// Created by yurunyang on 18-1-1.
//
#include "iostream"
#include "the_classes_declaration.h"
#include <string>
#include <vector>
#include <fstream>
#include "algorithm"
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

    Arcnode zhan_wei_jie_dian(9999,9999,"zhanwei");
    map.push_back(zhan_wei_jie_dian);

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

        new_node.add_linknode(-111,-111,"ZhanWeiJieDian");

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
        //cout<< map[1].linknode.size()<<"     "<<map[1].linknode[1].name <<endl;

}



///////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////


bool shi_fou_xuan_wan(int path[15][15],int i,int j )
{
    int p=0;
    for(p=0;p<j;p++)
    {
        if(path[i][p]==0)
            return true;
    }
    return false;
}


int min(int dict[]){

}







void Allmap::find_the_shortest_way(string beginNode, string endNode) {
    int path[15][15]={0};

    vector<int> dist(15,999);

    //int dist[15]={999};
    int i=0,j=1;
    for (i=1;i<16;i++){
        if(map[i].name==beginNode)
        {
            break;
        }
    }

    int k=0;
    for (k;k<map[i].linknode.size();k++)
    {
        dist[map[i].linknode[k].adjvex]=map[i].linknode[k].weight;
    }

    //for (j;j<map.size();j++)
     while(shi_fou_xuan_wan(path,i,15)) // 所有顶点都标记过了
    {
        if(path[i][j] !=1) {
            int tempdata = 0;
            tempdata = dist[map[i].linknode[j].adjvex] + map[i].linknode[j].weight;
            if (dist[map[i].linknode[j].adjvex] > tempdata)
                dist[map[i].linknode[j].adjvex] = tempdata;
            path[i][j] = 1;
        }
        vector<int>::iterator iter = std::max_element(dist.begin(),dist.end());
        j = *iter;

    cout<<dist[1];


    }
}


