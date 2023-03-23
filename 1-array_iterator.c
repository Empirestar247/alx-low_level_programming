#include <stdio.h>
#include "function_pointers"
/**
 * array_iterator - executes a function on each element of an array
 * @array: pointer to the first element of the array
 * @size: the number of elements in the array
 * @action: pointer to the function to execute on each element
 *
 * Return: void
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	if (array == NULL || action == NULL)
		return;

	for (size_t i = 0; i < size; i++)
		action(array[i]);
}

