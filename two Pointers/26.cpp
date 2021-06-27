class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        int i = 0;

        for (int j = 1; j < nums.size(); j++)
        {
            if (nums[j] != nums[i])
            {
                i += 1;
                nums[i] = nums[j];
            }
        }

        return i + 1;
    }
};