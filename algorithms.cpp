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
	int* SelectionSort(int* list, unsigned size)
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

}
