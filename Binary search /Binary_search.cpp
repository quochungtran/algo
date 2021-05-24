#include <iostream>

using namespace std;

/************Unordered Linear Search************/
//Time complexity: O(n). Space complexity:O(1).

int unOrderedLinearSearch(int A[], int n, int data)
{
    for (int i = 0; i < n; i++)
    {
        if (A[i] == data)
        {
            return i;
        }

        return -1;
    }
}

/************Ordered Linear Search************/
//Time complexity: O(n). This is because in the worst case we need to scan the complete array
// Space complexity:O(1).

int orderedLinearSearch(int A[], int n, int data)
{
    for (int i = 0; i < n; i++)
    {
        if (A[i] == data)
        {
            return i;
        }
        else if (A[i] > data)
        {
            return -1;
        }

        return -1;
    }
}

/************Binary Search************/
//Time complexity: O(logn)
// Space complexity:O(1).

// Iterative Binary Search Algo
// template 1
int binarySearch(vector<int> &nums, int target)
{
    if (nums.size() == 0)
        return -1;

    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
        // Prevent (left + right) overflow
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    // End Condition: left > right
    return -1;
}

// template 2
int binarySearch(vector<int> &nums, int target)
{
    if (nums.size() == 0)
        return -1;

    int left  = 0;
    int right = nums.size();
    while (left < right)
    {
        // Prevent (left + right) overflow
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }

    // Post-processing:
    // End Condition: left == right
    if (left != nums.size() && nums[left] == target)
        return left;

    return -1;
}

// template 3



// Recursive Binary Search Algo
int BinarySearchRecusive(int A[], int low, int high, int data)
{
    int mid = low + (high - low) / 2; // to avoid overflow

    if (low > high)
    {
        return -1;
    }

    if (A[mid] == data)
    {
        return mid;
    }

    else if (A[mid] < data)
    {
        return BinarySearchRecusive(A[], low + 1, high, data);
    }
    else
    {
        return BinarySearchRecusive(A[], low, high - 1, data);
    }

    return -1;
}