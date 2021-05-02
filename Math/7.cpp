class Solution
{
public:
    int reverse(int x)
    {
        int pop;
        int temp;

        int rev = 0;

        while (x)
        {
            // pop operation
            pop = x % 10;
            x /= 10;

            // check if the statement temp = rev*10 + pop can cause overflow. 
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7))
                return 0;

            if (rev < INT_MIN / 10 || (rev == INT_MAX / 10 && pop < -8))
                return 0;
            
            // push operation
            rev = rev * 10 + pop;
        }
        return rev;
    }
};