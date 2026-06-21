#include <iostream>
#include <map>

using namespace std;

struct Node
{
     int val;
     Node *l = 0, *r = 0;
     Node(int x) { val = x; }
};

bool check(Node *rt, int d, int &lv)
{
     if (!rt)
          return true;

     if (!rt->l && !rt->r)
          return lv == 0 ? (lv = d, true) : (d == lv);

     return check(rt->l, d + 1, lv) && check(rt->r, d + 1, lv);
}

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

     int lv = 0;
     if (check(rt, 1, lv))
          cout << 1 << "\n";
     else
          cout << 0 << "\n";
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