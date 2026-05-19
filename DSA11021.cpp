#include <bits/stdc++.h>
using namespace std;

struct Node
{
     int val;
     Node *left, *right;

     Node(int u)
     {
          val = u;
          left = right = nullptr;
     }
};

void insertNode(Node *&root, int u)
{
     if (root == nullptr)
     {
          root = new Node(u);
          return;
     }

     if (root->val < u)
          insertNode(root->right, u);
     else
          insertNode(root->left, u);
}

void leaf(Node *root)
{
     if (root->right == nullptr && root->left == nullptr)
     {
          cout << root->val << " ";
          return;
     }

     if (root->left)
          leaf(root->left);
     if (root->right)
          leaf(root->right);
}

void solve()
{
     int n;
     cin >> n;

     int x;
     cin >> x;

     Node *root = new Node(x);
     for (int i = 1; i < n; ++i)
     {
          cin >> x;
          insertNode(root, x);
     }

     leaf(root);
     cout << "\n";
}

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);

     int t;
     cin >> t;

     while (t--)
          solve();
}