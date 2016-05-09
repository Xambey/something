#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm> 
#include <functional>

using namespace std;

int main()
{
	ifstream input("input.txt");

	int sellersNumber = 0;
	int buyersNumber = 0;

	input >> sellersNumber;
	input >> buyersNumber;

	vector<int> sellPrices(sellersNumber);
	vector<int> buyPrices(buyersNumber);

	for (int i = 0; i < sellersNumber; i++)
	{
		input >> sellPrices[i];
	}

	for (int i = 0; i < buyersNumber; i++)
	{
		input >> buyPrices[i];
	}

	input.close();

	sort(sellPrices.begin(), sellPrices.end());
	sort(buyPrices.begin(), buyPrices.end(), std::greater<int>());

	long long int result = 0;
	int minRange = min(sellPrices.size(), buyPrices.size());

	for (int i = 0; i < minRange; i++)
	{
		int profit = buyPrices[i] - sellPrices[i];
		if (profit > 0)
		{
			result += profit;
		}
	}

	ofstream output("output.txt");
	output << result;
	output.close();

	return 0;
}