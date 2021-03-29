#include <string>
#include <stack>
#include <iostream>
using namespace std;

class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        stack<int> stack1;
        stack<int> stack2;

        string ans = "";

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                stack1.push(i);
            }
            if (s[i] == ')')
            {
                if (!stack1.empty())
                {
                    if (s[stack1.top()] == '(')
                    {
                        stack1.pop();
                        continue;
                    }
                    else if (s[stack1.top()] == ')')
                    {
                        stack1.push(i);
                    }
                }
                else
                    stack1.push(i);
            }
            // if (!stack1.empty())
            //     std::cout << stack1.top() << " ";
        }

        while (!stack1.empty())
        {
            stack2.push(stack1.top());
            // std::cout << stack2.top() << endl;
            stack1.pop();
        }

        while (!stack2.size())
        {
            std::cout << stack2.top() << endl;
            stack2.pop();
        }

        std::cout << "\n";

        for (int i = 0; i < s.size(); i++)
        {
            if (i == stack2.top())
            {
                std::cout << "yes";
                // stack2.pop();
                //         continue;
            }

            ans.push_back(s[i]);
        }

        return ans;
    }
};

int main()
{
    string a = ")y)((a";
    Solution sol;
    std::cout << sol.minRemoveToMakeValid(a) << endl;
    return 0;
}