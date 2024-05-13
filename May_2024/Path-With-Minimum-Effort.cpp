//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};

// } Driver Code Ends

class Solution
{
public:
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights)
    {
        // code here
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> dis(rows + 1, vector<int>(columns + 1, 1e9));
        pq.push({0, {0, 0}});
        dis[0][0] = 0;
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};
        while (!pq.empty())
        {
            int d = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            if (r == rows - 1 && c == columns - 1)
                return d;
            for (int x = 0; x < 4; x++)
            {
                int nr = r + dr[x];
                int nc = c + dc[x];
                if (nr >= 0 && nr < rows && nc >= 0 && nc < columns)
                {
                    int effort = max(d, abs(heights[nr][nc] - heights[r][c]));
                    if (effort < dis[nr][nc])
                    {
                        pq.push({effort, {nr, nc}});
                        dis[nr][nc] = effort;
                    }
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        int rows;
        scanf("%d", &rows);

        int columns;
        scanf("%d", &columns);

        vector<vector<int>> heights(rows, vector<int>(columns));
        Matrix::input(heights, rows, columns);

        Solution obj;
        int res = obj.MinimumEffort(rows, columns, heights);

        cout << res << endl;
    }
}

// } Driver Code Ends