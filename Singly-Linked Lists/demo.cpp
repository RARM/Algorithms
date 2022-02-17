#include <iostream>
#include "linked_lists.h"

int main(void) {
    rarm::SL_List<int> my_list;

    // Adding the first node (data = 10).
    rarm::SL_Node<int>* node = new rarm::SL_Node<int>;
    node->set_data(10);

    my_list.append(*node);

    // Adding the second node (data = 50).
    node = new rarm::SL_Node<int>;
    node->set_data(50);

    my_list.append(*node);
    
    return 0;
}