/**
 * Program 2 for CS 407 lab 3
 * @author Matthew Brown
 */

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

/**
 * Function to compute 1/n
 * Pre: A vector of vector double to store our table row in
 * Post: A vector of vector double with a full row of inverse values from 1 to 50
 */
void f(vector<vector<double>>&);

/**
 * Function to compute the sum of 1/n added to itself n-1 times.
 * Pre: A vector of vector double with the first row populated with values of 1/n from 1 to 50.
 * Post: A vector of vector double with the second row populated with the value of 1/n added to itself n-1 times
 */
void g(vector<vector<double>>&);

/**
 * Function to compute (1/n)*n.
 * Pre: A vector of vector double with two rows populated and the first row being 1/n from 1 to 50.
 * Post: a vector of vector double with three rows populated and the last row containing the values of (1/n)*n from 1 to 50.
 */
void h(vector<vector<double>>&);

/**
 * Function to output our vector table of values computed with functions f, g, and h.
 * Pre: A vector of vector double with three fully populated rows from functions f, g, and h.
 * Post: A stream of information sent to standard output.
 */
void output(vector<vector<double>>&);

/**
 * Main body of the program that instantiates our vector of vector double and calls the f, g, h, and output functions
 * to calculate 1/n, sum of 1/n added to itself n-1 times, and (1/n)*n, then display the information
 * to standard output.
 */
int main() {
	vector<vector<double>> table;
	
	// calculates 1/n and stores it in a vector of vector double as row 0.
	f(table);
	// Calculates the sum of 1/n added to itself n-1 times. Should result in 1, but we will see it propagate error.
	g(table);
	// Calculates the sum of (1/n)*n. Should result in 1, but we will see some error.
	h(table);
	// Output the values of the table.	
	output(table);

	system("PAUSE");
	return 0;
}

void f(vector<vector<double>> &table) {
	vector<double> values;
	double f_val;
	for (int i = 1; i <= 50; i++) {
		f_val = 1.0 / static_cast<double>(i);
		values.push_back(f_val);
	}
	table.push_back(values);
	cout << "f() completed..." << endl;
}

void g(vector<vector<double>> &table) {
	vector<double> values;
	double sum;
	for (int i = 1; i <= table[0].size(); i++) {
		sum = 0.0;
		for (int j = 1; j <= i; j++) {
			sum += table[0][i-1];
		}
		values.push_back(sum);
	}
	table.push_back(values);
	cout << "g() completed..." << endl;
}

void h(vector<vector<double>> &table) {
	vector<double> values;
	double product, n;
	for (int i = 0; i < table[0].size(); i++) {
		n = static_cast<double>(i + 1);
		product = n*table[0][i];
		values.push_back(product);
	}
	table.push_back(values);
	cout << "h() completed..." << endl;
}

void output(vector<vector<double>> &table) {
	cout << "       x\t    f(x)\t\t     g(x)\t\t      h(x)" << endl;
	for (int i = 0; i < table[0].size(); i++) {
		cout << fixed << setprecision(20) << setw(8) << i + 1 << ":  " << setw(20);
		cout << table[0][i] << "   " << table[1][i] << "   " << table[2][i] << endl;
	}
}