#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
	unsigned long long power, number, cutoff;
	// Here are our primes less than 64
	vector<unsigned long long> primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61 };
	
	// get the k value to compute marsenne primes up to
	cin >> power;

	// Loop through our list of primes below 63 
	for (unsigned i = 0; (i < primes.size()) && (primes[i] <= power); i++) {
		vector<unsigned long long> factors;
		// Calculate the maresenne prime
		number = static_cast<unsigned long long>(pow(2.0, static_cast<double>(primes[i]))) - 1;
		// Our factors will all be below 
		cutoff = sqrt(number);
		// 
		unsigned long long temp = number;
		for (unsigned long long j = 3; j <= cutoff; j++) {
			if (temp%j == 0) {
				temp /= j;
				factors.push_back(j);
			}
		}
		// Push back the remainder 
		if (temp > 1) factors.push_back(temp);
		
		// Print out the factors if there are any
		if (factors.size() > 1) {
			for (unsigned j = 0; j < factors.size(); j++) {
				if (j == (factors.size() - 1)) {
					cout << factors[j] << " = " << number << " =  ( 2 ^ " << primes[i] << " ) - 1" << endl;
				}
				else {
					cout << factors[j] << " * ";
				}
			}
		}
	}
	system("PAUSE");
	return 0;
}