#include <bits/stdc++.h>
using namespace std;

struct Node
{
     int val;
     Node *l = 0, *r = 0;
     Node(int x) { val = x; }
};

void solve()
{
     int n;
     cin >> n;

     map<int, Node *> m;
     Node *rt = 0;

     for (int i = 0; i < n; i++)
     {
          int u, v;
          char x;
          cin >> u >> v >> x;

          if (!m[u])
               m[u] = new Node(u), rt = rt ? rt : m[u];

          m[v] = new Node(v);

          if (x == 'L')
               m[u]->l = m[v];
          else
               m[u]->r = m[v];
     }

     queue<Node *> q;
     stack<Node *> s;

     if (rt)
          q.push(rt);

     bool rev = true;
     while (!q.empty())
     {
          int sz = q.size();

          while (sz--)
          {
               Node *u = q.front();
               q.pop();

               if (rev)
                    s.push(u);
               else
                    cout << u->val << " ";

               if (u->l)
                    q.push(u->l);
               if (u->r)
                    q.push(u->r);
          }

          if (rev)
               while (!s.empty())
                    cout << s.top()->val << " ", s.pop();

          rev = !rev;
     }
     cout << "\n";
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