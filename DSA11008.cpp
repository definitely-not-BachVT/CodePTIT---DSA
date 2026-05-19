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
     if (root == nullptr)
          return;

     if (root->val == x)
     {
          if (z == 'L')
               root->left = new Node(y);
          else
               root->right = new Node(y);

          return;
     }

     insertNode(root->left, x, y, z);
     insertNode(root->right, x, y, z);
}

int level = -1;
bool leaf(Node *root, int current_level, int &leaf_level)
{
     if (root == nullptr)
          return true;

     if (root->left == nullptr && root->right == nullptr)
     {
          if (leaf_level == -1)
          {
               leaf_level = current_level;
               return true;
          }

          return (current_level == leaf_level);
     }

     return leaf(root->left, current_level + 1, leaf_level) &&
            leaf(root->right, current_level + 1, leaf_level);
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

     int level = -1;
     if (leaf(root, 0, level))
          cout
              << "1\n";
     else
          cout << "0\n";
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