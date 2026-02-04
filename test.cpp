#include <bits/stdc++.h>
using namespace std;

vector<string> np;

int n = 8;
void sinh(string x, int idx)
{
  if(idx == 9)
  {
    np.push_back(x);
    return;
  }

  sinh(x + "0", idx + 1);
  sinh(x + "2", idx + 1);
}

bool check(string x)
{
    for (int i = 0; i < 4; i++)
        if (x[i] != x[7 - i])
            return false;

    int day = (x[0] - '0') * 10 + (x[1] - '0');
    int month = (x[2] - '0') * 10 + (x[3] - '0');
    int year = (x[4] - '0') * 1000 + (x[5] - '0') * 100
             + (x[6] - '0') * 10 + (x[7] - '0');

    if (day < 1 || day > 31) return false;
    if (month < 1 || month > 12) return false;
    if (year < 2000) return false;

    return true;
}


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  sinh("", 0);
  sort(np.begin(), np.end());

  for(string x : np)
    if(check(x))
      cout << x[0] << x[1] << "/" << x[2] << x[3] << "/" << x[4] << x[5] << x[6] << x[7] << "\n";

}
