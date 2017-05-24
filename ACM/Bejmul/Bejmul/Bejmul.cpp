#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main() {
	vector<char> vowels = { 'A','E','I','O','U','Y' };
	vector<string> multis = { "AI","AY","EA","EE","EO","IO","OA","OO","OY","YA","YO","YU","BL","BR","CH","CK",
		"CL","CR","DR","FL","FR","GH","GL","GR","KL","KR","KW","PF","PL","PR","SC","SCH","SCR","SH","SHR","SK",
		"SL","SM","SN","SP","SQ","ST","SW","TH","THR","TR","TW","WH","WR" };
	fstream inFile;
	{
		inFile.open("A.in");
		if (inFile.fail()) {
			cerr << "The file did not open..." << endl;
			exit(-1);
		}

		while (!inFile.eof()) {
			bool isVowel = false;
			bool consecutive = false;
			string state = "";
			string word, scrambled;
			getline(inFile, word);
			getline(inFile, scrambled);
			if (word.compare("999") || scrambled.compare("999")) {}
			else if (word.compare(scrambled) == 0) {
				cout << word << " is not a scramble of " << scrambled << endl;
			}
			else {
				for (int i = 0; i < scrambled.length(); i++) {
					switch (scrambled[i]) {
					case 'A':
						if (isVowel) consecutive = true;
						else if (word[i] == scrambled[i] && consecutive) state = "poor";
						else if (scrambled[i + 1] == 'I' || scrambled[i + 1] == 'Y') {
							i++;
						}
						isVowel = true;
						break;
					case 'B':
						if (!isVowel) consecutive = true;
						else if (scrambled[i + 1] != 'B') state = "poor";
						else if (scrambled[i + 1] == 'B' || scrambled[i + 1] == 'L' || scrambled[i + 1] == 'R') {
							i++;
						}
						isVowel = false;
						break;
					case 'C':
						if (scrambled[i + 1] == 'C' || scrambled[i + 1] == 'H' || scrambled[i + 1] == 'K' || scrambled[i + 1] == 'L' || scrambled[i + 1] == 'R') {
							i++;
						}
						isVowel = false;
						break;
					case 'D':
						if (scrambled[i + 1] == 'D' || scrambled[i + 1] == 'R') {
							i++;
						}
						isVowel = false;
						break;
					case 'E':
						if (scrambled[i + 1] == 'A' || scrambled[i + 1] == 'E' || scrambled[i + 1] == 'Y') {
							i++;
						}
						isVowel = true;
						break;
					case 'F':
						if (scrambled[i + 1] == 'F' || scrambled[i + 1] == 'L' || scrambled[i + 1] == 'R') {
							i++;
						}
						isVowel = false;
						break;
					case 'G':
						if (scrambled[i + 1] == 'G' || scrambled[i + 1] == 'H' || scrambled[i + 1] == 'L' || scrambled[i + 1] == 'R') {
							i++;
						}
						isVowel = false;
						break;
					case 'H':
						if (scrambled[i + 1] == 'H') {
							i++;
						}
						isVowel = false;
						break;
					case 'I':
						break;
					case 'J':
						break;
					case 'K':
						break;
					case 'L':
						break;
					case 'M':
						break;
					case 'N':
						break;
					case 'O':
						break;
					case 'P':
						break;
					case 'Q':
						break;
					case 'R':
						break;
					case 'S':
						break;
					case 'T':
						break;
					case 'U':
						isVowel = true;
						break;
					case 'V':
						break;
					case 'W':
						break;
					case 'X':
						break;
					case 'Y':
						break;
					case 'Z':
						break;
					default:
						break;
					}
				}
			}

			inFile.peek();
		}
		inFile.close();
	}

	system("PAUSE");
	return 0;
}