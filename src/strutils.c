#include <string.h>
#include "strutils.h"

#define BUFSIZE 1024

void strchg(char *buf, const char *target, const char *repl) {
	char tmp[BUFSIZE + 1];
	char *p;

	while ((p = strstr(buf, target)) != NULL) {
		*p = '\0';
		p += strlen(target);
		strcpy(tmp, p);
		strcat(buf, repl);
		strcat(buf, tmp);
	}
}
