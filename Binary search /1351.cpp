
/*****Binary search*****/
/******** O(n*log(m)) ********/

class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        // Initialize result
        int count = 0;

        // To store the index of the rightmost negative
        // element in the row under consideration
        int nextEnd = m - 1;

        for (int i = 0; i < n; i++)
        {
            // If the last element of the current row
            // is positive then there will be no negatives
            // in the matrix below or before it
            if (grid[i][m - 1] >= 0)
                continue;

            // Run binary search only until the index of last
            // negative Integer in the above row
            nextEnd = getLastNegativeIndex(grid[i], 0, nextEnd, n, m);

            //return the number of negative elements
            count += m - nextEnd;
        }

        return count;
    }
    // Recursive binary search to get last negative from right to left
    // value in a row between a start and an end
    int getLastNegativeIndex(vector<int> array, int start, int end, int n, int m)
    {
        // Base case
        if (start >= end)
            return start;

        // Get the mid for binary search
        int mid = start + (end - start) / 2;

        // if current element is negative
        if (array[mid] < 0)
        {
            // If it is the leftmost negative
            // element in the current row
            if (mid - 1 >= 0)
            {
                if (array[mid - 1] >= 0)
                    return mid;
            }

            // Check in the left half of the array
            return getLastNegativeIndex(array, start, mid - 1, n, m);
        }
        else
        {
            // Check in the right half of the array
            return getLastNegativeIndex(array, mid + 1, end, n, m);
        }
    }
};

/*****Naive solution*****/
/******** O(m*n) ********/

/*        
        int count = 0;
        
        for (int i = n-1 ; i >= 0 ; i--)
        {
            for (int j = m-1 ; j >= 0 ; j--)
            {
                if (grid[i][j] < 0)
                {
                    count++;
                }
                else
                {
                    break;
                }
            }
        }
        
        return count;
*/

/**** count the last position of the negative number of each row ******/
/**** O(m+n) ****/
/*        
        int count = 0;
        int nbRow = n-1 ;
        int lastPos = 0 ;
        
        while(nbRow >= 0 && lastPos < m)
        {
            
            if (grid[nbRow][lastPos] < 0)
            {
                count += m - lastPos ;   
                --nbRow;
            }
            else 
            {
                ++lastPos ;   
            }
          
        }
        
        return count ;
*/
