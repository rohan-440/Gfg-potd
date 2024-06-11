//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array
{
public:
    template <class T>
    static void input(vector<T> &a, int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ", &a[i]);
        }
    }

    template <class T>
    static void print(vector<T> &a)
    {
        for (int i = 0; i < a.size(); i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};

// } Driver Code Ends

class Solution
{
public:
    long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr)
    {
        vector<pair<int, int>> v;
        long long sum = 0;
        for (int i = 0; i < n; i++)
            v.push_back({abs(arr[i] - brr[i]), i});
        sort(v.begin(), v.end());
        for (int i = n - 1; i >= 0; i--)
        {
            int idx = v[i].second;
            if (arr[idx] > brr[idx] && x || !y)
            {
                x--;
                sum += arr[idx];
            }
            else
            {
                y--;
                sum += brr[idx];
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        vector<int> arr(n);
        Array::input(arr, n);

        vector<int> brr(n);
        Array::input(brr, n);

        Solution obj;
        long long res = obj.maxTip(n, x, y, arr, brr);

        cout << res << endl;
    }
}

// } Driver Code Ends