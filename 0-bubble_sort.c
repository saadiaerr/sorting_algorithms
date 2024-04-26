#include "sort.h"

/**
 *bubble_sort - srt
 *@array: array1
 *@size: size2
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	int tmp;
	size_t j, l;

	if (!array || !size)
		return;

	j = 0;
	while (j < size)
	{
		for (l = 0; l < size - 1; l++)
		{
			if (array[l] > array[l + 1])
			{
				tmp = array[l];
				array[l] = array[l + 1];
				array[l + 1] = tmp;
				print_array(array, size);
			}
		}
		j++;
	}
}
