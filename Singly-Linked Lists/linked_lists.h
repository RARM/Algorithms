#ifndef _SL_LISTS_H_
#define _SL_LISTS_H_

#include "rarm_base_elems.h"

// RARM are my initials.
namespace rarm {
	// SL stands for Single_Linked

	template <typename T>
	class SL_List; // Forward declaration. Read more here: https://stackoverflow.com/questions/8967521/class-template-with-template-class-friend-whats-really-going-on-here

	template <typename T>
	class SL_Node : private Node<T>
	{
		// Friend the SL_List so that class can edit private attributes of this one.
		friend class SL_List<T>;

	public:
		SL_Node();
		// ~SL_Node(); // Default constructor should work on this case.

		// Set the data of the node.
		void set_data(T val);
		
		// Get the current data of this node.
		T get_data();

	private:
		SL_Node<T>* next;
	};

	template <typename T>
	class SL_List
	{
	public:
		SL_List();
		~SL_List();

		void append(SL_Node<T>& new_node);
		// void prepend();
		// void insert_after();
		// void remove_after();

	private:
		SL_Node<T>* head;
		SL_Node<T>* tail;
	};
}

#endif