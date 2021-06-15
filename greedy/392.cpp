class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int count  = 0;
        int length = t.length();
        int k      = 0;

        if (s == " ")
            return false;

        if (t == " ")
            return false;

        for (int i = 0; i < length; i++)
        {
            if (t[i] == s[k])
            {
                ++count;
                ++k;
            }
        }

        if (count == s.length())
            return true;

        return false;
    }
};