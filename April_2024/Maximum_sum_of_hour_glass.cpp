//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int findMaxSum(int n, int m, vector<vector<int>> mat)
    {
        // code here
        if (n < 3 || m < 3)
            return -1;
        int maxsum = 0;
        for (int i = 1; i < n - 1; i++)
        {
            for (int j = 1; j < m - 1; j++)
            {
                int currsum = mat[i][j] + mat[i - 1][j] + mat[i - 1][j - 1] + mat[i - 1][j + 1] + mat[i + 1][j] + mat[i + 1][j - 1] + mat[i + 1][j + 1];
                maxsum = max(maxsum, currsum);
            }
        }
        return maxsum;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, M, i, j;
        cin >> N >> M;
        vector<vector<int>> Mat(N, vector<int>(M));
        for (i = 0; i < N; i++)
            for (j = 0; j < M; j++)
                cin >> Mat[i][j];
        Solution ob;
        cout << ob.findMaxSum(N, M, Mat) << "\n";
    }
}
// } Driver Code Ends