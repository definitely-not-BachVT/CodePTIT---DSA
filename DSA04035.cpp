#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

long long binPow(long long a, long long b)
{
    long long ans = 1;
    while (b)
    {
        if (b % 2)
            ans = ans * a % MOD;
        a = a * a % MOD;

        b /= 2;
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long a = 1, b = 1;

    while (true)
    {
        cin >> a >> b;
        if (a == 0 && b == 0)
            return 0;

        cout << binPow(a, b) << "\n";
    }
}