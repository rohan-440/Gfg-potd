//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int maxSquare(int n, int m, vector<vector<int>> mat)
    {
        // code here
        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 1)
                {
                    int up = 0;
                    if (i > 0 && j > 0)
                        up = mat[i - 1][j];
                    int dia = 0;
                    if (i > 0 && j > 0)
                        dia = mat[i - 1][j - 1];
                    int left = 0;
                    if (i > 0 && j > 0)
                        left = mat[i][j - 1];
                    mat[i][j] = 1 + min(up, min(dia, left));
                    maxi = max(maxi, mat[i][j]);
                }
            }
        }
        return maxi;
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
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n * m; i++)
            cin >> mat[i / m][i % m];

        Solution ob;
        cout << ob.maxSquare(n, m, mat) << "\n";
    }
    return 0;
}
// } Driver Code Ends