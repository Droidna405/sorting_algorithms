#include <stddef.h>
#include "sort.h"

/**
 * partition - Lomuto partition scheme
 * @array: array of integers
 * @low: starting index
 * @high: ending index
 * @size: size of array
 * Return: partition index
 */
int partition(int *array, int low, int high, size_t size)
{
int pivot = array[high];
int i = low - 1, j;

for (j = low; j < high; j++)
{
if (array[j] < pivot)
{
i++;
if (i != j)
{
int temp = array[i];
array[i] = array[j];
array[j] = temp;
print_array(array, size);
}
}
}
if (array[high] < array[i + 1])
{
int temp = array[i + 1];
array[i + 1] = array[high];
array[high] = temp;
print_array(array, size);
}
return (i + 1);
}

/**
 * quicksort - sorts an array of integers in ascending
 * order using quick sort algorithm
 * @array: array of integers
 * @low: starting index
 * @high: ending index
 * @size: size of array
 */
void quicksort(int *array, int low, int high, size_t size)
{
if (low < high)
{
int pi = partition(array, low, high, size);
quicksort(array, low, pi - 1, size);
quicksort(array, pi + 1, high, size);
}
}

/**
 * quick_sort - sorts an array of integers in ascending
 * order using quick sort algorithm
 * @array: array of integers
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;
quicksort(array, 0, size - 1, size);
}
