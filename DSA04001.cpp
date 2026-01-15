#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
long long binPow(long long a, long long k)
{
    a %= MOD;
    long long ans = 1;
    while (k)
    {
        if (k % 2)
            ans = ans * a % MOD;
        a = a * a % MOD;

        k /= 2;
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long n, k;
        cin >> n >> k;

        cout << binPow(n, k) << "\n";
    }
}
