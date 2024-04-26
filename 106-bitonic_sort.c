#include "sort.h"

void bitonic_recursion(int *array, int l, int r, int direction, size_t size);
void bitonic_merge(int *array, int l, int r, int direction);

/**
 * bitonic_sort - Sorts an array
 * @array: Pointer to the array
 * @size: Size of the array
 *
 * Return: not
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
	{
		return;
	}

	bitonic_recursion(array, 0, size - 1, 1, size);
}

/**
 * bitonic_recursion - Recursively divides and merges subarrays for Bitonic
 *                     sort
 * @array: Pointer to the array
 * @l: Left index of the subarray
 * @r: Right index of the subarray
 * @direction: Direction of the merging
 * @size: Size of the original array
 *
 * Return:not
 */
void bitonic_recursion(int *array, int l, int r, int direction, size_t size)
{
	int step;

	if (r - l >= 1)
	{
		step = (r + l) / 2;
		printf("Merging [%d/%lu] ", r - l + 1, size);
		if (direction)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(array + l, r - l + 1);
		bitonic_recursion(array, l, step, 1, size);
		bitonic_recursion(array, step + 1, r, 0, size);
		bitonic_merge(array, l, r, direction);
		printf("Result [%d/%lu] ", r - l + 1, size);
		if (direction)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(array + l, r - l + 1);
	}
}

/**
 * bitonic_merge - Merges two subarrays
 * @array: Pointer to the array containing
 * @l: Left index of the first subarray
 * @r: Right index of the second subarray
 * @direction: Direction of the merging
 *
 * Return: void
 */
void bitonic_merge(int *array, int l, int r, int direction)
{
	int tmp, i, step = (l + r) / 2, mid = (r - l + 1) / 2;

	if (r - l >= 1)
	{
		for (i = l; i < l + mid; i++)
		{
			if (direction == (array[i] > array[i + mid]))
			{
				tmp = array[i + mid];
				array[i + mid] = array[i];
				array[i] = tmp;
			}
		}
		bitonic_merge(array, l, step, direction);
		bitonic_merge(array, step + 1, r, direction);
	}
}
