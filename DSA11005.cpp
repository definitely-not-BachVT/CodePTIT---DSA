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

map<int, int> pos;
Node *build(vector<int> &in, vector<int> &level, int l, int r)
{
     if (l > r || level.empty())
          return nullptr;

     int val = level[0];
     Node *root = new Node(val);

     if (l == r)
          return root;

     int mid = pos[val];
     vector<int> leftLevel, rightLevel;

     for (int i = 1; i < level.size(); i++)
     {
          if (pos[level[i]] < mid)
               leftLevel.push_back(level[i]);
          else
               rightLevel.push_back(level[i]);
     }

     root->left = build(in, leftLevel, l, mid - 1);
     root->right = build(in, rightLevel, mid + 1, r);

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
     int n;
     cin >> n;

     vector<int> in(n), level(n);
     pos.clear();

     for (int i = 0; i < n; i++)
     {
          cin >> in[i];
          pos[in[i]] = i;
     }

     for (int i = 0; i < n; i++)
          cin >> level[i];

     Node *root = build(in, level, 0, n - 1);

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