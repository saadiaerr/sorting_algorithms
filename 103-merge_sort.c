#include "sort.h"

void merge_recursion(int *arr, int *array, size_t left, size_t right);
void merge_subarray(int *arr, int *array, size_t left,
		size_t middle, size_t right);

/**
 * merge_sort - mrg sort
 * @array: array to lst
 * @size: sze
 *
 * Return: nothing
 */
void merge_sort(int *array, size_t size)
{
	int *arr;

	if (!array || size < 2)
		return;

	arr = malloc(sizeof(int) * size);

	merge_recursion(arr, array, 0, size);
	free(arr);
}

/**
 * merge_recursion - merge recursion to array
 * @arr: array6
 * @array: ary
 * @left: yassar
 * @right: yamin
 *
 * Return: nothing
 */
void merge_recursion(int *arr, int *array, size_t left, size_t right)
{
	size_t middle;

	if (right - left > 1)
	{
		middle = (right - left) / 2 + left;
		merge_recursion(arr, array, left, middle);
		merge_recursion(arr, array, middle, right);
		merge_subarray(arr, array, left, middle, right);
	}
}

/**
 * merge_subarray - merges sub
 * @arr: cpy ary
 * @array: ary to merge
 * @left: lft element
 * @middle: middle element
 * @right: right element
 *
 * Return: nothing
 */
void merge_subarray(int *arr, int *array, size_t left,
		size_t middle, size_t right)
{
	size_t i, j, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, middle  - left);
	printf("[right]: ");
	print_array(array + middle, right - middle);

	for (i = left, j = middle; i < middle && j < right; k++)
	{
		if (array[i] < array[j])
			arr[k] = array[i++];
		else
			arr[k] = array[j++];
	}

	while (i < middle)
		arr[k++] = array[i++];
	while (j < right)
		arr[k++] = array[j++];

	for (k = left, i = 0; k < right; k++)
		array[k] = arr[i++];

	printf("[Done]: ");
	print_array(array + left, right - left);
}
