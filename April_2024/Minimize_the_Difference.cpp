//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array
{
public:
    template <class T>
    static void input(vector<T> &A, int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};

// } Driver Code Ends

class Solution
{
public:
    int minimizeDifference(int n, int k, vector<int> &arr)
    {
        // code here

        vector<int> rightMax(n, 0);
        vector<int> rightMin(n, 0);
        rightMax[n - 1] = arr[n - 1];
        rightMin[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            rightMax[i] = max(arr[i], rightMax[i + 1]);
            rightMin[i] = min(arr[i], rightMin[i + 1]);
        }
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int diff = INT_MAX;
        int l = 0;
        for (int r = k - 1; r < n; r++)
        {
            if (l != 0)
            {
                mini = min(mini, arr[l - 1]);
                maxi = max(maxi, arr[l - 1]);
            }
            int MX = maxi;
            int MN = mini;
            if (r != n - 1)
            {
                MX = max(MX, rightMax[r + 1]);
                MN = min(MN, rightMin[r + 1]);
            }
            diff = min(diff, abs(MX - MN));
            l++;
        }
        return diff;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        int n;
        scanf("%d", &n);

        int k;
        scanf("%d", &k);

        vector<int> arr(n);
        Array::input(arr, n);

        Solution obj;
        int res = obj.minimizeDifference(n, k, arr);

        cout << res << endl;
    }
}

// } Driver Code Ends