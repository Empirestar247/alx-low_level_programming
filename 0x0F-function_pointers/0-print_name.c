#include <stdio.h>
#include "function_pointers.h"

/**
*print_name - this function print a name
*@name: string to print.
*@f: this is a function pointer that receives a string.
*Return: nothing
*/
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
	return;
	(*f)(name);
}
