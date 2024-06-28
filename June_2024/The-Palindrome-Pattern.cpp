//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string pattern(vector<vector<int>> &arr)
    {
        // Code Here
        // unordered_set<vector<int>>s;
        string ans = "";
        for (int i = 0; i < arr.size(); i++)
        {
            vector<int> temp(arr[i].begin(), arr[i].end());
            vector<int> rev = temp;
            reverse(rev.begin(), rev.end());
            if (temp == rev)
            {
                string ans = to_string(i);
                ans = ans + " R";
                return ans;
            }
        }
        for (int i = 0; i < arr[0].size(); i++)
        {
            vector<int> temp;
            for (int j = 0; j < arr.size(); j++)
                temp.push_back(arr[j][i]);
            vector<int> rev = temp;
            reverse(rev.begin(), rev.end());
            if (temp == rev)
            {
                string ans = to_string(i);
                ans = ans + " C";
                return ans;
            }
        }
        return "-1";
    }
};

//{ Driver Code Starts.

int main()
{

    int t, n, i, j, flag, k;
    cin >> t;

    while (t--)
    {
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
                cin >> a[i][j];
        }
        Solution ob;
        cout << ob.pattern(a) << endl;
    }
    return 0;
}
// } Driver Code Ends