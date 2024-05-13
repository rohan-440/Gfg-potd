//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};

// } Driver Code Ends

class Solution
{
public:
    void dfs(int node, vector<int> &vis, vector<int> adj[], int &ver, int &ed)
    {
        vis[node] = 1;
        ver++;
        for (auto x : adj[node])
        {
            ed++;
            if (vis[x] == 0)
            {
                dfs(x, vis, adj, ver, ed);
            }
        }
    }
    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges)
    {
        // code here
        vector<int> adj[v + 1];
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(v + 1, 0);
        int count = 0;
        for (int i = 1; i < v + 1; i++)
        {
            int ver = 0;
            int ed = 0;
            if (vis[i] == 0)
            {
                dfs(i, vis, adj, ver, ed);
                if (ed == ver * (ver - 1))
                    count++;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        int e;
        scanf("%d", &e);

        int v;
        scanf("%d", &v);

        vector<vector<int>> edges(e, vector<int>(2));
        Matrix::input(edges, e, 2);

        Solution obj;
        int res = obj.findNumberOfGoodComponent(e, v, edges);

        cout << res << endl;
    }
}

// } Driver Code Ends