/* See LICENSE file for copyright information
 *
 * prime is a program designed to factor prime numbers
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

uint64_t tnum, snum;
float version = 0.1;

/*
 * Basic Trial Division
 * Ideally replaced by an AKS primality test
 * Inefficient for large numbers but simple
 */
bool 
isPrimeBTD(uint64_t n)
{
	if (n == 2)
		return true;

	if (!(n % 2) || n < 2)
		return false;

	for (uint64_t i = 3; i <= sqrtl(n); i++)
	{
		if (!(n % i))
			return false;
	}

	return true;
}

void
listPrimes()
{
	uint64_t cnum = snum;

	while (cnum <= tnum && cnum <= UINT64_MAX)
	{
		if (isPrimeBTD(cnum))
			printf("%jd is prime\n", cnum);
		else
			printf("%jd is composite\n", cnum);

		cnum++;
	}
}

int
main(int argc, char **argv)
{
	if (argc == 2 && !strcmp("-v", argv[1])) {
		printf("prime %.1f\n", version);
	} else {
		snum = 1;
		tnum = 100;
		listPrimes();
	}
	return 0;
}
