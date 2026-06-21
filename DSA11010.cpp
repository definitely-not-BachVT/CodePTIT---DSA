#include <bits/stdc++.h>
using namespace std;

struct Node
{
     int val;
     Node *left = 0, *right = 0;
     Node(int x)
     {
          val = x;
          left = right = 0;
     }
};

bool check(Node *root)
{
     if (!root)
          return true;

     queue<Node *> q;
     q.push(root);

     while (!q.empty())
     {
          int sz = q.size();
          bool isLeafLevel = false;

          while (sz--)
          {
               Node *u = q.front();
               q.pop();

               if (!u->left && !u->right)
                    isLeafLevel = true;
               else if (!u->left || !u->right)
                    return false;
               else
                    q.push(u->left), q.push(u->right);
          }

          if (isLeafLevel && !q.empty())
               return false;
     }
     return true;
}

void solve()
{
     int n;
     cin >> n;

     map<int, Node *> m;
     Node *root = 0;

     for (int i = 0; i < n; i++)
     {
          int u, v;
          char x;
          cin >> u >> v >> x;

          if (!m[u])
          {
               m[u] = new Node(u);
               if (!root)
                    root = m[u];
          }

          m[v] = new Node(v);

          if (x == 'L')
               m[u]->left = m[v];
          else
               m[u]->right = m[v];
     }

     if (check(root))
          cout << "Yes\n";
     else
          cout << "No\n";
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