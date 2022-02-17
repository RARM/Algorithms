// demo.cpp -- Demostration of usage of algorithms' implementations.
#include "algorithms.hpp"
#include <iostream>

int main(void)
{
	// --------------------------------------------------------------
	// SELECTION SORT DEMOSTRATION BELOW.
	std::cout << "Selection sort demo.\n";
	int selection_list[] = { 24, 10, -5, 8, 1, 22 };

	std::cout << "List before sorting: [ ";
	for (auto num : selection_list) std::cout << num << " ";
	std::cout << "]\n";

	air::selectionsort(selection_list, 6);

	std::cout << "List after sort: [ ";
	for (auto num : selection_list) std::cout << num << " ";
	std::cout << "]\n\n";



	// --------------------------------------------------------------
	// MERGER SORT DEMOSTRATION BELOW.
	std::cout << "Merge sort demo.\n";
	int merge_list[] = { 13, 12, -10, 55, 13, 10 };

	std::cout << "List before sorting: [ ";
	for (auto num : merge_list) std::cout << num << " ";
	std::cout << "]\n";

	air::mergesort(merge_list, 0, 5);

	std::cout << "List after sort: [ ";
	for (auto num : merge_list) std::cout << num << " ";
	std::cout << "]\n";



	// --------------------------------------------------------------
	// END OF DEMOSTRATIONS.
	return 0;
}