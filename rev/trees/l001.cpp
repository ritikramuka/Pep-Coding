#include <iostream>
#include <vector>
#include <climits>
#include <queue>
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

int idx = 0;
Node *constructTree(vector<int> &arr)
{
    if (idx == arr.size() || arr[idx] == -1)
    {
        idx++;
        return nullptr;
    }

    Node *node = new Node(arr[idx++]);
    node->left = constructTree(arr);
    node->right = constructTree(arr);
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

int Maximum_(Node *node)
{
    if (node == nullptr)
        return INT_MIN;

    return max(node->data, max(Maximum_(node->left), Maximum_(node->right)));
}

int Minimum_(Node *node)
{
    if (node == nullptr)
        return INT_MAX;

    return min(node->data, min(Minimum_(node->left), Minimum_(node->right)));
}

bool find(int data, Node *node)
{
    if (node == nullptr)
        return false;

    if (node->data == data)
        return true;

    return find(data, node->left) || find(data, node->right);
}

//Traversal.================================================================

void preOrder(Node *node)
{
    if (node == nullptr)
        return;

    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

void inOrder(Node *node)
{
    if (node == nullptr)
        return;

    inOrder(node->left);
    cout << node->data << " ";
    inOrder(node->right);
}

void postOrder(Node *node)
{
    if (node == nullptr)
        return;

    postOrder(node->left);
    postOrder(node->right);
    cout << node->data << " ";
}

//Questions.================================================================

bool nodeToRoot_(int data, Node *node, vector<Node *> &ans)
{
    if (node == nullptr)
        return false;

    if (node->data == data)
    {
        ans.push_back(node);
        return true;
    }

    int res = false;
    res = nodeToRoot_(data, node->left, ans) || nodeToRoot_(data, node->right, ans);

    if (res)
        ans.push_back(node);

    return res;
}

vector<Node *> nodeToRoot_(int data, Node *node)
{
    if (node == nullptr)
    {
        return {};
    }

    vector<Node *> ans;
    if (node->data == data)
    {
        ans.push_back(node);
        return ans;
    }

    ans = nodeToRoot_(data, node->left);
    if (ans.size() != 0)
    {
        ans.push_back(node);
        return ans;
    }

    ans = nodeToRoot_(data, node->right);
    if (ans.size() != 0)
    {
        ans.push_back(node);
        return ans;
    }

    return ans;
}

void nodeToRoot(Node *root)
{
    vector<Node *> ans_;
    nodeToRoot_(100, root, ans_);
    for (Node *e : ans_)
    {
        cout << e->data << "->";
    }
    cout << endl;
    vector<Node *> ans = nodeToRoot_(100, root);
    for (Node *e : ans)
    {
        cout << e->data << "->";
    }
}

//levelOrder traversal.=====================================================

void levelOrder(Node *node)
{
    queue<Node *> que;
    que.push(node);
    int level = 0;
    while (que.size() != 0)
    {
        cout << "Level -> " << level << ": ";
        level++;
        int size = que.size();
        while (size-- > 0)
        {
            Node *rnode = que.front();
            que.pop();
            cout << rnode->data << ", ";
            if (rnode->left)
                que.push(rnode->left);
            if (rnode->right)
                que.push(rnode->right);
        }
        cout << endl;
    }
}

void levelOrder_02(Node *node)
{
    queue<Node *> que;
    que.push(node);
    que.push(nullptr);
    int level = 0;
    cout << "Level -> " << level << ": ";
    while (que.size() != 1)
    {
        level++;
        int size = que.size();
        while (size-- > 0)
        {
            Node *rnode = que.front();
            que.pop();

            cout << rnode->data << ", ";
            if (rnode->left)
                que.push(rnode->left);
            if (rnode->right)
                que.push(rnode->right);

            if (que.front() == nullptr)
            {
                cout << endl
                     << "Level -> " << level << ": ";
                que.pop();
                que.push(nullptr);
            }
        }
    }
}

//view.=================================================================

void leftView(Node *node)
{
    queue<Node *> que;
    que.push(node);
    while (que.size() != 0)
    {
        cout << que.front()->data << endl;
        int size = que.size();
        while (size-- > 0)
        {
            Node *rnode = que.front();
            que.pop();
            if (rnode->left)
                que.push(rnode->left);
            if (rnode->right)
                que.push(rnode->right);
        }
    }
}

void rightView(Node *node)
{
    queue<Node *> que;
    que.push(node);
    while (que.size() != 0)
    {
        cout << que.front()->data << endl;
        int size = que.size();
        while (size-- > 0)
        {
            Node *rnode = que.front();
            que.pop();
            if (rnode->right)
                que.push(rnode->right);
            if (rnode->left)
                que.push(rnode->left);
        }
    }
}

/* vertical view */

int leftMinVal = 0;
int rightMaxVal = 0;
void width(Node *node, int idx)
{
    if (!node)
        return;

    leftMinVal = min(leftMinVal, idx);
    rightMaxVal = max(rightMaxVal, idx);

    width(node->left, idx - 1);
    width(node->right, idx + 1);
}

class pairVO
{
public:
    int vl;
    Node *node;
    pairVO(Node *node, int vl)
    {
        this->node = node;
        this->vl = vl;
    }
};

void verticalOrder(Node *node)
{
    width(node, 0);
    vector<vector<int>> ans(-leftMinVal + rightMaxVal + 1);
    queue<pairVO *> que;
    que.push(new pairVO(node, -leftMinVal));
    int level = 0;
    while (que.size() != 0)
    {
        int size = que.size();
        while (size-- > 0)
        {
            pairVO *rnode = que.front();
            que.pop();
            ans[rnode->vl].push_back(rnode->node->data);
            if (rnode->node->left)
                que.push(new pairVO(rnode->node->left, rnode->vl - 1));
            if (rnode->node->right)
                que.push(new pairVO(rnode->node->right, rnode->vl + 1));
        }
    }
    for (vector<int> a : ans)
    {
        for (int i : a)
            cout << i << " ";
        cout << endl;
    }
}

void TopView(Node *node)
{
    width(node, 0);
    vector<int> ans(-leftMinVal + rightMaxVal + 1, (int)-1e8);
    queue<pairVO *> que;
    que.push(new pairVO(node, -leftMinVal));
    while (que.size() != 0)
    {
        int size = que.size();
        while (size-- > 0)
        {
            pairVO *rvtx = que.front();
            que.pop();
            if (ans[rvtx->vl] == (int)-1e8)
                ans[rvtx->vl] = rvtx->node->data;
            if (rvtx->node->left)
                que.push(new pairVO(rvtx->node->left, rvtx->vl - 1));
            if (rvtx->node->right)
                que.push(new pairVO(rvtx->node->right, rvtx->vl + 1));
        }
    }
    for (int e : ans)
        cout << e << endl;
}

void bottomView(Node *node)
{
    width(node, 0);
    vector<int> ans(-leftMinVal + rightMaxVal + 1, (int)-1e8);
    queue<pairVO *> que;
    que.push(new pairVO(node, -leftMinVal));
    while (que.size() != 0)
    {
        int size = que.size();
        while (size-- > 0)
        {
            pairVO *rvtx = que.front();
            que.pop();
            ans[rvtx->vl] = rvtx->node->data;
            if (rvtx->node->left)
                que.push(new pairVO(rvtx->node->left, rvtx->vl - 1));
            if (rvtx->node->right)
                que.push(new pairVO(rvtx->node->right, rvtx->vl + 1));
        }
    }
    for (int e : ans)
        cout << e << endl;
}

void digonalView(Node *node)
{
    width(node, 0);
    vector<vector<int>> ans(-leftMinVal + 1);
    queue<pairVO *> que;
    que.push(new pairVO(node, -leftMinVal));
    while (que.size() != 0)
    {
        int size = que.size();
        while (size-- > 0)
        {
            pairVO *rvtx = que.front();
            que.pop();
            ans[rvtx->vl].push_back(rvtx->node->data);
            if (rvtx->node->left)
                que.push(new pairVO(rvtx->node->left, rvtx->vl - 1));
            if (rvtx->node->right)
                que.push(new pairVO(rvtx->node->right, rvtx->vl));
        }
    }
    for (vector<int> a : ans)
    {
        for (int i : a)
            cout << i << " ->";
        cout << endl;
    }
}

void levelOrderTraversal(Node *root)
{
    // levelOrder(root);
    // levelOrder_02(root);
    // leftView(root);
    // rightView(root);
    // verticalOrder(root);
    // TopView(root);
    // bottomView(root);
    digonalView(root);
}

void Basics(Node *root)
{
    cout << size(root) << endl;
    cout << height(root) << endl;
    cout << Maximum_(root) << endl;
    cout << Minimum_(root) << endl;
    cout << boolalpha << find(120, root) << endl;

    preOrder(root);
    cout << endl;
    inOrder(root);
    cout << endl;
    postOrder(root);
}

void solve()
{
    vector<int> arr = {10, 20, 40, -1, -1, 50, 80, -1, -1, 90, -1, -1, 30, 60, 100, -1, -1, -1, 70, 110, -1, -1, 120, -1, -1};
    Node *root = constructTree(arr);
    display(root);
    // Basics(root);
    // nodeToRoot(root);
    levelOrderTraversal(root);
}

int main()
{
    solve();
    return 0;
}