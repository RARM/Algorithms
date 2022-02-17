#ifndef _SL_LISTS_H_
#define _SL_LISTS_H_

#include "rarm_base_elems.h"

// RARM are my initials.
namespace rarm {
	template <typename T>
	class SL_List;

	template <typename T>
	class SL_Node : private Node<T>
	{
		// friend void sample_func();
		friend class SL_List<T>;

	public:

		// Get the current data of this node.
		void set_data(T val);
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

		// void append();
		// void prepend();
		// void insert_after();
		// void remove_after();

	private:
		SL_Node<T>* head;
		SL_Node<T>* tail;
	};
}

#endif