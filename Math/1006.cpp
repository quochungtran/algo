class Solution
{
public:
    int clumsy(int N)
    {
        int res = 0;

        if (N == 3)
            return 3 * 2 / 1;

        if (N == 2)
            return 2 * 1;

        if (N == 1)
            return 1;

        if (N >= 4)
        {
            for (int i = N; i > (N % 4); i = i - 4)
            {
                if (i == N)
                {
                    res = i * (i - 1) / (i - 2) + (i - 3);
                }
                else
                {
                    int temp = -i * (i - 1) / (i - 2) + (i - 3);

                    res = res + temp;
                }

                cout << i << "\n";
            }

            if (N % 4 == 1)
            {
                res = res - 1;
            }

            if (N % 4 == 2)
            {
                res = res - 2 * 1;
            }

            if (N % 4 == 3)
            {
                res = res - 3 * 2 / 1;
            }
        }

        return res;
    }
};