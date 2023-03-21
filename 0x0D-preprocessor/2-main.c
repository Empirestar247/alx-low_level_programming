#include <stdio.h>
/**
*main - prints the name of the file it was compiled from by a new line
*Return: 0 success
*/
int main(void)
{
	printf("%s\n", __FILE__);
	return (0);
}

