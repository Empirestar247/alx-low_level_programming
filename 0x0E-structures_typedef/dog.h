#ifndef DOG_H
#define DOG_H
/**
*struct dog - dog credentials
*
*@name: name of dog
*@age: age of dog
*@owner: owner of dog
*
*Return: 0 success
*/
struct dog
{
	char *name;
	float age;
	char *owner;
};

/**
 * dog_t -typedef for struct dog
 */
typedef struct dog dog_t;

/* Additional function prototype */
int _putchar(char c);
void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
void free_dog(dog_t *d);
dog_t *new_dog(char *name, float age, char *owner);

#endif /* DOG_H */
