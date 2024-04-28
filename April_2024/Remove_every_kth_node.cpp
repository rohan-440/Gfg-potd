//{ Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
/* Link list Node */
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void append(struct Node **head_ref, struct Node **tail_ref, int new_data)
{
    struct Node *new_node = new Node(new_data);

    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;

    *tail_ref = new_node;
}

// } Driver Code Ends
/* Link list Node

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

/*You are required to complete this method*/

/* Function to get the middle of the linked list*/
/*K will always be in range */
#include <vector>
class Solution
{
public:
    Node *deleteK(Node *head, int K)
    {
        // Your code here
        vector<int> v;
        Node *curr = head;
        int i = 1;
        while (curr != NULL)
        {
            if (i % K != 0)
                v.push_back(curr->data);
            curr = curr->next;
            i++;
        }
        Node *newnode = new Node(0);
        Node *node = newnode;
        for (int i = 0; i < v.size(); i++)
        {
            Node *temp = new Node(v[i]);
            newnode->next = temp;
            newnode = newnode->next;
        }
        return node->next;
    }
};

//{ Driver Code Starts.

/* Driver program to test above function*/
int main()
{
    int T, i, n, l;
    cin >> T;
    while (T--)
    {
        struct Node *head = NULL, *tail = NULL;
        cin >> n;
        for (i = 1; i <= n; i++)
        {
            cin >> l;
            append(&head, &tail, l);
        }
        int K;
        cin >> K;
        Solution obj;
        Node *res = obj.deleteK(head, K);
        Node *temp = res;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends