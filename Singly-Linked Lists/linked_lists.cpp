#include "linked_lists.h"

template <typename T>
rarm::SL_Node<T>::SL_Node()
    : next{ nullptr } {}

template <typename T>
void rarm::SL_Node<T>::set_data(T val) {
    this->data = val;
}

template <typename T>
T rarm::SL_Node<T>::get_data() {
    return this->data;
}

template <typename T>
rarm::SL_List<T>::SL_List()
    : head{ nullptr }, tail{ nullptr } {
    return;
}

template <typename T>
rarm::SL_List<T>::~SL_List() {
    rarm::SL_Node<T>* cur_node{ this->head }, * next_node{ nullptr };

    while (cur_node != nullptr) {
        next_node = cur_node->next;
        delete cur_node;
        cur_node = next_node;
    }

    return;
}

template <typename T>
void rarm::SL_List<T>::append(SL_Node<T>& new_node) {
    if (this->head == nullptr) { // List is empty.
        this->head = &new_node;
        this->tail = &new_node;
    }

    else { // It is not empty.
        this->tail->next = &new_node;
        this->tail = &new_node;
    }

    return;
}

// Types.
template rarm::SL_Node<int>;
template rarm::SL_List<int>;