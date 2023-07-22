#include "sort.h"

/**
 * swap - swap two inegers in an array
 * @a: first integer to swap
 * @b: second integer to swap
 */
void swap(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}

/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: array to sort
 * @size: size of array
 *
 * Description: prints an array after every swap
 */
void bubble_sort(int *array, size_t size)
{
size_t i, pass;
bool swapped;

if (array == NULL || size < 2)
	return;

for (pass = 0; pass < size - 1; pass++)
{
	swapped = true;
	for (i = 0; i < size - pass - 1; i++)
	{
		if (array[i] > array[i + 1])
		{
			swap(&array[i], &array[i + 1]);
			print_array(array, size);
			swapped = false;
		}
	}
	if(!swapped)
		pass--;
}
}
