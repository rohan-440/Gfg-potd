//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/*You are required to complete this method */

class Solution
{
public:
    /*
    0,0  0,1   1,0  2,0  1,1  0,2  1,2  2,1  2,2
    0,0  0,1   1,0  1,1



    */

    vector<int> matrixDiagonally(vector<vector<int>> &mat)
    {
        int n = mat.size();
        map<int, vector<int>> mp;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                mp[i + j].push_back(mat[i][j]);
            }
        }
        vector<int> ans;
        bool flag = true;
        for (int i = 0; i < mp.size(); i++)
        {
            if (flag)
            {
                reverse(mp[i].begin(), mp[i].end());
            }
            ans.insert(ans.end(), mp[i].begin(), mp[i].end());
            flag = !flag;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        int k = 0;
        // cin>>k;
        cin >> n;
        vector<vector<int>> mat(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int> ans = obj.matrixDiagonally(mat);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
}
// } Driver Code Ends