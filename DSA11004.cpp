#include <bits/stdc++.h>
using namespace std;

struct Node
{
     int val;
     Node *left = nullptr, *right = nullptr;

     Node(int u)
     {
          val = u;
          left = right = nullptr;
     }
};

void insertNode(Node *root, int u, int v, char x)
{
     if (root == nullptr)
          return;

     if (root->val == u)
     {
          if (x == 'L')
               root->left = new Node(v);
          else
               root->right = new Node(v);

          return;
     }

     insertNode(root->left, u, v, x);
     insertNode(root->right, u, v, x);
}

void in(Node *root)
{
     if (root == nullptr)
          return;

     queue<Node *> q;
     q.push(root);

     while (!q.empty())
     {
          auto fr = q.front();
          q.pop();
          cout << fr->val << " ";

          if (fr->left)
               q.push(fr->left);
          if (fr->right)
               q.push(fr->right);
     }
}

void solve()
{
     int n;
     cin >> n;

     int u, v;
     char x;

     cin >> u >> v >> x;
     Node *root = new Node(u);
     if (x == 'L')
          root->left = new Node(v);
     else
          root->right = new Node(v);

     for (int i = 1; i < n; ++i)
     {
          cin >> u >> v >> x;
          insertNode(root, u, v, x);
     }

     in(root);
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