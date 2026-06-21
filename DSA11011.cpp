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

void insertNode(Node *&root, int x, int y, char z)
{
     if (root->val == x)
     {
          if (z == 'L')
               root->left = new Node(y);
          else
               root->right = new Node(y);
          return;
     }

     if (root->left)
          insertNode(root->left, x, y, z);
     if (root->right)
          insertNode(root->right, x, y, z);

     return;
}

void solve()
{
     int n;
     cin >> n;

     int x, y;
     char z;

     cin >> x >> y >> z;
     Node *root = new Node(x);
     if (z == 'L')
          root->left = new Node(y);
     else
          root->right = new Node(y);

     for (int i = 1; i < n; ++i)
     {
          cin >> x >> y >> z;
          insertNode(root, x, y, z);
     }

     queue<Node *> q;
     q.push(root);

     bool ok = true;

     while (!q.empty())
     {
          Node *fr = q.front();
          q.pop();

          if (fr->left == nullptr && fr->right == nullptr)
               continue;

          if (fr->left && fr->right)
          {
               q.push(fr->left);
               q.push(fr->right);
          }
          else
          {
               ok = false;
               break;
          }
     }

     if (ok)
          cout << "1\n";
     else
          cout << "0\n";
}

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);

     int t = 1;
     cin >> t;

     while (t--)
          solve();
}