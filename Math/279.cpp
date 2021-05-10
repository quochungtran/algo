class Solution
{
public:
    int numSquares(int n)
    {
        if (n <= 0)
            return 0;

        int dp[n + 1];

        for (int k = 0; k < n + 1; k++)
        {
            dp[k] = INT_MAX;
        }
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j * j <= i; j++)
            {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }

        return dp[n];
    }
}