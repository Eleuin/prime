/* See LICENSE file for copyright information
 *
 * prime is a program designed to factor prime numbers
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

/*
 * Basic Trial Division
 * Ideally replaced by an AKS primality test
 * Inefficient for large numbers but simple
 */
bool 
isPrimeBTD(uint64_t n)
{
	if (!(n % 2) || n < 2)
		return false;

	for (uint64_t i = 3; i <= sqrtl(n); i++)
	{
		if (!(n % i))
			return false;
	}

	return true;
}

int
main()
{
	uint64_t num = 1;

	while (num <= UINT64_MAX)
	{
		if (isPrimeBTD(num))
			printf("%jd is prime\n", num);
		else
			printf("%jd is not prime\n", num);

		num++;
	}
	return 0;
}
