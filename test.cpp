#include <bits/stdc++.h>
using namespace std;

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);

     int n;
     cin >> n;

     vector<long long> res;
     vector<int> a = {2, 3, 5, 7};

     string tmp = "";
     for (int z : a)
          tmp = tmp + to_string(z);

     queue<pair<string, int>> q;
     q.push({tmp, 4});

     while (!q.empty())
     {
     }

     sort(res.begin(), res.end());
     for (long long x : res)
          cout << x << "\n";
}