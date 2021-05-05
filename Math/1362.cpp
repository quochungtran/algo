#include <vector>
#include <iostream>
#include <math.h> /* sqrt */

using namespace std;
class Solution
{
public:
    vector<int> closestDivisors(int num)
    {
        vector<int> res1;
        vector<int> res2;

        int abs1;
        int abs2;

        int num1 = num + 1;
        int num2 = num + 2;
        int j = 0;
        float val = sqrt(num1);

        for (int i = val; i >= 1; i--)
        {
            if (num1 % i == 0)
            {
                j = num1 / i;

                res1.push_back(i);

                res1.push_back(j);

                abs1 = abs(i - j);

                break;
            }
        }

        val = sqrt(num2);

        for (int i = val; i >= 1; i--)
        {
            if (num2 % i == 0)
            {
                j = num2 / i;

                res2.push_back(i);

                res2.push_back(j);

                abs2 = abs(i - j);

                break;
            }
        }

        if (abs1 < abs2)
            return res1;

        return res2;
    }
};