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
rarm::SL_List<T>::SL_List(const rarm::SL_List<T>& org) { // org = original
    rarm::SL_Node<T>* org_cur_node{ org.head }, * cur_node{ nullptr };

    if (org_cur_node == nullptr) { // If list is empty.
        this->head = nullptr;
        this->tail = nullptr;
    }

    else {
        cur_node = new rarm::SL_Node<T>;
        cur_node->data = org_cur_node->data;

        this->head = cur_node;
        this->tail = cur_node;

        org_cur_node = org_cur_node->next;

        while (org_cur_node != nullptr)
        {
            cur_node->next = new rarm::SL_Node<T>; // This removes the necessity of creating another variable in the local scope.
            cur_node = cur_node->next;
            cur_node->data = org_cur_node->data;

            this->tail = cur_node;

            org_cur_node = org_cur_node->next;
        }
    }

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
void rarm::SL_List<T>::append(SL_Node<T>* new_node) {
    if (this->head == nullptr) { // List is empty.
        this->head = new_node;
        this->tail = new_node;
    }

    else { // It is not empty.
        this->tail->next = new_node;
        this->tail = new_node;
    }

    return;
}

template <typename T>
void rarm::SL_List<T>::prepend(SL_Node<T>* new_node) {
    if (this->head == nullptr) {
        this->head = new_node;
        this->tail = new_node;
    }

    else {
        new_node->next = this->head;
        this->head = new_node;
    }

    return;
}

template <typename T>
void rarm::SL_List<T>::insert_after(SL_Node<T>* cur_node, SL_Node<T>* new_node) {
    if (this->head == nullptr) { // List is empty.
        this->head = new_node;
        this->tail = new_node;
    }

    else if (cur_node == this->tail) {
        this->tail->next = new_node;
        this->tail = new_node;
    }

    else {
        new_node->next = cur_node->next;
        cur_node->next = new_node;
    }

    return;
}

template <typename T>
void rarm::SL_List<T>::remove_after(rarm::SL_Node<T>* cur_node) {
    rarm::SL_Node<T>* suc_node{ nullptr }; // Successive node.
    
    if (cur_node == nullptr && this->head != nullptr) { // Remove head.
        suc_node = this->head->next;
        this->head = suc_node;

        if (suc_node == nullptr) this->tail = nullptr;
    }

    else if (cur_node != nullptr && cur_node->next != nullptr) {
        suc_node = cur_node->next->next;
        cur_node->next = suc_node;

        if (suc_node == nullptr) this->tail = cur_node; // If removing tail.
    }

    return;
}

// Types.
template rarm::SL_Node<int>;
template rarm::SL_List<int>;