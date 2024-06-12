//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int countNumberswith4(int n)
    {
        // code here
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            int num = i;
            int cnt = 0;
            while (num)
            {
                if (num % 10 == 4)
                    cnt++;
                num /= 10;
            }
            if (cnt > 0)
                sum++;
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

        Solution obj;
        int res = obj.countNumberswith4(n);

        cout << res << endl;
    }
}

// } Driver Code Ends