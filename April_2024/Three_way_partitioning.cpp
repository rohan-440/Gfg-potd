//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to partition the array around the range such
    // that array is divided into three parts.
    void threeWayPartition(vector<int> &arr, int a, int b)
    {
        // code here
        vector<int> v1;
        vector<int> v2;
        vector<int> v3;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] < a)
                v1.push_back(arr[i]);
            else if (arr[i] >= a && arr[i] <= b)
                v2.push_back(arr[i]);
            else if (arr[i] > b)
                v3.push_back(arr[i]);
        }
        int j = 0;
        for (int i = 0; i < v1.size(); i++)
        {
            arr[j] = v1[i];
            j++;
        }
        for (int i = 0; i < v2.size(); i++)
        {
            arr[j] = v2[i];
            j++;
        }
        for (int i = 0; i < v3.size(); i++)
        {
            arr[j] = v3[i];
            j++;
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;

        vector<int> array(N);
        unordered_map<int, int> ump;

        for (int i = 0; i < N; i++)
        {
            cin >> array[i];
            ump[array[i]]++;
        }

        int a, b;
        cin >> a >> b;

        vector<int> original = array;

        int k1 = 0, k2 = 0, k3 = 0;
        int kk1 = 0;
        int kk2 = 0;
        int kk3 = 0;

        for (int i = 0; i < N; i++)
        {
            if (original[i] > b)
                k3++;
            else if (original[i] <= b and original[i] >= a)
                k2++;
            else if (original[i] < b)
                k1++;
        }

        Solution ob;
        ob.threeWayPartition(array, a, b);

        for (int i = 0; i < k1; i++)
        {
            if (array[i] < b)
                kk1++;
        }

        for (int i = k1; i < k1 + k2; i++)
        {
            if (array[i] <= b and array[i] >= a)
                kk2++;
        }

        for (int i = k1 + k2; i < k1 + k2 + k3; i++)
        {
            if (array[i] > b)
                kk3++;
        }
        bool ok = 0;
        if (k1 == kk1 and k2 == kk2 and k3 == kk3)
            ok = 1;

        for (int i = 0; i < array.size(); i++)
            ump[array[i]]--;

        for (int i = 0; i < array.size(); i++)
            if (ump[array[i]] != 0)
                ok = 0;

        if (ok)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}

// } Driver Code Ends