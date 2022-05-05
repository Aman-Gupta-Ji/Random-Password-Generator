// C++ implementation of the 
// above approach 

#include <bits/stdc++.h> 
using namespace std; 

// Function to generate random numbers 
void linearCongruentialMethod( 
	int Xo, int m, int a, int c, 
	vector<int>& randomNums, 
	int noOfRandomNums) 
{ 

	// Initialize the seed state 
	randomNums[0] = Xo; 

	// Traverse to generate required 
	// numbers of random numbers 
	for (int i = 1; i < noOfRandomNums; i++) { 
		// Follow the linear congruential method 
		randomNums[i] 
			= ((randomNums[i - 1] * a) + c) % m; 
	} 
} 

// Driver Code 
int main() 
{ 
	int Xo = 5; // Seed value 
	int m = 7; // Modulus parameter 
	int a = 3; // Multiplier term 
	int c = 3; // Increment term 

	// Number of Random numbers 
	// to be generated 
	int noOfRandomNums = 10; 

	// To store random numbers 
	vector<int> randomNums( 
		noOfRandomNums); 

	// Function Call 
	linearCongruentialMethod( 
		Xo, m, a, c, 
		randomNums, noOfRandomNums); 

	// Print the generated random numbers 
	for (int i = 0; i < noOfRandomNums; i++) { 
		cout << randomNums[i] << " "; 
	} 

	return 0; 
} 

