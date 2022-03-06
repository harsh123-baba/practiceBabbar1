#include <iostream>
#include <algorithm>
using namespace std;

bool isPossible(int A[], int n, int m, int mid)
{
    int student = 1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += A[i];
        if (mid < sum)
        {
            student++;
            sum = A[i];
        }
    }
    return student <= m;
}

int findPages(int A[], int N, int M)
{
    //code here
    int max = INT32_MIN;
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += A[i];
        if (max < A[i])
        {
            max = A[i];
        }
    }
    int ans = 0;
    int low = max;
    int high = sum;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isPossible(A, N, M, mid) == true)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

int main()
{
    int A[] = {12,34,67,90};
    int n = sizeof(A)/sizeof(int);
    int m = 2;
    cout<<findPages(A, n, m);
}