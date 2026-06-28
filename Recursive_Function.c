#include <stdio.h>

// Recursive Function : the function to recall itself in define part
// We need two elements to terminate normally

// 1. Basic case : Termination condition to stop recursive call
// >> If it doesn't exist, The function will recall itself infinitely

// 2. Recursive case : The part to recall itself
// >> Each time the call is repeated, the condition should become closer to termination condition than before 

// => I would explain recursive function to use Factorial and Fibonacci numbers

// The part to implement Factorial calculation
int Factorial (int startN)
{
	printf("Log : Call Factorial(%d)\n", startN);
	
	// The part of basic case
	if (startN <= 1)
	{
		printf("Log : Stop Factorial(%d)\n", startN);
		return 1;
	}
	
	// The part of recursive case
	int result = startN * Factorial(startN - 1);
	
	printf("Log : Factorial(%d) is ended\n", startN);
	return result;
}

// The part to implement Fibonacci numbers
int Fibonacci(int n) {
	// when the n is first term
	// >> We count first term is zero index 
	if (n == 0) return 0;
	// When the n is second term
	if (n == 1) return 1;
	
	// In Fibonacci numbers, n term is sum of (n-1) term and (n-2) term
	// n = (n - 1) + (n - 2)
	
	// For instance, if n is 5
	// Divide by 4 and 3 to calculate and these calculations are independent
	// Fibonacci(4) makes 4 term value by dividing small term (using first and second terms)
	// ex) 4 -> 3[-> 2{-> 1 + 0} + 1] + 2[-> 1 + 0] 
	return Fibonacci(n-1) + Fibonacci(n-2);
}

int main()
{
	int factorialNum = 5;
	
	printf("Log : Start to calculate %d!\n", factorialNum);
	int total = Factorial(factorialNum);
	printf("Log : End to calculate %d!\n", factorialNum);
	printf("Log : result is %d\n", total);
	
	printf("\n\n\n");
	
	int wantTerm = 10;	// The number of term to express
	int i;
	printf("Fibonacci numbers :");
	for (i = 0; i < wantTerm; i++)
	{
		printf(" %d", Fibonacci(i));
	}
	
	return 0;
}
