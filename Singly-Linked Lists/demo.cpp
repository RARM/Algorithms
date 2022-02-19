// demo.cpp -- Demostration of sinlgy linked list usage.
//             There are some comments on the code to see what's expected.
//             Use the debugger to view live code execution and compare with expected results.
#include <iostream>
#include "linked_lists.h"

void testing_copy_constructor(rarm::SL_List<int>);

int main(void) {
    rarm::SL_List<int> my_list; // Creating a new empty list.

    // Adding the first node (data = 10).
    rarm::SL_Node<int>* node = new rarm::SL_Node<int>;
    node->set_data(10);

    my_list.append(node); // List: 10

    // Adding the second node (data = 50).
    node = new rarm::SL_Node<int>;
    node->set_data(50);

    my_list.append(node); // List: 10, 50

    testing_copy_constructor(my_list); // This should not affect the list on this scope.

    // Creating the third node (data = 100).
    node = new rarm::SL_Node<int>;
    node->set_data(100);

    my_list.prepend(node); // List: 100, 10, 50 

    // Using the insert after method.
    rarm::SL_Node<int>* another_node = new rarm::SL_Node<int>;
    another_node->set_data(35);

    my_list.insert_after(node, another_node); // List: 100, 35, 10, 50

    // Using the remove after method.
    my_list.remove_after(another_node); // List: 100, 35, 50
    
    return 0;
}

/* The copy constructor is tested. It is supposed to be a deep copy.
 * Therefore, changes here won't affect the main scope.
*/
void testing_copy_constructor(rarm::SL_List<int> copied_list) { // copied_list = [10, 50] from the first call in main.
    // Adding (data = 25).
    rarm::SL_Node<int>* node = new rarm::SL_Node<int>;
    node->set_data(25);

    copied_list.append(node); // List = [10, 50, 25] | However, the list in main is unchanged [10, 50]

    return;
}