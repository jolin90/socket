#include "jolin.h"
#include "text.h"

#define isspace(c)	(c == ' ' || c == '\t' || c == 10 || c == 13 || c == 0)

char *skip_spaces(const char *str)
{
	while (isspace(*str))
		++str;
	return (char *)str;
}

char *strim(char *s)
{
	size_t size;
	char *end;

	size = strlen(s);
	if (!size)
		return s;

	end = s + size - 1;
	while (end >= s && isspace(*end))
		end--;
	*(end + 1) = '\0';

	return skip_spaces(s);
}

char *allstrim(char *str)
{
	char *p = str, *q;

	while(*p != 0)
	{
		if(isspace(*p))
		{
			q = p;
			while(*q != 0)
			{
				*q = *(q+1);
				q++;
			}
		} else {
			p++;
		}
	}

	return str;
}
