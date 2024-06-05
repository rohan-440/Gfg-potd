//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    int findSwapValues(int a[], int n, int b[], int m)
    {
        long long int sumA = 0;
        for (int i = 0; i < n; i++)
            sumA += a[i];
        long long int sumB = 0;
        for (int i = 0; i < m; i++)
            sumB += b[i];
        if ((sumA + sumB) % 2 == 1)
            return -1;
        long long int sum = (sumA - sumB) / 2;
        unordered_set<long long int> s;
        for (int i = 0; i < m; i++)
            s.insert(b[i]);
        for (int i = 0; i < n; i++)
        {
            if (s.find(a[i] - sum) != s.end())
                return 1;
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
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends