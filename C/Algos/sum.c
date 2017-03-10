/*
 * =====================================================================================
 *
 *       Filename:  sum.c
 *
 *    Description:  Sum a series.
 *
 *        Version:  1.0
 *        Created:  12/03/2016 20:02:55
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Herbert Kagumba (habu), habukagumba@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

/* Sum a harmonic series: */
/* 	1 + 1/2 + 1/3 + ... */

/* 	H(n) = 1 + 1/2 + 1/3 + ... + 1/n */

/* 1. i = 0 */
/* 2. s = 0 */
/* 3. i++ */
/* 4. s += 1/i */
/* 5. if i < n; goto 3 */
/* 5. stop */
#include <stdio.h>


int main()
{
	int i = 0, n;
	float s = 0;

	printf("Enter n: ");
	scanf("%d", &n);

	do {
		i++;
		s += 1.0 / i;
	} while (i < n);

	printf("H(%d) = %f\n", n, s);
}
