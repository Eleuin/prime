/* See LICENSE file for copyright information
 *
 * prime is a program designed to factor prime numbers
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

static uint64_t starting_number;
static uint64_t ending_number;
static float version = 0.1;

/*
 * Basic Trial Division
 * Ideally replaced by an AKS primality test
 * Inefficient for large numbers but simple
 */
bool 
isPrimeBTD(uint64_t number)
{
	if (number == 2)
		return true;

	if (!(number % 2) || number < 2)
		return false;

	for (uint64_t integer = 3; integer <= sqrtl(number); integer++)
	{
		if (!(number % integer))
			return false;
	}

	return true;
}

void
listPrimes()
{
	uint64_t current_number = starting_number;

	while (current_number <= ending_number && current_number <= UINT64_MAX)
	{
		if (isPrimeBTD(current_number))
			printf("%jd is prime\n", current_number);
		else
			printf("%jd is composite\n", current_number);

		current_number++;
	}
}

int
main(int argc, char **argv)
{
	// do advanced option handling here
	if (argc == 2 && !strcmp("-v", argv[1])) {
		printf("prime %.1f\n", version);
	} else {
		starting_number = 1;
		ending_number = 100;
		listPrimes();
	}
	return 0;
}
