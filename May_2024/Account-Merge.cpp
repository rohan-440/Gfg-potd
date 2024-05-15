//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    class DSU
    {
    public:
        vector<int> parent;
        vector<int> size;
        DSU(int n)
        {
            size.resize(n + 1, 1);
            parent.resize(n + 1);
            for (int i = 0; i < parent.size(); i++)
            {
                parent[i] = i;
            }
        }
        int Find(int u)
        {
            if (parent[u] == u)
                return u;
            else
                parent[u] = Find(parent[u]);
        }

        void Union(int u, int v)
        {
            int a = Find(u);
            int b = Find(v);
            if (a == b)
                return;
            else if (size[a] < size[b])
            {
                size[b] += size[a];
                parent[a] = b;
            }
            else
            {
                size[a] += size[b];
                parent[b] = a;
            }
        }
    };
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        // code here
        DSU ds(accounts.size());
        sort(accounts.begin(), accounts.end());
        map<string, int> mp;
        for (int i = 0; i < accounts.size(); i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {
                if (mp.find(accounts[i][j]) == mp.end())
                {
                    mp[accounts[i][j]] = i;
                }
                else
                {
                    ds.Union(mp[accounts[i][j]], i);
                }
            }
        }
        vector<string> mail[accounts.size()];
        for (auto x : mp)
        {
            int node = ds.Find(x.second);
            mail[node].push_back(x.first);
        }
        vector<vector<string>> v;
        for (int i = 0; i < accounts.size(); i++)
        {
            if (mail[i].size() == 0)
                continue;
            sort(mail[i].begin(), mail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto x : mail[i])
            {
                temp.push_back(x);
            }
            v.push_back(temp);
        }
        sort(v.begin(), v.end());
        return v;
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
        vector<vector<string>> accounts;

        for (int i = 0; i < n; i++)
        {
            vector<string> temp;
            int x;
            cin >> x;

            for (int j = 0; j < x; j++)
            {
                string s1;
                cin >> s1;
                temp.push_back(s1);
            }
            accounts.push_back(temp);
        }

        ///
        Solution obj;
        vector<vector<string>> res = obj.accountsMerge(accounts);
        sort(res.begin(), res.end());
        cout << "[";
        for (int i = 0; i < res.size(); ++i)
        {
            cout << "[";
            for (int j = 0; j < res[i].size(); j++)
            {
                if (j != res[i].size() - 1)
                    cout << res[i][j] << ","
                         << " ";
                else
                    cout << res[i][j];
            }
            if (i != res.size() - 1)
                cout << "], " << endl;
            else
                cout << "]";
        }
        cout << "]" << endl;
    }
}
// } Driver Code Ends