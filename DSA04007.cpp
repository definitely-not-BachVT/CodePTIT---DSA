#include <bits/stdc++.h>
using namespace std;

long long toBase10(const string &s, int K)
{
    long long val = 0;
    for (char c : s)
    {
        val = val * K + (c - '0');
    }
    return val;
}

string fromBase10(long long x, int K)
{
    if (x == 0)
        return "0";
    string res = "";
    while (x > 0)
    {
        res.push_back(char('0' + (x % K)));
        x /= K;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        int K;
        string A, B;
        cin >> K >> A >> B;

        long long a10 = toBase10(A, K);
        long long b10 = toBase10(B, K);

        long long sum = a10 + b10;

        cout << fromBase10(sum, K) << '\n';
    }
}
