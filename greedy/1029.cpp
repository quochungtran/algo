class Solution
{
public:
    int twoCitySchedCost(vector<vector<int>> &costs)
    {
        int n = costs.size();
        int sum = 0;

        vector<vector<int>> v;

        for (vector<int> t : costs)
        {
            v.push_back({t[0], t[1], t[1] - t[0]});
        }

        sort(v.begin(), v.end(), condition);

        for (int i = 0; i < n / 2; i++)
        {
            sum += v[i][0];
        }

        for (int i = n / 2; i < n; i++)
        {
            sum += v[i][1];
        }

        return sum;
    }

    static bool condition(vector<int> &a, vector<int> &b)
    {
        return (a[2] > b[2]);
    }
};