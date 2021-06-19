class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        stack<char> stk;

        for (auto i : s)
        {
            if (i == ')')
            {
                if (!stk.empty())
                {
                    if (stk.top() == '(')
                    {
                        stk.pop();
                    }
                    else
                    {
                        stk.push(i);
                    }
                }
                else
                {
                    stk.push(i);
                }
            }
            else if (i == '(')
            {
                stk.push(i);
            }
        }

        return stk.size();
    }
};