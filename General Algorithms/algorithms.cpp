/* algorithms.cpp
 * This file contains the implementations of the algorithms found in the README
 * file in https://github.com/RARM/Algorithms
 *
 * This should serve just as a demostration. Please, check the README file of
 * the repository above.
*/

namespace air // Algorithms' Impelementation by Rodolfo
{

	/* Selection Sort
	 * Sorts an array of a given size.
	 * It returns the pointer to the array organized.
	*/
	int* selectionsort(int* list, unsigned size)
	{
		unsigned smallest;
		int temp;
		for (unsigned i{ 0 }; i < size - 1; i++)
		{
			smallest = i;
			for (unsigned j{ i + 1 }; j < size; j++) // Find the smallest for list[i]
				smallest = (list[j] < list[smallest]) ? j : smallest;

			temp = list[smallest];		// Here comes the swap.
			list[smallest] = list[i];
			list[i] = temp;			// Swapped!
		}

		return list;
	}



	/* Merge Sort
	 * The following two functions work together to
	 * implement the merge sort algorithm.
	 * 
	 * Use mergesort(list, first, last)
	 * where list is a pointer to the array to be
	 * sorterd. The variables first and last are
	 * the the index of the first and last
	 * elements in the array to be sorted, respectively.
	*/
	void merge(int* list, size_t first, size_t mid, size_t last)
	{
		// Size of the subarrays.
		size_t l1_len = mid - first + 1;
		size_t l2_len = last - mid;

		// Create to subarrays Left and Right.
		int* left = new int[l1_len];
		int* right = new int[l2_len];

		// Populate with the first and second half of the original
		// array, respectively.
		for (size_t i{ 0 }; i < l1_len; i++) left[i] = list[first + i];
		for (size_t j{ 0 }; j < l2_len; j++) right[j] = list[mid + j + 1];

		// Start the merge in the list.
		size_t i = 0, j = 0, k;
		for (k = first; i < l1_len && j < l2_len; k++)
			if (left[i] <= right[j]) list[k] = left[i++];
			else list[k] = right[j++];

		// Add the rest of the array.
		if (i < l1_len) while (i < l1_len)  list[k++] = left[i++];
		else while (j < l2_len) list[k++] = right[j++];

		// Free alocated memory.
		delete[] left;
		delete[] right;
	}

	void mergesort(int* list, size_t first, size_t last)
	{
		// As long as the list has more than one element,
		// split and merge sort.
		if (first < last)
		{
			size_t mid{ (first + last) / 2 }; // By default floor by truncating.
			mergesort(list, first, mid);
			mergesort(list, mid + 1, last);
			merge(list, first, mid, last);
		}
	}
}
