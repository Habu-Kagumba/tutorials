/*
 * =====================================================================================
 *
 *       Filename:  sqrt.c
 *
 *    Description:  Sqtr algorithm
 *
 *        Version:  1.0
 *        Created:  12/03/2016 19:50:40
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Herbert Kagumba (habu), habukagumba@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

/* Algorithm S: */

/* X = 1; */
/* do { */
/* 	Y = 2/X; */
/* 	X = (X+Y)/2; */
/* } while (fabs(X-Y) > epsilon); */

#include <stdio.h>
#include <math.h>

int main()
{
	float x, y, epsilon;
	printf("Enter epislon: ");
	scanf("%f", &epsilon);

	x = 1;
	do {
		y = 2 / x;
		x = (x + y) / 2;
	} while (fabs(x - y) > epsilon);

	printf("Approximate sqtr of 2 = %f\n", x);
}
