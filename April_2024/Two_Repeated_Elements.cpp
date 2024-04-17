//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to find two repeated elements.
    vector<int> twoRepeated(int arr[], int n)
    {
        // Your code here
        unordered_set<int> set;
        vector<int> v;
        for (int i = 0; i < n + 2; i++)
        {
            if (set.find(arr[i]) != set.end())
            {
                v.push_back(arr[i]);
            }
            else
            {
                set.insert(arr[i]);
            }
        }
        return v;
    }
};

//{ Driver Code Starts.

int main()
{
    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;

        int a[n + 2];

        for (int i = 0; i < n + 2; i++)
            cin >> a[i];

        Solution obj;
        vector<int> res;
        res = obj.twoRepeated(a, n);
        cout << res[0] << " " << res[1] << endl;
    }
    return 0;
}

// } Driver Code Ends