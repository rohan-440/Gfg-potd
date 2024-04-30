//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
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

struct Node *buildList(int size)
{
    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node *n)
{
    while (n)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
public:
    // Function to add two numbers represented by linked list.
    Node *reverse(Node *node)
    {
        Node *prev = NULL;
        while (node != NULL)
        {
            Node *temp = node->next;
            node->next = prev;
            prev = node;
            node = temp;
        }
        return prev;
    }
    Node *Add(Node *node1, Node *node2)
    {
        int carry = 0;
        Node *curr = new Node(-1);
        Node *node = curr;
        while (node1 != NULL && node2 != NULL)
        {
            int sum = node1->data + node2->data + carry;
            if (sum > 9)
            {
                curr->next = new Node(sum % 10);
                carry = 1;
            }
            else
            {
                curr->next = new Node(sum);
                carry = 0;
            }
            curr = curr->next;
            node1 = node1->next;
            node2 = node2->next;
        }
        while (node1 != NULL)
        {
            int sum = node1->data + carry;
            if (sum > 9)
            {
                curr->next = new Node(sum % 10);
                carry = 1;
            }
            else
            {
                curr->next = new Node(sum);
                carry = 0;
            }
            curr = curr->next;
            node1 = node1->next;
        }
        while (node2 != NULL)
        {
            int sum = node2->data + carry;
            if (sum > 9)
            {
                curr->next = new Node(sum % 10);
                carry = 1;
            }
            else
            {
                curr->next = new Node(sum);
                carry = 0;
            }
            curr = curr->next;
            node2 = node2->next;
        }
        if (carry == 1)
        {
            curr->next = new Node(1);
        }
        return node->next;
    }
    struct Node *addTwoLists(struct Node *num1, struct Node *num2)
    {
        // code here
        Node *node1 = reverse(num1);
        Node *node2 = reverse(num2);
        Node *node3 = reverse(Add(node1, node2));
        while (node3 != NULL && node3->data == 0)
        {
            node3 = node3->next;
        }
        if (node3 != NULL && node3->data != 0)
            return node3;
        return new Node(0);
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

        cin >> n;
        Node *num1 = buildList(n);

        cin >> m;
        Node *num2 = buildList(m);
        Solution ob;
        Node *res = ob.addTwoLists(num1, num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends