//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to find if there is a celebrity in the party or not.
    // v = {0,2,0} => {1,0,1}
    // v = {1,1} => {1,1}
    int celebrity(vector<vector<int>> &mat)
    {
        // code here
        vector<int> in(mat.size(), 0);
        vector<int> out(mat.size(), 0);
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[0].size(); j++)
            {
                if (mat[i][j] == 1)
                {
                    in[j]++;
                    out[i]++;
                }
            }
        }

        for (int i = 0; i < in.size(); i++)
        {
            if (in[i] == in.size() - 1 && out[i] == 0)
                return i;
        }
        return -1;
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
        vector<vector<int>> M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends