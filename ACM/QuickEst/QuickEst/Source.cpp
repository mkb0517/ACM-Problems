#include <iostream>
#include <string>

using namespace std;

int main() {
	int N;
	int i=0;
	string valueOf;	
	cin >> N;

	while (i < N) {
		cin >> valueOf;
		cout << valueOf.size() << endl;
		i++;
	}

	system("pause");
	return 0;
}