class Solution
{
public:
    int balancedString(string s)
    {
        int n = s.size(), k = n / 4, ans = n;
        unordered_map<char, int> cnt;
        for (int i = 0; i < n; i++)
        {
            cnt[s[i]]++; //stores count of all the chars in string
        }
        int lo = 0;
        for (int hi = 0; hi < n; hi++)
        {
            cnt[s[hi]]--; //Remove the current character, hence reduce its count

            //if the residual string has characters <= k, then we can safely remove the string betn s[lo...hi]
            while (lo < n && cnt['Q'] <= k && cnt['W'] <= k && cnt['E'] <= k && cnt['R'] <= k)
            {
                ans = min(ans, hi - lo + 1);
                cnt[s[lo]]++;
                lo++;
            }
        }
        return ans;
    }
};