class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        int leftmin=prices[0];
        for(int i=1;i<n;i++){
            int cost = prices[i]-leftmin;
            profit = max(profit,cost);
            leftmin = min(leftmin,prices[i]);
        }
        return profit;
    }
};