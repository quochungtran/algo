class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int length = prices.size();
        int maxProfit = 0;

        for (int i = 1; i < length; i++)
        {
            if (prices[i] > prices[i - 1])
            {
                maxProfit += -prices[i - 1] + prices[i];
            }
        }

        return maxProfit;
    }
};