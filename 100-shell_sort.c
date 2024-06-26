#include <stddef.h>
#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending
 * order using shell sort algorithm
 * @array: array of integers
 * @size: size of array
 */
void shell_sort(int *array, size_t size)
{
size_t gap = 1, i, j;
int temp;

if (array == NULL || size < 2)
return;

while (gap < size / 3)
gap = gap * 3 + 1;

while (gap >= 1)
{
for (i = gap; i < size; i++)
{
temp = array[i];
j = i;
while (j >= gap && array[j - gap] > temp)
{
array[j] = array[j - gap];
j -= gap;
}
array[j] = temp;
}
print_array(array, size);
gap /= 3;
}
}
