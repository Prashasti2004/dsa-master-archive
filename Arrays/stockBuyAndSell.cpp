/*
Problem: Best Time to Buy and Sell Stocks
Platform: Leetcode (Problem #121)
Approach: Traverse Array and take out the max profit
Time Complexity: O(N)
Space Complexity: O(1)
*/

//Approach 1: Small code and lesser variables used
int maxProfit(vector<int>& prices){
  int maxProfits = 0;
  int  minPrice = INT_MAX;

  for(int i=0; i<prices.size(); i++){
    minPrice = min(minPrice, prices[i]);
    maxProfits = max(maxProfits, prices[i]-minPrice);
  }

  return maxProfits;
}

//Approach 2: Simple code - keep track of best stock to sell and buy through indexes, checking profits and storing in a variable called maxProfit
int maxProfit(vector<int>& prices) {
        int buy = 0;
        int sell = 0;
        int profit = 0;
        int maxprofit = 0;

        for(int i=0; i<prices.size(); i++){
            if(prices[buy]>prices[i]){
                buy = i;
                sell = i;
            }

            if(prices[sell] < prices[i]){
                sell = i;
            }

            profit = prices[sell]-prices[buy];
            maxprofit = max(profit, maxprofit);
        }

        return maxprofit;

}
