// #include <bits/stdc++.h>
// using namespace std;

// bool cmp(pair<int, int> a, pair<int, int> b)
// {
//      if (b.first > a.first && b.second > a.second)
//           return true;
//      return false;
// }

// int main()
// {
//      ios_base::sync_with_stdio(false);
//      cin.tie(0);
//      cout.tie(0);

//      int n;
//      cin >> n;

//      vector<pair<int, int>> a(n);
//      for (int i = 0; i < n; ++i)
//           cin >> a[i].first >> a[i].second;

//      vector<pair<int, int>> tails;
//      for (int i = 0; i < n; ++i)
//      {
//           auto it = lower_bound(tails.begin(), tails.end(), a[i], cmp);
//           if (it == tails.end())
//                tails.push_back(a[i]);
//           else
//                *it = a[i];
//      }

//      // for (auto x : tails)
//      //      cout << x.first << " " << x.second << "\n";
//      cout << tails.size() << "\n";
// }

// - 2 - 7 = > -207 - 5 - 6 = > -506