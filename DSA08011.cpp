// Dang lam

#include <bits/stdc++.h>
using namespace std;

vector<string> adj[26]; // 'A' -> 'O'
vector<int> visited[26];
vector<int> mi[26];

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);

     int t;
     cin >> t;

     while (t--)
     {
          for (int i = 0; i < 26; ++i)
               adj[i].clear();

          int n;
          cin >> n;

          string st, ed;
          cin >> st >> ed;

          vector<string> a(n);
          vector<int> sz(26, 0);
          for (int i = 0; i < n; ++i)
          {
               cin >> a[i];
               for (char c : a[i])
               {
                    adj[c - 'A'].push_back(a[i]);
                    sz[c - 'A']++;
               }
          }

          for (int i = 0; i < 26; ++i)
          {
               visited[i].resize(sz[i]);
               for (int j = 0; j < sz[i]; ++j)
                    visited[i][j] = 0;

               mi[i].resize(sz[i]);
               for (int j = 0; j < sz[i]; ++j)
                    mi[i][j] = 1e9;
          }

          queue<string> q;
          q.push(st);

          int fi;
          for (int i = 0; i < 26; ++i)
          {
               for (int j = 0; j < sz[i]; ++i)
                    if (st == adj[i][j])
                         visited[i][j] = 1;
          }

          while (!q.empty())
          {
               string fr = q.front();
               q.pop();
          }
     }
}