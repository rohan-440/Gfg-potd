//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int dfs(vector<int> adj[], int u, int v, int &ans)
    {
        int count = 0;
        for (auto x : adj[u])
        {
            if (x != v)
            {
                int p = dfs(adj, x, u, ans);
                if (p % 2 == 0)
                    ans++;
                else
                    count += p;
            }
        }
        return count + 1;
    }
    int minimumEdgeRemove(int n, vector<vector<int>> edges)
    {
        // Code here
        vector<int> adj[n];
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0] - 1;
            int v = edges[i][1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans = 0;
        dfs(adj, 0, -1, ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<vector<int>> edges;
        for (int i = 0; i < n - 1; i++)
        {
            int x, y;
            cin >> x >> y;
            edges.push_back({x, y});
        }
        Solution obj;
        int ans = obj.minimumEdgeRemove(n, edges);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends