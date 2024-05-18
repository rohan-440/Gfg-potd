//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int findClosest(int n, int k, int arr[])
    {
        // Complete the function
        int l = 0;
        int r = n - 1;
        int minDiff = INT_MAX;
        int val = -1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            int diff = abs(arr[mid] - k);
            if (minDiff >= diff)
            {
                if (minDiff == diff)
                    val = max(val, arr[mid]);
                else
                    val = arr[mid];
                minDiff = diff;
            }
            if (arr[mid] == k)
                return k;
            else if (arr[mid] < k)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return val;
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        cout << ob.findClosest(n, k, arr) << endl;
    }
}

// } Driver Code Ends