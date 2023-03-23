#include "function_pointers.h"
#include <stdio.h>
/**
 * print_name - prints a name using a given function
 *
 * @name: the name to be printed
 * @f: the function used to print the name
 * Return: nothing
 **/
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
return;
	f(name);
