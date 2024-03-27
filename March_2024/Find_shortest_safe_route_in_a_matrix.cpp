//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int findShortestPath(vector<vector<int>> &mat)
    {
        // code here
        int ans = 1e9;
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[0].size(); j++)
            {
                if (mat[i][j] == 0)
                {
                    if (i - 1 >= 0)
                        mat[i - 1][j] = -1;
                    if (i + 1 < mat.size())
                        mat[i + 1][j] = -1;
                    if (j - 1 >= 0)
                        mat[i][j - 1] = -1;
                    if (j + 1 < mat[0].size())
                        mat[i][j + 1] = -1;
                }
            }
        }

        queue<pair<int, pair<int, int>>> q;
        for (int i = 0; i < mat.size(); i++)
        {
            if (mat[i][0] == 1)
                q.push({1, {i, 0}});
        }
        vector<vector<int>> dist(mat.size() + 1, vector<int>(mat[0].size() + 1, INT_MAX));
        while (!q.empty())
        {
            int dis = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();
            if (y == mat[0].size() - 1)
                return dis;
            for (int k = 0; k < 3; k++)
            {
                int r = x + dr[k];
                int c = y + dc[k];
                if (r >= 0 && r < mat.size() && c >= 0 && c < mat[0].size() && mat[r][c] == 1 && dist[r][c] > dis + 1)
                {
                    q.push({dis + 1, {r, c}});
                    dist[r][c] = dis + 1;
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> mat(R, vector<int>(C));
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> mat[i][j];
            }
        }

        Solution ob;
        int ans = ob.findShortestPath(mat);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends