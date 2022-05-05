// C++ implementation of the 
// above approach 
#include <bits/stdc++.h> 
using namespace std; 

// Function to generate random numbers 
void multiplicativeCongruentialMethod( 
	int Xo, int m, int a, 
	vector<int>& randomNums, 
	int noOfRandomNums) 
{ 

	// Initialize the seed state 
	randomNums[0] = Xo; 

	// Traverse to generate required 
	// numbers of random numbers 
	for (int i = 1; i < noOfRandomNums; i++) { 

		// Follow the multiplicative 
		// congruential method 
		randomNums[i] 
			= (randomNums[i - 1] * a) % m; 
	} 
} 

// Driver Code 
int main() 
{ 
	int Xo = 3; // seed value 
	int m = 15; // modulus parameter 
	int a = 7; // multiplier term 

	// Number of Random numbers 
	// to be generated 
	int noOfRandomNums = 10; 

	// To store random numbers 
	vector<int> randomNums(noOfRandomNums); 

	// Function Call 
	multiplicativeCongruentialMethod( 
		Xo, m, a, randomNums, 
		noOfRandomNums); 

	// Print the generated random numbers 
	for (int i = 0; i < noOfRandomNums; i++) { 
		cout << randomNums[i] << " "; 
	} 
	return 0; 
} 

// C++ implementation of the 
// above approach 

#include <bits/stdc++.h> 
using namespace std; 

// Function to generate random numbers 
void additiveCongruentialMethod( 
	int Xo, int m, int c, 
	vector<int>& randomNums, 
	int noOfRandomNums) 
{ 

	// Initialize the seed state 
	randomNums[0] = Xo; 

	// Traverse to generate required 
	// numbers of random numbers 
	for (int i = 1; i < noOfRandomNums; i++) { 

		// Follow the additive 
		// congruential method 
		randomNums[i] 
			= (randomNums[i - 1] + c) 
			% m; 
	} 
} 

// Driver Code 
int main() 
{ 
	int Xo = 3; // seed value 
	int m = 15; // modulus parameter 
	int c = 2; // increment term 

	// Number of Random numbers 
	// to be generated 
	int noOfRandomNums = 20; 

	// To store random numbers 
	vector<int> randomNums(noOfRandomNums); 

	// Function Call 
	additiveCongruentialMethod( 
Xo, m, c, 
							randomNums, 
noOfRandomNums); 

	// Print the generated random numbers 
	for (int i = 0; i < noOfRandomNums; i++) { 
		cout << randomNums[i] << " "; 
	} 

	return 0; 
} 

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

