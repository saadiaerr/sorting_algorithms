#include "sort.h"
/**
*swap - the positions of two elmts
*@array: array
*@item1: array element
*@item2: array element
*/
void swap(int *array, ssize_t item1, ssize_t item2)
{
	int tmp;

	tmp = array[item1];
	array[item1] = array[item2];
	array[item2] = tmp;
}
/**
 *lomuto_partition - lomuto partition sorting
 *@array: array
 *@low: low array
 *@hight: hight array
 *@size: sze array
 *Return: return the position
 */
int lomuto_partition(int *array, ssize_t low, ssize_t hight, size_t size)
{
	int pivot = array[hight];
	ssize_t current = low, i;

	for (i = low; i < hight; i++)
	{
		if (array[i] < pivot)
		{
			if (array[current] != array[i])
			{
				swap(array, current, i);
				print_array(array, size);
			}
			current++;
		}
	}
	if (array[current] != array[hight])
	{
		swap(array, current, hight);
		print_array(array, size);
	}
	return (current);
}
/**
 *qs - qucksort alg
 *@array: array
 *@low: low array elmt
 *@hight: hight array elmt
 *@size: array size
 */
void qs(int *array, ssize_t low, ssize_t hight, int size)
{
	ssize_t position = 0;


	if (low < hight)
	{
		position = lomuto_partition(array, low, hight, size);

		qs(array, low, position - 1, size);
		qs(array, position + 1, hight, size);
	}
}
/**
 *quick_sort - prepare the quicksort alg
 *@array: array
 *@size: array size
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	qs(array, 0, size - 1, size);
}
