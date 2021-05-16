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

int BinarySearchIterative(int A[], int n, int data)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2; // to avoid overflow
        if (A[mid] == data)
        {
            return mid;
        }
        else if (A[mid] < data)
        {
            low = mid + 1;
        }
        else
        {
            high = low - 1;
        }

        return -1;
    }
}

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