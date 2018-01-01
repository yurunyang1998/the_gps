#include <iostream>
#include "the_classes_declaration.h"
#include <string>
#include <vector>
using namespace std;
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

int main() {
    Arcnode testnode(1,0,"beimeng");
    testnode.add_linknode(3);
    testnode.print_linknode();
}