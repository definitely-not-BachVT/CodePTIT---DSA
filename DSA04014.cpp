#include <bits/stdc++.h>
using namespace std;

long long mergeSort(vector<int> &a, int left, int right)
{
     if (left >= right)
          return 0;

     int mid = (left + right) / 2;
     long long res = mergeSort(a, left, mid) + mergeSort(a, mid + 1, right);

     vector<int> b;
     int idx1 = left, idx2 = mid + 1;
     while (idx1 <= mid && idx2 <= right)
     {
          if (a[idx1] <= a[idx2])
          {
               b.push_back(a[idx1]);
               ++idx1;
          }
          else
          {
               b.push_back(a[idx2]);
               ++idx2;

               res += (mid - idx1 + 1);
          }
     }

     while (idx1 <= mid)
          b.push_back(a[idx1++]);
     while (idx2 <= right)
          b.push_back(a[idx2++]);

     int sz = b.size();
     for (int i = 0; i < sz; ++i)
          a[left + i] = b[i];

     return res;
}

void solve()
{
     int n;
     cin >> n;

     vector<int> a(n);
     for (int i = 0; i < n; ++i)
          cin >> a[i];

     cout << mergeSort(a, 0, n - 1) << "\n";
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