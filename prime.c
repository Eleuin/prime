/* See LICENSE file for copyright information
 *
 * prime is a program designed to factor prime numbers
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

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

	uint64_t num = 1;

	while (num <= 100 && num <= UINT64_MAX)
	{
		if (isPrimeBTD(num))
			printf("%jd is prime\n", num);
		else
			printf("%jd is composite\n", num);

		num++;
	}
}

int
main(int argc, char **argv)
{
	if (argc == 2 && !strcmp("-v", argv[1]))
		printf("version 0.1\n");
	else
		listPrimes();
	return 0;
}
