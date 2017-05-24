#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int packs;
	int bunspack;
	int temp = 0;
	vector<int> hotdogs;
	vector<int> buns;

	cin >> packs;
	for (int i = 0; i < packs; i++) {
		cin >> temp;
		hotdogs.push_back(temp);
	}

	cin >> bunspack;
	for (int i = 0; i < bunspack; i++) {
		cin >> temp;
		buns.push_back(temp);
	}

	sort(hotdogs.begin(), hotdogs.end());
	sort(buns.begin(), buns.end());
	

	int temp_hotdogs_sum;
	for (int i = 0;i < hotdogs.size();i++)
	{
		temp_hotdogs_sum = hotdogs[i];
		for (int k = 0; k < buns.size();k++)
		{
			if (temp_hotdogs_sum == buns[1])
			{
				cout << 2;
			}
		}

		for (int j = 0; j < i;j++)
		{
			//sum hotdogs up to i
			temp_hotdogs_sum = hotdogs[0] + hotdogs[i];
			//compair to hotdog buns
		}

	}

	return 0;
}