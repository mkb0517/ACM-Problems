#include <iostream>

using namespace std;

int main() {
	double f=2.0;
	long i;

	i = reinterpret_cast<long>(&f);
	i++;
	//f = reinterpret_cast<double>(&i);
	cout << f << ' ' << i << endl;

	system("PAUSE");
	return 0;
}