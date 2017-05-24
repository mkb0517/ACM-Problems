#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	vector<char> alpha = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	vector<string> newAlpha = {"@","8","(","|)","3","#","6","[-]","|","_|","|<","1","[]\\/[]","[]\\[]","0","|D","(,)","|z","$","']['","|_|","\\/","\\/\\/","}{","`/","2"};
	vector<char> input;
	string output;
	string line;
	char temp;
	bool isFound;

	while (cin.get(temp)) {
		if (temp == '\n') break;
		else input.push_back(temp);
	}

	for (char c : input) {
		isFound = false;
		for (int i = 0; i < 26; i++) {
			if (tolower(static_cast<int>(c)) == alpha[i]) {
				output += newAlpha[i];
				isFound = true;
				break;
			}
		}
		if (!isFound) output += c;
	}

	cout << output << endl;


	system("pause");

	return 0;
}