#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Node
{
public:
    int data = 0;
    int height = 0;
    int bal = 0;
    Node *left = nullptr;
    Node *right = nullptr;

    Node() {}

    Node(int data)
    {
        this->data = data;
    }
};

void updateHeightAndBalance(Node *node)
{
    int lh = -1;
    int rh = -1;

    if (node->left)
        lh = node->left->height;
    if (node->right)
        rh = node->right->height;

    node->height = max(lh, rh) + 1;
    node->bal = (lh - rh);

    return;
}

Node *LL(Node *A)
{
    Node *B = A->left;
    Node *BkaRight = B->right;

    B->right = A;
    A->left = BkaRight;

    updateHeightAndBalance(A);
    updateHeightAndBalance(B);

    return B;
}

Node *RR(Node *A)
{
    Node *B = A->right;
    Node *BkaLeft = B->left;

    B->left = A;
    A->right = BkaLeft;

    updateHeightAndBalance(A);
    updateHeightAndBalance(B);

    return B;
}

Node *getRotation(Node *node)
{
    updateHeightAndBalance(node);
    if (node->bal == 2)
    {
        if (node->left->bal == 1)
            return LL(node);
        else
        {
            node->left = RR(node->left);
            return LL(node);
        }
    }
    else if (node->bal == -2)
    {
        if (node->right->bal == -1)
            return RR(node);
        else
        {
            node->right = LL(node->right);
            return RR(node);
        }
    }
    return node;
}

Node *AddData(Node *node, int val)
{
    if (!node)
        return new Node(val);

    if (node->data > val)
        node->left = AddData(node->left, val);
    else
        node->right = AddData(node->right, val);

    return getRotation(node);
}

int maxElement(Node *node)
{
    Node *curr = node;
    while (curr->right != nullptr)
        curr = curr->right;
    return curr->data;
}

Node *RemoveData(Node *node, int val)
{
    if (!node)
        return nullptr;

    if (node->data > val)
        node->left = RemoveData(node->left, val);
    else if (node->data < val)
        node->right = RemoveData(node->right, val);
    else
    {
        if (node->left == nullptr || node->right == nullptr)
            return node->left != nullptr ? node->left : node->right;

        int maxValLeft = maxElement(node->left);
        node->data = maxValLeft;
        node->left = RemoveData(node->left, maxValLeft);
    }
    return getRotation(node);
}

Node *constructBST(vector<int> &arr, int si, int ei)
{
    if (si > ei)
        return nullptr;

    int mid = (si + ei) >> 1;
    Node *node = new Node(arr[mid]);

    node->left = constructBST(arr, si, mid - 1);
    node->right = constructBST(arr, mid + 1, ei);

    updateHeightAndBalance(node);
    return node;
}

void display(Node *node)
{
    if (!node)
        return;

    string str = "";
    str += ((node->left != nullptr) ? to_string(node->left->data) + "[" + to_string(node->left->bal) + "," + to_string(node->left->height) + "]" : ".");
    str += " <- " + to_string(node->data) + "[" + to_string(node->bal) + "," + to_string(node->height) + "]" + " -> ";
    str += ((node->right != nullptr) ? to_string(node->right->data) + "[" + to_string(node->right->bal) + "," + to_string(node->right->height) + "]" : ".");
    cout << (str) << endl;

    display(node->left);
    display(node->right);

    return;
}

void solve()
{
    vector<int> arr = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120};
    // Node *root = constructBST(arr, 0, arr.size() - 1);
    // root = RemoveData(root, 30);
    // root = AddData(root, 25);
    Node* root=nullptr;
    for(int e : arr)
    {
        root=AddData(root,e);
    }
    display(root);
}

int main()
{
    solve();
    return 0;
}