class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.begin() + n);

        int start = 0;
        int end = nums.size() - 1;

        while (start + 1 < end)
        {
            int mid = start + (end - start) / 2;

            if (mid < nums[mid])
            {
                start = mid;
            }
            else
            {
                end = mid;
            }
        }

        return nums[start];
    }
};