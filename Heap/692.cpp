#include <vector>
#include <iostream>
#include <queue>
#include <map>

using namespace std;

class Solution
{
    struct cmp
    {
        bool operator()(const pair<string, int> &a, const pair<string, int> &b)
        {
            if (a.second != b.second)
                return a.second < b.second;
            else
                return a.first > b.first;
        }
    };

public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        map<string, int> m;
        for (auto &s : words)
        {
            m[s]++;
        }

        priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> pq;
        vector<string> arr;
        vector<string> res;

        for (auto &item : m)
        {
            pq.push(item);
        }

        int count = 0;
        while (count < k)
        {
            pair<string, int> temp = pq.top();
            pq.pop();
            res.push_back(temp.first);
            count++;
        }
        return res;
    }
};