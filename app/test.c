
#include "jolin.h"
#include "text.h"

#include <ctype.h>

int main()
{
	char buff[] = " 1 2 3 4  5 6 7 8  9 0 ";

	printf("%s\n", allstrim(buff));

	if (isdigit('c'))
		printf("hello\n");

	return 0;
}
