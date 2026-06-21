#include <bits/stdc++.h>
using namespace std;

struct Node
{
     int val;
     Node *left = 0, *right = 0;
     Node(int x) { val = x; }
};

void insert(Node *root, int u, int v, char x)
{
     if (!root)
          return;

     if (root->val == u)
     {
          if (x == 'L')
               root->left = new Node(v);
          else
               root->right = new Node(v);
          return;
     }

     insert(root->left, u, v, x);
     insert(root->right, u, v, x);
}

int dfs(Node *u, int &maxSum)
{
     if (!u)
          return 0;

     if (!u->left && !u->right)
          return u->val;

     if (!u->left)
          return dfs(u->right, maxSum) + u->val;

     if (!u->right)
          return dfs(u->left, maxSum) + u->val;

     int leftSum = dfs(u->left, maxSum);
     int rightSum = dfs(u->right, maxSum);

     if (maxSum < leftSum + rightSum + u->val)
          maxSum = leftSum + rightSum + u->val;

     return max(leftSum, rightSum) + u->val;
}

void solve()
{
     int n;
     cin >> n;

     Node *root = 0;

     for (int i = 0; i < n; i++)
     {
          int u, v;
          char x;
          cin >> u >> v >> x;

          if (!root)
               root = new Node(u);

          insert(root, u, v, x);
     }

     int maxSum = -2e9;
     dfs(root, maxSum);

     cout << maxSum << "\n";
}

int main()
{
     ios_base::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);

     int t;
     cin >> t;
     while (t--)
          solve();
}