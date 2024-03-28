//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    int findCity(int n, int m, vector<vector<int>> &edges, int distanceThreshold)
    {
        // Your code here
        vector<pair<int, int>> adj[n];
        for (int i = 0; i < edges.size(); i++)
        {
            int from = edges[i][0];
            int to = edges[i][1];
            int cost = edges[i][2];
            adj[from].push_back({to, cost});
            adj[to].push_back({from, cost});
        }
        int nNode = 1e9;
        int maxNode = 1e9;
        for (int i = 0; i < n; i++)
        {
            vector<int> dis(n, 1e9);
            queue<pair<int, int>> q; // dest,cost
            dis[i] = 0;
            vis[i] = 1;
            q.push({i, 0});
            while (!q.empty())
            {
                int dest = q.front().first;
                int cost = q.front().second;
                q.pop();
                for (auto x : adj[dest])
                {
                    int node = x.first;
                    int c = x.second;
                    if (dis[node] > cost + c)
                    {
                        dis[node] = cost + c;
                        q.push({node, cost + c});
                    }
                }
            }
            int numNode = 0;
            for (int i = 0; i < n; i++)
            {
                if (dis[i] <= distanceThreshold)
                {
                    numNode++;
                }
            }
            if (numNode < nNode || (numNode == nNode && i > maxNode))
            {
                nNode = numNode;
                maxNode = i;
            }
        }
        return maxNode;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < 3; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends