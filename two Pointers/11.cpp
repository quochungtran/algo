// O(n)

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int n = height.size();

        int start = 0;
        int end = n - 1;
        int maxAre = 0;

        while (start < end)
        {
            int h = min(height[start], height[end]);
            int width = end - start;

            maxAre = max(maxAre, h * width);

            if (height[start] < height[end])
            {
                start++;
            }
            else 
            {
                end--;
            }
        }

        return maxAre;
    }
};