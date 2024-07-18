//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int f(int i, int considerGreater, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (i == 0)
            return 1;
        if (dp[i][considerGreater] != -1)
            return dp[i][considerGreater];
        int take = 0;
        int notake = f(i - 1, considerGreater, arr, dp);
        if (considerGreater == 1)
        {
            if (arr[i] > arr[i - 1])
                take = 1 + f(i - 1, 0, arr, dp);
        }
        else
        {
            if (arr[i] < arr[i - 1])
                take = 1 + f(i - 1, 1, arr, dp);
        }
        return dp[i][considerGreater] = max(take, notake);
    }
    int alternatingMaxLength(vector<int> &arr)
    {
        // Code her
        int n = arr.size() + 10;
        vector<vector<int>> dp(n, vector<int>(3, -1));
        return max(f(arr.size() - 1, 1, arr, dp), f(arr.size() - 1, 0, arr, dp));
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--)
    {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr;
        string temp;
        while (ss >> temp)
        {
            arr.push_back(stoi(temp));
        }
        Solution obj;
        int ans = obj.alternatingMaxLength(arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends