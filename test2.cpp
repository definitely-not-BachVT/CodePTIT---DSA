#include <bits/stdc++.h>
using namespace std;

struct Node
{
     int val;
     Node *left, *right;

     // Hàm khởi tạo
     Node(int x)
     {
          val = x;
          left = right = nullptr;
     }
};

map<int, Node *> mp;

void in(Node *root)
{
     if (root == nullptr)
          return;

     in(root->left);
     in(root->right);
     cout << root->val << " ";
}

void solve()
{
     int n;
     cin >> n;

     int dinh = 0;

     for (int i = 0; i < n; ++i)
     {
          int x, y;
          char c;
          cin >> x >> y >> c;

          if (dinh == 0)
               dinh = x;

          if (mp[x] == nullptr)
               mp[x] = new Node(x);

          if (mp[y] == nullptr)
               mp[y] = new Node(y);

          if (c == 'L')
               mp[x]->left = mp[y];
          else
               mp[x]->right = mp[y];
     }

     in(mp[dinh]);
}

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);

     solve();
}