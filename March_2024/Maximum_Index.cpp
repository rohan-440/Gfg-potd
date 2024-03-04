//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // A[]: input array
    // N: size of array

    // Function to find the maximum index difference
    /*
    9
26 1 8 2 24 25 29 1 27



    */
    int maxIndexDiff(int a[], int n)
    {
        // Your code here
        int l = 0;
        int r = n - 1;
        int maxDiff = 0;
        while (l <= r)
        {
            if (a[l] <= a[r])
            {
                maxDiff = max(maxDiff, r - l);
                l++;
                r = n - 1;
            }
            else
            {
                r--;
            }
        }
        return maxDiff;
    }
};

//{ Driver Code Starts.

/* Driver program to test above functions */
int main()
{
    int T;
    // testcases
    cin >> T;
    while (T--)
    {
        int num;
        // size of array
        cin >> num;
        int arr[num];

        // inserting elements
        for (int i = 0; i < num; i++)
            cin >> arr[i];
        Solution ob;

        // calling maxIndexDiff() function
        cout << ob.maxIndexDiff(arr, num) << endl;
    }
    return 0;
}
// } Driver Code Ends