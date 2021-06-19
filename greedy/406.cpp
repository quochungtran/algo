class Solution
{
public:
    static bool sortingComparator(vector<int> &a, vector<int> &b)
    {
        if (a[0] == b[0])
        {
            return (a[1] < b[1]);
        }
        else
        {
            return (a[0] > b[0]);
        }
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        int n = people.size();
        vector<vector<int>> resultat;

        sort(people.begin(), people.end(), sortingComparator);

        for (auto item : people)
        {
            int pos = item[1];
            vector<int> ans(item.begin(), item.end());
            resultat.insert(resultat.begin() + pos, ans);
        }

        return resultat;
    }
};