/*
 * =====================================================================================
 *
 *       Filename:  output.c
 *
 *    Description:  Output tutorial
 *
 *        Version:  1.0
 *        Created:  11/26/2016 23:39:44
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Herbert Kagumba (habu), habukagumba@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void testingChars()
{
	char testChar;
	printf("Enter characters: ");
	scanf("%c", &testChar);
	printf("Chars: %c\n\n", testChar);
}

void testingInts()
{
	int testInt;
	printf("-------------------------------------------------\n\n");
	printf("Enter an Integer: ");
	scanf("%d", &testInt);
	printf("Number: %d\n\n", testInt);
}

void testingFloats()
{
	float testFloat;
	printf("-------------------------------------------------\n\n");
	printf("Enter a float: ");
	scanf("%f", &testFloat);
	printf("Float: %.1f\n\n", testFloat);
}

void testingOperators()
{
	int a = 9, b = 4, c;
	printf("-------------------------------------------------\n\n");
	printf("a = %d & b = %d \n", a, b);
	c = a + b;
	printf("a + b = %d \n", c);
	c = a - b;
	printf("a - b = %d \n", c);
	c = a * b;
	printf("a * b = %d \n", c);
	c = a / b;
	printf("a / b = %d \n", c);
	c = a % b;
	printf("Remainder when a / b = %d \n\n", c);
}

void incr_decrOperators()
{
	int a = 10, b = 100;
	float c = 10.5, d = 100.5;
	printf("-------------------------------------------------\n\n");
	printf("a = %d |  b = %d | c = %f | d = %f \n", a, b, c, d);
	printf("++a = %d \n", ++a);
	printf("--b = %d \n", --b);
	printf("++c = %f \n", ++c);
	printf("--d = %f \n\n", --d);
}

void assignmentOperators()
{
	int a = 5, c;
	printf("-------------------------------------------------\n\n");
	printf("a is %d\n", a);
	c = a;
	printf("c = a; c = %d\n", c);
	c += a;
	printf("c += a; c = %d\n", c);
	c -= a;
	printf("c -= a; c = %d\n", c);
	c *= a;
	printf("c *= a; c = %d\n", c);
	c /= a;
	printf("c /= a; c = %d\n", c);
	c %= a;
	printf("c modulo a; c = %d\n\n", c);
}

void printBool(int boolean)
{
	if (boolean == 1) {
		printf("True");
	} else if (boolean == 0) {
		printf("False");
	}
}

void relationalOperators()
{
	int a = 5, b = 5, c = 10;
	printf("-------------------------------------------------\n\n");
	printf("a, b = %d | c = %d \n", a, c);

	printf("%d == %d = %d\n", a, b, a == b);
	printf("%d == %d = %d\n", a, c, a == c);
}

void logicalOperators()
{
	int a = 5, b = 5, c = 10, result;
	printf("-------------------------------------------------\n\n");

	result = (a = b) && (c > b);
	printf("(a = b) && (c > b) equals to %d\n", result);
}

void sizeOfOperators()
{
	int a, e[10];
	float b;
	double c;
	char d;
	printf("-------------------------------------------------\n\n");
	printf("int = %lu bytes\n", sizeof(a));
	printf("float = %lu bytes\n", sizeof(b));
	printf("double = %lu bytes\n", sizeof(c));
	printf("char = %lu bytes\n", sizeof(d));
	printf("Array[10] = %lu bytes\n", sizeof(e));
}

void ternaryOperator()
{
	char February;
	int days;
	printf("-------------------------------------------------\n\n");
	printf("If this is a leap year, enter 1. If not enter any integer: ");
	scanf("%c", &February);

	days = (February == '1') ? 29 : 28;

	printf("Number of days in February = %d\n", days);
}

void swapInput()
{
	double firstNumber, secondNumber, tempVariable;

	printf("Enter first number: ");
	scanf("%lf", &firstNumber);

	printf("Enter second number: ");
	scanf("%lf", &secondNumber);

	tempVariable = firstNumber;
	firstNumber = secondNumber;
	secondNumber = tempVariable;

	printf("\nFirst number = %.2lf\n", firstNumber);
	printf("\nSecond number = %.2lf\n", secondNumber);
}

void forLoop()
{
	int num, count, sum = 0;
	printf("Enter a positive integer: ");
	scanf("%d", &num);

	for (count = 1; count <= num; count++) {
		sum += count;
	}

	printf("Sum = %d\n", sum);
}


void doWhile()
{
	double number, sum = 0;

	do {
		printf("Enter a number: ");
		scanf("%lf", &number);
		sum += number;
	} while (number != 0.0);

	printf("Sum = %.2lf\n", sum);
}

void breakingIsh()
{
	int i;
	double number, sum = 0.0;

	for (i = 1; i < 10; ++i) {
		printf("Enter n%d: ", i);
		scanf("%lf", &number);

		if (number < 0.0) {
			break;
		}

		sum += number;
	}

	printf("Sum = %.2lf\n", sum);
}

void goTo()
{
	const int maxInput = 5;
	int i;
	double number, average, sum = 0.0;

	for (i = 1; i <= maxInput; ++i) {
		printf("%d. Enter a number: ", i);
		scanf("%lf", &number);

		if (number < 0.0)
			goto jump;

		sum += number;
	}

jump:

	average = sum / (i - 1);
	printf("Sum = %.2f\n", sum);
	printf("Average = %.2f\n", average);
}

void isEvenOrOdd()
{
	int number;

	printf("Enter a number: ");
	scanf("%d", &number);

	(number % 2 == 0) ?
		printf("%d is an even number.\n", number) :
		printf("%d is an odd number.\n", number);
}

int largestNumber()
{
	int n1, n2, n3, result;
	printf("Enter three numbers: ");
	scanf("%d %d %d", &n1, &n2, &n3);

	if (n1 >= n2 && n1 >= n3) {
		result = n1;
	} else if (n2 >= n1 && n2 >= n3) {
		result = n2;
	} else {
		result = n3;
	}

	return result;
}

void quadraticRoots()
{
	double a, b, c, determinant, root1, root2, realPart, imaginaryPart;

	printf("Enter coefficients a, b, and c: ");
	scanf("%lf %lf %lf", &a, &b, &c);

	/* determinant = b² - 4ac */
	determinant = b*b-4*a*c;

	/* real & different roots */
	if (determinant > 0)
	{
		root1 = (-b+sqrt(determinant))/(2*a);
		root2 = (-b-sqrt(determinant))/(2*a);

		printf("root1 = %lf & root2 = %lf\n", root1, root2);
	}
	else if (determinant == 0)
	{
		root1 = root2 = -b/(2*a);
	}
	else
	{
		realPart = -b/(2*a);
		imaginaryPart = sqrt(-determinant)/(2*a);

		printf("root1 = %.2lf+%.2lfi & root2 = %.2lf-%.2lfi\n", realPart, imaginaryPart, realPart, imaginaryPart);
	}
}

void isAlphabet()
{
	char c;
	printf("Enter a character: ");
	scanf("%c", &c);

	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
		printf("%c is an alphabet.\n", c);
	} else {
		printf("%c is not an alphabet.\n", c);
	}
}

void whileLoop()
{
	int number;
	long long factorial;

	printf("Enter an integer: ");
	scanf("%d", &number);

	factorial = 1;

	while (number > 0) {
		factorial *= number;
		--number;
	}

	printf("Factorial = %lld\n", factorial);
}

void getFactorial()
{
	int n, i;
	unsigned long long factorial = 1;

	printf("Enter an integer: ");
	scanf("%d", &n);

	if (n < 0) {
		printf("Error! Factorial of negative ints is a big No! No!\n");
	} else {
		for (i = 1; i <= n; ++i) {
			factorial *= i;
		}
		printf("Factorial of %d = %llu \n", n, factorial);
	}
}

void multTable()
{
	int n, i;

	printf("Enter a number: ");
	scanf("%d", &n);

	for (i = 0; i <= 10; ++i) {
		printf("%d * %d = %d \n", n, i, n*i);
	}
}

float square(float x)
{
	float p;
	p = x * x;
	return (p);
}

/* Call by value */
void valSwap(int a, int b)
{
	printf("Before	swap m -> %d and n -> %d\n", a, b);

	int tmp;
	tmp = a;
	a = b;
	b = tmp;

	printf("After	swap m -> %d and n -> %d\n", a, b);
}

/* Call by reference */
void refSwap(int *a, int *b)
{
	printf("Before	swap m -> %d and n -> %d\n", *a, *b);

	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;

	printf("After	swap m -> %d and n -> %d\n", *a, *b);
}

void getClock()
{
	time_t ct;
	char * ct_string;

	ct = time(NULL);
	ct_string = ctime(&ct);
	printf("%s\n", ct_string);
}

/*
 * Type casting
 *
 * Modify variable from one data type to another.
 * New data type should be mentioned before the var name / value in ()
 *
 * Example: typecast int to float
 */
void intToFloat()
{
	float x;
	x = (float) 7/5;
	printf("%f\n", x);
}

void envVars()
{
	printf("Directory -> %s\n", getenv("PWD"));
}

int dispErr()
{
	FILE *fp;
	char filename[40] = "test.txt";

	fp = fopen(filename, "r");

	if (fp == NULL) {
		perror("File not found");
		printf("errno: %d.\n", errno);
		return 1;
	}

	printf("File found.\n");
	fclose(fp);
	return 0;
}


struct student
{
	int id;
	char name[20];
	float percentage;
} record;

void structures()
{
	record.id = 1;
	strcpy(record.name, "Herbert");

	printf("Name is %s\n", record.name);
}

void pointers()
{
	int j, k;
	int *ptr;

	j = 1;
	k = 2;
	ptr = &k;
	printf("j = %d stored at %p\n", j, (void *)&j);
	printf("k = %d stored at %p\n", k, (void *)&k);
	printf("ptr = %p stored at %p\n", ptr, (void *)&ptr);
	printf("The value of integer poited to by ptr = %d\n", *ptr);
}

void pointersArr()
{
	int my_array[] = {1,23,17,4,-5,100};
	int *ptr;
	int i;

	ptr = &my_array[0];

	for (i = 0; i < 6; ++i) {
		printf("my_array[%d] = %d\n", i, my_array[i]);
		printf("ptr + %d = %d\n", i, *(++ptr));
	}
}

int main()
{
	printf("C Programming\n\n");

	/* testingChars(); */
	/* testingInts(); */
	/* testingFloats(); */
	/* testingOperators(); */
	/* incr_decrOperators(); */
	/* assignmentOperators(); */
	/* relationalOperators(); */
	/* logicalOperators(); */
	/* sizeOfOperators(); */
	/* ternaryOperator(); */
	/* swapInput(); */
	/* forLoop(); */
	/* whileLoop(); */
	/* doWhile(); */
	/* breakingIsh(); */
	/* goTo(); */
	/* isEvenOrOdd(); */
	/* printf("The largest number is %d.\n", largestNumber()); */
	/* quadraticRoots(); */
	/* isAlphabet(); */
	/* getFactorial(); */
	/* multTable(); */
	/* printf("2² -> %.0f\n", square(2)); */
	/* valSwap(22, 44); */
	/* int m = 22, n = 44; */
	/* refSwap(&m, &n); */
	/* getClock(); */
	/* intToFloat(); */
	/* envVars(); */
	/* dispErr(); */
	/* structures(); */
	/* pointers(); */
	pointersArr();

	return 0;
}
