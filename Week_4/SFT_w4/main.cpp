#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//OLD CODE
//#define MAX_FACTORIALS 10000
//#define NUM_FACTS 100
/*============================================================================================= 
 Integers can have slight variations depending on the system. 
 The maximum value for an unsigned integer is 18,446,744,073,709,551,615.
 Therefore, MAX_FACTORIALS can be set to 20, as any value beyond 21 will result in an overflow.
==============================================================================================*/  
//NEW CODE
#define MAX_FACTORIALS 20
#define NUM_FACTS 20

struct FactorialResults
{
	// OLD CODE
	//int results[MAX_FACTORIALS];
	/*===================================================================================
	//To print the maximum integer value possible, I would need to modify the data type.
	====================================================================================*/
	//NEW CODE
	unsigned long long results[MAX_FACTORIALS];
	int numResults;
};

// OLD CODE
// int factorial(const int n)
/*===================================================================================
// To print the maximum integer value possible, I would need to modify the data type.
====================================================================================*/
//NEW CODE
unsigned long long factorial(const int n)
{
	// OLD CODE
	//return (n <= n) ? n * factorial(n - 1) : 1;
	/*==============================================================================================
	The previous code had an infinite loop because the condition n <= n was always true.To fix this, 
	the code was modified to handle the special cases of n == 0 and n == 1, both of which return 1. 
	After making this modification, the code ran correctly.
	===============================================================================================*/
	//NEW CODE

	if (n == 0 || n == 1)
	{
		return n;
	}
	else
	{
		return n* factorial(n - 1);
	}
}

// OLD CODE
//int reduceFactorial(const int n)
//{
//	return n / n;
//}
/*==================================================================================
I believe this function is unnecessary because it limits the program's output range. 
The function attempts to fix the case where 19! equals 20!/20, 
but in the case of 20! equaling 21! / 21, we cannot obtain the value of 21!.
Therefore I chose to abandone the function.
//=================================================================================*/
// NEW CODE
 unsigned long long reduceFactorial(const int n, const unsigned long long results)
{
	if (n > 20)
	{
		return factorial(n-1);
	}

	return (n > 0)? results / n : 1;
} 


// OLD CODE
//void computeFactorials(struct FactorialResults results, int numFactorials)
//{
//	int i;
//	for (i = 0; i < numFactorials; i++)
//	{
//		results.results[i] = factorial(i);
//	}
//	results.numResults = numFactorials;
//}
/*==================================================================================
One major mistake here is that the original code only passes the structure by value.
This means that the value will not be stored in the structure.
After I modified it to pass the structure by address, everything worked correctly.
Additionally, in order to print the "next" value, 
I made a modification to the line results->results[i] = factorial(i + 1); 
This change directly stores the next value in the structure.
==================================================================================*/
//NEW CODE
void computeFactorials(struct FactorialResults* results, int numFactorials)
{
	int i;
	for (i = 0; i < numFactorials; i++)
	{
		results->results[i] = factorial(i + 1);
	}
	results->numResults = numFactorials;
}


int main(void)
{
	struct FactorialResults results = { {0}, 0 };
	int i;
	// OLD CODE
	//computeFactorials(results, NUM_FACTS);
	/*==============================================================================
	 To obtain pass by address, here I modifed the code to pass address of structure
	===============================================================================*/
	// NEW CODE
	computeFactorials(&results, NUM_FACTS);

	for (i = 0; i < NUM_FACTS; i++)
	{
		// OLD CODE, delete it.
		//results.results[i] = reduceFactorial(results.results[i]);

		// OLD CODE
		//printf("%5d %12f\n", i, results.results[i]);
		/*=================================================================================
		 To print the maximum integer value possible, I would need to modify the data type.
		===================================================================================*/
		// NEW CODE
		printf("%2d %19llu\n", i+1, results.results[i]);
	}
	return 0;
}