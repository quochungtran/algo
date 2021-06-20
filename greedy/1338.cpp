class Solution
{
public:
    int minSetSize(vector<int> &arr)
    {
        // unorder map
        unordered_map<int, int> mymap;
        unordered_map<int, int>::iterator it;

        for (int item : arr)
        {
            it = mymap.find(item);

            // if item is not contained in map
            if (it == mymap.end())
            {
                mymap.insert(pair<int, int>(item, 1));
            }
            else
            {
                ++mymap[item];
            }
        }

        vector<pair<int, int>> v;
        sortMap(mymap, v);

        int thresHold = arr.size() / 2;

        int sizeOfSet = 0;
        int sum = 0;

        for (auto &it : v)
        {
            sum += it.second;
            ++sizeOfSet;

            if (sum >= thresHold)
            {
                return sizeOfSet;
            }
        }

        return 1;
    }

    void sortMap(unordered_map<int, int> &M, vector<pair<int, int>> &A)
    {
        // Copy key-value pair from Map
        // to vector of pairs
        for (auto &it : M)
        {
            A.push_back(it);
        }

        // Sort using comparator function
        sort(A.begin(), A.end(), mysort);
    }

    static bool mysort(pair<int, int> &a, pair<int, int> &b)
    {
        return a.second > b.second;
    }
};