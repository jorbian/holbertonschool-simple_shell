#include <stdio.h>

int main()
{
	char *foo = "SPAM";
	char *bar = &foo;

	printf("%s", bar);

	return (0)
}
