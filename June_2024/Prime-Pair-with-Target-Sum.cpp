//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array
{
public:
    template <class T>
    static void input(vector<T> &A, int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};

// } Driver Code Ends

class Solution
{
public:
    vector<int> getPrimes(int n)
    {
        // code here
        vector<int> prime(n + 1, 1);
        prime[0] = 0;
        prime[1] = 0;

        for (int p = 2; p * p <= n; p++)
        {
            if (prime[p] == 1)
            {
                for (int i = p * p; i <= n; i += p)
                    prime[i] = 0;
            }
        }
        vector<int> v;
        for (int i = 0; i < prime.size(); i++)
            if (prime[i] == 1)
                v.push_back(i);
        set<int> s;
        for (int i = 0; i < v.size(); i++)
            s.insert(n - v[i]);
        for (int i = 0; i < v.size(); i++)
        {
            if (s.find(v[i]) != s.end())
                return {v[i], n - v[i]};
        }
        return {-1, -1};
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

        Solution obj;
        vector<int> res = obj.getPrimes(n);

        Array::print(res);
    }
}

// } Driver Code Ends