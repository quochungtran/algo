class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {

        vector<vector<int>> resultat;

        if (nums.size() == 0)
            return resultat;

        int sum;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            
            // skip the previous case
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;
            int right = nums.s ize() - 1;

            while (left < right)
            {
                sum = nums[i] + nums[left] + nums[right];

                if (sum == 0)
                {
                    vector<int> a;
                    a.push_back(nums[i]);
                    a.push_back(nums[left]);
                    a.push_back(nums[right]);
                    resultat.push_back(a);
                    left += 1;

                    // skip the same element
                    while ((left < right) && (nums[left] == nums[left - 1]))
                        left += 1;
                }
                else
                {
                    if (sum > 0)
                        right -= 1;
                    if (sum < 0)
                        left += 1;
                }
            }
        }

        return resultat;
    }
};