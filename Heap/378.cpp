#include <vector>
#include <iostream>
#include <queue>

using namespace std;

class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        priority_queue<int> maxHeap;
        int n = matrix.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                maxHeap.push(matrix[i][j]);
                while (maxHeap.size() > k)
                {
                    maxHeap.pop();
                }
            }
        }

        return maxHeap.top();
    }
};


// O(m) with m = n*n