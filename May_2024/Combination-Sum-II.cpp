//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    set<vector<int>> v;
    void f(int i, int sum, vector<int> &arr, vector<int> &temp)
    {
        if (sum < 0)
            return;
        if (sum == 0)
        {
            v.insert(temp);
            return;
        }
        if (i >= arr.size())
        {
            if (sum == 0)
            {
                v.insert(temp);
            }
            return;
        }
        temp.push_back(arr[i]);
        f(i + 1, sum - arr[i], arr, temp);
        temp.pop_back();
        f(i + 1, sum, arr, temp);
    }
    vector<vector<int>> CombinationSum2(vector<int> arr, int n, int k)
    {
        // code here
        sort(arr.begin(), arr.end());
        vector<int> temp;
        f(0, k, arr, temp);
        vector<vector<int>> ans;
        for (auto x : v)
        {
            ans.push_back(x);
        }
        return ans;
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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto obj = ob.CombinationSum2(arr, n, k);
        for (int i = 0; i < obj.size(); i++)
        {
            for (int j = 0; j < obj[i].size(); j++)
            {
                cout << obj[i][j] << " ";
            }
            cout << "\n";
        }
        if (obj.size() == 0)
            cout << "\n";
    }
    return 0;
}
// } Driver Code Ends