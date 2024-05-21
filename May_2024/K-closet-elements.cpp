//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    /*
    0 ->
    1 ->
    2 ->
    4 -> 39,
    5 -> 30,
    13 -> 22,
    19 -> 16,
    23 -> 12,
    4 ->
    5 ->

    */
    vector<int> printKClosest(vector<int> arr, int n, int k, int x)
    {
        // code here
        sort(arr.rbegin(), arr.rend());
        map<int, vector<int>> mp; // diff,array
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != x)
            {
                mp[abs(x - arr[i])].push_back(arr[i]);
            }
        }
        vector<int> v;
        for (auto x : mp)
        {
            for (auto y : x.second)
            {
                v.push_back(y);
                if (v.size() == k)
                    return v;
            }
        }
        return v;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans)
        {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends