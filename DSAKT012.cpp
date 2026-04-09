#include <bits/stdc++.h>
using namespace std;

long long minCnt = 1e9;
void backtrack(vector<long long> &t, long long sum, long long pos, long long currSum, long long cnt)
{
     if (currSum > sum || cnt > minCnt)
          return;

     long long size = t.size();
     long long tmp = currSum;
     for (long long i = pos; i < size; ++i)
          tmp += t[i];

     if (tmp < sum)
          return;

     if (currSum == sum)
     {
          if (cnt < minCnt)
               minCnt = cnt;
          return;
     }

     for (long long i = pos; i < size; ++i)
          backtrack(t, sum, i + 1, currSum + t[i], cnt + 1);
}

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);


          long long n, sum;
          cin >> n >> sum;

          vector<long long> t(n);
          for (long long i = 0; i < n; ++i)
               cin >> t[i];

          sort(t.rbegin(), t.rend());
          minCnt = 1e12;

          backtrack(t, sum, 0, 0, 0);
          if (minCnt != 1e12)
               cout << minCnt << "\n";
          else
               cout << "-1\n";
}