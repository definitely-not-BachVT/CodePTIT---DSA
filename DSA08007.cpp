#include <bits/stdc++.h>
using namespace std;

string toBin(long long n)
{
    if (n == 0)
        return "0";

    string s = "";
    while (n > 0)
    {
        int bit = n % 2;
        s.push_back(char('0' + bit));
        n /= 2;
    }
    reverse(s.begin(), s.end());
    return s;
}

bool isBin(const string &s)
{
    for (char c : s)
        if (c != '0' && c != '1')
            return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        long long n;
        cin >> n;

        string s = toBin(n);
        int len = s.size();

        long long cnt = 0;
        cnt += (long long)pow(2, len - 2) - 1;
        for (int i = 1; i < len; ++i)
        {
            if (s[i] == '1')
                cnt += (long long)pow(2, len - i - 2);
        }

        if (isBin(s))
            ++cnt;

        cout << cnt << "\n";
    }
}
