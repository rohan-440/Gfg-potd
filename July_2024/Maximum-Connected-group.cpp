//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class DSU
{
public:
    vector<int> parent;
    vector<int> size;
    DSU(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int u)
    {
        if (u == parent[u])
            return u;
        return parent[u] = find(parent[u]);
    }

    void Union(int u, int v)
    {
        int a = find(u);
        int b = find(v);
        if (a == b)
            return;
        else if (size[a] > size[b])
        {
            parent[b] = a;
            size[a] += size[b];
        }
        else
        {
            parent[a] = b;
            size[b] += size[a];
        }
    }
};
class Solution
{
public:
    int MaxConnection(vector<vector<int>> &grid)
    {
        // code here
        int n = grid.size();
        DSU ds(n * n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    int dr[] = {-1, 0, 1, 0};
                    int cr[] = {0, 1, 0, -1};
                    for (int x = 0; x < 4; x++)
                    {
                        int ni = i + dr[x];
                        int nj = j + cr[x];

                        if (ni >= 0 && nj >= 0 && ni < n && nj < n)
                        {
                            if (grid[ni][nj] == 1)
                            {
                                int node_i = ni * n + nj;
                                int old_node = i * n + j;
                                ds.Union(old_node, node_i);
                            }
                        }
                    }
                }
            }
        }
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                    continue;
                if (grid[i][j] == 0)
                {
                    int dr[] = {-1, 0, 1, 0};
                    int cr[] = {0, 1, 0, -1};
                    set<int> s;
                    for (int x = 0; x < 4; x++)
                    {
                        int ni = i + dr[x];
                        int nj = j + cr[x];

                        if (ni >= 0 && nj >= 0 && ni < n && nj < n)
                        {
                            if (grid[ni][nj] == 1)
                            {
                                int node_i = ni * n + nj;

                                s.insert(ds.find(node_i));
                            }
                        }
                    }
                    int temp = 1;
                    for (auto it : s)
                    {
                        temp += ds.size[it];
                    }
                    ans = max(temp, ans);
                }
            }
        }
        if (ans == 0)
        {
            return n * n;
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
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout << obj.MaxConnection(grid) << "\n";
    }
}

// } Driver Code Ends