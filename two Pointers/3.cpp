
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {

        if (s.empty())
            return 0;

        int i;
        int n = s.length();

        // starting point of current substring.
        int st = 0;

        // length of current substring.
        int currlen;

        // maximum length substring without repeating
        // characters.
        int maxlen = 0;

        // starting index of maximum length substring.
        int start;

        // Hash Map to store last occurrence of each
        // already visited character.
        unordered_map<char, int> pos;

        // Last occurrence of first character is index 0;
        pos[s[0]] = 0;

        for (i = 1; i < n; i++)
        {

            // If this character is not present in hash,
            // then this is first occurrence of this
            // character, store this in hash.
            if (pos.find(s[i]) == pos.end())
                pos[s[i]] = i;

            else
            {
                // If this character is present in hash then
                // this character has previous occurrence,
                // check if that occurrence is before or after
                // starting point of current substring.
                if (pos[s[i]] >= st)
                {

                    // find length of current substring and
                    // update maxlen and start accordingly.
                    currlen = i - st;
                    if (maxlen < currlen)
                    {
                        maxlen = currlen;
                        start = st;
                    }

                    // Next substring will start after the last
                    // occurrence of current character to avoid
                    // its repetition.
                    st = pos[s[i]] + 1;
                }

                // Update last occurrence of
                // current character.
                pos[s[i]] = i;
            }
        }

        // Compare length of last substring with maxlen and
        // update maxlen and start accordingly.
        if (maxlen < i - st)
        {
            maxlen = i - st;
            start = st;
        }
        // The required longest substring without
        // repeating characters is from str[start]
        // to str[start+maxlen-1].
        return maxlen;
    }
};