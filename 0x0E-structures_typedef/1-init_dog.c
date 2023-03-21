#include <stdio.h>
include "dog.h"
{
char *name;    
float age;
char *owner;
};
/**
 * init_dog - Initializes a dog structure with the provided values
 * @d: Pointer to the dog structure
 * @name: Name of the dog
 * @age: Age of the dog
 * @owner: Owner of the dog
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
d->name = name;
d->age = age;
d->owner = owner;
}
/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
struct dog my_dog;
init_dog(&my_dog, "Max", 3.5, "John");
printf("Name: %s\n", my_dog.name);
printf("Age: %.2f\n", my_dog.age);
printf("Owner: %s\n", my_dog.owner);
return (0);
}
