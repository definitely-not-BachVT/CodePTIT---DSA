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

void insertNode(Node *&root, int x, int y)
{
     if (root->val == x)
     {
          if (!root->left)
          {
               root->left = new Node(y);
               return;
          }

          if (!root->right)
          {
               root->right = new Node(y);
               return;
          }
     }

     if (root->left)
          insertNode(root->left, x, y);
     if (root->right)
          insertNode(root->right, x, y);

     return;
}

bool cmp(vector<int> a, vector<int> b)
{
     if (a.size() < b.size())
          return false;

     int idx = 0;
     int sz = a.size();

     for (int i = 0; i < sz; ++i)
          if (a[i] < b[i])
               return false;
     return true;
}

void solve()
{
     int n;
     cin >> n;

     Node *root = new Node(1);

     for (int i = 1; i < n; ++i)
     {
          int x, y;
          cin >> x >> y;

          insertNode(root, x, y);
     }

     queue<pair<Node *, vector<int>>> q;
     q.push({root, {1}});

     vector<vector<int>> ans;
     while (!q.empty())
     {
          auto [a, b] = q.front();
          q.pop();

          if (!a->left && !a->right)
          {
               ans.push_back(b);
               continue;
          }

          if (a->left)
          {
               vector<int> c = b;
               c.push_back(a->left->val);

               q.push({a->left, c});
          }

          if (a->right)
          {
               vector<int> c = b;
               c.push_back(a->right->val);

               q.push({a->right, c});
          }
     }

     sort(ans.begin(), ans.end(), cmp);
     for (auto a : ans)
     {
          for (auto b : a)
               cout << b << " ";
          cout << "\n";
     }
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