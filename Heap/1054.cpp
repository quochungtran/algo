
class Solution
{
    struct cmp
    {
        bool operator()(const pair<int, int> &a, const pair<int, int> &b)
        {
            if (a.second == b.second)
                return a.first < b.first;
            else
                return a.second < b.second;
        }
    };

public:
    vector<int> rearrangeBarcodes(vector<int> &barcodes)
    {
        int n = barcodes.size();

        map<int, int> m;

        for (int i : barcodes)
        {
            m[i]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

        for (auto &item : m)
        {
            pq.push(item);
        }

        vector<int> res(n, 0);

        pair<int, int> it = pq.top();
        int nb = it.second;
        int key = it.first;
        pq.pop();

        int idx = 0;
        while (nb > 0)
        {
            res[idx] = key;
            idx += 2;
            nb--;
        }

        if (idx >= n)
        {
            idx = 1;
        }

        while (pq.size())
        {
            pair<int, int> it = pq.top();
            int nb = it.second;
            int key = it.first;
            pq.pop();

            while (nb > 0)
            {
                res[idx] = key;
                idx += 2;
                nb--;

                if (idx >= n)
                {
                    idx = 1;
                }
            }
        }

        return res;
    }
};