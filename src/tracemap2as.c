/**
 * tracemap2as.c
 * Author: Shintaro Tanaka
 */

#include <stdio.h>
#include <string.h>

#include "strutils.h"
#include "ip4table.h"
#include "ip6table.h"
#include "ip4matcher.h"
#include "ip6matcher.h"
#include "ip4parser.h"
#include "ip6parser.h"

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
	//struct ip4table *table4 = load_ip4table();
	//struct ip6table *table6 = load_ip6table();
	char line[BUFSIZE + 1];
	char *ipstr;
	unsigned short int ip4bin;
	unsigned long long int ip6bin;
	unsigned int as_num;
	char *buf;
	char *p;

	// arg validation

	// stdin loop
	while(fgets(line, sizeof(line), stdin) != NULL) {
		// chomp
		if ((p = strrchr(line, '\n')) != NULL) {
			*p = '\0';
		}
		rewind(stdin);

		as_num = 0;

		//if ((ipstr = ip4match(line)) != NULL &&
		//	(ip4bin = ip4parse(ipstr)) != 0) {
		//	as_num = lookup_ip4table(ip4bin, table4);
		//} else if ((ipstr = ip6match(line)) != NULL &&
		//		(ip6bin = ip6parse(ipstr)) != 0) {
		//	as_num = lookup_ip6table(ip6bin, table6);
		//}
		// replace the line
		if (as_num != 0) {
			sprintf(buf, "%s[AS%d]", ipstr, as_num);
			strchg(line, ipstr, buf);
		}
		printf("%s\n", line);
	}

	return 0;
}
