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
int swapped;
size_t i, j, k;

for (i = 0; i < size - 1; i++)
{
	swapped = 0;
	for (j = 0; j < size - i - 1; j++)
	{
		if (array[j] > array[j + 1])
		{
			swap(&array[j], &array[j + 1]);
				swapped = 1;
		}
	}
	for (k = 0; k < size; k++)
	{
		printf("%d", array[k]);
		if (k < size - 1)
			printf(", ");
	}
	printf("\n");

	if (!swapped)
		break;
}
}
