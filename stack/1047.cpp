class Solution
{
public:
    string removeDuplicates(string S)
    {
        stack<char> ans;
        stack<char> str;
        string ansString;

        for (int i = 0; i < S.size(); i++)
        {
            str.push(S[S.size() - i - 1]);
        }

        while (!str.empty())
        {
            if (ans.empty())
            {
                ans.push(str.top());
                str.pop();
            }
            else
            {
                if (str.top() == ans.top())
                {
                    ans.pop();
                    str.pop();
                }
                else
                {
                    ans.push(str.top());
                    str.pop();
                }
            }
        }

        // reserve stack string
        while (!ans.empty())
        {
            str.push(ans.top());
            ans.pop();
        }

        while (!str.empty())
        {
            ansString.push_back(str.top());
            str.pop();
        }

        return ansString;
    }
};