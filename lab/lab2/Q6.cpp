/*
	Name: Muhammad Sabeeh
	Roll-no: 23K-0002
*/
#include <iostream>
#include <cmath> // Include the cmath library for abs() function

using namespace std;

// Function to calculate the least common multiple (LCM) of two integers
int LCM(int a, int b);

// Function to calculate the greatest common divisor (GCD) of two integers
int GCD(int a, int b);

int main() {
	int num1, num2;
	cout << "Enter the first integer value: ";
	cin >> num1;
	cout << "Enter the second integer value: ";
	cin >> num2;
	
	cout << "\nThe LCM is: " << LCM(num1, num2) << endl;
	cout << "The GCD is: " << GCD(num1, num2) << endl;
	
	return 0;
}

// Function to calculate the least common multiple (LCM) of two integers
int LCM(int a, int b) {
	int lcm;
	int ABS;
	ABS = abs(a * b); // Calculate the absolute value of the product of a and b
	lcm = ABS / GCD(a, b); // Calculate the LCM using the formula: LCM(a, b) = |a * b| / GCD(a, b)
	return lcm;
}

// Function to calculate the greatest common divisor (GCD) of two integers using Euclidean algorithm
int GCD(int a, int b) {
	int gcd;
	// Base case: If b is 0, then a is the GCD
	if (b == 0) {
		return a;
	} else {
		// Recursive case: Apply Euclidean algorithm to find the GCD
		return GCD(b, a % b);
	}
}
