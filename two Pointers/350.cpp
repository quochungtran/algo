class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {

        int m1 = nums1.size();
        int m2 = nums2.size();

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> res;
        int i = 0, j = 0;

        while (i < m1 && j < m2)
        {
            if (nums1[i] > nums2[j])
            {
                j++;
            }
            else if (nums1[i] < nums2[j])
            {
                i++;
            }
            else
            {
                res.push_back(nums1[i]);
                i++;
                j++;
            }
        }

        return res;
    }
};