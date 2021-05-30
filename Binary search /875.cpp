class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int start = 1;
        int end = pow(10, 9);

        while (start < end)
        {
            int mid = start + (end - start) / 2;
            if (!possible(piles, mid, h))
            {
                start = mid + 1;
            }
            else
            {
                end = mid;
            }
        }

        return start;
    }

    bool possible(vector<int> &piles, int K, int H)
    {
        int time = 0;
        for (int &item : piles)
        {
            time += ((item - 1) / K) + 1;
        }

        return (time <= H);
    }
};