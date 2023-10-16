#include <iostream>
using namespace std;

int main()
{
	// hangi günlerde alim satim yaparsak max profit yapariz
	int prices[6] = {5,2,3,4,9,1};
	int maxProfits[6];
	int maxProfit = 0;
	int maxProfitDay = 0;
	
	for(int i = 0;i < 6;i++)
	{
		int profit = 0;
		for(int j = 0;j < 6;j++)
			if(prices[j]-prices[i] > profit && i < j)
				profit = prices[j]-prices[i];
		maxProfits[i] = profit;
	}
	
	for(int i = 0;i < 6;i++)
		if(maxProfits[i] > maxProfit)
		{
			maxProfit = maxProfits[i];
			maxProfitDay = i+1;
		}
	
	cout << maxProfitDay << ". gunde maksimum kar(" << maxProfit << ") elde edilir.";
	
	
}
