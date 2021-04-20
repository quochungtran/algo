class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {

        int nonZeroIndex = 0;
        int len = nums.size();
        
        for (int i = 0; i < len; i++)
        {
            if (nums[i] != 0)
            {
                nums[nonZeroIndex] = nums[i];
                nonZeroIndex++;
            }
        }

        for (int j = nonZeroIndex; j < len; j++)
        {
            nums[j] = 0;
        }

        return;
    }
};