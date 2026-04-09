#include <bits/stdc++.h>
using namespace std;

string dp[205][205][205];

string cong(string a, string b) // Cộng SNL
{

     if (a.length() < b.length())
          swap(a, b);

     int lenA = a.length();
     int lenB = b.length();
     int carry = 0;
     string result = "";

     reverse(a.begin(), a.end());
     reverse(b.begin(), b.end());

     for (int i = 0; i < lenA; i++)
     {
          int digitA = a[i] - '0';
          int digitB = (i < lenB) ? (b[i] - '0') : 0;

          int sum = digitA + digitB + carry;
          carry = sum / 10;
          result.push_back((sum % 10) + '0');
     }

     if (carry > 0)
          result.push_back(carry + '0');
     reverse(result.begin(), result.end());

     size_t startPos = result.find_first_not_of('0');
     if (startPos != string::npos)
          return result.substr(startPos);
     return "0"; // Trường hợp cả hai số đều là 0
}

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);

     long long k, n;
     string s;

     cin >> k >> s;
     n = s.size();

     if (n == 0)
     {
          if (k == 0)
          {
               cout << "1";
               return 0;
          }
          cout << "0";
          return 0;
     }

     if (k == 0)
     {
          cout << "0";
          return 0;
     }

     for (int i = 0; i < 205; ++i)
          for (int j = 0; j < 205; ++j)
               for (int k = 0; k < 205; ++k)
                    dp[i][j][k] = "0";

     dp[0][0][0] = "1";

     for (int idx = 0; idx < n; ++idx)
          for (int open = 0; open <= idx; ++open)
               for (int mxd = 0; mxd <= k; ++mxd)
               {
                    if (dp[idx][open][mxd] == "0")
                         continue;

                    if (open > n / 2)
                    {
                         dp[idx][open][mxd] = "0";
                         continue;
                    }

                    if (s[idx] == '(' || s[idx] == '?')
                         if (open + 1 <= k)
                              dp[idx + 1][open + 1][max(mxd, open + 1)] = cong(dp[idx][open][mxd], dp[idx + 1][open + 1][max(mxd, open + 1)]);

                    if (s[idx] == ')' || s[idx] == '?')
                         if (open - 1 >= 0)
                              dp[idx + 1][open - 1][mxd] = cong(dp[idx][open][mxd], dp[idx + 1][open - 1][mxd]);
               }

     cout << dp[n][0][k];
}