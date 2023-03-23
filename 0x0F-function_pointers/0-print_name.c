#include "function_pointers"
#include <stdio.h>
/**
 * print_name - prints a name using a pointer to function
 *
 * @name: string to add
 * @f: pointer to the function used to print the name
 * Return: void
 **/
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
	return;
	f(name);
}
