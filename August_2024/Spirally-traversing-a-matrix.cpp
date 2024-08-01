//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> spirallyTraverse(vector<vector<int>> &matrix)
    {
        // code here
        int w = 0;
        int x = matrix.size();
        int y = 0;
        int z = matrix[0].size();
        vector<int> v;
        while (w < x && y < z)
        {
            for (int i = y; i < z; i++)
            {
                v.push_back(matrix[w][i]);
            }
            w++;
            for (int i = w; i < x; i++)
            {
                v.push_back(matrix[i][z - 1]);
            }
            z--;
            if (w < x)
            {
                for (int i = z - 1; i >= y; i--)
                {
                    v.push_back(matrix[x - 1][i]);
                }

                x--;
            }
            if (y < z)
            {
                for (int i = x - 1; i >= w; i--)
                {
                    v.push_back(matrix[i][y]);
                }
                y++;
            }
        }
        return v;
    }
};

// 1 4
//  41 66 47 23

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends