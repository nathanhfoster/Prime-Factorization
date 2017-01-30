#include <iostream>
#include <cmath>
#include "Random.hpp"
#include "Watch.hpp"
#include <stdio.h> 
#include <time.h>
#include <iomanip>

void primeFactorization(int n, int factor);

// Random number generator instance
Random r;


void main(){
	// Start watch
	Watch<> w;
	int autoTotal = 1000;

	// Automate random numbers
	for (int i = 0; i < autoTotal; i++) {
		int number = r.DrawNumber(1, autoTotal);

		std::cout << "Number: " << number << "\tPrime factors: ";

		primeFactorization(number, 2);

		std::cout << "\n";
	}
	// Stop watch
	w.stop();
	std::cout << std::setprecision(4) << "Total time elapsed in s: " << w.elapsed() * pow(10, -6) << std::endl;
	
	system("PAUSE");
}

void primeFactorization(int n, int factor = 2){
	// Base case
	if (n < 2)
		return;
	// If factor divides the number evenly
	if (n % factor == 0){
		primeFactorization(n / factor, factor);
		std::cout << factor << "\t";
	}
	// Else increment and then return the factor
	else
		primeFactorization(n, ++factor);
}