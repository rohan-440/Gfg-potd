//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    bool isValid(int i, int j, int n, int m)
    {
        if (i < 0 || j < 0 || i >= n || j >= m)
            return (false);
        return (true);
    }

    void fun(int i, int j, int k, int n, int m, vector<vector<int>> &matrix, vector<int> &ans)
    {
        int di = i + dir[k].first;
        int dj = j + dir[k].second;
        matrix[i][j] = 0;
        if (!isValid(di, dj, n, m))
        {
            ans[0] = i;
            ans[1] = j;
            return;
        }
        int dk = (k + matrix[di][dj]) % 4;

        fun(di, dj, dk, n, m, matrix, ans);
        return;
    }
    vector<int> FindExitPoint(int n, int m, vector<vector<int>> &matrix)
    {
        // Code here
        vector<int> ans(2, 0);
        int k = matrix[0][0];
        fun(0, 0, k, n, m, matrix, ans);
        return (ans);
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        vector<int> ans = obj.FindExitPoint(n, m, matrix);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends