class Solution
{
    struct cmp
    {
        bool operator()(vector<int> &point1, vector<int> &point2)
        {
            return sqrt(point1) >= sqrt(point2);
        }
    };

public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        vector<vector<int>> res;

        priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
        for (vector<int> &i : points)
        {
            pq.push(i);
        }

        for (int i = 0; i < k; i++)
        {
            res.push_back(pq.top());
            pq.pop();
        }

        return res;
    }

    static int sqrt(vector<int> &point)
    {
        return pow(point[1], 2) + pow(point[0], 2);
    }
};