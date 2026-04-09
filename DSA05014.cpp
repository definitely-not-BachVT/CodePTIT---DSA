#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
vector<string> dp(100 + 3, "0");

string nhan(string x, string y) // Nhân SNL
{
     if (x == "0" || y == "0")
          return "0";

     int n = x.size(), m = y.size();
     vector<int> res(n + m, 0);

     for (int i = n - 1; i >= 0; --i)
     {
          for (int j = m - 1; j >= 0; --j)
          {
               int mul = (x[i] - '0') * (y[j] - '0');
               int pos1 = i + j, pos2 = i + j + 1;
               int sum = mul + res[pos2];

               res[pos2] = sum % 10;
               res[pos1] += sum / 10;
          }
     }

     string ans = "";
     for (int i = 0; i < n + m; ++i)
     {
          if (!(ans.empty() && res[i] == 0))
               ans += to_string(res[i]);
     }

     return ans;
}
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

void sinh()
{
     dp[0] = "1";
     dp[1] = "1";

     for (int i = 2; i < 103; ++i)
     {
          dp[i] = "0";
          for (int j = 0; j < i; ++j)
               dp[i] = cong(dp[i], nhan(dp[j], dp[i - j - 1]));
          // dp[i] += dp[j] * dp[i - j - 1];
     }

     // dp[0] = 0;
}

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);

     int t;
     cin >> t;

     sinh();

     while (t--)
     {
          int n;
          cin >> n;

          cout << dp[n] << "\n";
     }
}