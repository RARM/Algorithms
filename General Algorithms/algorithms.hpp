#ifndef _ALGORITHMS_HPP_
#define _ALGORITHMS_HPP_

namespace air {
	int* selectionsort(int* list, unsigned size);
	void mergesort(int* list, size_t first, size_t last);
	void merge(int* list, size_t first, size_t mid, size_t last);
}

#endif
