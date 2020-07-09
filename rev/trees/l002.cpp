#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int data = 0;
    Node *left = nullptr;
    Node *right = nullptr;

    Node() {}

    Node(int data)
    {
        this->data = data;
    }
};

Node *constructBST(vector<int> &arr, int si, int ei)
{
    if (si > ei)
        return nullptr;

    int mid = (si + ei) >> 1; //same as divide by two

    Node *node = new Node(arr[mid]);
    node->left = constructBST(arr, si, mid - 1);
    node->right = constructBST(arr, mid + 1, ei);

    return node;
}

void display(Node *node)
{
    if (node == nullptr)
        return;

    string str = "";
    str += (node->left) != nullptr ? to_string(node->left->data) : ".";
    str += "<-" + to_string(node->data) + "->";
    str += (node->right) != nullptr ? to_string(node->right->data) : ".";
    cout << str << endl;
    display(node->left);
    display(node->right);
}

//Basics.===================================================================

int size(Node *node)
{
    if (node == nullptr)
        return 0;

    return size(node->left) + size(node->right) + 1;
}

int height(Node *node)
{
    if (node == nullptr)
        return -1;

    return max(height(node->left), height(node->right)) + 1;
}

bool find(Node *node, int data) //log(n)
{
    Node *curr = node;
    while (curr)
    {
        if (curr->data == data)
            return true;
        if (curr->data > data)
            curr = curr->left;
        else
            curr = curr->right;
    }
    return false;
}

/*Inorder sol*/
void allNodesInRange(Node *node, int a, int b, vector<int> &ans)
{
    if (!node)
        return;

    allNodesInRange(node->left, a, b, ans);

    if (node->data >= a && node->data <= b)
        ans.push_back(node->data);

    allNodesInRange(node->right, a, b, ans);
}

int idx = 0;
Node *ConstructBSTPre(vector<int> &pre, int lb, int rb)
{
    if (idx == pre.size() || lb > pre[idx] || rb < pre[idx])
        return nullptr;

    Node *node = new Node(pre[idx]);
    idx++;
    node->left = ConstructBSTPre(pre, lb, node->data);
    node->right = ConstructBSTPre(pre, node->data, rb);

    return node;
}

int idx_ = 0;
int heightOfBSTPre(vector<int> &pre, int lb, int rb)
{
    if (idx_ == pre.size() || lb > pre[idx_] || rb < pre[idx_])
        return 0;

    int ele = pre[idx_];
    idx_++;
    int lh = heightOfBSTPre(pre, lb, ele);
    int rh = heightOfBSTPre(pre, ele, rb);
    return max(lh, rh) + 1;
}

Node *addData(Node *node, int val)
{
    if (!node)
        return new Node(val);
    
    if(val<node->data)
        node->left = addData(node->left, val);
    else    
        node->right = addData(node->right, val);
    return node;
}

void Basics(Node *root)
{
    // cout<<size(root)<<endl;
    // cout<<height(root)<<endl;
    // cout<<boolalpha<<find(root,500)<<endl;
    vector<int> ans;
    allNodesInRange(root, 13, 86, ans);
    for (int e : ans)
        cout << e << " ";
    cout << endl;
}

void BSTfromPreOrder()
{
    vector<int> pre = {50, 17, 9, 14, 12, 23, 19, 76, 54, 72, 67};
    Node *root2 = ConstructBSTPre(pre, -1e8, 1e8);
    display(root2);
    cout << heightOfBSTPre(pre, -1e8, 1e8) << endl;
}

void QuesSet1(Node *root)
{
    Node *root_ = addData(root, 65);
    display(root_);
}

void solve()
{
    vector<int> arr = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120};
    Node *root = constructBST(arr, 0, arr.size() - 1);
    // display(root);
    // Basics(root);
    // BSTfromPreOrder();
    QuesSet1(root);
}

int main()
{
    solve();
    return 0;
}