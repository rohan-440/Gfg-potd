//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    // int lcs(int i,int j,string &x , string &y,vector<vector<int>> &dp){
    //     if(i >= x.size() || j >= y.size())return 0;
    //     if(dp[i][j] != -1) return dp[i][j];
    //     int take = 0;
    //     if(x[i] == y[j]) take = 1 + lcs(i+1,j+1,x,y,dp);
    //     int notake = max(lcs(i+1,j,x,y,dp),lcs(i,j+1,x,y,dp));
    //     return dp[i][j] = max(take,notake);
    // }
    int findMinCost(string x, string y, int costX, int costY)
    {
        // Your code goes here
        vector<vector<int>> dp(x.size() + 1, vector<int>(y.size() + 1, 0));
        for (int i = x.size() - 1; i >= 0; i--)
        {
            for (int j = y.size() - 1; j >= 0; j--)
            {
                int take = 0;
                if (x[i] == y[j])
                    take = 1 + dp[i + 1][j + 1];
                int notake = max(dp[i + 1][j], dp[i][j + 1]);
                dp[i][j] = max(take, notake);
            }
        }
        int len = dp[0][0];
        // cout<<"lcs is "<<len<<endl;
        return ((x.size() - len) * costX) + ((y.size() - len) * costY);
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        string x, y;
        cin >> x >> y;

        int costX, costY;
        cin >> costX >> costY;

        Solution ob;
        cout << ob.findMinCost(x, y, costX, costY);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends