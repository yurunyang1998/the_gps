#include <iostream>
#include "the_classes_declaration.h"

int main() {
    Arcnode testnode(1,0,"bei_meng");
    testnode.add_linknode(3);
    testnode.print_linknode();
}