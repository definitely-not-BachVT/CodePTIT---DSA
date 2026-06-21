#include <bits/stdc++.h>
using namespace std;

struct Node
{
     int val;
     Node *left, *right;

     Node(int x)
     {
          val = x;
          left = right = nullptr;
     }
};

int idx;
map<int, int> pos;

Node *build(vector<int> &pre, int l, int r)
{
     if (l > r)
          return nullptr;

     int val = pre[idx++];
     Node *root = new Node(val);

     if (l == r)
          return root;

     int mid = pos[val];
     root->left = build(pre, l, mid - 1);
     root->right = build(pre, mid + 1, r);

     return root;
}

void post(Node *root)
{
     if (!root)
          return;

     post(root->left);
     post(root->right);
     cout << root->val << " ";
}

void solve()
{
     idx = 0;
     pos.clear();

     int n;
     cin >> n;

     vector<int> in(n), pre(n);
     for (int i = 0; i < n; ++i)
     {
          cin >> in[i];
          pos[in[i]] = i;
     }

     for (int i = 0; i < n; ++i)
          cin >> pre[i];

     Node *root = build(pre, 0, n - 1);
     post(root);

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