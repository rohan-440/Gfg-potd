//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node *node)
{
    if (node == NULL)
        return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

// } Driver Code Ends
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution
{
public:
    // Function to return a tree created from postorder and inoreder traversals.
    Node *f(int l, int h, int ind, int post[], unordered_map<int, int> &mp)
    {
        if (l > h)
            return NULL;
        Node *root = new Node(post[ind]);

        root->left = f(l, mp[post[ind]] - 1, ind - (h - mp[post[ind]]) - 1, post, mp);
        root->right = f(mp[post[ind]] + 1, h, ind - 1, post, mp);
        return root;
    }
    Node *buildTree(int in[], int post[], int n)
    {
        // Your code here
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
            mp[in[i]] = i;
        int ind = n - 1;
        return f(0, n - 1, ind, post, mp);
    }
};

//{ Driver Code Starts.

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++)
            cin >> in[i];
        for (int i = 0; i < n; i++)
            cin >> post[i];
        Solution obj;
        Node *root = obj.buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends