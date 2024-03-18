//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    class DSU
    {
    public:
        int noedges = 0;
        vector<int> parent;
        vector<int> size;
        DSU(int n)
        {
            parent.resize(n + 1);
            iota(parent.begin(), parent.end(), 0);
            size.resize(n + 1, 1);
        }

        int find(int u)
        {
            if (parent[u] == u)
                return u;
            return parent[u] = find(parent[u]);
        }

        void Union(int u, int v)
        {
            int a = find(u);
            int b = find(v);

            if (a == b)
                return;

            noedges -= size[a] * (size[a] - 1) / 2;
            noedges -= size[b] * (size[b] - 1) / 2;

            if (size[a] < size[b])
            {
                parent[a] = b;
                size[b] += size[a];
                noedges += size[b] * (size[b] - 1) / 2;
            }
            else
            {
                parent[b] = a;
                size[a] += size[b];
                noedges += size[a] * (size[a] - 1) / 2;
            }
        }
    };
    vector<int> maximumWeight(int n, vector<vector<int>> edges, int q, vector<int> &queries)
    {
        // code here
        DSU ds(n);
        sort(edges.begin(), edges.end(), [](const auto x, const auto y)
             { return x[2] < y[2]; });
        vector<pair<int, int>> newQ;
        for (int i = 0; i < q; i++)
        {
            newQ.push_back({queries[i], i});
        }

        sort(newQ.begin(), newQ.end());
        vector<int> ans(q, 0);
        int j = 0;
        for (auto x : newQ)
        {
            while (j < edges.size() && x.first >= edges[j][2])
            {
                ds.Union(edges[j][0], edges[j][1]);
                j++;
            }
            ans[x.second] = ds.noedges;
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

        vector<vector<int>> edges(n - 1, vector<int>(3, 0));

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cin >> edges[i][j];
            }
        }

        int q;
        cin >> q;
        vector<int> queries(q);
        for (int i = 0; i < q; i++)
            cin >> queries[i];

        Solution obj;
        vector<int> ans = obj.maximumWeight(n, edges, q, queries);

        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends