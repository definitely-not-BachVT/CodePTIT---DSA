#include <bits/stdc++.h>
using namespace std;

const long long MOD = 123456789;

long long binPow(long long a, long long n)
{
    if (n == 0)
        return 1;

    long long tmp = binPow(a, n / 2);
    if (n % 2)
        return ((tmp % MOD * tmp) % MOD) * a % MOD;
    else
        return ((tmp % MOD * tmp) % MOD) % MOD;
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

        cout << binPow(2 % MOD, n - 1) << "\n";
    }
}