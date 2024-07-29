//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    vector<string> v;
    void f(int i, int j, string &temp, vector<vector<int>> &mat)
    {
        if (i == mat.size() - 1 && j == mat[0].size() - 1 && mat[i][j] == 1)
        {
            v.push_back(temp);
            return;
        }
        if (i < 0 || i >= mat.size() || j < 0 || j >= mat[0].size())
            return;
        mat[i][j] = 0;
        if (i > 0 && mat[i - 1][j] == 1)
        {
            temp.push_back('U');
            f(i - 1, j, temp, mat);
            temp.pop_back();
        }
        if (i + 1 < mat.size() && mat[i + 1][j] == 1)
        {
            temp.push_back('D');
            f(i + 1, j, temp, mat);
            temp.pop_back();
        }
        if (j > 0 && mat[i][j - 1] == 1)
        {
            temp.push_back('L');
            f(i, j - 1, temp, mat);
            temp.pop_back();
        }
        if (j + 1 < mat[0].size() && mat[i][j + 1] == 1)
        {
            temp.push_back('R');
            f(i, j + 1, temp, mat);
            temp.pop_back();
        }
        mat[i][j] = 1;
        return;
    }
    vector<string> findPath(vector<vector<int>> &mat)
    {
        // Your code goes here
        string temp = "";
        if (mat[0][0] == 1)
            f(0, 0, temp, mat);
        if (v.size() == 0)
            return {"-1"};
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
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends